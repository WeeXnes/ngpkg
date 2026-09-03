#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <errno.h>

#define BUFFER_SIZE 65536

static const char *root_dir = "/mnt/usb/netboot/www";
static const char *iso_dir = "/mnt/usb/isos";

static void send_headers(int client_fd, int status, const char *status_msg, const char *content_type, long long content_length, long long range_start, long long range_end, long long total_size) {
    char header[1024];
    int len;
    if (status == 206) {
        len = snprintf(header, sizeof(header),
            "HTTP/1.1 206 Partial Content\r\n"
            "Content-Type: %s\r\n"
            "Content-Length: %lld\r\n"
            "Content-Range: bytes %lld-%lld/%lld\r\n"
            "Accept-Ranges: bytes\r\n"
            "Connection: close\r\n"
            "Access-Control-Allow-Origin: *\r\n\r\n",
            content_type, content_length, range_start, range_end, total_size);
    } else {
        len = snprintf(header, sizeof(header),
            "HTTP/1.1 %d %s\r\n"
            "Content-Type: %s\r\n"
            "Content-Length: %lld\r\n"
            "Accept-Ranges: bytes\r\n"
            "Connection: close\r\n"
            "Access-Control-Allow-Origin: *\r\n\r\n",
            status, status_msg, content_type, content_length);
    }
    write(client_fd, header, len);
}

static void handle_client(int client_fd) {
    char req[2048];
    ssize_t n = read(client_fd, req, sizeof(req) - 1);
    if (n <= 0) {
        close(client_fd);
        return;
    }
    req[n] = '\0';

    char method[16], path[512], proto[16];
    if (sscanf(req, "%15s %511s %15s", method, path, proto) < 2) {
        send_headers(client_fd, 400, "Bad Request", "text/plain", 11, 0, 0, 0);
        write(client_fd, "Bad Request", 11);
        close(client_fd);
        return;
    }

    // Parse Range header if present
    long long range_start = -1, range_end = -1;
    char *range_hdr = strcasestr(req, "Range: bytes=");
    if (range_hdr) {
        range_hdr += 13;
        char *dash = strchr(range_hdr, '-');
        if (dash) {
            range_start = atoll(range_hdr);
            if (*(dash + 1) >= '0' && *(dash + 1) <= '9') {
                range_end = atoll(dash + 1);
            }
        }
    }

    // Resolve local file path
    char file_path[1024];
    if (strncmp(path, "/isos/", 6) == 0) {
        snprintf(file_path, sizeof(file_path), "%s/%s", iso_dir, path + 6);
    } else {
        if (strcmp(path, "/") == 0 || strcmp(path, "/boot.ipxe") == 0) {
            snprintf(file_path, sizeof(file_path), "%s/boot.ipxe", root_dir);
        } else {
            snprintf(file_path, sizeof(file_path), "%s%s", root_dir, path);
        }
    }

    // Sanitize path (prevent ../ traversal)
    if (strstr(file_path, "..")) {
        send_headers(client_fd, 403, "Forbidden", "text/plain", 9, 0, 0, 0);
        write(client_fd, "Forbidden", 9);
        close(client_fd);
        return;
    }

    int fd = open(file_path, O_RDONLY);
    if (fd < 0) {
        const char *not_found = "404 Not Found\n";
        send_headers(client_fd, 404, "Not Found", "text/plain", strlen(not_found), 0, 0, 0);
        write(client_fd, not_found, strlen(not_found));
        close(client_fd);
        return;
    }

    struct stat st;
    if (fstat(fd, &st) < 0 || S_ISDIR(st.st_mode)) {
        close(fd);
        send_headers(client_fd, 403, "Forbidden", "text/plain", 9, 0, 0, 0);
        write(client_fd, "Forbidden", 9);
        close(client_fd);
        return;
    }

    long long file_size = st.st_size;
    const char *content_type = "application/octet-stream";
    if (strstr(file_path, ".ipxe")) content_type = "text/plain";
    else if (strstr(file_path, ".iso")) content_type = "application/x-iso9660-image";

    if (range_start >= 0) {
        if (range_end < 0 || range_end >= file_size) {
            range_end = file_size - 1;
        }
        if (range_start > range_end || range_start >= file_size) {
            close(fd);
            send_headers(client_fd, 416, "Range Not Satisfiable", "text/plain", 0, 0, 0, file_size);
            close(client_fd);
            return;
        }

        long long chunk_len = range_end - range_start + 1;
        send_headers(client_fd, 206, "Partial Content", content_type, chunk_len, range_start, range_end, file_size);

        if (strcmp(method, "HEAD") != 0) {
            lseek(fd, range_start, SEEK_SET);
            char buf[BUFFER_SIZE];
            long long remaining = chunk_len;
            while (remaining > 0) {
                size_t to_read = (remaining > sizeof(buf)) ? sizeof(buf) : remaining;
                ssize_t rd = read(fd, buf, to_read);
                if (rd <= 0) break;
                ssize_t wr = write(client_fd, buf, rd);
                if (wr <= 0) break;
                remaining -= wr;
            }
        }
    } else {
        send_headers(client_fd, 200, "OK", content_type, file_size, 0, 0, 0);
        if (strcmp(method, "HEAD") != 0) {
            char buf[BUFFER_SIZE];
            ssize_t rd;
            while ((rd = read(fd, buf, sizeof(buf))) > 0) {
                if (write(client_fd, buf, rd) <= 0) break;
            }
        }
    }

    close(fd);
    close(client_fd);
}

int main(int argc, char **argv) {
    int port = 8080;
    if (argc > 1) port = atoi(argv[1]);
    if (argc > 2) root_dir = argv[2];
    if (argc > 3) iso_dir = argv[3];

    signal(SIGCHLD, SIG_IGN);
    signal(SIGPIPE, SIG_IGN);

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        return 1;
    }

    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        return 1;
    }

    if (listen(server_fd, 32) < 0) {
        perror("listen");
        return 1;
    }

    printf("OpenNGFW Netboot HTTP Server listening on port %d (root: %s, isos: %s)\n", port, root_dir, iso_dir);

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
        if (client_fd < 0) continue;

        if (fork() == 0) {
            close(server_fd);
            handle_client(client_fd);
            exit(0);
        }
        close(client_fd);
    }
    return 0;
}
