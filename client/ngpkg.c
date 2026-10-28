
#ifndef V_COMMIT_HASH
	#define V_COMMIT_HASH "45ae01d23168b6372f734eeb38a77360bbcf184a"
#endif

#define V_USE_SIGNAL_H

// V comptime_definitions:
// V compile time defines by -d or -define flags:
//     All custom defines      : no_backtrace,linux
//     Turned ON custom defines: no_backtrace,linux
#define CUSTOM_DEFINE_no_backtrace
#define CUSTOM_DEFINE_linux


// V typedefs:
typedef struct IError IError;
typedef struct none none;

// BEGIN_array_fixed_return_typedefs
typedef struct _v_Array_fixed_u8_128 _v_Array_fixed_u8_128;
typedef struct _v_Array_fixed_char_256 _v_Array_fixed_char_256;
typedef struct _v_Array_fixed_u8_32 _v_Array_fixed_u8_32;
typedef struct _v_Array_fixed_u8_64 _v_Array_fixed_u8_64;
typedef struct _v_Array_fixed_u8_5 _v_Array_fixed_u8_5;
typedef struct _v_Array_fixed_u8_20 _v_Array_fixed_u8_20;
typedef struct _v_Array_fixed_u32_10 _v_Array_fixed_u32_10;
typedef struct _v_Array_fixed_u64_20 _v_Array_fixed_u64_20;
typedef struct _v_Array_fixed_u64_584 _v_Array_fixed_u64_584;
typedef struct _v_Array_fixed_u64_652 _v_Array_fixed_u64_652;
typedef struct _v_Array_fixed_f64_36 _v_Array_fixed_f64_36;
typedef struct _v_Array_fixed_u8_26 _v_Array_fixed_u8_26;
typedef struct _v_Array_fixed_u8_512 _v_Array_fixed_u8_512;
typedef struct _v_Array_fixed_u64_47 _v_Array_fixed_u64_47;
typedef struct _v_Array_fixed_u64_31 _v_Array_fixed_u64_31;
typedef struct _v_Array_fixed_int_64 _v_Array_fixed_int_64;
typedef struct _v_Array_fixed_voidptr_64 _v_Array_fixed_voidptr_64;
typedef struct _v_Array_fixed_u8_17 _v_Array_fixed_u8_17;
typedef struct _v_Array_fixed_i32_1264 _v_Array_fixed_i32_1264;
typedef struct _v_Array_fixed_int_10 _v_Array_fixed_int_10;
typedef struct _v_Array_fixed_int_20 _v_Array_fixed_int_20;
typedef struct _v_Array_fixed_u8_4096 _v_Array_fixed_u8_4096;
typedef struct _v_Array_fixed_u8_1024 _v_Array_fixed_u8_1024;
// END_array_fixed_return_typedefs


// BEGIN_multi_return_typedefs
typedef struct multi_return_u32_u32 multi_return_u32_u32;
typedef struct multi_return_rune_int multi_return_rune_int;
typedef struct multi_return_strconv__Dec32_bool multi_return_strconv__Dec32_bool;
typedef struct multi_return_strconv__Dec64_bool multi_return_strconv__Dec64_bool;
typedef struct multi_return_string_int multi_return_string_int;
typedef struct multi_return_int_bool multi_return_int_bool;
typedef struct multi_return_u64_u64 multi_return_u64_u64;
// END_multi_return_typedefs

typedef struct strconv__BF_param strconv__BF_param;
typedef struct strconv__Dec32 strconv__Dec32;
typedef struct strconv__Dec64 strconv__Dec64;
typedef struct strconv__Uint128 strconv__Uint128;
typedef union strconv__Uf32 strconv__Uf32;
typedef union strconv__Uf64 strconv__Uf64;
typedef union strconv__Float64u strconv__Float64u;
typedef union strconv__Float32u strconv__Float32u;
typedef struct array array;
typedef struct ArrayDataHeader ArrayDataHeader;
typedef struct _result _result;
typedef struct Error Error;
typedef struct MessageError MessageError;
typedef struct _option _option;
typedef struct None__ None__;
typedef struct GraphemeState GraphemeState;
typedef struct DenseArray DenseArray;
typedef struct map map;
typedef struct string string;
typedef union StrIntpMem StrIntpMem;
typedef struct StrIntpData StrIntpData;
typedef struct os__NotExpected os__NotExpected;
typedef struct os__File os__File;
typedef struct os__FileNotOpenedError os__FileNotOpenedError;
typedef struct os__SizeOfTypeIs0Error os__SizeOfTypeIs0Error;
typedef struct os__CopyParams os__CopyParams;
typedef struct os__SystemError os__SystemError;
typedef struct os__Eof os__Eof;
typedef struct os__Result os__Result;
typedef struct os__ExecutableNotFoundError os__ExecutableNotFoundError;
typedef struct os__MkdirParams os__MkdirParams;
typedef struct os__Stat os__Stat;
typedef struct main__Repo main__Repo;
typedef struct main__Config main__Config;
typedef struct main__Package main__Package;
typedef struct _result_os__File _result_os__File;
typedef struct _result_FILE_ptr _result_FILE_ptr;
typedef struct _result_int _result_int;
typedef struct _result_void _result_void;
typedef struct _result_strings__Builder _result_strings__Builder;
typedef struct _result_string _result_string;
typedef struct _result_os__Stat _result_os__Stat;
typedef struct _result_Array_string _result_Array_string;
typedef struct _option_int _option_int;
typedef struct _option_u8 _option_u8;
typedef struct _option_string _option_string;
typedef struct _option_main__Package _option_main__Package;

 // V preincludes:
#define _GNU_SOURCE

#if defined(__TINYC__) && defined(__has_include) // tcc does not support has_include properly yet, turn it off completely
#undef __has_include
#endif

#if defined(__TINYC__) && defined(__BIONIC__)
	#define __builtin_nanf(ignored_string) (0.0F / 0.0F)
	#define __builtin_nan(ignored_string) (0.0 / 0.0)
	#define __builtin_nanl(ignored_string) (0.0L / 0.0L)
	#define __builtin_inff() (1.0F / 0.0F)
	#define __builtin_inf() (1.0 / 0.0)
	#define __builtin_infl() (1.0L / 0.0L)
	#define __builtin_huge_valf() (1.0F / 0.0F)
	#define __builtin_huge_val() (1.0 / 0.0)
	#define __builtin_huge_vall() (1.0L / 0.0L)
#endif

// V cheaders:
// Generated by the V compiler

#if defined __GNUC__ && __GNUC__ >= 14
#pragma GCC diagnostic warning "-Wimplicit-function-declaration"
#pragma GCC diagnostic warning "-Wincompatible-pointer-types"
#pragma GCC diagnostic warning "-Wint-conversion"
#pragma GCC diagnostic warning "-Wreturn-mismatch"
#endif


#if defined(__TINYC__) && defined(__has_include) // tcc does not support has_include properly yet, turn it off completely
#undef __has_include
#endif

#if defined(__TINYC__) && defined(__BIONIC__)
	#define __builtin_nanf(ignored_string) (0.0F / 0.0F)
	#define __builtin_nan(ignored_string) (0.0 / 0.0)
	#define __builtin_nanl(ignored_string) (0.0L / 0.0L)
	#define __builtin_inff() (1.0F / 0.0F)
	#define __builtin_inf() (1.0 / 0.0)
	#define __builtin_infl() (1.0L / 0.0L)
	#define __builtin_huge_valf() (1.0F / 0.0F)
	#define __builtin_huge_val() (1.0 / 0.0)
	#define __builtin_huge_vall() (1.0L / 0.0L)
#endif

#ifdef __TINYC__
#include <inttypes.h>
#else
#if defined(__has_include)
#if __has_include(<inttypes.h>)
#include <inttypes.h>
#elif __has_include(<stdint.h>)
#include <stdint.h>
#else
#error VERROR_MESSAGE The C compiler can not find <stdint.h>. Please install the package `build-essential`.
#endif
#else
#include <stdint.h>
#endif
#endif


#ifdef __TINYC__
#include <stddef.h>
#else
#if defined(__has_include)
#if __has_include(<stddef.h>)
#include <stddef.h>
#else
#error VERROR_MESSAGE The C compiler can not find <stddef.h>. Please install the package `build-essential`.
#endif
#else
#include <stddef.h>
#endif
#endif


//================================== builtin types ================================*/
#if defined(__x86_64__) || defined(_M_AMD64) || defined(__aarch64__) || defined(__arm64__) || defined(_M_ARM64) || (defined(__riscv_xlen) && __riscv_xlen == 64) || defined(__s390x__) || (defined(__powerpc64__) && defined(__LITTLE_ENDIAN__)) || defined(__loongarch64) || defined(__sparc__) || (defined(__powerpc64__) && defined(__BIG_ENDIAN__))
typedef int64_t vint_t;
#else
typedef int32_t vint_t;
#endif
typedef int64_t i64;
typedef int16_t i16;
typedef int8_t i8;
typedef uint64_t u64;
typedef uint32_t u32;
typedef uint8_t u8;
typedef uint16_t u16;
typedef u8 byte;
typedef int32_t i32;
typedef uint32_t rune;
typedef size_t usize;
typedef ptrdiff_t isize;
#ifndef VNOFLOAT
typedef float f32;
typedef double f64;
#else
typedef int32_t f32;
typedef int64_t f64;
#endif
typedef int64_t int_literal;
#ifndef VNOFLOAT
typedef double float_literal;
#else
typedef int64_t float_literal;
#endif
typedef unsigned char* byteptr;
typedef void* voidptr;
typedef char* charptr;
typedef u8 array_fixed_byte_300 [300];
typedef struct sync__Channel* chan;
#ifndef CUSTOM_DEFINE_no_bool
	#ifndef __cplusplus
		#if !defined(__STDC_VERSION__) || __STDC_VERSION__ < 202311L
		#ifndef bool
			#ifdef CUSTOM_DEFINE_4bytebool
				typedef int bool;
			#else
				typedef u8 bool;
			#endif
			#define true 1
			#define false 0
		#endif
		#endif
	#endif
#endif


#define V_SAFE_SHIFT_BITS(type) ((u64)(sizeof(type) * 8))
#define V_SAFE_LSHIFT_UNSIGNED(name, type) static inline type name(type x, u64 y) { return y >= V_SAFE_SHIFT_BITS(type) ? (type)0 : (type)(x << y); }
#define V_SAFE_LSHIFT_SIGNED(name, type, unsigned_type) static inline type name(type x, u64 y) { return y >= V_SAFE_SHIFT_BITS(type) ? (type)0 : (type)(((unsigned_type)x) << y); }
#define V_SAFE_RSHIFT_UNSIGNED(name, type) static inline type name(type x, u64 y) { return y >= V_SAFE_SHIFT_BITS(type) ? (type)0 : (type)(x >> y); }
#define V_SAFE_RSHIFT_SIGNED(name, type) static inline type name(type x, u64 y) { return y >= V_SAFE_SHIFT_BITS(type) ? (type)(x < 0 ? -1 : 0) : (type)(x >> y); }
V_SAFE_LSHIFT_SIGNED(v__lshift_char, char, u8)
V_SAFE_RSHIFT_SIGNED(v__rshift_char, char)
V_SAFE_LSHIFT_SIGNED(v__lshift_i8, i8, u8)
V_SAFE_RSHIFT_SIGNED(v__rshift_i8, i8)
V_SAFE_LSHIFT_SIGNED(v__lshift_i16, i16, u16)
V_SAFE_RSHIFT_SIGNED(v__rshift_i16, i16)
V_SAFE_LSHIFT_SIGNED(v__lshift_i32, i32, u32)
V_SAFE_RSHIFT_SIGNED(v__rshift_i32, i32)
V_SAFE_LSHIFT_SIGNED(v__lshift_int, int, unsigned int)
V_SAFE_RSHIFT_SIGNED(v__rshift_int, int)
V_SAFE_LSHIFT_SIGNED(v__lshift_vint_t, vint_t, u64)
V_SAFE_RSHIFT_SIGNED(v__rshift_vint_t, vint_t)
V_SAFE_LSHIFT_SIGNED(v__lshift_i64, i64, u64)
V_SAFE_RSHIFT_SIGNED(v__rshift_i64, i64)
V_SAFE_LSHIFT_SIGNED(v__lshift_isize, isize, usize)
V_SAFE_RSHIFT_SIGNED(v__rshift_isize, isize)
V_SAFE_LSHIFT_UNSIGNED(v__lshift_u8, u8)
V_SAFE_RSHIFT_UNSIGNED(v__rshift_u8, u8)
V_SAFE_LSHIFT_UNSIGNED(v__lshift_u16, u16)
V_SAFE_RSHIFT_UNSIGNED(v__rshift_u16, u16)
V_SAFE_LSHIFT_UNSIGNED(v__lshift_u32, u32)
V_SAFE_RSHIFT_UNSIGNED(v__rshift_u32, u32)
V_SAFE_LSHIFT_UNSIGNED(v__lshift_u64, u64)
V_SAFE_RSHIFT_UNSIGNED(v__rshift_u64, u64)
V_SAFE_LSHIFT_UNSIGNED(v__lshift_usize, usize)
V_SAFE_RSHIFT_UNSIGNED(v__rshift_usize, usize)
V_SAFE_LSHIFT_UNSIGNED(v__lshift_rune, rune)
V_SAFE_RSHIFT_UNSIGNED(v__rshift_rune, rune)
V_SAFE_LSHIFT_SIGNED(v__lshift_int_literal, int_literal, u64)
V_SAFE_RSHIFT_SIGNED(v__rshift_int_literal, int_literal)
#undef V_SAFE_RSHIFT_SIGNED
#undef V_SAFE_RSHIFT_UNSIGNED
#undef V_SAFE_LSHIFT_SIGNED
#undef V_SAFE_LSHIFT_UNSIGNED
#undef V_SAFE_SHIFT_BITS


typedef u64 (*MapHashFn)(voidptr);
typedef bool (*MapEqFn)(voidptr, voidptr);
typedef void (*MapCloneFn)(voidptr, voidptr);
typedef void (*MapFreeFn)(voidptr);

//============================== HELPER C MACROS =============================*/
// _SLIT0 is used as NULL string for literal arguments
// `"" s` is used to enforce a string literal argument
#define _SLIT0 (string){.str=(byteptr)(""), .len=0, .is_lit=1}
#define _S(s) ((string){.str=(byteptr)("" s), .len=(sizeof(s)-1), .is_lit=1})
#define _SLEN(s, n) ((string){.str=(byteptr)("" s), .len=n, .is_lit=1})
// optimized way to compare literal strings
#define _SLIT_EQ(sptr, slen, lit) (slen == sizeof("" lit)-1 && !builtin__vmemcmp(sptr, "" lit, slen))
#define _SLIT_NE(sptr, slen, lit) (slen != sizeof("" lit)-1 || builtin__vmemcmp(sptr, "" lit, slen))
// take the address of an rvalue
#define ADDR(type, expr) (&((type[]){expr}[0]))
// copy something to the heap
#define HEAP(type, expr) ((type*)builtin__memdup((void*)&((type[]){expr}[0]), sizeof(type)))
#define HEAP_noscan(type, expr) ((type*)builtin__memdup_noscan((void*)&((type[]){expr}[0]), sizeof(type)))
#define HEAP_align(type, expr, align) ((type*)builtin__memdup_align((void*)&((type[]){expr}[0]), sizeof(type), align))
#define HEAP_vgc(type, expr, ptrmap, nptrs) ((type*)builtin__vgc_memdup_typed((void*)&((type[]){expr}[0]), sizeof(type), (ptrmap), (nptrs)))
#define _PUSH_MANY(arr, val, tmp, tmp_typ) {tmp_typ tmp = (val); builtin__array_push_many(arr, tmp.data, tmp.len);}
#define _PUSH_MANY_noscan(arr, val, tmp, tmp_typ) {tmp_typ tmp = (val); builtin__array_push_many_noscan(arr, tmp.data, tmp.len);}

#define E_STRUCT_DECL
#define E_STRUCT
#define __NOINLINE __attribute__((noinline))
#define __IRQHANDLER __attribute__((interrupt))
#define __V_architecture 0
#if defined(__x86_64__) || defined(_M_AMD64)
	#define __V_amd64  1
	#undef __V_architecture
	#define __V_architecture 1
#endif
#if defined(__aarch64__) || defined(__arm64__) || defined(_M_ARM64)
	#define __V_arm64  1
	#undef __V_architecture
	#define __V_architecture 2
#endif
#if defined(__arm__) || defined(_M_ARM)
	#define __V_arm32  1
	#undef __V_architecture
	#define __V_architecture 3
#endif
#if defined(__riscv) && __riscv_xlen == 64
	#define __V_rv64  1
	#undef __V_architecture
	#define __V_architecture 4
#endif
#if defined(__riscv) && __riscv_xlen == 32
	#define __V_rv32  1
	#undef __V_architecture
	#define __V_architecture 5
#endif
#if defined(__i386__) || defined(_M_IX86)
	#define __V_x86    1
	#undef __V_architecture
	#define __V_architecture 6
#endif
#if defined(__s390x__)
	#define __V_s390x  1
	#undef __V_architecture
	#define __V_architecture 7
#endif
#if defined(__powerpc64__) && defined(__LITTLE_ENDIAN__)
	#define __V_ppc64le  1
	#undef __V_architecture
	#define __V_architecture 8
#endif
#if defined(__loongarch64)
	#define __V_loongarch64  1
	#undef __V_architecture
	#define __V_architecture 9
#endif
#if defined(__sparc__)
	#define __V_sparc64  1
	#undef __V_architecture
	#define __V_architecture 10
#endif
#if defined(__powerpc64__) && defined(__BIG_ENDIAN__)
	#define __V_ppc64  1
	#undef __V_architecture
	#define __V_architecture 11
#endif
#if (defined(__powerpc__) || defined(__powerpc) || defined(__POWERPC__) || defined(__ppc__) || defined(__ppc) || defined(__PPC__)) && !defined(__powerpc64__) && !defined(__ppc64__) && !defined(__PPC64__)
	#define __V_ppc  1
	#undef __V_architecture
	#define __V_architecture 12
#endif
// Using just __GNUC__ for detecting gcc, is not reliable because other compilers define it too:
#ifdef __GNUC__
	#define __V_GCC__
#endif
#ifdef __TINYC__
	#undef __V_GCC__
#endif
#ifdef __cplusplus
	#undef __V_GCC__
#endif
#ifdef __clang__
	#undef __V_GCC__
#endif
#ifdef _MSC_VER
	#undef __V_GCC__
	#undef E_STRUCT_DECL
	#undef E_STRUCT
	#define E_STRUCT_DECL unsigned char _dummy_pad
	#define E_STRUCT 0
#endif
#if defined(__has_include) && !defined(__TINYC__)
	#if __has_include(<execinfo.h>) && !defined(_WIN32)
		#define __V_HAVE_EXECINFO_H 1
		#include <execinfo.h>
	#else
		// On linux: int backtrace(void **__array, int __size);
		// On BSD: size_t backtrace(void **, size_t);
	#endif
#elif (defined(__linux__) && (defined(__GLIBC__) || defined(__GNU_LIBRARY__))) || defined(__APPLE__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
	#define __V_HAVE_EXECINFO_H 1
	#include <execinfo.h>
#else
	// On linux: int backtrace(void **__array, int __size);
	// On BSD: size_t backtrace(void **, size_t);
#endif
#ifndef __V_HAVE_EXECINFO_H
	#ifdef __cplusplus
	extern "C" {
	#endif
	int backtrace(void **__array, int __size);
	char **backtrace_symbols(void *const *__array, int __size);
	void backtrace_symbols_fd(void *const *__array, int __size, int __fd);
	#ifdef __cplusplus
	}
	#endif
#endif
#ifdef __TINYC__
	#define _Atomic volatile
	#undef E_STRUCT_DECL
	#undef E_STRUCT
	#define E_STRUCT_DECL unsigned char _dummy_pad
	#define E_STRUCT 0
	#undef __NOINLINE
	#undef __IRQHANDLER
	// tcc does not support inlining at all
	#define __NOINLINE
	#define __IRQHANDLER
	// #include <byteswap.h>
	int tcc_backtrace(const char *fmt, ...);
#endif
// Use __offsetof_ptr instead of __offset_of, when you *do* have a valid pointer, to avoid UB:
#ifndef __offsetof_ptr
	#define __offsetof_ptr(ptr,PTYPE,FIELDNAME) ((size_t)((byte *)&((PTYPE *)ptr)->FIELDNAME - (byte *)ptr))
#endif
// for __offset_of
#ifndef __offsetof
#if defined(__TINYC__) || defined(_MSC_VER)
	#define __offsetof(PTYPE,FIELDNAME) ((size_t)(&((PTYPE *)0)->FIELDNAME))
#else
	#define __offsetof(st, m) __builtin_offsetof(st, m)
#endif
#endif
#if defined(_WIN32) || defined(__CYGWIN__)
	#define VV_EXP extern __declspec(dllexport)
	#ifdef _VPARALLELCC
		#define VV_LOC
	#else
		#define VV_LOC static
	#endif
#else
	// 4 < gcc < 5 is used by some older Ubuntu LTS and Centos versions,
	// and does not support __has_attribute(visibility) ...
	#ifndef __has_attribute
		#define __has_attribute(x) 0  // Compatibility with non-clang compilers.
	#endif
	#if (defined(__GNUC__) && (__GNUC__ >= 4)) || (defined(__clang__) && __has_attribute(visibility))
		#ifdef ARM
			#define VV_EXP  extern __attribute__((externally_visible,visibility("default")))
		#else
			#define VV_EXP  extern __attribute__((visibility("default")))
		#endif
		#if defined(_VOBJECTFILE) || (defined(__clang__) && (defined(_VUSECACHE) || defined(_VBUILDMODULE)))
			#define VV_LOC static
		#else
			#define VV_LOC  __attribute__ ((visibility ("hidden")))
		#endif
	#else
		#define VV_EXP extern
		#ifdef _VPARALLELCC
			#define VV_LOC
		#else
			#define VV_LOC static
		#endif
	#endif
#endif
#ifdef __cplusplus
	#include <utility>
	#define _MOV std::move
#else
	#define _MOV
#endif
#if defined(__TINYC__) && defined(__has_include) // tcc does not support has_include properly yet, turn it off completely
#undef __has_include
#endif
//likely and unlikely macros
#if defined(__GNUC__) || defined(__INTEL_COMPILER) || defined(__clang__)
	#define _likely_(x)  __builtin_expect(x,1)
	#define _unlikely_(x)  __builtin_expect(x,0)
#else
	#define _likely_(x) (x)
	#define _unlikely_(x) (x)
#endif

#if !defined(VCALLCONV)
	#ifdef _MSC_VER
		#define VCALLCONV(name) __##name
	#else
		#define VCALLCONV(name) __attribute__((name))
	#endif
#endif

// c_headers
typedef int (*qsort_callback_func)(const void*, const void*);
#if defined(_MSC_VER) && !defined(__clang__)
	#define V_CRT_LINKAGE __declspec(dllimport)
	#define V_CRT_CALL VCALLCONV(cdecl)
#else
	#define V_CRT_LINKAGE
	#define V_CRT_CALL
#endif
#if (defined(_MSC_VER) && !defined(__clang__)) || defined(__cplusplus)
// Under C++ (g++/clang++), let libc declare FILE/stdio/string/stdlib to keep
// noexcept specifiers consistent — the manual extern "C" prototypes below
// would otherwise conflict with system headers under -std=c++NN.
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef va_copy
	#define va_copy(dest, src) ((dest) = (src))
#endif
#ifndef _TRUNCATE
	#define _TRUNCATE ((size_t)-1)
#endif
#elif defined(__NetBSD__)
// NetBSD exposes stdin/stdout/stderr as macros into a single `__sF[3]`
// array whose element size (sizeof(FILE)) depends on the platform and libc
// version, so we cannot forward-declare them. The FreeBSD-style
// `__stdinp/__stdoutp/__stderrp` symbols also do not exist on NetBSD (see
// vlang/v#27190). Defer to the system headers for FILE, the stdio streams,
// and the libc prototypes that would otherwise clash with the
// `__restrict`-qualified declarations in NetBSD libc.
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#elif defined(__TINYC__) && (defined(__FreeBSD__) || defined(__OpenBSD__))
// TinyCC reports a hard redefinition error if system OpenSSL pulls in
// <stdarg.h> after V has provided its own va_start macro. Include it first,
// but keep V manual FILE declarations on these BSD libc variants.
#include <stdarg.h>
#if defined(__FreeBSD__)
typedef struct __sFILE FILE;
extern FILE* __stdinp;
extern FILE* __stdoutp;
extern FILE* __stderrp;
#define stdin __stdinp
#define stdout __stdoutp
#define stderr __stderrp
#else
typedef struct __sFILE FILE;
#ifndef _STDFILES_DECLARED
	#define _STDFILES_DECLARED
struct __sFstub { long _stub; };
extern struct __sFstub __stdin[];
extern struct __sFstub __stdout[];
extern struct __sFstub __stderr[];
#endif
#define stdin ((struct __sFILE *)__stdin)
#define stdout ((struct __sFILE *)__stdout)
#define stderr ((struct __sFILE *)__stderr)
#endif
#elif (defined(__MINGW32__) || defined(__MINGW64__)) && defined(__V_GCC__)
// mingw-w64 stdio.h provides fprintf/vfprintf as static inline overrides
// when __USE_MINGW_ANSI_STDIO is enabled, so use the system declarations
// instead of the manual formatted-stdio prototypes below.
#include <stdarg.h>
#include <stdio.h>
#elif defined(__MINGW32__) || defined(__MINGW64__) || (defined(__clang__) && (defined(_WIN32) || defined(_WIN64)))
typedef struct _iobuf FILE;
FILE* __cdecl __acrt_iob_func(unsigned index);
#define stdin  (__acrt_iob_func(0))
#define stdout (__acrt_iob_func(1))
#define stderr (__acrt_iob_func(2))
#elif defined(__TINYC__) && (defined(_WIN32) || defined(_WIN64))
#ifndef _FILE_DEFINED
struct _iobuf {
	char *_ptr;
	int _cnt;
	char *_base;
	int _flag;
	int _file;
	int _charbuf;
	int _bufsiz;
	char *_tmpfname;
};
typedef struct _iobuf FILE;
#define _FILE_DEFINED
#endif
	#if defined(_WIN64)
FILE* __cdecl __iob_func(void);
	#else
		#ifdef _MSVCRT_
extern FILE _iob[];
			#define __iob_func() (_iob)
		#else
extern FILE (*_imp___iob)[];
			#define __iob_func() (*_imp___iob)
			#define _iob __iob_func()
		#endif
	#endif
#define stdin (&__iob_func()[0])
#define stdout (&__iob_func()[1])
#define stderr (&__iob_func()[2])
#elif defined(__vinix__)
typedef struct __file FILE;
extern FILE* stdin;
extern FILE* stdout;
extern FILE* stderr;
struct __thread_data;
struct __threadattr;
// pthread_t handling for vinix builds:
//  - Vinix kernel (freestanding, __STDC_HOSTED__=0): no libc, define
//    pthread_t ourselves so V code that references it compiles.
//  - util-vinix cross-compiled on a libc-providing host (hosted, e.g.
//    glibc on Linux or macOS with -D__vinix__): pull pthread_t from
//    libc to avoid colliding with the libc typedef.
#if defined(__STDC_HOSTED__) && __STDC_HOSTED__ && defined(__has_include) && __has_include(<pthread.h>)
#include <pthread.h>
#else
typedef struct __thread_data *pthread_t;
#endif
typedef __builtin_va_list va_list;
#ifndef va_start
	#define va_start(ap, v) __builtin_va_start(ap, v)
#endif
#ifndef va_arg
	#define va_arg(ap, t) __builtin_va_arg(ap, t)
#endif
#ifndef va_end
	#define va_end(ap) __builtin_va_end(ap)
#endif
#ifndef va_copy
	#define va_copy(dest, src) __builtin_va_copy(dest, src)
#endif
#else
	#if defined(__APPLE__) || defined(__FreeBSD__)
typedef struct __sFILE FILE;
extern FILE* __stdinp;
extern FILE* __stdoutp;
extern FILE* __stderrp;
#define stdin __stdinp
#define stdout __stdoutp
#define stderr __stderrp
	#elif defined(__DragonFly__)
typedef struct __sFILE FILE;
extern FILE* __stdinp;
extern FILE* __stdoutp;
extern FILE* __stderrp;
#define stdin __stdinp
#define stdout __stdoutp
#define stderr __stderrp
	#elif defined(__OpenBSD__)
typedef struct __sFILE FILE;
#ifndef _STDFILES_DECLARED
	#define _STDFILES_DECLARED
struct __sFstub { long _stub; };
extern struct __sFstub __stdin[];
extern struct __sFstub __stdout[];
extern struct __sFstub __stderr[];
#endif
#define stdin ((struct __sFILE *)__stdin)
#define stdout ((struct __sFILE *)__stdout)
#define stderr ((struct __sFILE *)__stderr)
	#elif defined(__BIONIC__)
struct __sFILE;
typedef struct __sFILE FILE;
extern FILE* stdin;
extern FILE* stdout;
extern FILE* stderr;
	#elif defined(__linux__) && !defined(__GLIBC__) && !defined(__GNU_LIBRARY__) && !defined(__BIONIC__) && !defined(__UCLIBC__)
typedef struct _IO_FILE FILE;
// musl exposes the stdio streams as `FILE *const`, so match that to stay
// compatible with later <stdio.h> includes from headers like miniz.h.
extern FILE* const stdin;
extern FILE* const stdout;
extern FILE* const stderr;
	#else
typedef struct _IO_FILE FILE;
extern FILE* stdin;
extern FILE* stdout;
extern FILE* stderr;
	#endif
typedef __builtin_va_list va_list;
#ifndef va_start
	#define va_start(ap, v) __builtin_va_start(ap, v)
#endif
#ifndef va_arg
	#define va_arg(ap, t) __builtin_va_arg(ap, t)
#endif
#ifndef va_end
	#define va_end(ap) __builtin_va_end(ap)
#endif
#ifndef va_copy
	#define va_copy(dest, src) __builtin_va_copy(dest, src)
#endif
#endif
#if (!defined(_MSC_VER) || defined(__clang__)) && !defined(__cplusplus) && !defined(__NetBSD__)
// mingw-w64 stdio.h declares these as static __mingw_ovr inline overrides
// when __USE_MINGW_ANSI_STDIO is on. Skip them under gcc+mingw to avoid
// static-after-extern conflicts; clang+mingw needs them because it builds
// with -Werror=implicit-function-declaration and does not hit the conflict.
// NetBSD pulls these prototypes from <stdio.h>/<stdlib.h>/<string.h> via
// the include block above to avoid `__restrict` qualifier conflicts.
#if !((defined(__MINGW32__) || defined(__MINGW64__)) && !defined(__clang__))
V_CRT_LINKAGE int V_CRT_CALL vfprintf(FILE *stream, const char *format, va_list ap);
V_CRT_LINKAGE int V_CRT_CALL vsnprintf(char *str, size_t size, const char *format, va_list ap);
V_CRT_LINKAGE int V_CRT_CALL fprintf(FILE *stream, const char *format, ...);
V_CRT_LINKAGE int V_CRT_CALL printf(const char *format, ...);
V_CRT_LINKAGE int V_CRT_CALL snprintf(char *str, size_t size, const char *format, ...);
V_CRT_LINKAGE int V_CRT_CALL sprintf(char *str, const char *format, ...);
V_CRT_LINKAGE int V_CRT_CALL sscanf(const char *str, const char *format, ...);
V_CRT_LINKAGE int V_CRT_CALL scanf(const char *format, ...);
#endif
V_CRT_LINKAGE int V_CRT_CALL puts(const char *str);
V_CRT_LINKAGE void V_CRT_CALL perror(const char *str);
V_CRT_LINKAGE int V_CRT_CALL fputs(const char *str, FILE *stream);
V_CRT_LINKAGE int V_CRT_CALL getchar(void);
V_CRT_LINKAGE int V_CRT_CALL putchar(int ch);
V_CRT_LINKAGE int V_CRT_CALL getc(FILE *stream);
V_CRT_LINKAGE int V_CRT_CALL fgetc(FILE *stream);
V_CRT_LINKAGE int V_CRT_CALL ungetc(int ch, FILE *stream);
V_CRT_LINKAGE int V_CRT_CALL fflush(FILE *stream);
V_CRT_LINKAGE int V_CRT_CALL feof(FILE *stream);
V_CRT_LINKAGE int V_CRT_CALL ferror(FILE *stream);
V_CRT_LINKAGE void V_CRT_CALL clearerr(FILE *stream);
V_CRT_LINKAGE int V_CRT_CALL setvbuf(FILE *stream, char *buf, int mode, size_t size);
V_CRT_LINKAGE long V_CRT_CALL ftell(FILE *stream);
V_CRT_LINKAGE void V_CRT_CALL rewind(FILE *stream);
V_CRT_LINKAGE FILE * V_CRT_CALL fopen(const char *filename, const char *mode);
V_CRT_LINKAGE FILE * V_CRT_CALL fdopen(int fd, const char *mode);
V_CRT_LINKAGE FILE * V_CRT_CALL freopen(const char *filename, const char *mode, FILE *stream);
V_CRT_LINKAGE int V_CRT_CALL fileno(FILE *stream);
V_CRT_LINKAGE size_t V_CRT_CALL fread(void *ptr, size_t size, size_t items, FILE *stream);
V_CRT_LINKAGE size_t V_CRT_CALL fwrite(const void *ptr, size_t size, size_t items, FILE *stream);
#if defined(__vinix__)
V_CRT_LINKAGE char * V_CRT_CALL fgets(char *str, size_t size, FILE *stream);
#else
V_CRT_LINKAGE char * V_CRT_CALL fgets(char *str, int size, FILE *stream);
#endif
V_CRT_LINKAGE int V_CRT_CALL fclose(FILE *stream);
#if defined(__vinix__)
V_CRT_LINKAGE FILE * V_CRT_CALL popen(char *command, char *mode);
#else
V_CRT_LINKAGE FILE * V_CRT_CALL popen(const char *command, const char *mode);
#endif
V_CRT_LINKAGE int V_CRT_CALL pclose(FILE *stream);
V_CRT_LINKAGE void * V_CRT_CALL malloc(size_t size);
V_CRT_LINKAGE void * V_CRT_CALL calloc(size_t nitems, size_t size);
V_CRT_LINKAGE void * V_CRT_CALL realloc(void *ptr, size_t size);
V_CRT_LINKAGE void * V_CRT_CALL aligned_alloc(size_t alignment, size_t size);
V_CRT_LINKAGE int V_CRT_CALL posix_memalign(void **memptr, size_t alignment, size_t size);
V_CRT_LINKAGE void V_CRT_CALL free(void *ptr);
V_CRT_LINKAGE int V_CRT_CALL rand(void);
V_CRT_LINKAGE void V_CRT_CALL srand(unsigned int seed);
V_CRT_LINKAGE int V_CRT_CALL atexit(void (*cb)(void));
V_CRT_LINKAGE void V_CRT_CALL exit(int status);
V_CRT_LINKAGE int V_CRT_CALL abs(int n);
V_CRT_LINKAGE int V_CRT_CALL atoi(const char *str);
V_CRT_LINKAGE double V_CRT_CALL atof(const char *str);
V_CRT_LINKAGE char * V_CRT_CALL getenv(const char *name);
V_CRT_LINKAGE int V_CRT_CALL setenv(const char *name, const char *value, int overwrite);
V_CRT_LINKAGE int V_CRT_CALL unsetenv(const char *name);
V_CRT_LINKAGE int V_CRT_CALL system(const char *command);
V_CRT_LINKAGE int V_CRT_CALL remove(const char *path);
V_CRT_LINKAGE int V_CRT_CALL rename(const char *old_path, const char *new_path);
V_CRT_LINKAGE char * V_CRT_CALL realpath(const char *path, char *resolved_path);
V_CRT_LINKAGE int V_CRT_CALL mkstemp(char *stemplate);
V_CRT_LINKAGE void V_CRT_CALL qsort(void *base, size_t items, size_t item_size, qsort_callback_func cb);
#if defined(__vinix__)
V_CRT_LINKAGE int V_CRT_CALL strcmp(char *left, char *right);
V_CRT_LINKAGE int V_CRT_CALL strncmp(char *left, char *right, size_t n);
#else
V_CRT_LINKAGE int V_CRT_CALL strcmp(const char *left, const char *right);
V_CRT_LINKAGE int V_CRT_CALL strncmp(const char *left, const char *right, size_t n);
#endif
#if !defined(_WIN32) && !defined(_WIN64) && !defined(__BIONIC__)
V_CRT_LINKAGE char * V_CRT_CALL strdup(const char *str);
#endif
#if !defined(_WIN32) && !defined(_WIN64)
V_CRT_LINKAGE int V_CRT_CALL strcasecmp(const char *left, const char *right);
V_CRT_LINKAGE int V_CRT_CALL strncasecmp(const char *left, const char *right, size_t n);
#endif
#if defined(__vinix__)
V_CRT_LINKAGE size_t V_CRT_CALL strlen(char *str);
#else
V_CRT_LINKAGE size_t V_CRT_CALL strlen(const char *str);
#endif
V_CRT_LINKAGE char * V_CRT_CALL strerror(int errnum);
V_CRT_LINKAGE void * V_CRT_CALL memcpy(void *dest, const void *src, size_t n);
V_CRT_LINKAGE void * V_CRT_CALL memmove(void *dest, const void *src, size_t n);
V_CRT_LINKAGE void * V_CRT_CALL memset(void *dest, int ch, size_t n);
V_CRT_LINKAGE int V_CRT_CALL memcmp(const void *left, const void *right, size_t n);
V_CRT_LINKAGE void * V_CRT_CALL memchr(const void *str, int c, size_t n);
V_CRT_LINKAGE char * V_CRT_CALL strchr(const char *str, int c);
V_CRT_LINKAGE char * V_CRT_CALL strrchr(const char *str, int c);
V_CRT_LINKAGE char * V_CRT_CALL strstr(const char *haystack, const char *needle);
V_CRT_LINKAGE int V_CRT_CALL fseek(FILE *stream, long offset, int whence);
V_CRT_LINKAGE isize V_CRT_CALL getline(char **lineptr, size_t *n, FILE *stream);
#if defined(_WIN32) || defined(_WIN64)
V_CRT_LINKAGE int V_CRT_CALL _fileno(FILE *stream);
V_CRT_LINKAGE FILE * V_CRT_CALL _wfopen(const unsigned short *filename, const unsigned short *mode);
V_CRT_LINKAGE int V_CRT_CALL _wremove(const unsigned short *path);
V_CRT_LINKAGE void * V_CRT_CALL _aligned_malloc(size_t size, size_t alignment);
V_CRT_LINKAGE void * V_CRT_CALL _aligned_realloc(void *memory, size_t size, size_t alignment);
V_CRT_LINKAGE void V_CRT_CALL _aligned_free(void *memory);
V_CRT_LINKAGE unsigned short * V_CRT_CALL _wgetenv(const unsigned short *varname);
V_CRT_LINKAGE int V_CRT_CALL _wputenv(const unsigned short *envstring);
#endif
#if defined(_MSC_VER) && !defined(__clang__)
#ifndef _TRUNCATE
	#define _TRUNCATE ((size_t)-1)
#endif
V_CRT_LINKAGE int V_CRT_CALL _vscprintf(const char *format, va_list ap);
V_CRT_LINKAGE int V_CRT_CALL _vsnprintf_s(char *buffer, size_t size, size_t count, const char *format, va_list ap);
#endif
#endif
#ifndef _IOFBF
	#define _IOFBF 0
#endif
#ifndef _IOLBF
	#define _IOLBF 1
#endif
#ifndef _IONBF
	#define _IONBF 2
#endif
#ifndef EOF
	#define EOF (-1)
#endif
#ifndef SEEK_SET
	#define SEEK_SET 0
#endif
#ifndef SEEK_CUR
	#define SEEK_CUR 1
#endif
#ifndef SEEK_END
	#define SEEK_END 2
#endif
#ifndef RAND_MAX
enum {
	#if defined(_MSC_VER)
		RAND_MAX = 0x7fff
	#else
		RAND_MAX = 2147483647
	#endif
};
#endif
#undef V_CRT_LINKAGE
#undef V_CRT_CALL
static void v_stable_sort(void *base, size_t items, size_t item_size, qsort_callback_func cb) {
	if (items < 2 || item_size == 0) {
		return;
	}
	if (items > ((size_t)-1) / item_size) {
		qsort(base, items, item_size, cb);
		return;
	}
	const size_t bytes = items * item_size;
	char *base_bytes = (char*)base;
	char *tmp = (char*)malloc(bytes);
	if (tmp == 0) {
		qsort(base, items, item_size, cb);
		return;
	}
	char *src = base_bytes;
	char *dst = tmp;
	for (size_t width = 1; width < items;) {
		for (size_t left = 0; left < items;) {
			size_t mid = left;
			mid += width;
			if (mid > items) {
				mid = items;
			}
			size_t right = mid;
			right += width;
			if (right > items || right < mid) {
				right = items;
			}
			size_t i = left;
			size_t j = mid;
			size_t k = left;
			while (i < mid && j < right) {
				char *leftp = src;
				leftp += i * item_size;
				char *rightp = src;
				rightp += j * item_size;
				char *dstp = dst;
				dstp += k * item_size;
				if (cb(leftp, rightp) <= 0) {
					memcpy(dstp, leftp, item_size);
					i++;
				} else {
					memcpy(dstp, rightp, item_size);
					j++;
				}
				k++;
			}
			while (i < mid) {
				char *dstp = dst;
				dstp += k * item_size;
				char *srcp = src;
				srcp += i * item_size;
				memcpy(dstp, srcp, item_size);
				i++;
				k++;
			}
			while (j < right) {
				char *dstp = dst;
				dstp += k * item_size;
				char *srcp = src;
				srcp += j * item_size;
				memcpy(dstp, srcp, item_size);
				j++;
				k++;
			}
			left = right;
		}
		char *next_src = dst;
		dst = src;
		src = next_src;
		if (width > items / 2) {
			width = items;
		} else {
			width *= 2;
		}
	}
	if (src != base_bytes) {
		memcpy(base_bytes, src, bytes);
	}
	free(tmp);
}
#if defined(__TINYC__)
// https://lists.nongnu.org/archive/html/tinycc-devel/2025-10/msg00007.html
// gnu headers use to #define __attribute__ to empty for non-gcc compilers
#undef __attribute__
#endif
#if defined(_MSC_VER) && !defined(__clang__)
// Ensure C99-like return semantics and NUL-termination for MSVC snprintf/vsnprintf.
static int v__vsnprintf(char *s, size_t n, const char *fmt, va_list ap) {
	va_list ap_copy;
	va_copy(ap_copy, ap);
	const int needed = _vscprintf(fmt, ap_copy);
	va_end(ap_copy);
	if (n > 0) {
		const int written = _vsnprintf_s(s, n, _TRUNCATE, fmt, ap);
		if (written < 0) {
			s[n -
	1] = 0;
		}
	}
	return needed;
}
static int v__snprintf(char *s, size_t n, const char *fmt, ...) {
	va_list ap;
	va_start(ap, fmt);
	const int needed = v__vsnprintf(s, n, fmt, ap);
	va_end(ap);
	return needed;
}
#define vsnprintf v__vsnprintf
#define snprintf v__snprintf
#endif
//================================== GLOBALS =================================*/
#ifdef _VOBJECTFILE
static void _vinit(int ___argc, voidptr ___argv);
static void _vcleanup(void);
#else
void _vinit(int ___argc, voidptr ___argv);
void _vcleanup(void);
#endif
#ifdef _WIN32
	// Export helpers so the autogenerated DllMain, or a user-defined one,
	// can reuse the default V shared-library init/cleanup path.
	#ifdef _VOBJECTFILE
		static void _vinit_caller();
		static void _vcleanup_caller();
	#else
		VV_EXP void _vinit_caller();
		VV_EXP void _vcleanup_caller();
	#endif
#endif
#if !defined(_WIN32)
#define sigaction_size sizeof(sigaction);
#endif
#define _ARR_LEN(a) ( (sizeof(a)) / (sizeof(a[0])) )
#if INTPTR_MAX == INT32_MAX
	#define TARGET_IS_32BIT 1
#elif INTPTR_MAX == INT64_MAX
	#define TARGET_IS_64BIT 1
#else
	#error "The environment is not 32 or 64-bit."
#endif
#if defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__ || defined(__BYTE_ORDER) && __BYTE_ORDER == __BIG_ENDIAN || defined(__BIG_ENDIAN__) || defined(__ARMEB__) || defined(__THUMBEB__) || defined(__AARCH64EB__) || defined(_MIBSEB) || defined(__MIBSEB) || defined(__MIBSEB__)
	#define TARGET_ORDER_IS_BIG 1
#elif defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__ || defined(__BYTE_ORDER) && __BYTE_ORDER == __LITTLE_ENDIAN || defined(__LITTLE_ENDIAN__) || defined(__ARMEL__) || defined(__THUMBEL__) || defined(__AARCH64EL__) || defined(_MIPSEL) || defined(__MIPSEL) || defined(__MIPSEL__) || defined(_M_AMD64) || defined(_M_ARM64) || defined(_M_X64) || defined(_M_IX86)
	#define TARGET_ORDER_IS_LITTLE 1
#else
	#error "Unknown architecture endianness"
#endif
#if !defined(_WIN32) && !defined(__vinix__)
	#include <ctype.h>
	#include <locale.h> // tolower
	#include <sys/time.h>
	#include <unistd.h> // sleep
	extern char **environ;
	#include <pthread.h>
	#ifndef PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP
		// musl does not have that
		#define pthread_rwlockattr_setkind_np(a, b)
	#endif
#endif
#if (defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__serenity__) || defined(__sun) || defined(__plan9__) || defined(__OpenBSD__)) && !defined(__vinix__)
	#include <sys/types.h>
	#include <sys/wait.h> // for os__wait
#endif
#ifdef __OpenBSD__
	#include <sys/resource.h>
#endif
#ifdef __FreeBSD__
	#include <signal.h>
	#include <execinfo.h>
#endif
#ifdef __NetBSD__
	#include <sys/wait.h> // for os__wait
#endif
#ifdef __TERMUX__
#if !defined(__BIONIC_AVAILABILITY_GUARD)
	#define __BIONIC_AVAILABILITY_GUARD(api_level) 0
#endif
#if __BIONIC_AVAILABILITY_GUARD(28)
#else
void * aligned_alloc(size_t alignment, size_t size) { return malloc(size); }
#endif
#endif
#ifdef __APPLE__
	// macOS only exports aligned_alloc starting with 10.15.
	#if !defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__) || __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ < 101500
static void *v__aligned_alloc_fallback(size_t alignment, size_t size) {
	void *res = 0;
	if (alignment < sizeof(void *)) {
		alignment = sizeof(void *);
	}
	if (posix_memalign(&res, alignment, size) != 0) {
		return 0;
	}
	return res;
}
		#define aligned_alloc v__aligned_alloc_fallback
	#endif
#endif
#ifdef _WIN32
	#ifdef WINVER
		#undef WINVER
	#endif
	#define WINVER 0x0600
	#ifdef _WIN32_WINNT
		#undef _WIN32_WINNT
	#endif
	#define _WIN32_WINNT 0x0600
	#ifndef WIN32_FULL
	#define WIN32_LEAN_AND_MEAN
	#endif
	#ifndef _UNICODE
	#define _UNICODE
	#endif
	#ifndef UNICODE
	#define UNICODE
	#endif
	#include <windows.h>
	#include <io.h> // _waccess
	#include <direct.h> // _wgetcwd
	#ifdef V_USE_SIGNAL_H
	#include <signal.h> // signal and SIGSEGV for segmentation fault handler
	#endif
	#ifdef _MSC_VER
		// On MSVC these are the same (as long as /volatile:ms is passed)
		#define _Atomic volatile
		// MSVC cannot parse some things properly
		#undef __NOINLINE
		#undef __IRQHANDLER
		#define __NOINLINE __declspec(noinline)
		#define __IRQHANDLER __declspec(naked)
		#include <dbghelp.h>
		#pragma comment(lib, "Dbghelp")
	#endif
#endif
#if defined(__CYGWIN__) && !defined(_WIN32)
	#error Cygwin is not supported, please use MinGW or Visual Studio.
#endif
#if defined(__MINGW32__) || defined(__MINGW64__) || (defined(_WIN32) && defined(__TINYC__)) || defined(_MSC_VER)
	#undef PRId64
	#undef PRIi64
	#undef PRIo64
	#undef PRIu64
	#undef PRIx64
	#undef PRIX64
	#define PRId64 "lld"
	#define PRIi64 "lli"
	#define PRIo64 "llo"
	#define PRIu64 "llu"
	#define PRIx64 "llx"
	#define PRIX64 "llX"
#endif
#ifdef _VFREESTANDING
#undef _VFREESTANDING
#endif


// deterministic float -> u64 conversions for explicit V casts
// direct C casts are undefined for out-of-range values
static inline uint64_t _v_f64_to_u64(double x) {
	if (!(x >= 0.0)) {
		return 0;
	}
	if (x >= 18446744073709551616.0) {
		return UINT64_MAX;
	}
	return (uint64_t)x;
}


// unsigned/signed comparisons
static inline bool _us32_gt(uint32_t a, int32_t b) { return a > INT32_MAX || (int32_t)a > b; }
static inline bool _us32_ge(uint32_t a, int32_t b) { return a >= INT32_MAX || (int32_t)a >= b; }
static inline bool _us32_eq(uint32_t a, int32_t b) { return a <= INT32_MAX && (int32_t)a == b; }
static inline bool _us32_ne(uint32_t a, int32_t b) { return a > INT32_MAX || (int32_t)a != b; }
static inline bool _us32_le(uint32_t a, int32_t b) { return a <= INT32_MAX && (int32_t)a <= b; }
static inline bool _us32_lt(uint32_t a, int32_t b) { return a < INT32_MAX && (int32_t)a < b; }
static inline bool _us64_gt(uint64_t a, int64_t b) { return a > INT64_MAX || (int64_t)a > b; }
static inline bool _us64_ge(uint64_t a, int64_t b) { return a >= INT64_MAX || (int64_t)a >= b; }
static inline bool _us64_eq(uint64_t a, int64_t b) { return a <= INT64_MAX && (int64_t)a == b; }
static inline bool _us64_ne(uint64_t a, int64_t b) { return a > INT64_MAX || (int64_t)a != b; }
static inline bool _us64_le(uint64_t a, int64_t b) { return a <= INT64_MAX && (int64_t)a <= b; }
static inline bool _us64_lt(uint64_t a, int64_t b) { return a < INT64_MAX && (int64_t)a < b; }


#if !defined(VNORETURN)
	#if defined(__TINYC__)
		#define VNORETURN __attribute__((noreturn))
	# elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
	#  define VNORETURN _Noreturn
	# elif !defined(VNORETURN) && defined(__GNUC__) && __GNUC__ >= 2
	#  define VNORETURN __attribute__((noreturn))
	# endif
	#ifndef VNORETURN
		#define VNORETURN
	#endif
#endif


#if !defined(VUNREACHABLE)
	#if defined(__GNUC__) && !defined(__clang__)
		#define V_GCC_VERSION  (__GNUC__ * 10000L + __GNUC_MINOR__ * 100L + __GNUC_PATCHLEVEL__)
		#if (V_GCC_VERSION >= 40500L) && !defined(__TINYC__)
			#define VUNREACHABLE()  do { __builtin_unreachable(); } while (0)
		#endif
	#endif
	#if defined(__clang__) && defined(__has_builtin) && !defined(__TINYC__)
		#if __has_builtin(__builtin_unreachable)
			#define VUNREACHABLE()  do { __builtin_unreachable(); } while (0)
		#endif
	#endif
	#ifndef VUNREACHABLE
		#define VUNREACHABLE() do { } while (0)
	#endif
#endif


#ifndef wyhash_final_version_4_2
#define wyhash_final_version_4_2
#ifndef WYHASH_CONDOM
// protections that produce different results:
// 1: normal valid behavior
// 2: extra protection against entropy loss (probability=2^-63), aka. "blind multiplication"
#define WYHASH_CONDOM 1
#endif
#ifndef WYHASH_32BIT_MUM
// 0: normal version, slow on 32 bit systems
// 1: faster on 32 bit systems but produces different results, incompatible with wy2u0k function
#define WYHASH_32BIT_MUM 0
#endif
// includes
#include <stdint.h>
#if defined(_MSC_VER) && defined(_M_X64)
	#include <intrin.h>
	#pragma intrinsic(_umul128)
#endif
// 128bit multiply function
static inline uint64_t _wyrot(uint64_t x) { return (x>>32)|(x<<32); }
static inline void _wymum(uint64_t *A, uint64_t *B){
#if(WYHASH_32BIT_MUM)
	uint64_t hh=(*A>>32)*(*B>>32), hl=(*A>>32)*(uint32_t)*B, lh=(uint32_t)*A*(*B>>32), ll=(uint64_t)(uint32_t)*A*(uint32_t)*B;
	#if(WYHASH_CONDOM>1)
	*A^=_wyrot(hl)^hh; *B^=_wyrot(lh)^ll;
	#else
	*A=_wyrot(hl)^hh; *B=_wyrot(lh)^ll;
	#endif
#elif defined(__SIZEOF_INT128__) && !defined(VWASM)
	__uint128_t r=*A; r*=*B;
	#if(WYHASH_CONDOM>1)
	*A^=(uint64_t)r; *B^=(uint64_t)(r>>64);
	#else
	*A=(uint64_t)r; *B=(uint64_t)(r>>64);
	#endif
#elif defined(_MSC_VER) && defined(_M_X64)
	#if(WYHASH_CONDOM>1)
	uint64_t  a,  b;
	a=_umul128(*A,*B,&b);
	*A^=a;  *B^=b;
	#else
	*A=_umul128(*A,*B,B);
	#endif
#else
	uint64_t ha=*A>>32, hb=*B>>32, la=(uint32_t)*A, lb=(uint32_t)*B, hi, lo;
	uint64_t rh=ha*hb, rm0=ha*lb, rm1=hb*la, rl=la*lb, t=rl+(rm0<<32), c=t<rl;
	lo=t+(rm1<<32); c+=lo<t; hi=rh+(rm0>>32)+(rm1>>32)+c;
	#if(WYHASH_CONDOM>1)
	*A^=lo;  *B^=hi;
	#else
	*A=lo;  *B=hi;
	#endif
#endif
}
// multiply and xor mix function, aka MUM
static inline uint64_t _wymix(uint64_t A, uint64_t B){ _wymum(&A,&B); return A^B; }
// endian macros
#ifndef WYHASH_LITTLE_ENDIAN
	#ifdef TARGET_ORDER_IS_LITTLE
		#define WYHASH_LITTLE_ENDIAN 1
	#else
		#define WYHASH_LITTLE_ENDIAN 0
	#endif
#endif
// read functions
#if (WYHASH_LITTLE_ENDIAN)
	static inline uint64_t _wyr8(const uint8_t *p) { uint64_t v; memcpy(&v, p, 8); return v;}
	static inline uint64_t _wyr4(const uint8_t *p) { uint32_t v; memcpy(&v, p, 4); return v;}
#elif !defined(__TINYC__) && (defined(__GNUC__) || defined(__INTEL_COMPILER) || defined(__clang__))
	static inline uint64_t _wyr8(const uint8_t *p) { uint64_t v; memcpy(&v, p, 8); return __builtin_bswap64(v);}
	static inline uint64_t _wyr4(const uint8_t *p) { uint32_t v; memcpy(&v, p, 4); return __builtin_bswap32(v);}
#elif defined(_MSC_VER)
	static inline uint64_t _wyr8(const uint8_t *p) { uint64_t v; memcpy(&v, p, 8); return _byteswap_uint64(v);}
	static inline uint64_t _wyr4(const uint8_t *p) { uint32_t v; memcpy(&v, p, 4); return _byteswap_ulong(v);}
#else
	static inline uint64_t _wyr8(const uint8_t *p) {
		uint64_t v; memcpy(&v, p, 8);
		return (((v >> 56) & 0xff)| ((v >> 40) & 0xff00)| ((v >> 24) & 0xff0000)| ((v >>  8) & 0xff000000)| ((v <<  8) & 0xff00000000)| ((v << 24) & 0xff0000000000)| ((v << 40) & 0xff000000000000)| ((v << 56) & 0xff00000000000000));
	}
	static inline uint64_t _wyr4(const uint8_t *p) {
		uint32_t v; memcpy(&v, p, 4);
		return (((v >> 24) & 0xff)| ((v >>  8) & 0xff00)| ((v <<  8) & 0xff0000)| ((v << 24) & 0xff000000));
	}
#endif
static inline uint64_t _wyr3(const uint8_t *p, size_t k) { return (((uint64_t)p[0])<<16)|(((uint64_t)p[k>>1])<<8)|p[k-1];}
// wyhash main function
static inline uint64_t wyhash(const void *key, size_t len, uint64_t seed, const uint64_t *secret){
	const uint8_t *p=(const uint8_t *)key; seed^=_wymix(seed^secret[0]^len,secret[1]);	uint64_t a, b;
	if (_likely_(len<=16)) {
		if (_likely_(len>=4)) { a=(_wyr4(p)<<32)|_wyr4(p+((len>>3)<<2)); b=(_wyr4(p+len-4)<<32)|_wyr4(p+len-4-((len>>3)<<2)); }
		else if (_likely_(len>0)) { a=_wyr3(p,len); b=0; }
		else a=b=0;
	} else {
		size_t i=len;
		if (_unlikely_(i>=48)) {
			uint64_t see1=seed, see2=seed;
			do {
				seed=_wymix(_wyr8(p)^secret[1],_wyr8(p+8)^seed);
				see1=_wymix(_wyr8(p+16)^secret[2],_wyr8(p+24)^see1);
				see2=_wymix(_wyr8(p+32)^secret[3],_wyr8(p+40)^see2);
				p+=48; i-=48;
			} while(_likely_(i>=48));
			seed^=see1^see2;
		}
		while(_unlikely_(i>16)) { seed=_wymix(_wyr8(p)^secret[1],_wyr8(p+8)^seed);  i-=16; p+=16; }
		a=_wyr8(p+i-16);  b=_wyr8(p+i-8);
	}
	a^=secret[1]; b^=seed;  _wymum(&a,&b);
	return  _wymix(a^secret[0]^len,b^secret[1]);
}
// the default secret parameters
static const uint64_t _wyp[4] = {0x2d358dccaa6c78a5ull, 0x8bb84b93962eacc9ull, 0x4b33a62ed433d4a3ull, 0x4d5a2da51de1aa47ull};
// a useful 64bit-64bit mix function to produce deterministic pseudo random numbers that can pass BigCrush and PractRand
static inline uint64_t wyhash64(uint64_t A, uint64_t B){ A^=0x2d358dccaa6c78a5ull; B^=0x8bb84b93962eacc9ull; _wymum(&A,&B); return _wymix(A^0x2d358dccaa6c78a5ull,B^0x8bb84b93962eacc9ull);}
// the wyrand PRNG that pass BigCrush and PractRand
static inline uint64_t wyrand(uint64_t *seed){ *seed+=0x2d358dccaa6c78a5ull; return _wymix(*seed,*seed^0x8bb84b93962eacc9ull);}
#ifndef __vinix__
// convert any 64 bit pseudo random numbers to uniform distribution [0,1). It can be combined with wyrand, wyhash64 or wyhash.
static inline double wy2u01(uint64_t r){ const double _wynorm=1.0/(1ull<<52); return (r>>12)*_wynorm;}
// convert any 64 bit pseudo random numbers to APPROXIMATE Gaussian distribution. It can be combined with wyrand, wyhash64 or wyhash.
static inline double wy2gau(uint64_t r){ const double _wynorm=1.0/(1ull<<20); return ((r&0x1fffff)+((r>>21)&0x1fffff)+((r>>42)&0x1fffff))*_wynorm-3.0;}
#endif
#if(!WYHASH_32BIT_MUM)
// fast range integer random number generation on [0,k) credit to Daniel Lemire. May not work when WYHASH_32BIT_MUM=1. It can be combined with wyrand, wyhash64 or wyhash.
static inline uint64_t wy2u0k(uint64_t r, uint64_t k){ _wymum(&r,&k); return k; }
#endif
#endif
#define _IN_MAP(val, m) builtin__map_exists(m, val)

#if __GLIBC__ == 2 && __GLIBC_MINOR__ < 30
#include <sys/syscall.h>
#define gettid() syscall(SYS_gettid)
#endif

// V includes:

#if defined(__TINYC__) && defined(__has_include) // tcc does not support has_include properly yet, turn it off completely
#undef __has_include
#endif

#if defined(__TINYC__) && defined(__BIONIC__)
	#define __builtin_nanf(ignored_string) (0.0F / 0.0F)
	#define __builtin_nan(ignored_string) (0.0 / 0.0)
	#define __builtin_nanl(ignored_string) (0.0L / 0.0L)
	#define __builtin_inff() (1.0F / 0.0F)
	#define __builtin_inf() (1.0 / 0.0)
	#define __builtin_infl() (1.0L / 0.0L)
	#define __builtin_huge_valf() (1.0F / 0.0F)
	#define __builtin_huge_val() (1.0 / 0.0)
	#define __builtin_huge_vall() (1.0L / 0.0L)
#endif

#if 1

// added by module `builtin.closure`, file: closure_nix.c.v:4:

#ifdef __TINYC__
#include <sys/mman.h>
#else
#if defined(__has_include)
#if __has_include(<sys/mman.h>)
#include <sys/mman.h>
#else
#error VERROR_MESSAGE Header file <sys/mman.h>, needed for module `builtin.closure` was not found. Please install the corresponding development headers.
#endif
#else
#include <sys/mman.h>
#endif
#endif


// inserted by module `builtin.closure`, file: closure_nix.c.v:5:
#ifndef V_CLOSURE_ONCE_NIX_H
#define V_CLOSURE_ONCE_NIX_H

#include <pthread.h>

typedef void (*v_closure_init_fn)(void);

#ifndef V_CLOSURE_STATIC_INLINE
# ifdef _MSC_VER
#  define V_CLOSURE_STATIC_INLINE static __inline
# else
#  define V_CLOSURE_STATIC_INLINE static inline
# endif
#endif

static pthread_mutex_t v_closure_once_mutex = PTHREAD_MUTEX_INITIALIZER;
static int v_closure_once_done = 0;

V_CLOSURE_STATIC_INLINE void v_closure_init_once(v_closure_init_fn init_fn) {
	pthread_mutex_lock(&v_closure_once_mutex);
	if (!v_closure_once_done) {
		init_fn();
		v_closure_once_done = 1;
	}
	pthread_mutex_unlock(&v_closure_once_mutex);
}

#endif

#endif

#if 1

// added by module `builtin.closure`, file: closure_nix.c.v:4:

#ifdef __TINYC__
#include <sys/mman.h>
#else
#if defined(__has_include)
#if __has_include(<sys/mman.h>)
#include <sys/mman.h>
#else
#error VERROR_MESSAGE Header file <sys/mman.h>, needed for module `builtin.closure` was not found. Please install the corresponding development headers.
#endif
#else
#include <sys/mman.h>
#endif
#endif


// inserted by module `builtin.closure`, file: closure_nix.c.v:5:
#ifndef V_CLOSURE_ONCE_NIX_H
#define V_CLOSURE_ONCE_NIX_H

#include <pthread.h>

typedef void (*v_closure_init_fn)(void);

#ifndef V_CLOSURE_STATIC_INLINE
# ifdef _MSC_VER
#  define V_CLOSURE_STATIC_INLINE static __inline
# else
#  define V_CLOSURE_STATIC_INLINE static inline
# endif
#endif

static pthread_mutex_t v_closure_once_mutex = PTHREAD_MUTEX_INITIALIZER;
static int v_closure_once_done = 0;

V_CLOSURE_STATIC_INLINE void v_closure_init_once(v_closure_init_fn init_fn) {
	pthread_mutex_lock(&v_closure_once_mutex);
	if (!v_closure_once_done) {
		init_fn();
		v_closure_once_done = 1;
	}
	pthread_mutex_unlock(&v_closure_once_mutex);
}

#endif

#endif

// inserted by module `builtin`, file: allocation.c.v:43:
#ifndef V_TRACK_HEAP_CHECKS_H
#define V_TRACK_HEAP_CHECKS_H

#if defined(CUSTOM_DEFINE_track_heap) && (defined(_VGCBOEHM) || defined(CUSTOM_DEFINE_gcboehm))
#error "-d track_heap requires manual memory management; rebuild with -gc none"
#endif

#if defined(CUSTOM_DEFINE_track_heap) && defined(CUSTOM_DEFINE_vgc)
#error "-d track_heap requires manual memory management; rebuild with -gc none"
#endif

#if defined(CUSTOM_DEFINE_track_heap) && defined(_VPREALLOC)
#error "-d track_heap requires manual memory management; rebuild with -gc none (not -prealloc)"
#endif

#endif


// added by module `builtin`, file: float.c.v:9:

#ifdef __TINYC__
#include <float.h>
#else
#if defined(__has_include)
#if __has_include(<float.h>)
#include <float.h>
#else
#error VERROR_MESSAGE Header file <float.h>, needed for module `builtin` was not found. Please install the corresponding development headers.
#endif
#else
#include <float.h>
#endif
#endif


// added by module `term.termios`, file: termios_linux.c.v:10:

#ifdef __TINYC__
#include <termios.h>
#else
#if defined(__has_include)
#if __has_include(<termios.h>)
#include <termios.h>
#else
#error VERROR_MESSAGE Header file <termios.h>, needed for module `term.termios` was not found. Please install the corresponding development headers.
#endif
#else
#include <termios.h>
#endif
#endif


// added by module `term.termios`, file: termios_linux.c.v:11:

#ifdef __TINYC__
#include <sys/ioctl.h>
#else
#if defined(__has_include)
#if __has_include(<sys/ioctl.h>)
#include <sys/ioctl.h>
#else
#error VERROR_MESSAGE Header file <sys/ioctl.h>, needed for module `term.termios` was not found. Please install the corresponding development headers.
#endif
#else
#include <sys/ioctl.h>
#endif
#endif


// added by module `os`, file: debugger_linux.c.v:3:

#ifdef __TINYC__
#include <sys/ptrace.h>
#else
#if defined(__has_include)
#if __has_include(<sys/ptrace.h>)
#include <sys/ptrace.h>
#else
#error VERROR_MESSAGE Header file <sys/ptrace.h>, needed for module `os` was not found. Please install the corresponding development headers.
#endif
#else
#include <sys/ptrace.h>
#endif
#endif


#if 1

// added by module `os`, file: fd.c.v:6:

#ifdef __TINYC__
#include <sys/select.h>
#else
#if defined(__has_include)
#if __has_include(<sys/select.h>)
#include <sys/select.h>
#else
#error VERROR_MESSAGE Header file <sys/select.h>, needed for module `os` was not found. Please install the corresponding development headers.
#endif
#else
#include <sys/select.h>
#endif
#endif


// added by module `os`, file: fd.c.v:7:

#ifdef __TINYC__
#include <sys/ioctl.h>
#else
#if defined(__has_include)
#if __has_include(<sys/ioctl.h>)
#include <sys/ioctl.h>
#else
#error VERROR_MESSAGE Header file <sys/ioctl.h>, needed for module `os` was not found. Please install the corresponding development headers.
#endif
#else
#include <sys/ioctl.h>
#endif
#endif

#endif

#if 1

// added by module `os`, file: fd.c.v:6:

#ifdef __TINYC__
#include <sys/select.h>
#else
#if defined(__has_include)
#if __has_include(<sys/select.h>)
#include <sys/select.h>
#else
#error VERROR_MESSAGE Header file <sys/select.h>, needed for module `os` was not found. Please install the corresponding development headers.
#endif
#else
#include <sys/select.h>
#endif
#endif


// added by module `os`, file: fd.c.v:7:

#ifdef __TINYC__
#include <sys/ioctl.h>
#else
#if defined(__has_include)
#if __has_include(<sys/ioctl.h>)
#include <sys/ioctl.h>
#else
#error VERROR_MESSAGE Header file <sys/ioctl.h>, needed for module `os` was not found. Please install the corresponding development headers.
#endif
#else
#include <sys/ioctl.h>
#endif
#endif

#endif

// added by module `os`, file: os.c.v:5:

#ifdef __TINYC__
#include <sys/stat.h>
#else
#if defined(__has_include)
#if __has_include(<sys/stat.h>)
#include <sys/stat.h>
#else
#error VERROR_MESSAGE Header file <sys/stat.h>, needed for module `os` was not found. Please install the corresponding development headers.
#endif
#else
#include <sys/stat.h>
#endif
#endif


// added by module `os`, file: os.c.v:6:
#include <errno.h>

// added by module `os`, file: os_nix.c.v:3:

#ifdef __TINYC__
#include <dirent.h>
#else
#if defined(__has_include)
#if __has_include(<dirent.h>)
#include <dirent.h>
#else
#error VERROR_MESSAGE Header file <dirent.h>, needed for module `os` was not found. Please install the corresponding development headers.
#endif
#else
#include <dirent.h>
#endif
#endif


// added by module `os`, file: os_nix.c.v:4:

#ifdef __TINYC__
#include <unistd.h>
#else
#if defined(__has_include)
#if __has_include(<unistd.h>)
#include <unistd.h>
#else
#error VERROR_MESSAGE Header file <unistd.h>, needed for module `os` was not found. Please install the corresponding development headers.
#endif
#else
#include <unistd.h>
#endif
#endif


// added by module `os`, file: os_nix.c.v:5:

#ifdef __TINYC__
#include <fcntl.h>
#else
#if defined(__has_include)
#if __has_include(<fcntl.h>)
#include <fcntl.h>
#else
#error VERROR_MESSAGE Header file <fcntl.h>, needed for module `os` was not found. Please install the corresponding development headers.
#endif
#else
#include <fcntl.h>
#endif
#endif


// added by module `os`, file: os_nix.c.v:6:

#ifdef __TINYC__
#include <sys/utsname.h>
#else
#if defined(__has_include)
#if __has_include(<sys/utsname.h>)
#include <sys/utsname.h>
#else
#error VERROR_MESSAGE Header file <sys/utsname.h>, needed for module `os` was not found. Please install the corresponding development headers.
#endif
#else
#include <sys/utsname.h>
#endif
#endif


// added by module `os`, file: os_nix.c.v:7:

#ifdef __TINYC__
#include <sys/types.h>
#else
#if defined(__has_include)
#if __has_include(<sys/types.h>)
#include <sys/types.h>
#else
#error VERROR_MESSAGE Header file <sys/types.h>, needed for module `os` was not found. Please install the corresponding development headers.
#endif
#else
#include <sys/types.h>
#endif
#endif


// added by module `os`, file: os_nix.c.v:8:

#ifdef __TINYC__
#include <sys/statvfs.h>
#else
#if defined(__has_include)
#if __has_include(<sys/statvfs.h>)
#include <sys/statvfs.h>
#else
#error VERROR_MESSAGE Header file <sys/statvfs.h>, needed for module `os` was not found. Please install the corresponding development headers.
#endif
#else
#include <sys/statvfs.h>
#endif
#endif


// added by module `os`, file: os_nix.c.v:9:

#ifdef __TINYC__
#include <sys/wait.h>
#else
#if defined(__has_include)
#if __has_include(<sys/wait.h>)
#include <sys/wait.h>
#else
#error VERROR_MESSAGE Header file <sys/wait.h>, needed for module `os` was not found. Please install the corresponding development headers.
#endif
#else
#include <sys/wait.h>
#endif
#endif


// added by module `os`, file: os_nix.c.v:10:

#ifdef __TINYC__
#include <utime.h>
#else
#if defined(__has_include)
#if __has_include(<utime.h>)
#include <utime.h>
#else
#error VERROR_MESSAGE Header file <utime.h>, needed for module `os` was not found. Please install the corresponding development headers.
#endif
#else
#include <utime.h>
#endif
#endif


// inserted by module `os`, file: os_nix.c.v:11:
// v_os_execute_set_cloexec marks an fd as close-on-exec. When multiple threads
// each call os.execute, every pipe() they create is briefly visible to all of
// them; without FD_CLOEXEC, one thread's spawned child can inherit another
// thread's pipe write end, keeping that pipe open after the intended writer
// exits. The reader then never observes EOF and the captured output ends up
// empty (seen on macOS arm64 in CI). Setting CLOEXEC closes the fd
// automatically across exec, which fixes the race for both fork/execvp and
// posix_spawn paths.
static void v_os_execute_set_cloexec(int fd) {
	int flags = fcntl(fd, F_GETFD, 0);
	if (flags >= 0) {
		fcntl(fd, F_SETFD, flags | FD_CLOEXEC);
	}
}

#if defined(__ANDROID__) && (!defined(__ANDROID_API__) || __ANDROID_API__ < 28)
// Android API levels below 28 do not provide posix_spawn(). Fall back to
// fork()/execvp() with a pipe; this is what popen() does internally and
// is sufficient for capturing the merged stdout+stderr of a shell command.
static int v_os_execute_capture_start(const char *cmd, int *child_pid, int *read_fd) {
	int pipefd[2];
	if (pipe(pipefd) != 0) {
		return -1;
	}
	v_os_execute_set_cloexec(pipefd[0]);
	v_os_execute_set_cloexec(pipefd[1]);
	pid_t pid = fork();
	if (pid < 0) {
		close(pipefd[0]);
		close(pipefd[1]);
		return -1;
	}
	if (pid == 0) {
		// child: redirect stdout+stderr to the pipe, then exec the shell.
		// dup2 clears FD_CLOEXEC on the destination, so STDOUT/STDERR stay
		// open across exec while the original pipe fds are auto-closed.
		dup2(pipefd[1], STDOUT_FILENO);
		dup2(pipefd[1], STDERR_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		execlp("sh", "sh", "-c", cmd, (char *)NULL);
		_exit(127);
	}
	close(pipefd[1]);
	*child_pid = (int)pid;
	*read_fd = pipefd[0];
	return 0;
}

static int v_os_exec_capture_start(char *const argv[], int *child_pid, int *read_fd) {
	if (argv == NULL || argv[0] == NULL) {
		return -1;
	}
	int pipefd[2];
	if (pipe(pipefd) != 0) {
		return -1;
	}
	v_os_execute_set_cloexec(pipefd[0]);
	v_os_execute_set_cloexec(pipefd[1]);
	pid_t pid = fork();
	if (pid < 0) {
		close(pipefd[0]);
		close(pipefd[1]);
		return -1;
	}
	if (pid == 0) {
		dup2(pipefd[1], STDOUT_FILENO);
		dup2(pipefd[1], STDERR_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		execvp(argv[0], argv);
		_exit(127);
	}
	close(pipefd[1]);
	*child_pid = (int)pid;
	*read_fd = pipefd[0];
	return 0;
}
#else
// Use opaque void* declarations for posix_spawn instead of #include <spawn.h>.
// Including <spawn.h> transitively pulls in <features.h>/<sys/cdefs.h>, which
// breaks under musl-gcc on the Ubuntu docker image where <sys/cdefs.h> is not
// on the include path. The 128-byte buffer is comfortably larger than the
// real posix_spawn_file_actions_t on glibc (~80 bytes) and musl (~40 bytes);
// posix_spawn_file_actions_init() initializes the buffer, so its true layout
// is not needed here. We pass NULL for posix_spawnattr_t, so it is not
// declared. Calling these via void* is ABI-compatible: pointer parameters
// are passed identically regardless of pointee type.
typedef struct { unsigned char _opaque[128]; } v_posix_spawn_file_actions_t;
#ifdef __cplusplus
extern "C" {
#endif
extern int posix_spawn(pid_t *, const char *, const void *, const void *, char *const [], char *const []);
extern int posix_spawnp(pid_t *, const char *, const void *, const void *, char *const [], char *const []);
extern int posix_spawn_file_actions_init(void *);
extern int posix_spawn_file_actions_destroy(void *);
extern int posix_spawn_file_actions_adddup2(void *, int, int);
extern int posix_spawn_file_actions_addclose(void *, int);

extern char **environ;
#ifdef __cplusplus
}
#endif

static int v_os_execute_capture_start(const char *cmd, int *child_pid, int *read_fd) {
	int pipefd[2];
	if (pipe(pipefd) != 0) {
		return -1;
	}
	v_os_execute_set_cloexec(pipefd[0]);
	v_os_execute_set_cloexec(pipefd[1]);
	v_posix_spawn_file_actions_t actions;
	if (posix_spawn_file_actions_init(&actions) != 0) {
		close(pipefd[0]);
		close(pipefd[1]);
		return -1;
	}
	int err = 0;
	if ((err = posix_spawn_file_actions_adddup2(&actions, pipefd[1], STDOUT_FILENO)) != 0
		|| (err = posix_spawn_file_actions_adddup2(&actions, pipefd[1], STDERR_FILENO)) != 0
		|| (err = posix_spawn_file_actions_addclose(&actions, pipefd[0])) != 0
		|| (err = posix_spawn_file_actions_addclose(&actions, pipefd[1])) != 0) {
		posix_spawn_file_actions_destroy(&actions);
		close(pipefd[0]);
		close(pipefd[1]);
		return -1;
	}
	char *const argv[] = {(char *)"/bin/sh", (char *)"-c", (char *)cmd, NULL};
	err = posix_spawn(child_pid, "/bin/sh", &actions, NULL, argv, environ);
	posix_spawn_file_actions_destroy(&actions);
	if (err != 0) {
		close(pipefd[0]);
		close(pipefd[1]);
		return -1;
	}
	close(pipefd[1]);
	*read_fd = pipefd[0];
	return 0;
}

static int v_os_exec_capture_start(char *const argv[], int *child_pid, int *read_fd) {
	if (argv == NULL || argv[0] == NULL) {
		return -1;
	}
	int pipefd[2];
	if (pipe(pipefd) != 0) {
		return -1;
	}
	v_os_execute_set_cloexec(pipefd[0]);
	v_os_execute_set_cloexec(pipefd[1]);
	v_posix_spawn_file_actions_t actions;
	if (posix_spawn_file_actions_init(&actions) != 0) {
		close(pipefd[0]);
		close(pipefd[1]);
		return -1;
	}
	int err = 0;
	if ((err = posix_spawn_file_actions_adddup2(&actions, pipefd[1], STDOUT_FILENO)) != 0
		|| (err = posix_spawn_file_actions_adddup2(&actions, pipefd[1], STDERR_FILENO)) != 0
		|| (err = posix_spawn_file_actions_addclose(&actions, pipefd[0])) != 0
		|| (err = posix_spawn_file_actions_addclose(&actions, pipefd[1])) != 0) {
		posix_spawn_file_actions_destroy(&actions);
		close(pipefd[0]);
		close(pipefd[1]);
		return -1;
	}
	err = posix_spawnp(child_pid, argv[0], &actions, NULL, argv, environ);
	posix_spawn_file_actions_destroy(&actions);
	if (err != 0) {
		close(pipefd[0]);
		close(pipefd[1]);
		return -1;
	}
	close(pipefd[1]);
	*read_fd = pipefd[0];
	return 0;
}
#endif


// added by module `os`, file: signal.c.v:3:

#ifdef __TINYC__
#include <signal.h>
#else
#if defined(__has_include)
#if __has_include(<signal.h>)
#include <signal.h>
#else
#error VERROR_MESSAGE Header file <signal.h>, needed for module `os` was not found. Please install the corresponding development headers.
#endif
#else
#include <signal.h>
#endif
#endif

// defined by module `os`
#define v_signal_with_handler_cast(sig, handler) signal((sig), (void (*)(int))(handler))

// added by module `os`, file: signal_linux.c.v:5:

#ifdef __TINYC__
#include <signal.h>
#else
#if defined(__has_include)
#if __has_include(<signal.h>)
#include <signal.h>
#else
#error VERROR_MESSAGE Header file <signal.h>, needed for module `os` was not found. Please install the corresponding development headers.
#endif
#else
#include <signal.h>
#endif
#endif

#if !defined(__cplusplus) && !defined(CUSTOM_DEFINE_no_bool)
#ifdef bool
#undef bool
#endif
#if !defined(__STDC_VERSION__) || __STDC_VERSION__ < 202311L
#ifdef CUSTOM_DEFINE_4bytebool
typedef int bool;
#else
typedef u8 bool;
#endif
#endif
#endif

// V global/const #define ... :
#define _const_strconv__max_size_f64_char 512
#define _const_autostr_type_stack_max_depth 64
#define _const_min_int -2147483648
#define _const_max_int 2147483647
#define _const_hashbits 24
#define _const_max_cached_hashbits 16
#define _const_init_log_capicity 5
#define _const_init_capicity 32
#define _const_init_even_index 30
#define _const_extra_metas_inc 4
#define _const_rune_maps_columns_in_row 4
#define _const_rune_maps_ul -3
#define _const_rune_maps_utl -2
#define _const_degree 6
#define _const_replace_stack_buffer_size 10
#define _const_kmp_stack_buffer_size 20
#define _const_os__max_path_buffer_size 4096
#define _const_os__buf_size 4096
#define _const_os__error_code_not_set -1
#define _const_os__max_path_len 4096
#define _const_os__f_ok 0
#define _const_os__read_lines_chunk_size 131072

// Enum definitions:

typedef enum {
	strconv__Align_text__right = 0, // 0
	strconv__Align_text__left, // 0+1
	strconv__Align_text__center, // 0+2
}  strconv__Align_text;

typedef enum {
	ArrayFlags__noslices = 1U, // u64(1) << 0
	ArrayFlags__noshrink = 2U, // u64(1) << 1
	ArrayFlags__nogrow = 4U, // u64(1) << 2
	ArrayFlags__nofree = 8U, // u64(1) << 3
	ArrayFlags__managed = 16U, // u64(1) << 4
	ArrayFlags__noscan_data = 32U, // u64(1) << 5
	ArrayFlags__is_slice = 64U, // u64(1) << 6
}  ArrayFlags;

typedef enum {
	GraphemeBreakProperty__other, // 
	GraphemeBreakProperty__cr, // +1
	GraphemeBreakProperty__lf, // +2
	GraphemeBreakProperty__control, // +3
	GraphemeBreakProperty__extend, // +4
	GraphemeBreakProperty__regional_indicator, // +5
	GraphemeBreakProperty__prepend, // +6
	GraphemeBreakProperty__spacing_mark, // +7
	GraphemeBreakProperty__l, // +8
	GraphemeBreakProperty__v, // +9
	GraphemeBreakProperty__t, // +10
	GraphemeBreakProperty__lv, // +11
	GraphemeBreakProperty__lvt, // +12
	GraphemeBreakProperty__zwj, // +13
}  GraphemeBreakProperty;

typedef enum {
	MapMode__to_upper, // 
	MapMode__to_lower, // +1
	MapMode__to_title, // +2
}  MapMode;

typedef enum {
	TrimMode__trim_left, // 
	TrimMode__trim_right, // +1
	TrimMode__trim_both, // +2
}  TrimMode;

typedef enum {
	StrIntpType__si_no_str = 0, // 0
	StrIntpType__si_c, // 0+1
	StrIntpType__si_u8, // 0+2
	StrIntpType__si_i8, // 0+3
	StrIntpType__si_u16, // 0+4
	StrIntpType__si_i16, // 0+5
	StrIntpType__si_u32, // 0+6
	StrIntpType__si_i32, // 0+7
	StrIntpType__si_u64, // 0+8
	StrIntpType__si_i64, // 0+9
	StrIntpType__si_e32, // 0+10
	StrIntpType__si_e64, // 0+11
	StrIntpType__si_f32, // 0+12
	StrIntpType__si_f64, // 0+13
	StrIntpType__si_g32, // 0+14
	StrIntpType__si_g64, // 0+15
	StrIntpType__si_s, // 0+16
	StrIntpType__si_p, // 0+17
	StrIntpType__si_r, // 0+18
	StrIntpType__si_vp, // 0+19
}  StrIntpType;

typedef enum {
	os__FileType__unknown, // 
	os__FileType__regular, // +1
	os__FileType__directory, // +2
	os__FileType__character_device, // +3
	os__FileType__block_device, // +4
	os__FileType__fifo, // +5
	os__FileType__symbolic_link, // +6
	os__FileType__socket, // +7
}  os__FileType;

// V type definitions:
struct IError {
	union {
		void* _object;
		None__* _None__;
		voidptr* _voidptr;
		MessageError* _MessageError;
		os__Eof* _os__Eof;
		os__NotExpected* _os__NotExpected;
		os__FileNotOpenedError* _os__FileNotOpenedError;
		os__SizeOfTypeIs0Error* _os__SizeOfTypeIs0Error;
		os__ExecutableNotFoundError* _os__ExecutableNotFoundError;
		Error* _Error;
	};
	u32 _typ;
	void* _methods;
};

struct string {
	u8* str;
	int len;
	int is_lit;
};

struct array {
	voidptr data;
	int offset;
	int len;
	int cap;
	ArrayFlags flags;
	int element_size;
};

struct DenseArray {
	int key_bytes;
	int value_bytes;
	int cap;
	int len;
	u32 deletes;
	u8* all_deleted;
	u8* keys;
	u8* values;
};

struct map {
	int key_bytes;
	int value_bytes;
	u32 even_index;
	u8 cached_hashbits;
	u8 shift;
	DenseArray key_values;
	u32* metas;
	u32 extra_metas;
	bool has_string_keys;
	MapHashFn hash_fn;
	MapEqFn key_eq_fn;
	MapCloneFn clone_fn;
	MapFreeFn free_fn;
	int len;
};

struct Error {
	E_STRUCT_DECL;
};

struct _option {
	u8 state;
	IError err;
};

struct _result {
	bool is_error;
	IError err;
};
typedef array Array_string;
typedef array Array_u8;
typedef array Array_voidptr;
typedef array Array_int;
typedef array Array_rune;
typedef array Array_main__Repo;
typedef array Array_main__Package;
typedef map Map_string_bool;
typedef u8 Array_fixed_u8_128 [128];
typedef char Array_fixed_char_256 [256];
typedef u8 Array_fixed_u8_32 [32];
typedef u8 Array_fixed_u8_64 [64];
typedef u8 Array_fixed_u8_5 [5];
typedef u8 Array_fixed_u8_20 [20];
typedef u32 Array_fixed_u32_10 [10];
typedef u64 Array_fixed_u64_20 [20];
typedef u64 Array_fixed_u64_584 [584];
typedef u64 Array_fixed_u64_652 [652];
typedef f64 Array_fixed_f64_36 [36];
typedef u8 Array_fixed_u8_26 [26];
typedef u8 Array_fixed_u8_512 [512];
typedef u64 Array_fixed_u64_47 [47];
typedef u64 Array_fixed_u64_31 [31];
typedef int Array_fixed_int_64 [64];
typedef voidptr Array_fixed_voidptr_64 [64];
typedef array Array_GraphemeBreakProperty;
typedef u8 Array_fixed_u8_17 [17];
typedef i32 Array_fixed_i32_1264 [1264];
typedef int Array_fixed_int_10 [10];
typedef int Array_fixed_int_20 [20];
typedef array Array_StrIntpType;
typedef u8 Array_fixed_u8_4096 [4096];
typedef u8 Array_fixed_u8_1024 [1024];
typedef Array_u8 strings__Builder;
// #start sorted_symbols
struct none {
	E_STRUCT_DECL;
};

struct None__ {
	Error Error;
};

struct os__Eof {
	Error Error;
};

struct os__FileNotOpenedError {
	Error Error;
};

struct os__SizeOfTypeIs0Error {
	Error Error;
};

struct os__ExecutableNotFoundError {
	Error Error;
};

struct ArrayDataHeader {
	bool has_slices;
};

struct MessageError {
	string msg;
	int code;
};

union strconv__Float64u {
	f64 f;
	u64 u;
};

union strconv__Float32u {
	f32 f;
	u32 u;
};

struct GraphemeState {
	GraphemeBreakProperty prev_prop;
	int ri_count;
	u8 extended_pictographic_state;
};

union StrIntpMem {
	u32 d_c;
	u8 d_u8;
	i8 d_i8;
	u16 d_u16;
	i16 d_i16;
	u32 d_u32;
	i32 d_i32;
	u64 d_u64;
	i64 d_i64;
	f32 d_f32;
	f64 d_f64;
	string d_s;
	string d_r;
	voidptr d_p;
	voidptr d_vp;
};

struct strconv__BF_param {
	u8 pad_ch;
	int len0;
	int len1;
	bool positive;
	bool sign_flag;
	strconv__Align_text align;
	bool rm_tail_zero;
};

struct main__Repo {
	string name;
	string url;
	string raw_url;
	int package_count;
};

struct main__Config {
	Array_main__Repo repos;
	string prefix;
	string db_dir;
};

struct main__Package {
	string name;
	string version;
	string arch;
	string size;
	u64 size_bytes;
	string description;
	string category;
	string bin;
	string src;
	string pkg_type;
	string repo_name;
};

struct strconv__Dec32 {
	u32 m;
	int e;
};

union strconv__Uf32 {
	f32 f;
	u32 u;
};

struct strconv__Dec64 {
	u64 m;
	int e;
};

struct strconv__Uint128 {
	u64 lo;
	u64 hi;
};

union strconv__Uf64 {
	f64 f;
	u64 u;
};

struct os__NotExpected {
	string cause;
	int code;
};

struct os__File {
	voidptr cfile;
	int fd;
	bool is_opened;
};

struct os__Stat {
	u64 dev;
	u64 inode;
	u32 mode;
	u64 nlink;
	u32 uid;
	u32 gid;
	u64 rdev;
	u64 size;
	i64 atime;
	i64 mtime;
	i64 ctime;
};

struct os__CopyParams {
	bool fail_if_exists;
};

struct os__SystemError {
	string msg;
	int code;
};

struct os__Result {
	int exit_code;
	string output;
};

struct os__MkdirParams {
	u32 mode;
};

struct StrIntpData {
	string str;
	u32 fmt;
	StrIntpMem d;
	int dyn_width;
	int dyn_precision;
	u8 dyn_flags;
};
// #end sorted_symbols

// BEGIN_array_fixed_return_structs
struct _v_Array_fixed_u8_128 {
	u8 ret_arr[128];
};
struct _v_Array_fixed_char_256 {
	char ret_arr[256];
};
struct _v_Array_fixed_u8_32 {
	u8 ret_arr[32];
};
struct _v_Array_fixed_u8_64 {
	u8 ret_arr[64];
};
struct _v_Array_fixed_u8_5 {
	u8 ret_arr[5];
};
struct _v_Array_fixed_u8_20 {
	u8 ret_arr[20];
};
struct _v_Array_fixed_u32_10 {
	u32 ret_arr[10];
};
struct _v_Array_fixed_u64_20 {
	u64 ret_arr[20];
};
struct _v_Array_fixed_u64_584 {
	u64 ret_arr[584];
};
struct _v_Array_fixed_u64_652 {
	u64 ret_arr[652];
};
struct _v_Array_fixed_f64_36 {
	f64 ret_arr[36];
};
struct _v_Array_fixed_u8_26 {
	u8 ret_arr[26];
};
struct _v_Array_fixed_u8_512 {
	u8 ret_arr[512];
};
struct _v_Array_fixed_u64_47 {
	u64 ret_arr[47];
};
struct _v_Array_fixed_u64_31 {
	u64 ret_arr[31];
};
struct _v_Array_fixed_int_64 {
	int ret_arr[64];
};
struct _v_Array_fixed_voidptr_64 {
	voidptr ret_arr[64];
};
struct _v_Array_fixed_u8_17 {
	u8 ret_arr[17];
};
struct _v_Array_fixed_i32_1264 {
	i32 ret_arr[1264];
};
struct _v_Array_fixed_int_10 {
	int ret_arr[10];
};
struct _v_Array_fixed_int_20 {
	int ret_arr[20];
};
struct _v_Array_fixed_u8_4096 {
	u8 ret_arr[4096];
};
struct _v_Array_fixed_u8_1024 {
	u8 ret_arr[1024];
};
// END_array_fixed_return_structs


// BEGIN_multi_return_structs
struct multi_return_u32_u32 {
	u32 arg0;
	u32 arg1;
};

struct multi_return_rune_int {
	rune arg0;
	int arg1;
};

struct multi_return_strconv__Dec32_bool {
	strconv__Dec32 arg0;
	bool arg1;
};

struct multi_return_strconv__Dec64_bool {
	strconv__Dec64 arg0;
	bool arg1;
};

struct multi_return_string_int {
	string arg0;
	int arg1;
};

struct multi_return_int_bool {
	int arg0;
	bool arg1;
};

struct multi_return_u64_u64 {
	u64 arg0;
	u64 arg1;
};

// END_multi_return_structs

static bool Array_u8_contains(Array_u8 a, u8 v);
static bool Array_string_contains(Array_string a, string v);

// V Option_xxx definitions:
struct _option_int {
	byte state;
	IError err;
	byte data[sizeof(int) > 1 ? sizeof(int) : 1];
};

struct _option_u8 {
	byte state;
	IError err;
	byte data[sizeof(u8) > 1 ? sizeof(u8) : 1];
};

struct _option_string {
	byte state;
	IError err;
	byte data[sizeof(string) > 1 ? sizeof(string) : 1];
};

struct _option_main__Package {
	byte state;
	IError err;
	byte data[sizeof(main__Package) > 1 ? sizeof(main__Package) : 1];
};


// V result_xxx definitions:
struct _result_os__File {
	bool is_error;
	IError err;
	byte data[sizeof(os__File) > 1 ? sizeof(os__File) : 1];
};

struct _result_FILE_ptr {
	bool is_error;
	IError err;
	byte data[sizeof(FILE*) > 1 ? sizeof(FILE*) : 1];
};

struct _result_int {
	bool is_error;
	IError err;
	byte data[sizeof(int) > 1 ? sizeof(int) : 1];
};

struct _result_void {
	bool is_error;
	IError err;
	byte data[sizeof(u8) > 1 ? sizeof(u8) : 1];
};

struct _result_strings__Builder {
	bool is_error;
	IError err;
	byte data[sizeof(strings__Builder) > 1 ? sizeof(strings__Builder) : 1];
};

struct _result_string {
	bool is_error;
	IError err;
	byte data[sizeof(string) > 1 ? sizeof(string) : 1];
};

struct _result_os__Stat {
	bool is_error;
	IError err;
	byte data[sizeof(os__Stat) > 1 ? sizeof(os__Stat) : 1];
};

struct _result_Array_string {
	bool is_error;
	IError err;
	byte data[sizeof(Array_string) > 1 ? sizeof(Array_string) : 1];
};


// V definitions:
static char * v_typeof_interface_IError(u32 sidx);
u32 v_typeof_interface_idx_IError(u32 sidx);
// end of definitions #endif
strings__Builder strings__new_builder(int initial_size);
Array_u8 strings__Builder_reuse_as_plain_u8_array(strings__Builder* b);
void strings__Builder_write_ptr(strings__Builder* b, u8* ptr, int len);
void strings__Builder_write_rune(strings__Builder* b, rune r);
void strings__Builder_write_runes(strings__Builder* b, Array_rune runes);
void strings__Builder_write_u8(strings__Builder* b, u8 data);
void strings__Builder_write_byte(strings__Builder* b, u8 data);
void strings__Builder_write_u_decimal(strings__Builder* b, u64 n);
void strings__Builder_write_string(strings__Builder* b, string s);
string strings__Builder_spart(strings__Builder* b, int start_pos, int n);
string strings__Builder_cut_last(strings__Builder* b, int n);
string strings__Builder_str(strings__Builder* b);
void strings__Builder_ensure_cap(strings__Builder* b, int n);
void strings__Builder_free(strings__Builder* b);
void strings__Builder_write_repeated_rune(strings__Builder* b, rune r, int count);
string strings__repeat(u8 c, int n);
multi_return_u64_u64 math__bits__mul_64(u64 x, u64 y);
int math__bits__trailing_zeros_32(u32 x);
int math__bits__trailing_zeros_64(u64 x);
VV_LOC int math__bits__trailing_zeros_32_default(u32 x);
VV_LOC int math__bits__trailing_zeros_64_default(u64 x);
VV_LOC multi_return_u64_u64 math__bits__mul_64_default(u64 x, u64 y);
string strconv__Dec32_get_string_32(strconv__Dec32 d, bool neg, int i_n_digit, int i_pad_digit);
VV_LOC multi_return_strconv__Dec32_bool strconv__f32_to_decimal_exact_int(u32 i_mant, u32 exp);
VV_LOC strconv__Dec32 strconv__f32_to_decimal(u32 mant, u32 exp);
string strconv__f32_to_str(f32 f, int n_digit);
VV_LOC string strconv__Dec64_get_string_64(strconv__Dec64 d, bool neg, int i_n_digit, int i_pad_digit);
VV_LOC multi_return_strconv__Dec64_bool strconv__f64_to_decimal_exact_int(u64 i_mant, u64 exp);
VV_LOC strconv__Dec64 strconv__f64_to_decimal(u64 mant, u64 exp);
string strconv__f64_to_str(f64 f, int n_digit);
string strconv__f64_to_str_pad(f64 f, int n_digit);
void strconv__format_str_sb(string s, strconv__BF_param p, strings__Builder* sb);
void strconv__format_dec_sb(u64 d, strconv__BF_param p, strings__Builder* res);
string strconv__f64_to_str_lnd1(f64 f, int dec_digit);
string strconv__format_fl(f64 f, strconv__BF_param p);
string strconv__format_es(f64 f, strconv__BF_param p);
string strconv__remove_tail_zeros(string s);
string strconv__ftoa_64(f64 f);
string strconv__ftoa_32(f32 f);
string strconv__format_int(i64 n, int radix);
string strconv__format_uint(u64 n, int radix);
string strconv__f32_to_str_l(f32 f);
string strconv__f32_to_str_l_with_dot(f32 f);
string strconv__f64_to_str_l(f64 f);
string strconv__f64_to_str_l_with_dot(f64 f);
string strconv__fxx_to_str_l_parse(string s);
string strconv__fxx_to_str_l_parse_with_dot(string s);
VV_LOC u32 strconv__bool_to_u32(bool b);
VV_LOC u64 strconv__bool_to_u64(bool b);
VV_LOC string strconv__get_string_special(bool neg, bool expZero, bool mantZero);
VV_LOC u32 strconv__mul_shift_32(u32 m, u64 mul, int ishift);
VV_LOC u32 strconv__mul_pow5_invdiv_pow2(u32 m, u32 q, int j);
VV_LOC u32 strconv__mul_pow5_div_pow2(u32 m, u32 i, int j);
VV_LOC u32 strconv__pow5_factor_32(u32 i_v);
VV_LOC bool strconv__multiple_of_power_of_five_32(u32 v, u32 p);
VV_LOC bool strconv__multiple_of_power_of_two_32(u32 v, u32 p);
VV_LOC u32 strconv__log10_pow2(int e);
VV_LOC u32 strconv__log10_pow5(int e);
VV_LOC int strconv__pow5_bits(int e);
VV_LOC u64 strconv__shift_right_128(strconv__Uint128 v, int shift);
VV_LOC u64 strconv__mul_shift_64(u64 m, strconv__Uint128 mul, int shift);
VV_LOC u32 strconv__pow5_factor_64(u64 v_i);
VV_LOC bool strconv__multiple_of_power_of_five_64(u64 v, u32 p);
VV_LOC bool strconv__multiple_of_power_of_two_64(u64 v, u32 p);
int strconv__dec_digits(u64 n);
VV_LOC void builtin___memory_panic(string fname, isize size);
u8* builtin___v_malloc(isize n);
u8* builtin__malloc_noscan(isize n);
VV_LOC u8* builtin__malloc_uninit(isize n);
VV_LOC u64 builtin____at_least_one(u64 how_many);
u8* builtin__v_realloc(u8* b, isize n);
u8* builtin__realloc_data(u8* old_data, int old_size, int new_size);
u8* builtin__vcalloc(isize n);
u8* builtin__vcalloc_noscan(isize n);
void builtin___v_free(voidptr ptr);
voidptr builtin__memdup(voidptr src, isize sz);
voidptr builtin__memdup_noscan(voidptr src, isize sz);
VV_LOC int builtin__array_data_header_size(void);
VV_LOC u64 builtin__array_data_allocation_size(u64 total_size);
VV_LOC voidptr builtin__alloc_array_data(u64 total_size);
VV_LOC voidptr builtin__alloc_array_data_uninit(u64 total_size);
VV_LOC bool builtin__array_uses_noscan_data(array a);
VV_LOC voidptr builtin__array_alloc_array_data_like(array a, u64 total_size);
VV_LOC voidptr builtin__array_alloc_array_data_like_uninit(array a, u64 total_size);
VV_LOC ArrayDataHeader* builtin__array_data_header(array a);
VV_LOC bool builtin__array_buffer_has_slices(array a);
VV_LOC void builtin__array_mark_buffer_has_slices(array* a);
VV_LOC void builtin__array_set_managed_flags(array* a, bool is_slice);
VV_LOC void builtin__array_clone_shallow_to_cap(array* a, int new_cap);
VV_LOC int builtin__v_ni_index(int i, int len);
VV_LOC array builtin____new_array(int mylen, int cap, int elm_size);
VV_LOC array builtin____new_array_with_default(int mylen, int cap, int elm_size, voidptr val);
VV_LOC array builtin____new_array_with_multi_default(int mylen, int cap, int elm_size, voidptr val);
VV_LOC array builtin____new_array_with_array_default(int mylen, int cap, int elm_size, array val, int depth);
VV_LOC array builtin__new_array_from_c_array(int len, int cap, int elm_size, voidptr c_array);
void builtin__array_ensure_cap(array* a, int required);
VV_LOC bool builtin__array_needs_unique_shift(array a, int required);
VV_LOC bool builtin__array_needs_unique_append(array a, int required);
VV_LOC bool builtin__array_needs_unique_shrink(array a);
void builtin__array_insert(array* a, int i, voidptr val);
VV_LOC void builtin__array_insert_many(array* a, int i, voidptr val, int size);
void builtin__array_prepend(array* a, voidptr val);
VV_LOC void builtin__array_prepend_many(array* a, voidptr val, int size);
void builtin__array_delete(array* a, int i);
void builtin__array_delete_many(array* a, int i, int size);
void builtin__array_clear(array* a);
void builtin__array_trim(array* a, int index);
VV_LOC voidptr builtin__array_get_unsafe(array a, int i);
VV_LOC voidptr builtin__array_get(array a, int i);
VV_LOC voidptr builtin__array_get_i64(array a, i64 i);
VV_LOC voidptr builtin__array_get_u64(array a, u64 i);
VV_LOC voidptr builtin__array_get_ni(array a, int i);
VV_LOC voidptr builtin__array_get_with_check(array a, int i);
VV_LOC voidptr builtin__array_get_with_check_i64(array a, i64 i);
VV_LOC voidptr builtin__array_get_with_check_u64(array a, u64 i);
VV_LOC voidptr builtin__array_get_with_check_ni(array a, int i);
VV_LOC array builtin__array_slice(array a, int start, int _end);
VV_LOC array builtin__array_clone_static_to_depth(array a, int depth);
array builtin__array_clone(array* a);
array builtin__array_clone_to_depth(array* a, int depth);
VV_LOC void builtin__array_set_unsafe(array* a, int i, voidptr val);
VV_LOC void builtin__array_set(array* a, int i, voidptr val);
VV_LOC void builtin__array_set_i64(array* a, i64 i, voidptr val);
VV_LOC void builtin__array_set_u64(array* a, u64 i, voidptr val);
VV_LOC void builtin__array_set_ni(array* a, int i, voidptr val);
VV_LOC void builtin__copy_element_to(voidptr dest, voidptr src, int element_size);
VV_LOC void builtin__array_push(array* a, voidptr val);
void builtin__array_push_many(array* a, voidptr val, int size);
void builtin__array_free(array* a);
bool builtin__array_contains(array a, voidptr value);
void Array_string_free(Array_string* a);
string Array_string_str(Array_string a);
void builtin__u8_free(u8* data);
VV_LOC void builtin__panic_on_negative_len(int len);
VV_LOC void builtin__panic_on_negative_cap(int cap);
VV_LOC array builtin____new_array_with_default_noscan(int mylen, int cap, int elm_size, voidptr val);
VV_LOC void builtin__array_prepend_noscan(array* a, voidptr val);
VV_LOC void builtin__array_push_noscan(array* a, voidptr val);
VV_LOC void builtin__array_push_many_noscan(array* a, voidptr val, int size);
VV_LOC bool builtin__autostr_type_in_stack(int typ);
VV_LOC void builtin__autostr_type_push(int typ);
VV_LOC void builtin__autostr_type_pop(void);
VV_LOC bool builtin__autostr_addr_in_stack(voidptr addr);
VV_LOC void builtin__autostr_addr_push(voidptr addr);
VV_LOC void builtin__autostr_addr_pop(void);
VV_LOC string builtin__autostr_array_circular(int len);
bool builtin__print_backtrace_skipping_top_frames(int xskipframes);
void builtin___v_exit(int code);
VV_LOC void builtin__v_segmentation_fault_handler(i32 signal_number);
VV_LOC int builtin__v_fixed_index(int i, int len);
VV_LOC int builtin__v_fixed_index_i64(i64 i, int len);
VV_LOC int builtin__v_fixed_index_u64(u64 i, int len);
VV_LOC int builtin__v_fixed_index_ni(int i, int len);
VV_LOC int builtin__v_slice_index_i64(i64 i);
VV_LOC int builtin__v_slice_index_u64(u64 i);
Array_string builtin__arguments(void);
string builtin__vcurrent_hash(void);
u64 builtin__v_getpid(void);
u64 builtin__v_gettid(void);
bool builtin__isnil(voidptr v);
VV_LOC void builtin__builtin_init(void);
int builtin__vstrlen(u8* s);
int builtin__vstrlen_char(char* s);
voidptr builtin__vmemcpy(voidptr dest, const void* const_src, isize n);
voidptr builtin__vmemmove(voidptr dest, const void* const_src, isize n);
int builtin__vmemcmp(const void* const_s1, const void* const_s2, isize n);
voidptr builtin__vmemset(voidptr s, int c, isize n);
VV_LOC void builtin___result_ok(voidptr data, _result* res, int size);
VV_LOC void builtin___result_clone(_result* current, _result* res, int size);
string builtin__IError_str(IError err);
string builtin__Error_msg(Error err);
int builtin__Error_code(Error err);
string builtin__MessageError_str(MessageError err);
string builtin__MessageError_msg(MessageError err);
int builtin__MessageError_code(MessageError err);
void builtin__MessageError_free(MessageError* err);
IError builtin___v_error(string message);
IError builtin__error_with_code(string message, int code);
VV_LOC void builtin___option_none(voidptr data, _option* option, int size);
VV_LOC void builtin___option_ok(voidptr data, _option* option, int size);
VV_LOC void builtin___option_clone(_option* current, _option* option, int size);
VV_LOC void builtin___result_ok_markused(void);
VV_LOC string builtin__None___str(None__ _d1);
string builtin__f64_str(f64 x);
string builtin__f64_strg(f64 x);
string builtin__f32_str(f32 x);
string builtin__f32_strg(f32 x);
f32 builtin__f32_abs(f32 a);
f64 builtin__f64_abs(f64 a);
VV_LOC u32 builtin__grapheme_hex_nibble(u8 c);
VV_LOC u32 builtin__grapheme_hex_byte(string ranges, int i);
VV_LOC u32 builtin__grapheme_range_value(string ranges, int value_idx);
VV_LOC bool builtin__in_grapheme_ranges(rune r, string ranges);
VV_LOC GraphemeBreakProperty builtin__grapheme_break_property(rune r);
VV_LOC bool builtin__is_extended_pictographic(rune r);
VV_LOC GraphemeState builtin__grapheme_state_from_rune(rune r, GraphemeBreakProperty prop);
VV_LOC void builtin__GraphemeState_push(GraphemeState* gs, rune r, GraphemeBreakProperty prop);
VV_LOC bool builtin__should_break_grapheme(GraphemeState gs, rune r, GraphemeBreakProperty prop);
VV_LOC int builtin__utf8_rune_visible_width(rune r, GraphemeBreakProperty prop);
VV_LOC int builtin__utf8_grapheme_visible_length(string s);
string builtin__ptr_str(voidptr ptr);
string builtin__isize_str(isize x);
string builtin__usize_str(usize x);
string builtin__char_str(char* cptr);
VV_LOC string builtin__int_str_l(int nn, int max);
string builtin__i8_str(i8 n);
string builtin__i16_str(i16 n);
string builtin__u16_str(u16 n);
string builtin__i32_str(i32 n);
string builtin__int_str(int n);
string builtin__u32_str(u32 nn);
string builtin__int_literal_str(int_literal n);
string builtin__i64_str(i64 nn);
VV_LOC string builtin__impl_i64_to_string(i64 nn);
string builtin__u64_str(u64 nn);
string builtin__bool_str(bool b);
VV_LOC string builtin__u64_to_hex_no_leading_zeros(u64 nn, u8 len);
string builtin__u64_hex(u64 nn);
string builtin__voidptr_str(voidptr nn);
string builtin__byteptr_str(byteptr nn);
string builtin__charptr_str(charptr nn);
string builtin__u8_str(u8 b);
string builtin__u8_ascii_str(u8 b);
VV_LOC bool builtin__fast_string_eq(string a, string b);
VV_LOC u64 builtin__map_hash_string(voidptr pkey);
VV_LOC u64 builtin__map_hash_int_1(voidptr pkey);
VV_LOC u64 builtin__map_hash_int_2(voidptr pkey);
VV_LOC u64 builtin__map_hash_int_4(voidptr pkey);
VV_LOC u64 builtin__map_hash_int_8(voidptr pkey);
VV_LOC voidptr builtin__map_enum_fn(int kind, int esize);
VV_LOC void builtin__DenseArray_zeros_to_end(DenseArray* d);
VV_LOC DenseArray builtin__new_dense_array(int key_bytes, int value_bytes);
VV_LOC voidptr builtin__DenseArray_key(DenseArray* d, int i);
VV_LOC voidptr builtin__DenseArray_value(DenseArray* d, int i);
VV_LOC bool builtin__DenseArray_has_index(DenseArray* d, int i);
VV_LOC void builtin__DenseArray_trim_deleted_tail(DenseArray* d);
VV_LOC int builtin__DenseArray_expand(DenseArray* d);
VV_LOC bool builtin__map_eq_string(voidptr a, voidptr b);
VV_LOC bool builtin__map_eq_int_1(voidptr a, voidptr b);
VV_LOC bool builtin__map_eq_int_2(voidptr a, voidptr b);
VV_LOC bool builtin__map_eq_int_4(voidptr a, voidptr b);
VV_LOC bool builtin__map_eq_int_8(voidptr a, voidptr b);
VV_LOC bool builtin__map_map_eq(map a, map b);
VV_LOC void builtin__map_clone_string(voidptr dest, voidptr pkey);
VV_LOC void builtin__map_clone_int_1(voidptr dest, voidptr pkey);
VV_LOC void builtin__map_clone_int_2(voidptr dest, voidptr pkey);
VV_LOC void builtin__map_clone_int_4(voidptr dest, voidptr pkey);
VV_LOC void builtin__map_clone_int_8(voidptr dest, voidptr pkey);
VV_LOC void builtin__map_free_string(voidptr pkey);
VV_LOC void builtin__map_free_nop(voidptr _d1);
VV_LOC map builtin__new_map(int key_bytes, int value_bytes, u64 (*hash_fn)(voidptr _d1), bool (*key_eq_fn)(voidptr _d1, voidptr _d2), void (*clone_fn)(voidptr _d1, voidptr _d2), void (*free_fn)(voidptr _d1));
VV_LOC map builtin__new_map_init(u64 (*hash_fn)(voidptr _d1), bool (*key_eq_fn)(voidptr _d1, voidptr _d2), void (*clone_fn)(voidptr _d1, voidptr _d2), void (*free_fn)(voidptr _d1), int n, int key_bytes, int value_bytes, voidptr keys, voidptr values);
map builtin__map_move(map* m);
void builtin__map_clear(map* m);
VV_LOC multi_return_u32_u32 builtin__map_key_to_index(map* m, voidptr pkey);
VV_LOC multi_return_u32_u32 builtin__map_meta_less(map* m, u32 _index, u32 _metas);
VV_LOC void builtin__map_meta_greater(map* m, u32 _index, u32 _metas, u32 kvi);
VV_LOC void builtin__map_ensure_extra_metas_grow(map* m);
VV_LOC void builtin__map_ensure_extra_metas(map* m, u32 probe_count);
VV_LOC void builtin__map_set(map* m, voidptr key, voidptr value);
VV_LOC void builtin__map_expand(map* m);
VV_LOC void builtin__map_rehash(map* m);
VV_LOC void builtin__map_reserve_metas(map* m, u32 meta_bytes);
void builtin__map_reserve(map* m, u32 n);
VV_LOC void builtin__map_cached_rehash(map* m, u32 old_cap);
VV_LOC voidptr builtin__map_get_and_set(map* m, voidptr key, voidptr zero);
VV_LOC voidptr builtin__map_get(map* m, voidptr key, voidptr zero);
VV_LOC voidptr builtin__map_get_check(map* m, voidptr key);
VV_LOC bool builtin__map_exists(map* m, voidptr key);
VV_LOC void builtin__DenseArray_delete(DenseArray* d, int i);
void builtin__map_delete(map* m, voidptr key);
array builtin__map_keys(map* m);
array builtin__map_values(map* m);
VV_LOC DenseArray builtin__DenseArray_clone(DenseArray* d);
map builtin__map_clone(map* m);
void builtin__map_free(map* m);
void builtin__IError_free(IError* ie);
void builtin__panic_option_not_set(string s);
void builtin__panic_result_not_set(string s);
void builtin___v_panic(string s);
void builtin__panic_n(string s, i64 number1);
void builtin__panic_n2(string s, i64 number1, i64 number2);
VV_LOC void builtin__panic_n3(string s, i64 number1, i64 number2, i64 number3);
VV_LOC void builtin__set_stream_unbuffered(FILE* stream);
void builtin__eprintln(string s);
void builtin__eprint(string s);
void builtin__flush_stdout(void);
void builtin__flush_stderr(void);
void builtin__unbuffer_stdout(void);
void builtin__print(string s);
void builtin__println(string s);
VV_LOC void builtin___writeln_to_fd(int fd, string s);
VV_LOC void builtin___write_buf_to_fd(int fd, u8* buf, int buf_len);
string builtin__rune_str(rune c);
string Array_rune_string(Array_rune ra);
Array_u8 builtin__rune_bytes(rune c);
rune builtin__rune_to_upper(rune c);
rune builtin__rune_to_lower(rune c);
VV_LOC rune builtin__rune_map_to(rune c, MapMode mode);
Array_rune builtin__string_runes(string s);
string builtin__cstring_to_vstring(const char* const_s);
string builtin__tos_clone(const u8* const_s);
string builtin__tos(u8* s, int len);
string builtin__tos2(u8* s);
string builtin__tos3(char* s);
string builtin__u8_vstring(u8* bp);
string builtin__u8_vstring_with_len(u8* bp, int len);
bool builtin__string_is_pure_ascii(string s);
string builtin__string_clone(string a);
string builtin__string_replace(string s, string rep, string with);
VV_LOC bool builtin__string__eq(string s, string a);
VV_LOC bool builtin__string__lt(string s, string a);
VV_LOC string builtin__string__plus(string s, string a);
VV_LOC string builtin__string_plus_many(int data_len, string* input_base);
Array_string builtin__string_split(string s, string delim);
Array_string builtin__string_split_nth(string s, string delim, int nth);
Array_string builtin__string_split_into_lines(string s);
string builtin__string_substr(string s, int start, int _end);
string builtin__string_substr_unsafe(string s, int start, int _end);
int builtin__string_index_(string s, string p);
_option_int builtin__string_last_index(string s, string needle);
VV_LOC int builtin__string_index_kmp(string s, string p);
VV_LOC int builtin__string_index_last_(string s, string p);
int builtin__string_index_after_(string s, string p, int start);
bool builtin__string_contains_u8(string s, u8 x);
bool builtin__string_contains(string s, string substr);
bool builtin__string_starts_with(string s, string p);
bool builtin__string_ends_with(string s, string p);
string builtin__string_to_lower_ascii(string s);
string builtin__string_to_lower(string s);
string builtin__string_to_upper_ascii(string s);
string builtin__string_to_upper(string s);
string builtin__string_trim_space(string s);
string builtin__string_trim(string s, string cutset);
VV_LOC string builtin__string_trim_chars(string s, string cutset, TrimMode mode);
VV_LOC string builtin__string_trim_runes(string s, string cutset, TrimMode mode);
string builtin__string_trim_left(string s, string cutset);
string builtin__string_trim_right(string s, string cutset);
string builtin__string_trim_string_right(string s, string str);
string builtin__string_str(string s);
VV_LOC u8 builtin__string_at(string s, int idx);
VV_LOC u8 builtin__string_at_i64(string s, i64 idx);
VV_LOC u8 builtin__string_at_u64(string s, u64 idx);
VV_LOC u8 builtin__string_at_ni(string s, int idx);
VV_LOC _option_u8 builtin__string_at_with_check(string s, int idx);
VV_LOC _option_u8 builtin__string_at_with_check_i64(string s, i64 idx);
VV_LOC _option_u8 builtin__string_at_with_check_u64(string s, u64 idx);
VV_LOC _option_u8 builtin__string_at_with_check_ni(string s, int idx);
void builtin__string_free(string* s);
string builtin__string_all_before(string s, string sub);
string builtin__string_all_before_last(string s, string sub);
string builtin__string_all_after(string s, string sub);
string builtin__string_all_after_last(string s, string sub);
string Array_string_join(Array_string a, string sep);
Array_string builtin__string_fields(string s);
string builtin__StrIntpType_str(StrIntpType x);
VV_LOC f32 builtin__fabs32(f32 x);
VV_LOC f64 builtin__fabs64(f64 x);
VV_LOC u64 builtin__abs64(i64 x);
VV_LOC void builtin__StrIntpData_process_str_intp_data(StrIntpData* data, strings__Builder* sb);
string builtin__str_intp(int data_len, StrIntpData* input_base);
string builtin__utf32_to_str(u32 code);
string builtin__utf32_to_str_no_malloc(u32 code, u8* buf);
int builtin__utf32_decode_to_buffer(u32 code, u8* buf);
VV_LOC bool builtin__utf8_is_continuation(u8 b);
VV_LOC multi_return_rune_int builtin__utf8_decode_rune(u8* _bytes, int available_len);
int builtin__utf8_str_visible_length(string s);
bool builtin__ArrayFlags_has(ArrayFlags* e, ArrayFlags flag_);
void builtin__ArrayFlags_set(ArrayFlags* e, ArrayFlags flag_);
void builtin__ArrayFlags_clear(ArrayFlags* e, ArrayFlags flag_);
string os__getenv(string key);
_option_string os__getenv_opt(string key);
VV_LOC voidptr os__v_os_execute_mutex_ptr(void);
VV_LOC void os__init(void);
VV_LOC void os__v_os_execute_lock(void);
VV_LOC void os__v_os_execute_unlock(void);
int os__fd_close(int fd);
Array_string os__fd_slurp(int fd);
multi_return_string_int os__fd_read(int fd, int maxbytes);
VV_LOC string os__NotExpected_msg(os__NotExpected err);
VV_LOC int os__NotExpected_code(os__NotExpected err);
_result_os__File os__open(string path);
_result_os__File os__create(string path);
_result_int os__File_read(os__File* f, Array_u8* buf);
_result_void os__File_write_full_buffer(os__File* f, voidptr buffer, usize buffer_len);
VV_LOC _result_int os__fread(voidptr ptr, int item_size, int items, FILE* stream);
string os__FileNotOpenedError_msg(os__FileNotOpenedError err);
string os__SizeOfTypeIs0Error_msg(os__SizeOfTypeIs0Error err);
VV_LOC IError os__error_file_not_opened(void);
VV_LOC IError os__error_size_of_type_0(void);
VV_LOC u16 os__swap_bytes_u16(u16 x);
VV_LOC u32 os__swap_bytes_u32(u32 x);
VV_LOC u64 os__swap_bytes_u64(u64 x);
VV_LOC _result_void os__check_cf(usize x, string label);
VV_LOC _result_void os__check_fwrite(usize x);
VV_LOC _result_void os__check_fread(usize x);
VV_LOC _result_int os__find_cfile_size(FILE* fp);
VV_LOC _result_strings__Builder os__slurp_file_in_builder(FILE* fp);
_result_string os__read_file(string path);
u64 os__file_size(string path);
_result_void os__cp(string src, string dst, os__CopyParams config);
_result_FILE_ptr os__vfopen(string path, string mode);
int os__fileno(voidptr cfile);
VV_LOC bool os__posix_wait_status_exited(int status);
VV_LOC int os__posix_wait_status_exit_code(int status);
VV_LOC bool os__posix_wait_status_signaled(int status);
VV_LOC int os__posix_wait_status_signal(int status);
VV_LOC multi_return_int_bool os__posix_wait4_to_exit_status(int waitret);
string os__posix_get_error_msg(int code);
bool os__exists(string path);
_result_void os__rm(string path);
_result_void os__rmdir(string path);
string os__real_path(string fpath);
VV_LOC void os__normalize_drive_letter(string path);
_result_void os__chmod(string path, int mode);
IError os__error_posix(os__SystemError e);
void os__Result_free(os__Result* result);
_result_Array_string os__read_lines(string path);
VV_LOC _result_Array_string os__read_lines_from_open_file(os__File* file);
_result_void os__rmdir_all(string path);
string os__dir(string path);
string os__file_name(string path);
_result_void os__write_file(string path, string text);
string os__ExecutableNotFoundError_msg(os__ExecutableNotFoundError err);
bool os__is_file(string path);
string os__join_path_single(string base, string elem);
VV_LOC void os__normalize_path_in_builder(strings__Builder* sb);
_result_void os__mkdir_all(string opath, os__MkdirParams params);
_result_Array_string os__ls(string path);
_result_void os__mkdir(string path, os__MkdirParams params);
os__Result os__execute(string cmd);
_result_void os__symlink(string target, string link_name);
void os__File_close(os__File* f);
_result_os__Stat os__stat(string path);
_result_os__Stat os__lstat(string path);
os__FileType os__Stat_get_filetype(os__Stat st);
bool os__is_dir(string path);
bool os__is_link(string path);
VV_LOC string main__pad_right(string s, int width);
VV_LOC string main__format_bytes(u64 bytes);
VV_LOC string main__json_escape(string s);
VV_LOC string main__parse_json_value(string json_str, string key);
VV_LOC void main__print_banner(void);
VV_LOC string main__normalize_repo_url(string url);
VV_LOC Array_string main__get_repo_file_urls(main__Repo repo, string rel_path);
VV_LOC Array_string main__get_repos_conf_paths(string prefix);
VV_LOC main__Config main__load_config(void);
VV_LOC bool main__save_repos_config(main__Config cfg);
VV_LOC Array_string main__get_installed_db_dirs(main__Config cfg);
VV_LOC bool main__is_installed(main__Config cfg, string pkg_name);
VV_LOC Array_string main__get_installed_packages(main__Config cfg);
VV_LOC _option_main__Package main__get_installed_meta(main__Config cfg, string pkg_name);
VV_LOC Array_main__Package main__parse_index_json(string content, string repo_name);
VV_LOC Array_main__Package main__fetch_all_repo_packages(main__Config cfg);
VV_LOC bool main__download_url(string url, string dest);
VV_LOC int main__cmd_update(main__Config cfg);
VV_LOC int main__cmd_list(main__Config cfg, bool json_mode);
VV_LOC int main__cmd_search(main__Config cfg, string query);
VV_LOC int main__cmd_info(main__Config cfg, string pkg_name);
VV_LOC int main__cmd_install(main__Config cfg, string pkg_name);
VV_LOC int main__cmd_install_local_file(main__Config cfg, string file_path);
VV_LOC int main__deploy_package_payload(main__Config cfg, string payload_file, main__Package pkg);
VV_LOC int main__cmd_remove(main__Config cfg, string pkg_name);
VV_LOC int main__cmd_repo_list(main__Config cfg, bool json_mode);
VV_LOC int main__cmd_repo_add(main__Config* cfg, string name, string url);
VV_LOC int main__cmd_repo_remove(main__Config* cfg, string name);
VV_LOC int main__cmd_status(main__Config cfg);
VV_LOC void main__print_help(void);
VV_LOC void main__main(void);

// V global/const non-precomputed definitions:
static string _const_strconv__digit_pairs; // a string literal, inited later
static string _const_strconv__base_digits; // a string literal, inited later
static string _const_grapheme_control_ranges; // a string literal, inited later
static string _const_grapheme_extend_ranges; // a string literal, inited later
static string _const_grapheme_spacing_mark_ranges; // a string literal, inited later
static string _const_grapheme_prepend_ranges; // a string literal, inited later
static string _const_grapheme_extended_pictographic_ranges; // a string literal, inited later
static string _const_digit_pairs; // a string literal, inited later
static string _const_os__path_separator; // a string literal, inited later
static string _const_main__version; // a string literal, inited later
static string _const_main__default_repo_name; // a string literal, inited later
static string _const_main__default_repo_url; // a string literal, inited later
static string _const_main__default_install_prefix; // a string literal, inited later
static string _const_main__default_db_dir; // a string literal, inited later
static string _const_main__c_reset; // a string literal, inited later
static string _const_main__c_bold; // a string literal, inited later
static string _const_main__c_dim; // a string literal, inited later
static string _const_main__c_cyan; // a string literal, inited later
static string _const_main__c_blue; // a string literal, inited later
static string _const_main__c_green; // a string literal, inited later
static string _const_main__c_yellow; // a string literal, inited later
static string _const_main__c_red; // a string literal, inited later
static string _const_main__c_purple; // a string literal, inited later
static string _const_main__c_gray; // a string literal, inited later
static const u32 _const_math__bits__de_bruijn32 = 125613361; // precomputed2
static Array_fixed_u8_32 _const_math__bits__de_bruijn32tab = {((u8)(0)), 1, 28, 2, 29, 14, 24, 3, 30, 22, 20, 15, 25, 17, 4, 8, 
31, 27, 13, 23, 21, 19, 16, 7, 26, 12, 18, 6, 11, 5, 10, 9}; // fixed array const
static const u64 _const_math__bits__de_bruijn64 = 285870213051353865U; // precomputed2
static Array_fixed_u8_64 _const_math__bits__de_bruijn64tab = {((u8)(0)), 1, 56, 2, 57, 49, 28, 3, 61, 58, 42, 50, 38, 29, 17, 4, 
62, 47, 59, 36, 45, 43, 51, 22, 53, 39, 33, 30, 24, 18, 12, 5, 
63, 55, 48, 27, 60, 41, 37, 16, 46, 35, 44, 21, 52, 32, 23, 11, 
54, 26, 40, 15, 34, 20, 31, 10, 25, 14, 19, 9, 13, 8, 7, 6}; // fixed array const
static const u64 _const_math__bits__two32 = 4294967296U; // precomputed2
static const u64 _const_math__bits__mask32 = 4294967295U; // precomputed2
static const u32 _const_strconv__single_plus_zero = 0; // precomputed2
static const u32 _const_strconv__single_minus_zero = 2147483648; // precomputed2
static const u32 _const_strconv__single_plus_infinity = 2139095040; // precomputed2
static const u32 _const_strconv__single_minus_infinity = 4286578688; // precomputed2
static const u64 _const_strconv__double_plus_zero = 0U; // precomputed2
static const u64 _const_strconv__double_minus_zero = 9223372036854775808U; // precomputed2
static const u64 _const_strconv__double_plus_infinity = 9218868437227405312U; // precomputed2
static const u64 _const_strconv__double_minus_infinity = 18442240474082181120U; // precomputed2
static Array_fixed_u32_10 _const_strconv__ten_pow_table_32 = {((u32)(1)), ((u32)(10)), ((u32)(100)), ((u32)(1000)), ((u32)(10000)), ((u32)(100000)), ((u32)(1000000)), ((u32)(10000000)), ((u32)(100000000)), ((u32)(1000000000))}; // fixed array const
static const u32 _const_strconv__mantbits32 = 23; // precomputed2
static const u32 _const_strconv__expbits32 = 8; // precomputed2
static Array_fixed_u64_20 _const_strconv__ten_pow_table_64 = {((u64)(1)), ((u64)(10)), ((u64)(100)), ((u64)(1000)), ((u64)(10000)), ((u64)(100000)), ((u64)(1000000)), ((u64)(10000000)), ((u64)(100000000)), ((u64)(1000000000)), ((u64)(10000000000LL)), ((u64)(100000000000LL)), ((u64)(1000000000000LL)), ((u64)(10000000000000LL)), ((u64)(100000000000000LL)), ((u64)(1000000000000000LL)), ((u64)(10000000000000000LL)), ((u64)(100000000000000000LL)), ((u64)(1000000000000000000LL)), ((u64)(10000000000000000000ULL))}; // fixed array const
static const u32 _const_strconv__mantbits64 = 52; // precomputed2
static const u32 _const_strconv__expbits64 = 11; // precomputed2
static Array_fixed_f64_36 _const_strconv__dec_round = {((f64)(0.5)), 0.05, 0.005, 0.0005, 0.00005, 0.000005, 0.0000005, 0.00000005, 0.000000005, 0.0000000005, 0.00000000005, 0.000000000005, 0.0000000000005, 0.00000000000005, 0.000000000000005, 0.0000000000000005, 
0.00000000000000005, 0.000000000000000005, 0.0000000000000000005, 0.00000000000000000005, 0.000000000000000000005, 0.0000000000000000000005, 0.00000000000000000000005, 0.000000000000000000000005, 0.0000000000000000000000005, 0.00000000000000000000000005, 0.000000000000000000000000005, 0.0000000000000000000000000005, 0.00000000000000000000000000005, 0.000000000000000000000000000005, 0.0000000000000000000000000000005, 0.00000000000000000000000000000005, 0.000000000000000000000000000000005, 0.0000000000000000000000000000000005, 0.00000000000000000000000000000000005, 0.000000000000000000000000000000000005}; // fixed array const
static Array_fixed_u64_47 _const_strconv__pow5_split_32 = {((u64)(1152921504606846976LL)), ((u64)(1441151880758558720LL)), ((u64)(1801439850948198400LL)), ((u64)(2251799813685248000LL)), ((u64)(1407374883553280000LL)), ((u64)(1759218604441600000LL)), ((u64)(2199023255552000000LL)), ((u64)(1374389534720000000LL)), ((u64)(1717986918400000000LL)), ((u64)(2147483648000000000LL)), ((u64)(1342177280000000000LL)), ((u64)(1677721600000000000LL)), ((u64)(2097152000000000000LL)), ((u64)(1310720000000000000LL)), ((u64)(1638400000000000000LL)), ((u64)(2048000000000000000LL)), 
((u64)(1280000000000000000LL)), ((u64)(1600000000000000000LL)), ((u64)(2000000000000000000LL)), ((u64)(1250000000000000000LL)), ((u64)(1562500000000000000LL)), ((u64)(1953125000000000000LL)), ((u64)(1220703125000000000LL)), ((u64)(1525878906250000000LL)), ((u64)(1907348632812500000LL)), ((u64)(1192092895507812500LL)), ((u64)(1490116119384765625LL)), ((u64)(1862645149230957031LL)), ((u64)(1164153218269348144LL)), ((u64)(1455191522836685180LL)), ((u64)(1818989403545856475LL)), ((u64)(2273736754432320594LL)), 
((u64)(1421085471520200371LL)), ((u64)(1776356839400250464LL)), ((u64)(2220446049250313080LL)), ((u64)(1387778780781445675LL)), ((u64)(1734723475976807094LL)), ((u64)(2168404344971008868LL)), ((u64)(1355252715606880542LL)), ((u64)(1694065894508600678LL)), ((u64)(2117582368135750847LL)), ((u64)(1323488980084844279LL)), ((u64)(1654361225106055349LL)), ((u64)(2067951531382569187LL)), ((u64)(1292469707114105741LL)), ((u64)(1615587133892632177LL)), ((u64)(2019483917365790221LL))}; // fixed array const
static Array_fixed_u64_31 _const_strconv__pow5_inv_split_32 = {((u64)(576460752303423489LL)), ((u64)(461168601842738791LL)), ((u64)(368934881474191033LL)), ((u64)(295147905179352826LL)), ((u64)(472236648286964522LL)), ((u64)(377789318629571618LL)), ((u64)(302231454903657294LL)), ((u64)(483570327845851670LL)), ((u64)(386856262276681336LL)), ((u64)(309485009821345069LL)), ((u64)(495176015714152110LL)), ((u64)(396140812571321688LL)), ((u64)(316912650057057351LL)), ((u64)(507060240091291761LL)), ((u64)(405648192073033409LL)), ((u64)(324518553658426727LL)), 
((u64)(519229685853482763LL)), ((u64)(415383748682786211LL)), ((u64)(332306998946228969LL)), ((u64)(531691198313966350LL)), ((u64)(425352958651173080LL)), ((u64)(340282366920938464LL)), ((u64)(544451787073501542LL)), ((u64)(435561429658801234LL)), ((u64)(348449143727040987LL)), ((u64)(557518629963265579LL)), ((u64)(446014903970612463LL)), ((u64)(356811923176489971LL)), ((u64)(570899077082383953LL)), ((u64)(456719261665907162LL)), ((u64)(365375409332725730LL))}; // fixed array const
static Array_fixed_u64_652 _const_strconv__pow5_split_64_x = {((u64)(0x0000000000000000)), ((u64)(0x0100000000000000LL)), ((u64)(0x0000000000000000)), ((u64)(0x0140000000000000LL)), ((u64)(0x0000000000000000)), ((u64)(0x0190000000000000LL)), ((u64)(0x0000000000000000)), ((u64)(0x01f4000000000000LL)), ((u64)(0x0000000000000000)), ((u64)(0x0138800000000000LL)), ((u64)(0x0000000000000000)), ((u64)(0x0186a00000000000LL)), ((u64)(0x0000000000000000)), ((u64)(0x01e8480000000000LL)), ((u64)(0x0000000000000000)), ((u64)(0x01312d0000000000LL)), 
((u64)(0x0000000000000000)), ((u64)(0x017d784000000000LL)), ((u64)(0x0000000000000000)), ((u64)(0x01dcd65000000000LL)), ((u64)(0x0000000000000000)), ((u64)(0x012a05f200000000LL)), ((u64)(0x0000000000000000)), ((u64)(0x0174876e80000000LL)), ((u64)(0x0000000000000000)), ((u64)(0x01d1a94a20000000LL)), ((u64)(0x0000000000000000)), ((u64)(0x012309ce54000000LL)), ((u64)(0x0000000000000000)), ((u64)(0x016bcc41e9000000LL)), ((u64)(0x0000000000000000)), ((u64)(0x01c6bf5263400000LL)), 
((u64)(0x0000000000000000)), ((u64)(0x011c37937e080000LL)), ((u64)(0x0000000000000000)), ((u64)(0x016345785d8a0000LL)), ((u64)(0x0000000000000000)), ((u64)(0x01bc16d674ec8000LL)), ((u64)(0x0000000000000000)), ((u64)(0x01158e460913d000LL)), ((u64)(0x0000000000000000)), ((u64)(0x015af1d78b58c400LL)), ((u64)(0x0000000000000000)), ((u64)(0x01b1ae4d6e2ef500LL)), ((u64)(0x0000000000000000)), ((u64)(0x010f0cf064dd5920LL)), ((u64)(0x0000000000000000)), ((u64)(0x0152d02c7e14af68LL)), 
((u64)(0x0000000000000000)), ((u64)(0x01a784379d99db42LL)), ((u64)(0x4000000000000000LL)), ((u64)(0x0108b2a2c2802909LL)), ((u64)(0x9000000000000000ULL)), ((u64)(0x014adf4b7320334bLL)), ((u64)(0x7400000000000000LL)), ((u64)(0x019d971e4fe8401eLL)), ((u64)(0x0880000000000000LL)), ((u64)(0x01027e72f1f12813LL)), ((u64)(0xcaa0000000000000ULL)), ((u64)(0x01431e0fae6d7217LL)), ((u64)(0xbd48000000000000ULL)), ((u64)(0x0193e5939a08ce9dLL)), ((u64)(0x2c9a000000000000LL)), ((u64)(0x01f8def8808b0245LL)), 
((u64)(0x3be0400000000000LL)), ((u64)(0x013b8b5b5056e16bLL)), ((u64)(0x0ad8500000000000LL)), ((u64)(0x018a6e32246c99c6LL)), ((u64)(0x8d8e640000000000ULL)), ((u64)(0x01ed09bead87c037LL)), ((u64)(0xb878fe8000000000ULL)), ((u64)(0x013426172c74d822LL)), ((u64)(0x66973e2000000000LL)), ((u64)(0x01812f9cf7920e2bLL)), ((u64)(0x403d0da800000000LL)), ((u64)(0x01e17b84357691b6LL)), ((u64)(0xe826288900000000ULL)), ((u64)(0x012ced32a16a1b11LL)), ((u64)(0x622fb2ab40000000LL)), ((u64)(0x0178287f49c4a1d6LL)), 
((u64)(0xfabb9f5610000000ULL)), ((u64)(0x01d6329f1c35ca4bLL)), ((u64)(0x7cb54395ca000000LL)), ((u64)(0x0125dfa371a19e6fLL)), ((u64)(0x5be2947b3c800000LL)), ((u64)(0x016f578c4e0a060bLL)), ((u64)(0x32db399a0ba00000LL)), ((u64)(0x01cb2d6f618c878eLL)), ((u64)(0xdfc9040047440000ULL)), ((u64)(0x011efc659cf7d4b8LL)), ((u64)(0x17bb450059150000LL)), ((u64)(0x0166bb7f0435c9e7LL)), ((u64)(0xddaa16406f5a4000ULL)), ((u64)(0x01c06a5ec5433c60LL)), ((u64)(0x8a8a4de845986800ULL)), ((u64)(0x0118427b3b4a05bcLL)), 
((u64)(0xad2ce16256fe8200ULL)), ((u64)(0x015e531a0a1c872bLL)), ((u64)(0x987819baecbe2280ULL)), ((u64)(0x01b5e7e08ca3a8f6LL)), ((u64)(0x1f4b1014d3f6d590LL)), ((u64)(0x0111b0ec57e6499aLL)), ((u64)(0xa71dd41a08f48af4ULL)), ((u64)(0x01561d276ddfdc00LL)), ((u64)(0xd0e549208b31adb1ULL)), ((u64)(0x01aba4714957d300LL)), ((u64)(0x828f4db456ff0c8eULL)), ((u64)(0x010b46c6cdd6e3e0LL)), ((u64)(0xa33321216cbecfb2ULL)), ((u64)(0x014e1878814c9cd8LL)), ((u64)(0xcbffe969c7ee839eULL)), ((u64)(0x01a19e96a19fc40eLL)), 
((u64)(0x3f7ff1e21cf51243LL)), ((u64)(0x0105031e2503da89LL)), ((u64)(0x8f5fee5aa43256d4ULL)), ((u64)(0x014643e5ae44d12bLL)), ((u64)(0x7337e9f14d3eec89LL)), ((u64)(0x0197d4df19d60576LL)), ((u64)(0x1005e46da08ea7abLL)), ((u64)(0x01fdca16e04b86d4LL)), ((u64)(0x8a03aec4845928cbULL)), ((u64)(0x013e9e4e4c2f3444LL)), ((u64)(0xac849a75a56f72fdULL)), ((u64)(0x018e45e1df3b0155LL)), ((u64)(0x17a5c1130ecb4fbdLL)), ((u64)(0x01f1d75a5709c1abLL)), ((u64)(0xeec798abe93f11d6ULL)), ((u64)(0x013726987666190aLL)), 
((u64)(0xaa797ed6e38ed64bULL)), ((u64)(0x0184f03e93ff9f4dLL)), ((u64)(0x1517de8c9c728bdeLL)), ((u64)(0x01e62c4e38ff8721LL)), ((u64)(0xad2eeb17e1c7976bULL)), ((u64)(0x012fdbb0e39fb474LL)), ((u64)(0xd87aa5ddda397d46ULL)), ((u64)(0x017bd29d1c87a191LL)), ((u64)(0x4e994f5550c7dc97LL)), ((u64)(0x01dac74463a989f6LL)), ((u64)(0xf11fd195527ce9deULL)), ((u64)(0x0128bc8abe49f639LL)), ((u64)(0x6d67c5faa71c2456LL)), ((u64)(0x0172ebad6ddc73c8LL)), ((u64)(0x88c1b77950e32d6cULL)), ((u64)(0x01cfa698c95390baLL)), 
((u64)(0x957912abd28dfc63ULL)), ((u64)(0x0121c81f7dd43a74LL)), ((u64)(0xbad75756c7317b7cULL)), ((u64)(0x016a3a275d494911LL)), ((u64)(0x298d2d2c78fdda5bLL)), ((u64)(0x01c4c8b1349b9b56LL)), ((u64)(0xd9f83c3bcb9ea879ULL)), ((u64)(0x011afd6ec0e14115LL)), ((u64)(0x50764b4abe865297LL)), ((u64)(0x0161bcca7119915bLL)), ((u64)(0x2493de1d6e27e73dLL)), ((u64)(0x01ba2bfd0d5ff5b2LL)), ((u64)(0x56dc6ad264d8f086LL)), ((u64)(0x01145b7e285bf98fLL)), ((u64)(0x2c938586fe0f2ca8LL)), ((u64)(0x0159725db272f7f3LL)), 
((u64)(0xf7b866e8bd92f7d2ULL)), ((u64)(0x01afcef51f0fb5efLL)), ((u64)(0xfad34051767bdae3ULL)), ((u64)(0x010de1593369d1b5LL)), ((u64)(0x79881065d41ad19cLL)), ((u64)(0x015159af80444623LL)), ((u64)(0x57ea147f49218603LL)), ((u64)(0x01a5b01b605557acLL)), ((u64)(0xb6f24ccf8db4f3c1ULL)), ((u64)(0x01078e111c3556cbLL)), ((u64)(0xa4aee003712230b2ULL)), ((u64)(0x014971956342ac7eLL)), ((u64)(0x4dda98044d6abcdfLL)), ((u64)(0x019bcdfabc13579eLL)), ((u64)(0xf0a89f02b062b60bULL)), ((u64)(0x010160bcb58c16c2LL)), 
((u64)(0xacd2c6c35c7b638eULL)), ((u64)(0x0141b8ebe2ef1c73LL)), ((u64)(0x98077874339a3c71ULL)), ((u64)(0x01922726dbaae390LL)), ((u64)(0xbe0956914080cb8eULL)), ((u64)(0x01f6b0f092959c74LL)), ((u64)(0xf6c5d61ac8507f38ULL)), ((u64)(0x013a2e965b9d81c8LL)), ((u64)(0x34774ba17a649f07LL)), ((u64)(0x0188ba3bf284e23bLL)), ((u64)(0x01951e89d8fdc6c8LL)), ((u64)(0x01eae8caef261acaLL)), ((u64)(0x40fd3316279e9c3dLL)), ((u64)(0x0132d17ed577d0beLL)), ((u64)(0xd13c7fdbb186434cULL)), ((u64)(0x017f85de8ad5c4edLL)), 
((u64)(0x458b9fd29de7d420LL)), ((u64)(0x01df67562d8b3629LL)), ((u64)(0xcb7743e3a2b0e494ULL)), ((u64)(0x012ba095dc7701d9LL)), ((u64)(0x3e5514dc8b5d1db9LL)), ((u64)(0x017688bb5394c250LL)), ((u64)(0x4dea5a13ae346527LL)), ((u64)(0x01d42aea2879f2e4LL)), ((u64)(0xb0b2784c4ce0bf38ULL)), ((u64)(0x01249ad2594c37ceLL)), ((u64)(0x5cdf165f6018ef06LL)), ((u64)(0x016dc186ef9f45c2LL)), ((u64)(0xf416dbf7381f2ac8ULL)), ((u64)(0x01c931e8ab871732LL)), ((u64)(0xd88e497a83137abdULL)), ((u64)(0x011dbf316b346e7fLL)), 
((u64)(0xceb1dbd923d8596cULL)), ((u64)(0x01652efdc6018a1fLL)), ((u64)(0xc25e52cf6cce6fc7ULL)), ((u64)(0x01be7abd3781eca7LL)), ((u64)(0xd97af3c1a40105dcULL)), ((u64)(0x01170cb642b133e8LL)), ((u64)(0x0fd9b0b20d014754LL)), ((u64)(0x015ccfe3d35d80e3LL)), ((u64)(0xd3d01cde90419929ULL)), ((u64)(0x01b403dcc834e11bLL)), ((u64)(0x6462120b1a28ffb9LL)), ((u64)(0x01108269fd210cb1LL)), ((u64)(0xbd7a968de0b33fa8ULL)), ((u64)(0x0154a3047c694fddLL)), ((u64)(0x2cd93c3158e00f92LL)), ((u64)(0x01a9cbc59b83a3d5LL)), 
((u64)(0x3c07c59ed78c09bbLL)), ((u64)(0x010a1f5b81324665LL)), ((u64)(0x8b09b7068d6f0c2aULL)), ((u64)(0x014ca732617ed7feLL)), ((u64)(0x2dcc24c830cacf34LL)), ((u64)(0x019fd0fef9de8dfeLL)), ((u64)(0xdc9f96fd1e7ec180ULL)), ((u64)(0x0103e29f5c2b18beLL)), ((u64)(0x93c77cbc661e71e1ULL)), ((u64)(0x0144db473335deeeLL)), ((u64)(0x38b95beb7fa60e59LL)), ((u64)(0x01961219000356aaLL)), ((u64)(0xc6e7b2e65f8f91efULL)), ((u64)(0x01fb969f40042c54LL)), ((u64)(0xfc50cfcffbb9bb35ULL)), ((u64)(0x013d3e2388029bb4LL)), 
((u64)(0x3b6503c3faa82a03LL)), ((u64)(0x018c8dac6a0342a2LL)), ((u64)(0xca3e44b4f9523484ULL)), ((u64)(0x01efb1178484134aLL)), ((u64)(0xbe66eaf11bd360d2ULL)), ((u64)(0x0135ceaeb2d28c0eLL)), ((u64)(0x6e00a5ad62c83907LL)), ((u64)(0x0183425a5f872f12LL)), ((u64)(0x0980cf18bb7a4749LL)), ((u64)(0x01e412f0f768fad7LL)), ((u64)(0x65f0816f752c6c8dLL)), ((u64)(0x012e8bd69aa19cc6LL)), ((u64)(0xff6ca1cb527787b1ULL)), ((u64)(0x017a2ecc414a03f7LL)), ((u64)(0xff47ca3e2715699dULL)), ((u64)(0x01d8ba7f519c84f5LL)), 
((u64)(0xbf8cde66d86d6202ULL)), ((u64)(0x0127748f9301d319LL)), ((u64)(0x2f7016008e88ba83LL)), ((u64)(0x017151b377c247e0LL)), ((u64)(0x3b4c1b80b22ae923LL)), ((u64)(0x01cda62055b2d9d8LL)), ((u64)(0x250f91306f5ad1b6LL)), ((u64)(0x012087d4358fc827LL)), ((u64)(0xee53757c8b318623ULL)), ((u64)(0x0168a9c942f3ba30LL)), ((u64)(0x29e852dbadfde7acLL)), ((u64)(0x01c2d43b93b0a8bdLL)), ((u64)(0x3a3133c94cbeb0ccLL)), ((u64)(0x0119c4a53c4e6976LL)), ((u64)(0xc8bd80bb9fee5cffULL)), ((u64)(0x016035ce8b6203d3LL)), 
((u64)(0xbaece0ea87e9f43eULL)), ((u64)(0x01b843422e3a84c8LL)), ((u64)(0x74d40c9294f238a7LL)), ((u64)(0x01132a095ce492fdLL)), ((u64)(0xd2090fb73a2ec6d1ULL)), ((u64)(0x0157f48bb41db7bcLL)), ((u64)(0x068b53a508ba7885LL)), ((u64)(0x01adf1aea12525acLL)), ((u64)(0x8417144725748b53ULL)), ((u64)(0x010cb70d24b7378bLL)), ((u64)(0x651cd958eed1ae28LL)), ((u64)(0x014fe4d06de5056eLL)), ((u64)(0xfe640faf2a8619b2ULL)), ((u64)(0x01a3de04895e46c9LL)), ((u64)(0x3efe89cd7a93d00fLL)), ((u64)(0x01066ac2d5daec3eLL)), 
((u64)(0xcebe2c40d938c413ULL)), ((u64)(0x014805738b51a74dLL)), ((u64)(0x426db7510f86f518LL)), ((u64)(0x019a06d06e261121LL)), ((u64)(0xc9849292a9b4592fULL)), ((u64)(0x0100444244d7cab4LL)), ((u64)(0xfbe5b73754216f7aULL)), ((u64)(0x01405552d60dbd61LL)), ((u64)(0x7adf25052929cb59LL)), ((u64)(0x01906aa78b912cbaLL)), ((u64)(0x1996ee4673743e2fLL)), ((u64)(0x01f485516e7577e9LL)), ((u64)(0xaffe54ec0828a6ddULL)), ((u64)(0x0138d352e5096af1LL)), ((u64)(0x1bfdea270a32d095LL)), ((u64)(0x018708279e4bc5aeLL)), 
((u64)(0xa2fd64b0ccbf84baULL)), ((u64)(0x01e8ca3185deb719LL)), ((u64)(0x05de5eee7ff7b2f4LL)), ((u64)(0x01317e5ef3ab3270LL)), ((u64)(0x0755f6aa1ff59fb1LL)), ((u64)(0x017dddf6b095ff0cLL)), ((u64)(0x092b7454a7f3079eLL)), ((u64)(0x01dd55745cbb7ecfLL)), ((u64)(0x65bb28b4e8f7e4c3LL)), ((u64)(0x012a5568b9f52f41LL)), ((u64)(0xbf29f2e22335ddf3ULL)), ((u64)(0x0174eac2e8727b11LL)), ((u64)(0x2ef46f9aac035570LL)), ((u64)(0x01d22573a28f19d6LL)), ((u64)(0xdd58c5c0ab821566ULL)), ((u64)(0x0123576845997025LL)), 
((u64)(0x54aef730d6629ac0LL)), ((u64)(0x016c2d4256ffcc2fLL)), ((u64)(0x29dab4fd0bfb4170LL)), ((u64)(0x01c73892ecbfbf3bLL)), ((u64)(0xfa28b11e277d08e6ULL)), ((u64)(0x011c835bd3f7d784LL)), ((u64)(0x38b2dd65b15c4b1fLL)), ((u64)(0x0163a432c8f5cd66LL)), ((u64)(0xc6df94bf1db35de7ULL)), ((u64)(0x01bc8d3f7b3340bfLL)), ((u64)(0xdc4bbcf772901ab0ULL)), ((u64)(0x0115d847ad000877LL)), ((u64)(0xd35eac354f34215cULL)), ((u64)(0x015b4e5998400a95LL)), ((u64)(0x48365742a30129b4LL)), ((u64)(0x01b221effe500d3bLL)), 
((u64)(0x0d21f689a5e0ba10LL)), ((u64)(0x010f5535fef20845LL)), ((u64)(0x506a742c0f58e894LL)), ((u64)(0x01532a837eae8a56LL)), ((u64)(0xe4851137132f22b9ULL)), ((u64)(0x01a7f5245e5a2cebLL)), ((u64)(0x6ed32ac26bfd75b4LL)), ((u64)(0x0108f936baf85c13LL)), ((u64)(0x4a87f57306fcd321LL)), ((u64)(0x014b378469b67318LL)), ((u64)(0x5d29f2cfc8bc07e9LL)), ((u64)(0x019e056584240fdeLL)), ((u64)(0xfa3a37c1dd7584f1ULL)), ((u64)(0x0102c35f729689eaLL)), ((u64)(0xb8c8c5b254d2e62eULL)), ((u64)(0x014374374f3c2c65LL)), 
((u64)(0x26faf71eea079fb9LL)), ((u64)(0x01945145230b377fLL)), ((u64)(0xf0b9b4e6a48987a8ULL)), ((u64)(0x01f965966bce055eLL)), ((u64)(0x5674111026d5f4c9LL)), ((u64)(0x013bdf7e0360c35bLL)), ((u64)(0x2c111554308b71fbLL)), ((u64)(0x018ad75d8438f432LL)), ((u64)(0xb7155aa93cae4e7aULL)), ((u64)(0x01ed8d34e547313eLL)), ((u64)(0x326d58a9c5ecf10cLL)), ((u64)(0x013478410f4c7ec7LL)), ((u64)(0xff08aed437682d4fULL)), ((u64)(0x01819651531f9e78LL)), ((u64)(0x3ecada89454238a3LL)), ((u64)(0x01e1fbe5a7e78617LL)), 
((u64)(0x873ec895cb496366ULL)), ((u64)(0x012d3d6f88f0b3ceLL)), ((u64)(0x290e7abb3e1bbc3fLL)), ((u64)(0x01788ccb6b2ce0c2LL)), ((u64)(0xb352196a0da2ab4fULL)), ((u64)(0x01d6affe45f818f2LL)), ((u64)(0xb0134fe24885ab11ULL)), ((u64)(0x01262dfeebbb0f97LL)), ((u64)(0x9c1823dadaa715d6ULL)), ((u64)(0x016fb97ea6a9d37dLL)), ((u64)(0x031e2cd19150db4bLL)), ((u64)(0x01cba7de5054485dLL)), ((u64)(0x21f2dc02fad2890fLL)), ((u64)(0x011f48eaf234ad3aLL)), ((u64)(0xaa6f9303b9872b53ULL)), ((u64)(0x01671b25aec1d888LL)), 
((u64)(0xd50b77c4a7e8f628ULL)), ((u64)(0x01c0e1ef1a724eaaLL)), ((u64)(0xc5272adae8f199d9ULL)), ((u64)(0x01188d357087712aLL)), ((u64)(0x7670f591a32e004fLL)), ((u64)(0x015eb082cca94d75LL)), ((u64)(0xd40d32f60bf98063ULL)), ((u64)(0x01b65ca37fd3a0d2LL)), ((u64)(0xc4883fd9c77bf03eULL)), ((u64)(0x0111f9e62fe44483LL)), ((u64)(0xb5aa4fd0395aec4dULL)), ((u64)(0x0156785fbbdd55a4LL)), ((u64)(0xe314e3c447b1a760ULL)), ((u64)(0x01ac1677aad4ab0dLL)), ((u64)(0xaded0e5aaccf089cULL)), ((u64)(0x010b8e0acac4eae8LL)), 
((u64)(0xd96851f15802cac3ULL)), ((u64)(0x014e718d7d7625a2LL)), ((u64)(0x8fc2666dae037d74ULL)), ((u64)(0x01a20df0dcd3af0bLL)), ((u64)(0x39d980048cc22e68LL)), ((u64)(0x010548b68a044d67LL)), ((u64)(0x084fe005aff2ba03LL)), ((u64)(0x01469ae42c8560c1LL)), ((u64)(0x4a63d8071bef6883LL)), ((u64)(0x0198419d37a6b8f1LL)), ((u64)(0x9cfcce08e2eb42a4ULL)), ((u64)(0x01fe52048590672dLL)), ((u64)(0x821e00c58dd309a7ULL)), ((u64)(0x013ef342d37a407cLL)), ((u64)(0xa2a580f6f147cc10ULL)), ((u64)(0x018eb0138858d09bLL)), 
((u64)(0x8b4ee134ad99bf15ULL)), ((u64)(0x01f25c186a6f04c2LL)), ((u64)(0x97114cc0ec80176dULL)), ((u64)(0x0137798f428562f9LL)), ((u64)(0xfcd59ff127a01d48ULL)), ((u64)(0x018557f31326bbb7LL)), ((u64)(0xfc0b07ed7188249aULL)), ((u64)(0x01e6adefd7f06aa5LL)), ((u64)(0xbd86e4f466f516e0ULL)), ((u64)(0x01302cb5e6f642a7LL)), ((u64)(0xace89e3180b25c98ULL)), ((u64)(0x017c37e360b3d351LL)), ((u64)(0x1822c5bde0def3beLL)), ((u64)(0x01db45dc38e0c826LL)), ((u64)(0xcf15bb96ac8b5857ULL)), ((u64)(0x01290ba9a38c7d17LL)), 
((u64)(0xc2db2a7c57ae2e6dULL)), ((u64)(0x01734e940c6f9c5dLL)), ((u64)(0x3391f51b6d99ba08LL)), ((u64)(0x01d022390f8b8375LL)), ((u64)(0x403b393124801445LL)), ((u64)(0x01221563a9b73229LL)), ((u64)(0x904a077d6da01956ULL)), ((u64)(0x016a9abc9424feb3LL)), ((u64)(0x745c895cc9081facLL)), ((u64)(0x01c5416bb92e3e60LL)), ((u64)(0x48b9d5d9fda513cbLL)), ((u64)(0x011b48e353bce6fcLL)), ((u64)(0x5ae84b507d0e58beLL)), ((u64)(0x01621b1c28ac20bbLL)), ((u64)(0x31a25e249c51eeeeLL)), ((u64)(0x01baa1e332d728eaLL)), 
((u64)(0x5f057ad6e1b33554LL)), ((u64)(0x0114a52dffc67992LL)), ((u64)(0xf6c6d98c9a2002aaULL)), ((u64)(0x0159ce797fb817f6LL)), ((u64)(0xb4788fefc0a80354ULL)), ((u64)(0x01b04217dfa61df4LL)), ((u64)(0xf0cb59f5d8690214ULL)), ((u64)(0x010e294eebc7d2b8LL)), ((u64)(0x2cfe30734e83429aLL)), ((u64)(0x0151b3a2a6b9c767LL)), ((u64)(0xf83dbc9022241340ULL)), ((u64)(0x01a6208b50683940LL)), ((u64)(0x9b2695da15568c08ULL)), ((u64)(0x0107d457124123c8LL)), ((u64)(0xc1f03b509aac2f0aULL)), ((u64)(0x0149c96cd6d16cbaLL)), 
((u64)(0x726c4a24c1573acdLL)), ((u64)(0x019c3bc80c85c7e9LL)), ((u64)(0xe783ae56f8d684c0ULL)), ((u64)(0x0101a55d07d39cf1LL)), ((u64)(0x616499ecb70c25f0LL)), ((u64)(0x01420eb449c8842eLL)), ((u64)(0xf9bdc067e4cf2f6cULL)), ((u64)(0x019292615c3aa539LL)), ((u64)(0x782d3081de02fb47LL)), ((u64)(0x01f736f9b3494e88LL)), ((u64)(0x4b1c3e512ac1dd0cLL)), ((u64)(0x013a825c100dd115LL)), ((u64)(0x9de34de57572544fULL)), ((u64)(0x018922f31411455aLL)), ((u64)(0x455c215ed2cee963LL)), ((u64)(0x01eb6bafd91596b1LL)), 
((u64)(0xcb5994db43c151deULL)), ((u64)(0x0133234de7ad7e2eLL)), ((u64)(0x7e2ffa1214b1a655LL)), ((u64)(0x017fec216198ddbaLL)), ((u64)(0x1dbbf89699de0febLL)), ((u64)(0x01dfe729b9ff1529LL)), ((u64)(0xb2957b5e202ac9f3ULL)), ((u64)(0x012bf07a143f6d39LL)), ((u64)(0x1f3ada35a8357c6fLL)), ((u64)(0x0176ec98994f4888LL)), ((u64)(0x270990c31242db8bLL)), ((u64)(0x01d4a7bebfa31aaaLL)), ((u64)(0x5865fa79eb69c937LL)), ((u64)(0x0124e8d737c5f0aaLL)), ((u64)(0xee7f791866443b85ULL)), ((u64)(0x016e230d05b76cd4LL)), 
((u64)(0x2a1f575e7fd54a66LL)), ((u64)(0x01c9abd04725480aLL)), ((u64)(0x5a53969b0fe54e80LL)), ((u64)(0x011e0b622c774d06LL)), ((u64)(0xf0e87c41d3dea220ULL)), ((u64)(0x01658e3ab7952047LL)), ((u64)(0xed229b5248d64aa8ULL)), ((u64)(0x01bef1c9657a6859LL)), ((u64)(0x3435a1136d85eea9LL)), ((u64)(0x0117571ddf6c8138LL)), ((u64)(0x4143095848e76a53LL)), ((u64)(0x015d2ce55747a186LL)), ((u64)(0xd193cbae5b2144e8ULL)), ((u64)(0x01b4781ead1989e7LL)), ((u64)(0xe2fc5f4cf8f4cb11ULL)), ((u64)(0x0110cb132c2ff630LL)), 
((u64)(0x1bbb77203731fdd5LL)), ((u64)(0x0154fdd7f73bf3bdLL)), ((u64)(0x62aa54e844fe7d4aLL)), ((u64)(0x01aa3d4df50af0acLL)), ((u64)(0xbdaa75112b1f0e4eULL)), ((u64)(0x010a6650b926d66bLL)), ((u64)(0xad15125575e6d1e2ULL)), ((u64)(0x014cffe4e7708c06LL)), ((u64)(0x585a56ead360865bLL)), ((u64)(0x01a03fde214caf08LL)), ((u64)(0x37387652c41c53f8LL)), ((u64)(0x010427ead4cfed65LL)), ((u64)(0x850693e7752368f7ULL)), ((u64)(0x014531e58a03e8beLL)), ((u64)(0x264838e1526c4334LL)), ((u64)(0x01967e5eec84e2eeLL)), 
((u64)(0xafda4719a7075402ULL)), ((u64)(0x01fc1df6a7a61ba9LL)), ((u64)(0x0de86c7008649481LL)), ((u64)(0x013d92ba28c7d14aLL)), ((u64)(0x9162878c0a7db9a1ULL)), ((u64)(0x018cf768b2f9c59cLL)), ((u64)(0xb5bb296f0d1d280aULL)), ((u64)(0x01f03542dfb83703LL)), ((u64)(0x5194f9e568323906LL)), ((u64)(0x01362149cbd32262LL)), ((u64)(0xe5fa385ec23ec747ULL)), ((u64)(0x0183a99c3ec7eafaLL)), ((u64)(0x9f78c67672ce7919ULL)), ((u64)(0x01e494034e79e5b9LL)), ((u64)(0x03ab7c0a07c10bb0LL)), ((u64)(0x012edc82110c2f94LL)), 
((u64)(0x04965b0c89b14e9cLL)), ((u64)(0x017a93a2954f3b79LL)), ((u64)(0x45bbf1cfac1da243LL)), ((u64)(0x01d9388b3aa30a57LL)), ((u64)(0x8b957721cb92856aULL)), ((u64)(0x0127c35704a5e676LL)), ((u64)(0x2e7ad4ea3e7726c4LL)), ((u64)(0x0171b42cc5cf6014LL)), ((u64)(0x3a198a24ce14f075LL)), ((u64)(0x01ce2137f7433819LL)), ((u64)(0xc44ff65700cd1649ULL)), ((u64)(0x0120d4c2fa8a030fLL)), ((u64)(0xb563f3ecc1005bdbULL)), ((u64)(0x016909f3b92c83d3LL)), ((u64)(0xa2bcf0e7f14072d2ULL)), ((u64)(0x01c34c70a777a4c8LL)), 
((u64)(0x65b61690f6c847c3LL)), ((u64)(0x011a0fc668aac6fdLL)), ((u64)(0xbf239c35347a59b4ULL)), ((u64)(0x016093b802d578bcLL)), ((u64)(0xeeec83428198f021ULL)), ((u64)(0x01b8b8a6038ad6ebLL)), ((u64)(0x7553d20990ff9615LL)), ((u64)(0x01137367c236c653LL)), ((u64)(0x52a8c68bf53f7b9aLL)), ((u64)(0x01585041b2c477e8LL)), ((u64)(0x6752f82ef28f5a81LL)), ((u64)(0x01ae64521f7595e2LL)), ((u64)(0x8093db1d57999890ULL)), ((u64)(0x010cfeb353a97dadLL)), ((u64)(0xe0b8d1e4ad7ffeb4ULL)), ((u64)(0x01503e602893dd18LL)), 
((u64)(0x18e7065dd8dffe62LL)), ((u64)(0x01a44df832b8d45fLL)), ((u64)(0x6f9063faa78bfefdLL)), ((u64)(0x0106b0bb1fb384bbLL)), ((u64)(0x4b747cf9516efebcLL)), ((u64)(0x01485ce9e7a065eaLL)), ((u64)(0xde519c37a5cabe6bULL)), ((u64)(0x019a742461887f64LL)), ((u64)(0x0af301a2c79eb703LL)), ((u64)(0x01008896bcf54f9fLL)), ((u64)(0xcdafc20b798664c4ULL)), ((u64)(0x0140aabc6c32a386LL)), ((u64)(0x811bb28e57e7fdf5ULL)), ((u64)(0x0190d56b873f4c68LL)), ((u64)(0xa1629f31ede1fd72ULL)), ((u64)(0x01f50ac6690f1f82LL)), 
((u64)(0xa4dda37f34ad3e67ULL)), ((u64)(0x013926bc01a973b1LL)), ((u64)(0x0e150c5f01d88e01LL)), ((u64)(0x0187706b0213d09eLL)), ((u64)(0x919a4f76c24eb181ULL)), ((u64)(0x01e94c85c298c4c5LL)), ((u64)(0x7b0071aa39712ef1LL)), ((u64)(0x0131cfd3999f7afbLL)), ((u64)(0x59c08e14c7cd7aadLL)), ((u64)(0x017e43c8800759baLL)), ((u64)(0xf030b199f9c0d958ULL)), ((u64)(0x01ddd4baa0093028LL)), ((u64)(0x961e6f003c1887d7ULL)), ((u64)(0x012aa4f4a405be19LL)), ((u64)(0xfba60ac04b1ea9cdULL)), ((u64)(0x01754e31cd072d9fLL)), 
((u64)(0xfa8f8d705de65440ULL)), ((u64)(0x01d2a1be4048f907LL)), ((u64)(0xfc99b8663aaff4a8ULL)), ((u64)(0x0123a516e82d9ba4LL)), ((u64)(0x3bc0267fc95bf1d2LL)), ((u64)(0x016c8e5ca239028eLL)), ((u64)(0xcab0301fbbb2ee47ULL)), ((u64)(0x01c7b1f3cac74331LL)), ((u64)(0x1eae1e13d54fd4ecLL)), ((u64)(0x011ccf385ebc89ffLL)), ((u64)(0xe659a598caa3ca27ULL)), ((u64)(0x01640306766bac7eLL)), ((u64)(0x9ff00efefd4cbcb1ULL)), ((u64)(0x01bd03c81406979eLL)), ((u64)(0x23f6095f5e4ff5efLL)), ((u64)(0x0116225d0c841ec3LL)), 
((u64)(0xecf38bb735e3f36aULL)), ((u64)(0x015baaf44fa52673LL)), ((u64)(0xe8306ea5035cf045ULL)), ((u64)(0x01b295b1638e7010LL)), ((u64)(0x911e4527221a162bULL)), ((u64)(0x010f9d8ede39060aLL)), ((u64)(0x3565d670eaa09bb6LL)), ((u64)(0x015384f295c7478dLL)), ((u64)(0x82bf4c0d2548c2a3ULL)), ((u64)(0x01a8662f3b391970LL)), ((u64)(0x51b78f88374d79a6LL)), ((u64)(0x01093fdd8503afe6LL)), ((u64)(0xe625736a4520d810ULL)), ((u64)(0x014b8fd4e6449bdfLL)), ((u64)(0xdfaed044d6690e14ULL)), ((u64)(0x019e73ca1fd5c2d7LL)), ((u64)(0xebcd422b0601a8ccULL)), ((u64)(0x0103085e53e599c6LL)), ((u64)(0xa6c092b5c78212ffULL)), ((u64)(0x0143ca75e8df0038LL)), ((u64)(0xd070b763396297bfULL)), ((u64)(0x0194bd136316c046LL)), ((u64)(0x848ce53c07bb3dafULL)), ((u64)(0x01f9ec583bdc7058LL)), ((u64)(0x52d80f4584d5068dLL)), ((u64)(0x013c33b72569c637LL)), ((u64)(0x278e1316e60a4831LL)), ((u64)(0x018b40a4eec437c5LL))}; // fixed array const
static Array_fixed_u64_584 _const_strconv__pow5_inv_split_64_x = {((u64)(0x0000000000000001)), ((u64)(0x0400000000000000LL)), ((u64)(0x3333333333333334LL)), ((u64)(0x0333333333333333LL)), ((u64)(0x28f5c28f5c28f5c3LL)), ((u64)(0x028f5c28f5c28f5cLL)), ((u64)(0xed916872b020c49cULL)), ((u64)(0x020c49ba5e353f7cLL)), ((u64)(0xaf4f0d844d013a93ULL)), ((u64)(0x0346dc5d63886594LL)), ((u64)(0x8c3f3e0370cdc876ULL)), ((u64)(0x029f16b11c6d1e10LL)), ((u64)(0xd698fe69270b06c5ULL)), ((u64)(0x0218def416bdb1a6LL)), ((u64)(0xf0f4ca41d811a46eULL)), ((u64)(0x035afe535795e90aLL)), 
((u64)(0xf3f70834acdae9f1ULL)), ((u64)(0x02af31dc4611873bLL)), ((u64)(0x5cc5a02a23e254c1LL)), ((u64)(0x0225c17d04dad296LL)), ((u64)(0xfad5cd10396a2135ULL)), ((u64)(0x036f9bfb3af7b756LL)), ((u64)(0xfbde3da69454e75eULL)), ((u64)(0x02bfaffc2f2c92abLL)), ((u64)(0x2fe4fe1edd10b918LL)), ((u64)(0x0232f33025bd4223LL)), ((u64)(0x4ca19697c81ac1bfLL)), ((u64)(0x0384b84d092ed038LL)), ((u64)(0x3d4e1213067bce33LL)), ((u64)(0x02d09370d4257360LL)), ((u64)(0x643e74dc052fd829LL)), ((u64)(0x024075f3dceac2b3LL)), 
((u64)(0x6d30baf9a1e626a7LL)), ((u64)(0x039a5652fb113785LL)), ((u64)(0x2426fbfae7eb5220LL)), ((u64)(0x02e1dea8c8da92d1LL)), ((u64)(0x1cebfcc8b9890e80LL)), ((u64)(0x024e4bba3a487574LL)), ((u64)(0x94acc7a78f41b0ccULL)), ((u64)(0x03b07929f6da5586LL)), ((u64)(0xaa23d2ec729af3d7ULL)), ((u64)(0x02f394219248446bLL)), ((u64)(0xbb4fdbf05baf2979ULL)), ((u64)(0x025c768141d369efLL)), ((u64)(0xc54c931a2c4b758dULL)), ((u64)(0x03c7240202ebdcb2LL)), ((u64)(0x9dd6dc14f03c5e0bULL)), ((u64)(0x0305b66802564a28LL)), 
((u64)(0x4b1249aa59c9e4d6LL)), ((u64)(0x026af8533511d4edLL)), ((u64)(0x44ea0f76f60fd489LL)), ((u64)(0x03de5a1ebb4fbb15LL)), ((u64)(0x6a54d92bf80caa07LL)), ((u64)(0x0318481895d96277LL)), ((u64)(0x21dd7a89933d54d2LL)), ((u64)(0x0279d346de4781f9LL)), ((u64)(0x362f2a75b8622150LL)), ((u64)(0x03f61ed7ca0c0328LL)), ((u64)(0xf825bb91604e810dULL)), ((u64)(0x032b4bdfd4d668ecLL)), ((u64)(0xc684960de6a5340bULL)), ((u64)(0x0289097fdd7853f0LL)), ((u64)(0xd203ab3e521dc33cULL)), ((u64)(0x02073accb12d0ff3LL)), 
((u64)(0xe99f7863b696052cULL)), ((u64)(0x033ec47ab514e652LL)), ((u64)(0x87b2c6b62bab3757ULL)), ((u64)(0x02989d2ef743eb75LL)), ((u64)(0xd2f56bc4efbc2c45ULL)), ((u64)(0x0213b0f25f69892aLL)), ((u64)(0x1e55793b192d13a2LL)), ((u64)(0x0352b4b6ff0f41deLL)), ((u64)(0x4b77942f475742e8LL)), ((u64)(0x02a8909265a5ce4bLL)), ((u64)(0xd5f9435905df68baULL)), ((u64)(0x022073a8515171d5LL)), ((u64)(0x565b9ef4d6324129LL)), ((u64)(0x03671f73b54f1c89LL)), ((u64)(0xdeafb25d78283421ULL)), ((u64)(0x02b8e5f62aa5b06dLL)), 
((u64)(0x188c8eb12cecf681LL)), ((u64)(0x022d84c4eeeaf38bLL)), ((u64)(0x8dadb11b7b14bd9bULL)), ((u64)(0x037c07a17e44b8deLL)), ((u64)(0x7157c0e2c8dd647cLL)), ((u64)(0x02c99fb46503c718LL)), ((u64)(0x8ddfcd823a4ab6caULL)), ((u64)(0x023ae629ea696c13LL)), ((u64)(0x1632e269f6ddf142LL)), ((u64)(0x0391704310a8acecLL)), ((u64)(0x44f581ee5f17f435LL)), ((u64)(0x02dac035a6ed5723LL)), ((u64)(0x372ace584c1329c4LL)), ((u64)(0x024899c4858aac1cLL)), ((u64)(0xbeaae3c079b842d3ULL)), ((u64)(0x03a75c6da27779c6LL)), 
((u64)(0x6555830061603576LL)), ((u64)(0x02ec49f14ec5fb05LL)), ((u64)(0xb7779c004de6912bULL)), ((u64)(0x0256a18dd89e626aLL)), ((u64)(0xf258f99a163db512ULL)), ((u64)(0x03bdcf495a9703ddLL)), ((u64)(0x5b7a614811caf741LL)), ((u64)(0x02fe3f6de212697eLL)), ((u64)(0xaf951aa00e3bf901ULL)), ((u64)(0x0264ff8b1b41edfeLL)), ((u64)(0x7f54f7667d2cc19bLL)), ((u64)(0x03d4cc11c5364997LL)), ((u64)(0x32aa5f8530f09ae3LL)), ((u64)(0x0310a3416a91d479LL)), ((u64)(0xf55519375a5a1582ULL)), ((u64)(0x0273b5cdeedb1060LL)), 
((u64)(0xbbbb5b8bc3c3559dULL)), ((u64)(0x03ec56164af81a34LL)), ((u64)(0x2fc916096969114aLL)), ((u64)(0x03237811d593482aLL)), ((u64)(0x596dab3ababa743cLL)), ((u64)(0x0282c674aadc39bbLL)), ((u64)(0x478aef622efb9030LL)), ((u64)(0x0202385d557cfafcLL)), ((u64)(0xd8de4bd04b2c19e6ULL)), ((u64)(0x0336c0955594c4c6LL)), ((u64)(0xad7ea30d08f014b8ULL)), ((u64)(0x029233aaaadd6a38LL)), ((u64)(0x24654f3da0c01093LL)), ((u64)(0x020e8fbbbbe454faLL)), ((u64)(0x3a3bb1fc346680ebLL)), ((u64)(0x034a7f92c63a2190LL)), 
((u64)(0x94fc8e635d1ecd89ULL)), ((u64)(0x02a1ffa89e94e7a6LL)), ((u64)(0xaa63a51c4a7f0ad4ULL)), ((u64)(0x021b32ed4baa52ebLL)), ((u64)(0xdd6c3b607731aaedULL)), ((u64)(0x035eb7e212aa1e45LL)), ((u64)(0x1789c919f8f488bdLL)), ((u64)(0x02b22cb4dbbb4b6bLL)), ((u64)(0xac6e3a7b2d906d64ULL)), ((u64)(0x022823c3e2fc3c55LL)), ((u64)(0x13e390c515b3e23aLL)), ((u64)(0x03736c6c9e606089LL)), ((u64)(0xdcb60d6a77c31b62ULL)), ((u64)(0x02c2bd23b1e6b3a0LL)), ((u64)(0x7d5e7121f968e2b5LL)), ((u64)(0x0235641c8e52294dLL)), 
((u64)(0xc8971b698f0e3787ULL)), ((u64)(0x0388a02db0837548LL)), ((u64)(0xa078e2bad8d82c6cULL)), ((u64)(0x02d3b357c0692aa0LL)), ((u64)(0xe6c71bc8ad79bd24ULL)), ((u64)(0x0242f5dfcd20eee6LL)), ((u64)(0x0ad82c7448c2c839LL)), ((u64)(0x039e5632e1ce4b0bLL)), ((u64)(0x3be023903a356cfaLL)), ((u64)(0x02e511c24e3ea26fLL)), ((u64)(0x2fe682d9c82abd95LL)), ((u64)(0x0250db01d8321b8cLL)), ((u64)(0x4ca4048fa6aac8eeLL)), ((u64)(0x03b4919c8d1cf8e0LL)), ((u64)(0x3d5003a61eef0725LL)), ((u64)(0x02f6dae3a4172d80LL)), 
((u64)(0x9773361e7f259f51ULL)), ((u64)(0x025f1582e9ac2466LL)), ((u64)(0x8beb89ca6508fee8ULL)), ((u64)(0x03cb559e42ad070aLL)), ((u64)(0x6fefa16eb73a6586LL)), ((u64)(0x0309114b688a6c08LL)), ((u64)(0xf3261abef8fb846bULL)), ((u64)(0x026da76f86d52339LL)), ((u64)(0x51d691318e5f3a45LL)), ((u64)(0x03e2a57f3e21d1f6LL)), ((u64)(0x0e4540f471e5c837LL)), ((u64)(0x031bb798fe8174c5LL)), ((u64)(0xd8376729f4b7d360ULL)), ((u64)(0x027c92e0cb9ac3d0LL)), ((u64)(0xf38bd84321261effULL)), ((u64)(0x03fa849adf5e061aLL)), 
((u64)(0x293cad0280eb4bffLL)), ((u64)(0x032ed07be5e4d1afLL)), ((u64)(0xedca240200bc3cccULL)), ((u64)(0x028bd9fcb7ea4158LL)), ((u64)(0xbe3b50019a3030a4ULL)), ((u64)(0x02097b309321cde0LL)), ((u64)(0xc9f88002904d1a9fULL)), ((u64)(0x03425eb41e9c7c9aLL)), ((u64)(0x3b2d3335403daee6LL)), ((u64)(0x029b7ef67ee396e2LL)), ((u64)(0x95bdc291003158b8ULL)), ((u64)(0x0215ff2b98b6124eLL)), ((u64)(0x892f9db4cd1bc126ULL)), ((u64)(0x035665128df01d4aLL)), ((u64)(0x07594af70a7c9a85LL)), ((u64)(0x02ab840ed7f34aa2LL)), 
((u64)(0x6c476f2c0863aed1LL)), ((u64)(0x0222d00bdff5d54eLL)), ((u64)(0x13a57eacda3917b4LL)), ((u64)(0x036ae67966562217LL)), ((u64)(0x0fb7988a482dac90LL)), ((u64)(0x02bbeb9451de81acLL)), ((u64)(0xd95fad3b6cf156daULL)), ((u64)(0x022fefa9db1867bcLL)), ((u64)(0xf565e1f8ae4ef15cULL)), ((u64)(0x037fe5dc91c0a5faLL)), ((u64)(0x911e4e608b725ab0ULL)), ((u64)(0x02ccb7e3a7cd5195LL)), ((u64)(0xda7ea51a0928488dULL)), ((u64)(0x023d5fe9530aa7aaLL)), ((u64)(0xf7310829a8407415ULL)), ((u64)(0x039566421e7772aaLL)), 
((u64)(0x2c2739baed005cdeLL)), ((u64)(0x02ddeb68185f8eefLL)), ((u64)(0xbcec2e2f24004a4bULL)), ((u64)(0x024b22b9ad193f25LL)), ((u64)(0x94ad16b1d333aa11ULL)), ((u64)(0x03ab6ac2ae8ecb6fLL)), ((u64)(0xaa241227dc2954dbULL)), ((u64)(0x02ef889bbed8a2bfLL)), ((u64)(0x54e9a81fe35443e2LL)), ((u64)(0x02593a163246e899LL)), ((u64)(0x2175d9cc9eed396aLL)), ((u64)(0x03c1f689ea0b0dc2LL)), ((u64)(0xe7917b0a18bdc788ULL)), ((u64)(0x03019207ee6f3e34LL)), ((u64)(0xb9412f3b46fe393aULL)), ((u64)(0x0267a8065858fe90LL)), 
((u64)(0xf535185ed7fd285cULL)), ((u64)(0x03d90cd6f3c1974dLL)), ((u64)(0xc42a79e57997537dULL)), ((u64)(0x03140a458fce12a4LL)), ((u64)(0x03552e512e12a931LL)), ((u64)(0x02766e9e0ca4dbb7LL)), ((u64)(0x9eeeb081e3510eb4ULL)), ((u64)(0x03f0b0fce107c5f1LL)), ((u64)(0x4bf226ce4f740bc3LL)), ((u64)(0x0326f3fd80d304c1LL)), ((u64)(0xa3281f0b72c33c9cULL)), ((u64)(0x02858ffe00a8d09aLL)), ((u64)(0x1c2018d5f568fd4aLL)), ((u64)(0x020473319a20a6e2LL)), ((u64)(0xf9ccf48988a7fba9ULL)), ((u64)(0x033a51e8f69aa49cLL)), 
((u64)(0xfb0a5d3ad3b99621ULL)), ((u64)(0x02950e53f87bb6e3LL)), ((u64)(0x2f3b7dc8a96144e7LL)), ((u64)(0x0210d8432d2fc583LL)), ((u64)(0xe52bfc7442353b0cULL)), ((u64)(0x034e26d1e1e608d1LL)), ((u64)(0xb756639034f76270ULL)), ((u64)(0x02a4ebdb1b1e6d74LL)), ((u64)(0x2c451c735d92b526LL)), ((u64)(0x021d897c15b1f12aLL)), ((u64)(0x13a1c71efc1deea3LL)), ((u64)(0x0362759355e981ddLL)), ((u64)(0x761b05b2634b2550LL)), ((u64)(0x02b52adc44bace4aLL)), ((u64)(0x91af37c1e908eaa6ULL)), ((u64)(0x022a88b036fbd83bLL)), 
((u64)(0x82b1f2cfdb417770ULL)), ((u64)(0x03774119f192f392LL)), ((u64)(0xcef4c23fe29ac5f3ULL)), ((u64)(0x02c5cdae5adbf60eLL)), ((u64)(0x3f2a34ffe87bd190LL)), ((u64)(0x0237d7beaf165e72LL)), ((u64)(0x984387ffda5fb5b2ULL)), ((u64)(0x038c8c644b56fd83LL)), ((u64)(0xe0360666484c915bULL)), ((u64)(0x02d6d6b6a2abfe02LL)), ((u64)(0x802b3851d3707449ULL)), ((u64)(0x024578921bbccb35LL)), ((u64)(0x99dec082ebe72075ULL)), ((u64)(0x03a25a835f947855LL)), ((u64)(0xae4bcd358985b391ULL)), ((u64)(0x02e8486919439377LL)), 
((u64)(0xbea30a913ad15c74ULL)), ((u64)(0x02536d20e102dc5fLL)), ((u64)(0xfdd1aa81f7b560b9ULL)), ((u64)(0x03b8ae9b019e2d65LL)), ((u64)(0x97daeece5fc44d61ULL)), ((u64)(0x02fa2548ce182451LL)), ((u64)(0xdfe258a51969d781ULL)), ((u64)(0x0261b76d71ace9daLL)), ((u64)(0x996a276e8f0fbf34ULL)), ((u64)(0x03cf8be24f7b0fc4LL)), ((u64)(0xe121b9253f3fcc2aULL)), ((u64)(0x030c6fe83f95a636LL)), ((u64)(0xb41afa8432997022ULL)), ((u64)(0x02705986994484f8LL)), ((u64)(0xecf7f739ea8f19cfULL)), ((u64)(0x03e6f5a4286da18dLL)), 
((u64)(0x23f99294bba5ae40LL)), ((u64)(0x031f2ae9b9f14e0bLL)), ((u64)(0x4ffadbaa2fb7be99LL)), ((u64)(0x027f5587c7f43e6fLL)), ((u64)(0x7ff7c5dd1925fdc2LL)), ((u64)(0x03feef3fa6539718LL)), ((u64)(0xccc637e4141e649bULL)), ((u64)(0x033258ffb842df46LL)), ((u64)(0xd704f983434b83afULL)), ((u64)(0x028ead9960357f6bLL)), ((u64)(0x126a6135cf6f9c8cLL)), ((u64)(0x020bbe144cf79923LL)), ((u64)(0x83dd685618b29414ULL)), ((u64)(0x0345fced47f28e9eLL)), ((u64)(0x9cb12044e08edcddULL)), ((u64)(0x029e63f1065ba54bLL)), 
((u64)(0x16f419d0b3a57d7dLL)), ((u64)(0x02184ff405161dd6LL)), ((u64)(0x8b20294dec3bfbfbULL)), ((u64)(0x035a19866e89c956LL)), ((u64)(0x3c19baa4bcfcc996LL)), ((u64)(0x02ae7ad1f207d445LL)), ((u64)(0xc9ae2eea30ca3adfULL)), ((u64)(0x02252f0e5b39769dLL)), ((u64)(0x0f7d17dd1add2afdLL)), ((u64)(0x036eb1b091f58a96LL)), ((u64)(0x3f97464a7be42264LL)), ((u64)(0x02bef48d41913babLL)), ((u64)(0xcc790508631ce850ULL)), ((u64)(0x02325d3dce0dc955LL)), ((u64)(0xe0c1a1a704fb0d4dULL)), ((u64)(0x0383c862e3494222LL)), 
((u64)(0x4d67b4859d95a43eLL)), ((u64)(0x02cfd3824f6dce82LL)), ((u64)(0x711fc39e17aae9cbLL)), ((u64)(0x023fdc683f8b0b9bLL)), ((u64)(0xe832d2968c44a945ULL)), ((u64)(0x039960a6cc11ac2bLL)), ((u64)(0xecf575453d03ba9eULL)), ((u64)(0x02e11a1f09a7bcefLL)), ((u64)(0x572ac4376402fbb1LL)), ((u64)(0x024dae7f3aec9726LL)), ((u64)(0x58446d256cd192b5LL)), ((u64)(0x03af7d985e47583dLL)), ((u64)(0x79d0575123dadbc4LL)), ((u64)(0x02f2cae04b6c4697LL)), ((u64)(0x94a6ac40e97be303ULL)), ((u64)(0x025bd5803c569edfLL)), 
((u64)(0x8771139b0f2c9e6cULL)), ((u64)(0x03c62266c6f0fe32LL)), ((u64)(0x9f8da948d8f07ebdULL)), ((u64)(0x0304e85238c0cb5bLL)), ((u64)(0xe60aedd3e0c06564ULL)), ((u64)(0x026a5374fa33d5e2LL)), ((u64)(0xa344afb9679a3bd2ULL)), ((u64)(0x03dd5254c3862304LL)), ((u64)(0xe903bfc78614fca8ULL)), ((u64)(0x031775109c6b4f36LL)), ((u64)(0xba6966393810ca20ULL)), ((u64)(0x02792a73b055d8f8LL)), ((u64)(0x2a423d2859b4769aLL)), ((u64)(0x03f510b91a22f4c1LL)), ((u64)(0xee9b642047c39215ULL)), ((u64)(0x032a73c7481bf700LL)), 
((u64)(0xbee2b680396941aaULL)), ((u64)(0x02885c9f6ce32c00LL)), ((u64)(0xff1bc53361210155ULL)), ((u64)(0x0206b07f8a4f5666LL)), ((u64)(0x31c6085235019bbbLL)), ((u64)(0x033de73276e5570bLL)), ((u64)(0x27d1a041c4014963LL)), ((u64)(0x0297ec285f1ddf3cLL)), ((u64)(0xeca7b367d0010782ULL)), ((u64)(0x021323537f4b18fcLL)), ((u64)(0xadd91f0c8001a59dULL)), ((u64)(0x0351d21f3211c194LL)), ((u64)(0xf17a7f3d3334847eULL)), ((u64)(0x02a7db4c280e3476LL)), ((u64)(0x279532975c2a0398LL)), ((u64)(0x021fe2a3533e905fLL)), 
((u64)(0xd8eeb75893766c26ULL)), ((u64)(0x0366376bb8641a31LL)), ((u64)(0x7a5892ad42c52352LL)), ((u64)(0x02b82c562d1ce1c1LL)), ((u64)(0xfb7a0ef102374f75ULL)), ((u64)(0x022cf044f0e3e7cdLL)), ((u64)(0xc59017e8038bb254ULL)), ((u64)(0x037b1a07e7d30c7cLL)), ((u64)(0x37a67986693c8eaaLL)), ((u64)(0x02c8e19feca8d6caLL)), ((u64)(0xf951fad1edca0bbbULL)), ((u64)(0x023a4e198a20abd4LL)), ((u64)(0x28832ae97c76792bLL)), ((u64)(0x03907cf5a9cddfbbLL)), ((u64)(0x2068ef21305ec756LL)), ((u64)(0x02d9fd9154a4b2fcLL)), 
((u64)(0x19ed8c1a8d189f78LL)), ((u64)(0x0247fe0ddd508f30LL)), ((u64)(0x5caf4690e1c0ff26LL)), ((u64)(0x03a66349621a7eb3LL)), ((u64)(0x4a25d20d81673285LL)), ((u64)(0x02eb82a11b48655cLL)), ((u64)(0x3b5174d79ab8f537LL)), ((u64)(0x0256021a7c39eab0LL)), ((u64)(0x921bee25c45b21f1ULL)), ((u64)(0x03bcd02a605caab3LL)), ((u64)(0xdb498b5169e2818eULL)), ((u64)(0x02fd735519e3bbc2LL)), ((u64)(0x15d46f7454b53472LL)), ((u64)(0x02645c4414b62fcfLL)), ((u64)(0xefba4bed545520b6ULL)), ((u64)(0x03d3c6d35456b2e4LL)), 
((u64)(0xf2fb6ff110441a2bULL)), ((u64)(0x030fd242a9def583LL)), ((u64)(0x8f2f8cc0d9d014efULL)), ((u64)(0x02730e9bbb18c469LL)), ((u64)(0xb1e5ae015c80217fULL)), ((u64)(0x03eb4a92c4f46d75LL)), ((u64)(0xc1848b344a001accULL)), ((u64)(0x0322a20f03f6bdf7LL)), ((u64)(0xce03a2903b3348a3ULL)), ((u64)(0x02821b3f365efe5fLL)), ((u64)(0xd802e873628f6d4fULL)), ((u64)(0x0201af65c518cb7fLL)), ((u64)(0x599e40b89db2487fLL)), ((u64)(0x0335e56fa1c14599LL)), ((u64)(0xe14b66fa17c1d399ULL)), ((u64)(0x029184594e3437adLL)), 
((u64)(0x81091f2e7967dc7aULL)), ((u64)(0x020e037aa4f692f1LL)), ((u64)(0x9b41cb7d8f0c93f6ULL)), ((u64)(0x03499f2aa18a84b5LL)), ((u64)(0xaf67d5fe0c0a0ff8ULL)), ((u64)(0x02a14c221ad536f7LL)), ((u64)(0xf2b977fe70080cc7ULL)), ((u64)(0x021aa34e7bddc592LL)), ((u64)(0x1df58cca4cd9ae0bLL)), ((u64)(0x035dd2172c9608ebLL)), ((u64)(0xe4c470a1d7148b3cULL)), ((u64)(0x02b174df56de6d88LL)), ((u64)(0x83d05a1b1276d5caULL)), ((u64)(0x022790b2abe5246dLL)), ((u64)(0x9fb3c35e83f1560fULL)), ((u64)(0x0372811ddfd50715LL)), 
((u64)(0xb2f635e5365aab3fULL)), ((u64)(0x02c200e4b310d277LL)), ((u64)(0xf591c4b75eaeef66ULL)), ((u64)(0x0234cd83c273db92LL)), ((u64)(0xef4fa125644b18a3ULL)), ((u64)(0x0387af39371fc5b7LL)), ((u64)(0x8c3fb41de9d5ad4fULL)), ((u64)(0x02d2f2942c196af9LL)), ((u64)(0x3cffc34b2177bdd9LL)), ((u64)(0x02425ba9bce12261LL)), ((u64)(0x94cc6bab68bf9628ULL)), ((u64)(0x039d5f75fb01d09bLL)), ((u64)(0x10a38955ed6611b9LL)), ((u64)(0x02e44c5e6267da16LL)), ((u64)(0xda1c6dde5784dafbULL)), ((u64)(0x02503d184eb97b44LL)), 
((u64)(0xf693e2fd58d49191ULL)), ((u64)(0x03b394f3b128c53aLL)), ((u64)(0xc5431bfde0aa0e0eULL)), ((u64)(0x02f610c2f4209dc8LL)), ((u64)(0x6a9c1664b3bb3e72LL)), ((u64)(0x025e73cf29b3b16dLL)), ((u64)(0x10f9bd6dec5eca4fLL)), ((u64)(0x03ca52e50f85e8afLL)), ((u64)(0xda616457f04bd50cULL)), ((u64)(0x03084250d937ed58LL)), ((u64)(0xe1e783798d09773dULL)), ((u64)(0x026d01da475ff113LL)), ((u64)(0x030c058f480f252eLL)), ((u64)(0x03e19c9072331b53LL)), ((u64)(0x68d66ad906728425LL)), ((u64)(0x031ae3a6c1c27c42LL)), 
((u64)(0x8711ef14052869b7ULL)), ((u64)(0x027be952349b969bLL)), ((u64)(0x0b4fe4ecd50d75f2LL)), ((u64)(0x03f97550542c242cLL)), ((u64)(0xa2a650bd773df7f5ULL)), ((u64)(0x032df7737689b689LL)), ((u64)(0xb551da312c31932aULL)), ((u64)(0x028b2c5c5ed49207LL)), ((u64)(0x5ddb14f4235adc22LL)), ((u64)(0x0208f049e576db39LL)), ((u64)(0x2fc4ee536bc49369LL)), ((u64)(0x034180763bf15ec2LL)), ((u64)(0xbfd0bea92303a921ULL)), ((u64)(0x029acd2b63277f01LL)), ((u64)(0x9973cbba8269541aULL)), ((u64)(0x021570ef8285ff34LL)), 
((u64)(0x5bec792a6a42202aLL)), ((u64)(0x0355817f373ccb87LL)), ((u64)(0xe3239421ee9b4cefULL)), ((u64)(0x02aacdff5f63d605LL)), ((u64)(0xb5b6101b25490a59ULL)), ((u64)(0x02223e65e5e97804LL)), ((u64)(0x22bce691d541aa27LL)), ((u64)(0x0369fd6fd64259a1LL)), ((u64)(0xb563eba7ddce21b9ULL)), ((u64)(0x02bb31264501e14dLL)), ((u64)(0xf78322ecb171b494ULL)), ((u64)(0x022f5a850401810aLL)), ((u64)(0x259e9e47824f8753LL)), ((u64)(0x037ef73b399c01abLL)), ((u64)(0x1e187e9f9b72d2a9LL)), ((u64)(0x02cbf8fc2e1667bcLL)), 
((u64)(0x4b46cbb2e2c24221LL)), ((u64)(0x023cc73024deb963LL)), ((u64)(0x120adf849e039d01LL)), ((u64)(0x039471e6a1645bd2LL)), ((u64)(0xdb3be603b19c7d9aULL)), ((u64)(0x02dd27ebb4504974LL)), ((u64)(0x7c2feb3627b0647cLL)), ((u64)(0x024a865629d9d45dLL)), ((u64)(0x2d197856a5e7072cLL)), ((u64)(0x03aa7089dc8fba2fLL)), ((u64)(0x8a7ac6abb7ec05bdULL)), ((u64)(0x02eec06e4a0c94f2LL)), ((u64)(0xd52f05562cbcd164ULL)), ((u64)(0x025899f1d4d6dd8eLL)), ((u64)(0x21e4d556adfae8a0LL)), ((u64)(0x03c0f64fbaf1627eLL)), 
((u64)(0xe7ea444557fbed4dULL)), ((u64)(0x0300c50c958de864LL)), ((u64)(0xecbb69d1132ff10aULL)), ((u64)(0x0267040a113e5383LL)), ((u64)(0xadf8a94e851981aaULL)), ((u64)(0x03d8067681fd526cLL)), ((u64)(0x8b2d543ed0e13488ULL)), ((u64)(0x0313385ece6441f0LL)), ((u64)(0xd5bddcff0d80f6d3ULL)), ((u64)(0x0275c6b23eb69b26LL)), ((u64)(0x892fc7fe7c018aebULL)), ((u64)(0x03efa45064575ea4LL)), ((u64)(0x3a8c9ffec99ad589LL)), ((u64)(0x03261d0d1d12b21dLL)), ((u64)(0xc8707fff07af113bULL)), ((u64)(0x0284e40a7da88e7dLL)), 
((u64)(0x39f39998d2f2742fLL)), ((u64)(0x0203e9a1fe2071feLL)), ((u64)(0x8fec28f484b7204bULL)), ((u64)(0x033975cffd00b663LL)), ((u64)(0xd989ba5d36f8e6a2ULL)), ((u64)(0x02945e3ffd9a2b82LL)), ((u64)(0x47a161e42bfa521cLL)), ((u64)(0x02104b66647b5602LL)), ((u64)(0x0c35696d132a1cf9LL)), ((u64)(0x034d4570a0c5566aLL)), ((u64)(0x09c454574288172dLL)), ((u64)(0x02a4378d4d6aab88LL)), ((u64)(0xa169dd129ba0128bULL)), ((u64)(0x021cf93dd7888939LL)), ((u64)(0x0242fb50f9001dabLL)), ((u64)(0x03618ec958da7529LL)), 
((u64)(0x9b68c90d940017bcULL)), ((u64)(0x02b4723aad7b90edLL)), ((u64)(0x4920a0d7a999ac96LL)), ((u64)(0x0229f4fbbdfc73f1LL)), ((u64)(0x750101590f5c4757LL)), ((u64)(0x037654c5fcc71fe8LL)), ((u64)(0x2a6734473f7d05dfLL)), ((u64)(0x02c5109e63d27fedLL)), ((u64)(0xeeb8f69f65fd9e4cULL)), ((u64)(0x0237407eb641fff0LL)), ((u64)(0xe45b24323cc8fd46ULL)), ((u64)(0x038b9a6456cfffe7LL)), ((u64)(0xb6af502830a0ca9fULL)), ((u64)(0x02d6151d123fffecLL)), ((u64)(0xf88c402026e7087fULL)), ((u64)(0x0244ddb0db666656LL)), 
((u64)(0x2746cd003e3e73feLL)), ((u64)(0x03a162b4923d708bLL)), ((u64)(0x1f6bd73364fec332LL)), ((u64)(0x02e7822a0e978d3cLL)), ((u64)(0xe5efdf5c50cbcf5bULL)), ((u64)(0x0252ce880bac70fcLL)), ((u64)(0x3cb2fefa1adfb22bLL)), ((u64)(0x03b7b0d9ac471b2eLL)), ((u64)(0x308f3261af195b56LL)), ((u64)(0x02f95a47bd05af58LL)), ((u64)(0x5a0c284e25ade2abLL)), ((u64)(0x0261150630d15913LL)), ((u64)(0x29ad0d49d5e30445LL)), ((u64)(0x03ce8809e7b55b52LL)), ((u64)(0x548a7107de4f369dLL)), ((u64)(0x030ba007ec9115dbLL)), ((u64)(0xdd3b8d9fe50c2bb1ULL)), ((u64)(0x026fb3398a0dab15LL)), ((u64)(0x952c15cca1ad12b5ULL)), ((u64)(0x03e5eb8f434911bcLL)), ((u64)(0x775677d6e7bda891LL)), ((u64)(0x031e560c35d40e30LL)), ((u64)(0xc5dec645863153a7ULL)), ((u64)(0x027eab3cf7dcd826LL))}; // fixed array const
bool v_memory_panic = false; // global 6

int_literal g_autostr_type_stack_len = 0; // global 6

int_literal g_autostr_addr_stack_len = 0; // global 6

int g_main_argc = ((int)(0)); // global 6

voidptr g_main_argv = ((void*)0); // global 6

voidptr g_live_reload_info; // global 6

/* skip C global: errno */

/* skip C global: stdout */

/* skip C global: stderr */

/* skip C global: _wyp */

static IError _const_error_sentinel; // inited later
static IError _const_none__; // inited later
static const i32 _const_min_i32 = -2147483648; // precomputed2
static const i32 _const_max_i32 = 2147483647; // precomputed2
static i64 _const_min_i64; // inited later
static i64 _const_max_i64; // inited later
static const u32 _const_hash_mask = 16777215; // precomputed2
static const u32 _const_probe_inc = 16777216; // precomputed2
static Array_fixed_i32_1264 _const_rune_maps = {((i32)(0xB5)), 0xB5, 743, 0, 0xC0, 0xD6, 0, 32, 0xD8, 0xDE, 0, 32, 0xE0, 0xF6, -32, 0, 
0xF8, 0xFE, -32, 0, 0xFF, 0xFF, 121, 0, 0x100, 0x12F, -3, -3, 0x130, 0x130, 0, -199, 
0x131, 0x131, -232, 0, 0x132, 0x137, -3, -3, 0x139, 0x148, -3, -3, 0x14A, 0x177, -3, -3, 
0x178, 0x178, 0, -121, 0x179, 0x17E, -3, -3, 0x17F, 0x17F, -300, 0, 0x180, 0x180, 195, 0, 
0x181, 0x181, 0, 210, 0x182, 0x185, -3, -3, 0x186, 0x186, 0, 206, 0x187, 0x188, -3, -3, 
0x189, 0x18A, 0, 205, 0x18B, 0x18C, -3, -3, 0x18E, 0x18E, 0, 79, 0x18F, 0x18F, 0, 202, 
0x190, 0x190, 0, 203, 0x191, 0x192, -3, -3, 0x193, 0x193, 0, 205, 0x194, 0x194, 0, 207, 
0x195, 0x195, 97, 0, 0x196, 0x196, 0, 211, 0x197, 0x197, 0, 209, 0x198, 0x199, -3, -3, 
0x19A, 0x19A, 163, 0, 0x19C, 0x19C, 0, 211, 0x19D, 0x19D, 0, 213, 0x19E, 0x19E, 130, 0, 
0x19F, 0x19F, 0, 214, 0x1A0, 0x1A5, -3, -3, 0x1A6, 0x1A6, 0, 218, 0x1A7, 0x1A8, -3, -3, 
0x1A9, 0x1A9, 0, 218, 0x1AC, 0x1AD, -3, -3, 0x1AE, 0x1AE, 0, 218, 0x1AF, 0x1B0, -3, -3, 
0x1B1, 0x1B2, 0, 217, 0x1B3, 0x1B6, -3, -3, 0x1B7, 0x1B7, 0, 219, 0x1B8, 0x1B9, -3, -3, 
0x1BC, 0x1BD, -3, -3, 0x1BF, 0x1BF, 56, 0, 0x1C4, 0x1CC, -2, -2, 0x1CD, 0x1DC, -3, -3, 
0x1DD, 0x1DD, -79, 0, 0x1DE, 0x1EF, -3, -3, 0x1F1, 0x1F3, -2, -2, 0x1F4, 0x1F5, -3, -3, 
0x1F6, 0x1F6, 0, -97, 0x1F7, 0x1F7, 0, -56, 0x1F8, 0x21F, -3, -3, 0x220, 0x220, 0, -130, 
0x222, 0x233, -3, -3, 0x23A, 0x23A, 0, 10795, 0x23B, 0x23C, -3, -3, 0x23D, 0x23D, 0, -163, 
0x23E, 0x23E, 0, 10792, 0x23F, 0x240, 10815, 0, 0x241, 0x242, -3, -3, 0x243, 0x243, 0, -195, 
0x244, 0x244, 0, 69, 0x245, 0x245, 0, 71, 0x246, 0x24F, -3, -3, 0x250, 0x250, 10783, 0, 
0x251, 0x251, 10780, 0, 0x252, 0x252, 10782, 0, 0x253, 0x253, -210, 0, 0x254, 0x254, -206, 0, 
0x256, 0x257, -205, 0, 0x259, 0x259, -202, 0, 0x25B, 0x25B, -203, 0, 0x25C, 0x25C, 42319, 0, 
0x260, 0x260, -205, 0, 0x261, 0x261, 42315, 0, 0x263, 0x263, -207, 0, 0x265, 0x265, 42280, 0, 
0x266, 0x266, 42308, 0, 0x268, 0x268, -209, 0, 0x269, 0x269, -211, 0, 0x26A, 0x26A, 42308, 0, 
0x26B, 0x26B, 10743, 0, 0x26C, 0x26C, 42305, 0, 0x26F, 0x26F, -211, 0, 0x271, 0x271, 10749, 0, 
0x272, 0x272, -213, 0, 0x275, 0x275, -214, 0, 0x27D, 0x27D, 10727, 0, 0x280, 0x280, -218, 0, 
0x282, 0x282, 42307, 0, 0x283, 0x283, -218, 0, 0x287, 0x287, 42282, 0, 0x288, 0x288, -218, 0, 
0x289, 0x289, -69, 0, 0x28A, 0x28B, -217, 0, 0x28C, 0x28C, -71, 0, 0x292, 0x292, -219, 0, 
0x29D, 0x29D, 42261, 0, 0x29E, 0x29E, 42258, 0, 0x345, 0x345, 84, 0, 0x370, 0x373, -3, -3, 
0x376, 0x377, -3, -3, 0x37B, 0x37D, 130, 0, 0x37F, 0x37F, 0, 116, 0x386, 0x386, 0, 38, 
0x388, 0x38A, 0, 37, 0x38C, 0x38C, 0, 64, 0x38E, 0x38F, 0, 63, 0x391, 0x3A1, 0, 32, 
0x3A3, 0x3AB, 0, 32, 0x3AC, 0x3AC, -38, 0, 0x3AD, 0x3AF, -37, 0, 0x3B1, 0x3C1, -32, 0, 
0x3C2, 0x3C2, -31, 0, 0x3C3, 0x3CB, -32, 0, 0x3CC, 0x3CC, -64, 0, 0x3CD, 0x3CE, -63, 0, 
0x3CF, 0x3CF, 0, 8, 0x3D0, 0x3D0, -62, 0, 0x3D1, 0x3D1, -57, 0, 0x3D5, 0x3D5, -47, 0, 
0x3D6, 0x3D6, -54, 0, 0x3D7, 0x3D7, -8, 0, 0x3D8, 0x3EF, -3, -3, 0x3F0, 0x3F0, -86, 0, 
0x3F1, 0x3F1, -80, 0, 0x3F2, 0x3F2, 7, 0, 0x3F3, 0x3F3, -116, 0, 0x3F4, 0x3F4, 0, -60, 
0x3F5, 0x3F5, -96, 0, 0x3F7, 0x3F8, -3, -3, 0x3F9, 0x3F9, 0, -7, 0x3FA, 0x3FB, -3, -3, 
0x3FD, 0x3FF, 0, -130, 0x400, 0x40F, 0, 80, 0x410, 0x42F, 0, 32, 0x430, 0x44F, -32, 0, 
0x450, 0x45F, -80, 0, 0x460, 0x481, -3, -3, 0x48A, 0x4BF, -3, -3, 0x4C0, 0x4C0, 0, 15, 
0x4C1, 0x4CE, -3, -3, 0x4CF, 0x4CF, -15, 0, 0x4D0, 0x52F, -3, -3, 0x531, 0x556, 0, 48, 
0x561, 0x586, -48, 0, 0x10A0, 0x10C5, 0, 7264, 0x10C7, 0x10C7, 0, 7264, 0x10CD, 0x10CD, 0, 7264, 
0x10D0, 0x10FA, 3008, 0, 0x10FD, 0x10FF, 3008, 0, 0x13A0, 0x13EF, 0, 38864, 0x13F0, 0x13F5, 0, 8, 
0x13F8, 0x13FD, -8, 0, 0x1C80, 0x1C80, -6254, 0, 0x1C81, 0x1C81, -6253, 0, 0x1C82, 0x1C82, -6244, 0, 
0x1C83, 0x1C84, -6242, 0, 0x1C85, 0x1C85, -6243, 0, 0x1C86, 0x1C86, -6236, 0, 0x1C87, 0x1C87, -6181, 0, 
0x1C88, 0x1C88, 35266, 0, 0x1C90, 0x1CBA, 0, -3008, 0x1CBD, 0x1CBF, 0, -3008, 0x1D79, 0x1D79, 35332, 0, 
0x1D7D, 0x1D7D, 3814, 0, 0x1D8E, 0x1D8E, 35384, 0, 0x1E00, 0x1E95, -3, -3, 0x1E9B, 0x1E9B, -59, 0, 
0x1E9E, 0x1E9E, 0, -7615, 0x1EA0, 0x1EFF, -3, -3, 0x1F00, 0x1F07, 8, 0, 0x1F08, 0x1F0F, 0, -8, 
0x1F10, 0x1F15, 8, 0, 0x1F18, 0x1F1D, 0, -8, 0x1F20, 0x1F27, 8, 0, 0x1F28, 0x1F2F, 0, -8, 
0x1F30, 0x1F37, 8, 0, 0x1F38, 0x1F3F, 0, -8, 0x1F40, 0x1F45, 8, 0, 0x1F48, 0x1F4D, 0, -8, 
0x1F51, 0x1F51, 8, 0, 0x1F53, 0x1F53, 8, 0, 0x1F55, 0x1F55, 8, 0, 0x1F57, 0x1F57, 8, 0, 
0x1F59, 0x1F59, 0, -8, 0x1F5B, 0x1F5B, 0, -8, 0x1F5D, 0x1F5D, 0, -8, 0x1F5F, 0x1F5F, 0, -8, 
0x1F60, 0x1F67, 8, 0, 0x1F68, 0x1F6F, 0, -8, 0x1F70, 0x1F71, 74, 0, 0x1F72, 0x1F75, 86, 0, 
0x1F76, 0x1F77, 100, 0, 0x1F78, 0x1F79, 128, 0, 0x1F7A, 0x1F7B, 112, 0, 0x1F7C, 0x1F7D, 126, 0, 
0x1F80, 0x1F87, 8, 0, 0x1F88, 0x1F8F, 0, -8, 0x1F90, 0x1F97, 8, 0, 0x1F98, 0x1F9F, 0, -8, 
0x1FA0, 0x1FA7, 8, 0, 0x1FA8, 0x1FAF, 0, -8, 0x1FB0, 0x1FB1, 8, 0, 0x1FB3, 0x1FB3, 9, 0, 
0x1FB8, 0x1FB9, 0, -8, 0x1FBA, 0x1FBB, 0, -74, 0x1FBC, 0x1FBC, 0, -9, 0x1FBE, 0x1FBE, -7205, 0, 
0x1FC3, 0x1FC3, 9, 0, 0x1FC8, 0x1FCB, 0, -86, 0x1FCC, 0x1FCC, 0, -9, 0x1FD0, 0x1FD1, 8, 0, 
0x1FD8, 0x1FD9, 0, -8, 0x1FDA, 0x1FDB, 0, -100, 0x1FE0, 0x1FE1, 8, 0, 0x1FE5, 0x1FE5, 7, 0, 
0x1FE8, 0x1FE9, 0, -8, 0x1FEA, 0x1FEB, 0, -112, 0x1FEC, 0x1FEC, 0, -7, 0x1FF3, 0x1FF3, 9, 0, 
0x1FF8, 0x1FF9, 0, -128, 0x1FFA, 0x1FFB, 0, -126, 0x1FFC, 0x1FFC, 0, -9, 0x2126, 0x2126, 0, -7517, 
0x212A, 0x212A, 0, -8383, 0x212B, 0x212B, 0, -8262, 0x2132, 0x2132, 0, 28, 0x214E, 0x214E, -28, 0, 
0x2160, 0x216F, 0, 16, 0x2170, 0x217F, -16, 0, 0x2183, 0x2184, -3, -3, 0x24B6, 0x24CF, 0, 26, 
0x24D0, 0x24E9, -26, 0, 0x2C00, 0x2C2F, 0, 48, 0x2C30, 0x2C5F, -48, 0, 0x2C60, 0x2C61, -3, -3, 
0x2C62, 0x2C62, 0, -10743, 0x2C63, 0x2C63, 0, -3814, 0x2C64, 0x2C64, 0, -10727, 0x2C65, 0x2C65, -10795, 0, 
0x2C66, 0x2C66, -10792, 0, 0x2C67, 0x2C6C, -3, -3, 0x2C6D, 0x2C6D, 0, -10780, 0x2C6E, 0x2C6E, 0, -10749, 
0x2C6F, 0x2C6F, 0, -10783, 0x2C70, 0x2C70, 0, -10782, 0x2C72, 0x2C73, -3, -3, 0x2C75, 0x2C76, -3, -3, 
0x2C7E, 0x2C7F, 0, -10815, 0x2C80, 0x2CE3, -3, -3, 0x2CEB, 0x2CEE, -3, -3, 0x2CF2, 0x2CF3, -3, -3, 
0x2D00, 0x2D25, -7264, 0, 0x2D27, 0x2D27, -7264, 0, 0x2D2D, 0x2D2D, -7264, 0, 0xA640, 0xA66D, -3, -3, 
0xA680, 0xA69B, -3, -3, 0xA722, 0xA72F, -3, -3, 0xA732, 0xA76F, -3, -3, 0xA779, 0xA77C, -3, -3, 
0xA77D, 0xA77D, 0, -35332, 0xA77E, 0xA787, -3, -3, 0xA78B, 0xA78C, -3, -3, 0xA78D, 0xA78D, 0, -42280, 
0xA790, 0xA793, -3, -3, 0xA794, 0xA794, 48, 0, 0xA796, 0xA7A9, -3, -3, 0xA7AA, 0xA7AA, 0, -42308, 
0xA7AB, 0xA7AB, 0, -42319, 0xA7AC, 0xA7AC, 0, -42315, 0xA7AD, 0xA7AD, 0, -42305, 0xA7AE, 0xA7AE, 0, -42308, 
0xA7B0, 0xA7B0, 0, -42258, 0xA7B1, 0xA7B1, 0, -42282, 0xA7B2, 0xA7B2, 0, -42261, 0xA7B3, 0xA7B3, 0, 928, 
0xA7B4, 0xA7C3, -3, -3, 0xA7C4, 0xA7C4, 0, -48, 0xA7C5, 0xA7C5, 0, -42307, 0xA7C6, 0xA7C6, 0, -35384, 
0xA7C7, 0xA7CA, -3, -3, 0xA7D0, 0xA7D1, -3, -3, 0xA7D6, 0xA7D9, -3, -3, 0xA7F5, 0xA7F6, -3, -3, 
0xAB53, 0xAB53, -928, 0, 0xAB70, 0xABBF, -38864, 0, 0xFF21, 0xFF3A, 0, 32, 0xFF41, 0xFF5A, -32, 0, 
0x10400, 0x10427, 0, 40, 0x10428, 0x1044F, -40, 0, 0x104B0, 0x104D3, 0, 40, 0x104D8, 0x104FB, -40, 0, 
0x10570, 0x1057A, 0, 39, 0x1057C, 0x1058A, 0, 39, 0x1058C, 0x10592, 0, 39, 0x10594, 0x10595, 0, 39, 
0x10597, 0x105A1, -39, 0, 0x105A3, 0x105B1, -39, 0, 0x105B3, 0x105B9, -39, 0, 0x105BB, 0x105BC, -39, 0, 
0x10C80, 0x10CB2, 0, 64, 0x10CC0, 0x10CF2, -64, 0, 0x118A0, 0x118BF, 0, 32, 0x118C0, 0x118DF, -32, 0, 
0x16E40, 0x16E5F, 0, 32, 0x16E60, 0x16E7F, -32, 0, 0x1E900, 0x1E921, 0, 34, 0x1E922, 0x1E943, -34, 0}; // fixed array const
static const u8 _const_str_intp_has_dynamic_width = 1; // precomputed2
static const u8 _const_str_intp_has_dynamic_precision = 2; // precomputed2
static rune _const_utf8_replacement_rune; // inited later
Array_fixed_u8_128 g_v_os_execute_mutex_storage = {0}; // global 6

Array_fixed_int_64 g_autostr_type_stack = {0}; // global 6

Array_fixed_voidptr_64 g_autostr_addr_stack = {0}; // global 6

static Array_string _const_os__args; // inited later

// V interface table:
static IError I_None___to_Interface_IError(None__* x);
enum { _IError_None___index = 1 };
static IError I_voidptr_to_Interface_IError(voidptr* x);
enum { _IError_voidptr_index = 2 };
static IError I_MessageError_to_Interface_IError(MessageError* x);
enum { _IError_MessageError_index = 3 };
static IError I_os__Eof_to_Interface_IError(os__Eof* x);
enum { _IError_os__Eof_index = 4 };
static IError I_os__NotExpected_to_Interface_IError(os__NotExpected* x);
enum { _IError_os__NotExpected_index = 5 };
static IError I_os__FileNotOpenedError_to_Interface_IError(os__FileNotOpenedError* x);
enum { _IError_os__FileNotOpenedError_index = 6 };
static IError I_os__SizeOfTypeIs0Error_to_Interface_IError(os__SizeOfTypeIs0Error* x);
enum { _IError_os__SizeOfTypeIs0Error_index = 7 };
static IError I_os__ExecutableNotFoundError_to_Interface_IError(os__ExecutableNotFoundError* x);
enum { _IError_os__ExecutableNotFoundError_index = 8 };
static IError I_Error_to_Interface_IError(Error* x);
enum { _IError_Error_index = 9 };
// ^^^ number of types for interface IError: 9

// Methods wrapper for interface "IError"
static inline int builtin__None___code_Interface_IError_method_wrapper(None__* err) {
	return builtin__Error_code(err->Error);
}
static inline int builtin__None___code_Interface_IError_method_adapter(void* _x) {
	return builtin__None___code_Interface_IError_method_wrapper((None__*)_x);
}
static inline string builtin__None___msg_Interface_IError_method_wrapper(None__* err) {
	return builtin__Error_msg(err->Error);
}
static inline string builtin__None___msg_Interface_IError_method_adapter(void* _x) {
	return builtin__None___msg_Interface_IError_method_wrapper((None__*)_x);
}
static inline int builtin__MessageError_code_Interface_IError_method_wrapper(MessageError* err) {
	return builtin__MessageError_code(*err);
}
static inline int builtin__MessageError_code_Interface_IError_method_adapter(void* _x) {
	return builtin__MessageError_code_Interface_IError_method_wrapper((MessageError*)_x);
}
static inline string builtin__MessageError_msg_Interface_IError_method_wrapper(MessageError* err) {
	return builtin__MessageError_msg(*err);
}
static inline string builtin__MessageError_msg_Interface_IError_method_adapter(void* _x) {
	return builtin__MessageError_msg_Interface_IError_method_wrapper((MessageError*)_x);
}
static inline int builtin__os__Eof_code_Interface_IError_method_wrapper(os__Eof* err) {
	return builtin__Error_code(err->Error);
}
static inline int builtin__os__Eof_code_Interface_IError_method_adapter(void* _x) {
	return builtin__os__Eof_code_Interface_IError_method_wrapper((os__Eof*)_x);
}
static inline string builtin__os__Eof_msg_Interface_IError_method_wrapper(os__Eof* err) {
	return builtin__Error_msg(err->Error);
}
static inline string builtin__os__Eof_msg_Interface_IError_method_adapter(void* _x) {
	return builtin__os__Eof_msg_Interface_IError_method_wrapper((os__Eof*)_x);
}
static inline int os__NotExpected_code_Interface_IError_method_wrapper(os__NotExpected* err) {
	return os__NotExpected_code(*err);
}
static inline int os__NotExpected_code_Interface_IError_method_adapter(void* _x) {
	return os__NotExpected_code_Interface_IError_method_wrapper((os__NotExpected*)_x);
}
static inline string os__NotExpected_msg_Interface_IError_method_wrapper(os__NotExpected* err) {
	return os__NotExpected_msg(*err);
}
static inline string os__NotExpected_msg_Interface_IError_method_adapter(void* _x) {
	return os__NotExpected_msg_Interface_IError_method_wrapper((os__NotExpected*)_x);
}
static inline int builtin__os__FileNotOpenedError_code_Interface_IError_method_wrapper(os__FileNotOpenedError* err) {
	return builtin__Error_code(err->Error);
}
static inline int builtin__os__FileNotOpenedError_code_Interface_IError_method_adapter(void* _x) {
	return builtin__os__FileNotOpenedError_code_Interface_IError_method_wrapper((os__FileNotOpenedError*)_x);
}
static inline string os__FileNotOpenedError_msg_Interface_IError_method_wrapper(os__FileNotOpenedError* err) {
	return os__FileNotOpenedError_msg(*err);
}
static inline string os__FileNotOpenedError_msg_Interface_IError_method_adapter(void* _x) {
	return os__FileNotOpenedError_msg_Interface_IError_method_wrapper((os__FileNotOpenedError*)_x);
}
static inline int builtin__os__SizeOfTypeIs0Error_code_Interface_IError_method_wrapper(os__SizeOfTypeIs0Error* err) {
	return builtin__Error_code(err->Error);
}
static inline int builtin__os__SizeOfTypeIs0Error_code_Interface_IError_method_adapter(void* _x) {
	return builtin__os__SizeOfTypeIs0Error_code_Interface_IError_method_wrapper((os__SizeOfTypeIs0Error*)_x);
}
static inline string os__SizeOfTypeIs0Error_msg_Interface_IError_method_wrapper(os__SizeOfTypeIs0Error* err) {
	return os__SizeOfTypeIs0Error_msg(*err);
}
static inline string os__SizeOfTypeIs0Error_msg_Interface_IError_method_adapter(void* _x) {
	return os__SizeOfTypeIs0Error_msg_Interface_IError_method_wrapper((os__SizeOfTypeIs0Error*)_x);
}
static inline int builtin__os__ExecutableNotFoundError_code_Interface_IError_method_wrapper(os__ExecutableNotFoundError* err) {
	return builtin__Error_code(err->Error);
}
static inline int builtin__os__ExecutableNotFoundError_code_Interface_IError_method_adapter(void* _x) {
	return builtin__os__ExecutableNotFoundError_code_Interface_IError_method_wrapper((os__ExecutableNotFoundError*)_x);
}
static inline string os__ExecutableNotFoundError_msg_Interface_IError_method_wrapper(os__ExecutableNotFoundError* err) {
	return os__ExecutableNotFoundError_msg(*err);
}
static inline string os__ExecutableNotFoundError_msg_Interface_IError_method_adapter(void* _x) {
	return os__ExecutableNotFoundError_msg_Interface_IError_method_wrapper((os__ExecutableNotFoundError*)_x);
}
static inline int builtin__Error_code_Interface_IError_method_wrapper(Error* err) {
	return builtin__Error_code(*err);
}
static inline int builtin__Error_code_Interface_IError_method_adapter(void* _x) {
	return builtin__Error_code_Interface_IError_method_wrapper((Error*)_x);
}
static inline string builtin__Error_msg_Interface_IError_method_wrapper(Error* err) {
	return builtin__Error_msg(*err);
}
static inline string builtin__Error_msg_Interface_IError_method_adapter(void* _x) {
	return builtin__Error_msg_Interface_IError_method_wrapper((Error*)_x);
}

struct _IError_interface_methods {
	int (*_method_code)(void* _);
	string (*_method_msg)(void* _);
};

struct _IError_interface_methods IError_name_table[10] = {
	{0},
	{
		._method_code = builtin__None___code_Interface_IError_method_adapter,
		._method_msg = builtin__None___msg_Interface_IError_method_adapter,
	},
	{
		._method_code = (void*) 0,
		._method_msg = (void*) 0,
	},
	{
		._method_code = builtin__MessageError_code_Interface_IError_method_adapter,
		._method_msg = builtin__MessageError_msg_Interface_IError_method_adapter,
	},
	{
		._method_code = builtin__os__Eof_code_Interface_IError_method_adapter,
		._method_msg = builtin__os__Eof_msg_Interface_IError_method_adapter,
	},
	{
		._method_code = os__NotExpected_code_Interface_IError_method_adapter,
		._method_msg = os__NotExpected_msg_Interface_IError_method_adapter,
	},
	{
		._method_code = builtin__os__FileNotOpenedError_code_Interface_IError_method_adapter,
		._method_msg = os__FileNotOpenedError_msg_Interface_IError_method_adapter,
	},
	{
		._method_code = builtin__os__SizeOfTypeIs0Error_code_Interface_IError_method_adapter,
		._method_msg = os__SizeOfTypeIs0Error_msg_Interface_IError_method_adapter,
	},
	{
		._method_code = builtin__os__ExecutableNotFoundError_code_Interface_IError_method_adapter,
		._method_msg = os__ExecutableNotFoundError_msg_Interface_IError_method_adapter,
	},
	{
		._method_code = builtin__Error_code_Interface_IError_method_adapter,
		._method_msg = builtin__Error_msg_Interface_IError_method_adapter,
	},
};


// Casting functions for converting "None__" to interface "IError"

static inline IError I_None___to_Interface_IError(None__* x) {
return (IError) {
		._None__ = x,
		._typ = _IError_None___index,
		._methods = &IError_name_table[_IError_None___index],
	};
}

// Casting functions for converting "voidptr" to interface "IError"

static inline IError I_voidptr_to_Interface_IError(voidptr* x) {
return (IError) {
		._voidptr = x,
		._typ = _IError_voidptr_index,
		._methods = &IError_name_table[_IError_voidptr_index],
	};
}

// Casting functions for converting "MessageError" to interface "IError"

static inline IError I_MessageError_to_Interface_IError(MessageError* x) {
return (IError) {
		._MessageError = x,
		._typ = _IError_MessageError_index,
		._methods = &IError_name_table[_IError_MessageError_index],
	};
}

// Casting functions for converting "os__Eof" to interface "IError"

static inline IError I_os__Eof_to_Interface_IError(os__Eof* x) {
return (IError) {
		._os__Eof = x,
		._typ = _IError_os__Eof_index,
		._methods = &IError_name_table[_IError_os__Eof_index],
	};
}

// Casting functions for converting "os__NotExpected" to interface "IError"

static inline IError I_os__NotExpected_to_Interface_IError(os__NotExpected* x) {
return (IError) {
		._os__NotExpected = x,
		._typ = _IError_os__NotExpected_index,
		._methods = &IError_name_table[_IError_os__NotExpected_index],
	};
}

// Casting functions for converting "os__FileNotOpenedError" to interface "IError"

static inline IError I_os__FileNotOpenedError_to_Interface_IError(os__FileNotOpenedError* x) {
return (IError) {
		._os__FileNotOpenedError = x,
		._typ = _IError_os__FileNotOpenedError_index,
		._methods = &IError_name_table[_IError_os__FileNotOpenedError_index],
	};
}

// Casting functions for converting "os__SizeOfTypeIs0Error" to interface "IError"

static inline IError I_os__SizeOfTypeIs0Error_to_Interface_IError(os__SizeOfTypeIs0Error* x) {
return (IError) {
		._os__SizeOfTypeIs0Error = x,
		._typ = _IError_os__SizeOfTypeIs0Error_index,
		._methods = &IError_name_table[_IError_os__SizeOfTypeIs0Error_index],
	};
}

// Casting functions for converting "os__ExecutableNotFoundError" to interface "IError"

static inline IError I_os__ExecutableNotFoundError_to_Interface_IError(os__ExecutableNotFoundError* x) {
return (IError) {
		._os__ExecutableNotFoundError = x,
		._typ = _IError_os__ExecutableNotFoundError_index,
		._methods = &IError_name_table[_IError_os__ExecutableNotFoundError_index],
	};
}

// Casting functions for converting "Error" to interface "IError"

static inline IError I_Error_to_Interface_IError(Error* x) {
return (IError) {
		._Error = x,
		._typ = _IError_Error_index,
		._methods = &IError_name_table[_IError_Error_index],
	};
}


static inline IError __v_interface_clone_variant__IError__None__(void* x) {
return I_None___to_Interface_IError((None__*)builtin__memdup(x, sizeof(None__)));
}

static inline IError __v_interface_clone_variant__IError__voidptr(void* x) {
return I_voidptr_to_Interface_IError((voidptr*)builtin__memdup(x, sizeof(voidptr)));
}

static inline IError __v_interface_clone_variant__IError__MessageError(void* x) {
return I_MessageError_to_Interface_IError((MessageError*)builtin__memdup(x, sizeof(MessageError)));
}

static inline IError __v_interface_clone_variant__IError__os__Eof(void* x) {
return I_os__Eof_to_Interface_IError((os__Eof*)builtin__memdup(x, sizeof(os__Eof)));
}

static inline IError __v_interface_clone_variant__IError__os__NotExpected(void* x) {
return I_os__NotExpected_to_Interface_IError((os__NotExpected*)builtin__memdup(x, sizeof(os__NotExpected)));
}

static inline IError __v_interface_clone_variant__IError__os__FileNotOpenedError(void* x) {
return I_os__FileNotOpenedError_to_Interface_IError((os__FileNotOpenedError*)builtin__memdup(x, sizeof(os__FileNotOpenedError)));
}

static inline IError __v_interface_clone_variant__IError__os__SizeOfTypeIs0Error(void* x) {
return I_os__SizeOfTypeIs0Error_to_Interface_IError((os__SizeOfTypeIs0Error*)builtin__memdup(x, sizeof(os__SizeOfTypeIs0Error)));
}

static inline IError __v_interface_clone_variant__IError__os__ExecutableNotFoundError(void* x) {
return I_os__ExecutableNotFoundError_to_Interface_IError((os__ExecutableNotFoundError*)builtin__memdup(x, sizeof(os__ExecutableNotFoundError)));
}

static inline IError __v_interface_clone_variant__IError__Error(void* x) {
return I_Error_to_Interface_IError((Error*)builtin__memdup(x, sizeof(Error)));
}

static inline IError __v_interface_clone__IError(IError x) {
	if (x._object == 0) {
		return x;
	}
	if (x._typ == _IError_None___index) {
		return __v_interface_clone_variant__IError__None__(x._object);
	}
	if (x._typ == _IError_voidptr_index) {
		return __v_interface_clone_variant__IError__voidptr(x._object);
	}
	if (x._typ == _IError_MessageError_index) {
		return __v_interface_clone_variant__IError__MessageError(x._object);
	}
	if (x._typ == _IError_os__Eof_index) {
		return __v_interface_clone_variant__IError__os__Eof(x._object);
	}
	if (x._typ == _IError_os__NotExpected_index) {
		return __v_interface_clone_variant__IError__os__NotExpected(x._object);
	}
	if (x._typ == _IError_os__FileNotOpenedError_index) {
		return __v_interface_clone_variant__IError__os__FileNotOpenedError(x._object);
	}
	if (x._typ == _IError_os__SizeOfTypeIs0Error_index) {
		return __v_interface_clone_variant__IError__os__SizeOfTypeIs0Error(x._object);
	}
	if (x._typ == _IError_os__ExecutableNotFoundError_index) {
		return __v_interface_clone_variant__IError__os__ExecutableNotFoundError(x._object);
	}
	if (x._typ == _IError_Error_index) {
		return __v_interface_clone_variant__IError__Error(x._object);
	}
	return x;
}

static inline u64 VSAFE_DIV_u64(u64 x, u64 y) { if (_unlikely_(0 == y)) { builtin___v_panic(_S("division by zero")); } return x / y; }
static inline u64 VSAFE_MOD_u64(u64 x, u64 y) { if (_unlikely_(0 == y)) { builtin___v_panic(_S("modulo by zero")); } return x % y; }
static inline u32 VSAFE_DIV_u32(u32 x, u32 y) { if (_unlikely_(0 == y)) { builtin___v_panic(_S("division by zero")); } return x / y; }
static inline u32 VSAFE_MOD_u32(u32 x, u32 y) { if (_unlikely_(0 == y)) { builtin___v_panic(_S("modulo by zero")); } return x % y; }
static inline int VSAFE_MOD_int(int x, int y) { if (_unlikely_(0 == y)) { builtin___v_panic(_S("modulo by zero")); } return x % y; }
static inline int VSAFE_DIV_int(int x, int y) { if (_unlikely_(0 == y)) { builtin___v_panic(_S("division by zero")); } return x / y; }
static inline i64 VSAFE_MOD_i64(i64 x, i64 y) { if (_unlikely_(0 == y)) { builtin___v_panic(_S("modulo by zero")); } return x % y; }
static inline i64 VSAFE_DIV_i64(i64 x, i64 y) { if (_unlikely_(0 == y)) { builtin___v_panic(_S("division by zero")); } return x / y; }
static inline rune VSAFE_MOD_rune(rune x, rune y) { if (_unlikely_(0 == y)) { builtin___v_panic(_S("modulo by zero")); } return x % y; }

// end of V out (header)

// V auto functions:
static bool Array_u8_contains(Array_u8 a, u8 v) {
	for (int i = 0; i < a.len; ++i) {
		if (((u8*)a.data)[i] == v) {
			return true;
		}
	}
	return false;
}

static bool Array_string_contains(Array_string a, string v) {
	for (int i = 0; i < a.len; ++i) {
		if (builtin__fast_string_eq(((string*)a.data)[i], v)) {
			return true;
		}
	}
	return false;
}


// >> typeof() support for sum types / interfaces
static char * v_typeof_interface_IError(u32 sidx) {
	if (sidx == _IError_None___index) return "None__";
	if (sidx == _IError_voidptr_index) return "voidptr";
	if (sidx == _IError_MessageError_index) return "MessageError";
	if (sidx == _IError_os__Eof_index) return "os.Eof";
	if (sidx == _IError_os__NotExpected_index) return "os.NotExpected";
	if (sidx == _IError_os__FileNotOpenedError_index) return "os.FileNotOpenedError";
	if (sidx == _IError_os__SizeOfTypeIs0Error_index) return "os.SizeOfTypeIs0Error";
	if (sidx == _IError_os__ExecutableNotFoundError_index) return "os.ExecutableNotFoundError";
	if (sidx == _IError_Error_index) return "Error";
	return "unknown IError";
}

u32 v_typeof_interface_idx_IError(u32 sidx) {
	if (sidx == _IError_None___index) return 65;
	if (sidx == _IError_voidptr_index) return 2;
	if (sidx == _IError_MessageError_index) return 67;
	if (sidx == _IError_os__Eof_index) return 165;
	if (sidx == _IError_os__NotExpected_index) return 163;
	if (sidx == _IError_os__FileNotOpenedError_index) return 166;
	if (sidx == _IError_os__SizeOfTypeIs0Error_index) return 167;
	if (sidx == _IError_os__ExecutableNotFoundError_index) return 187;
	if (sidx == _IError_Error_index) return 66;
	return 30;
}
// << typeof() support for sum types

strings__Builder strings__new_builder(int initial_size) {
	strings__Builder res = ((builtin____new_array_with_default(0, initial_size, sizeof(u8), 0)));
	builtin__ArrayFlags_set(&res.flags, ArrayFlags__noslices);
	return res;
}
Array_u8 strings__Builder_reuse_as_plain_u8_array(strings__Builder* b) {
	builtin__ArrayFlags_clear(&b->flags, ArrayFlags__noslices);
	return *b;
}
void strings__Builder_write_ptr(strings__Builder* b, u8* ptr, int len) {
	if (len == 0) {
		return;
	}
	builtin__array_push_many(b, ptr, len);
}
void strings__Builder_write_rune(strings__Builder* b, rune r) {
	Array_fixed_u8_5 buffer = {0};
	string res = builtin__utf32_to_str_no_malloc(((u32)(r)), &buffer[0]);
	if (res.len == 0) {
		return;
	}
	builtin__array_push_many(b, res.str, res.len);
}
void strings__Builder_write_runes(strings__Builder* b, Array_rune runes) {
	Array_fixed_u8_5 buffer = {0};
	for (int _t1 = 0; _t1 < runes.len; ++_t1) {
		rune r = ((rune*)runes.data)[_t1];
		string res = builtin__utf32_to_str_no_malloc(((u32)(r)), &buffer[0]);
		if (res.len == 0) {
			continue;
		}
		builtin__array_push_many(b, res.str, res.len);
	}
}
inline void strings__Builder_write_u8(strings__Builder* b, u8 data) {
	builtin__array_push((array*)b, _MOV((u8[]){ data }));
}
inline void strings__Builder_write_byte(strings__Builder* b, u8 data) {
	builtin__array_push((array*)b, _MOV((u8[]){ data }));
}
void strings__Builder_write_u_decimal(strings__Builder* b, u64 n) {
	if (n == 0) {
		strings__Builder_write_u8(b, 0x30);
		return;
	}
	Array_fixed_u8_20 buf = {0};
	u64 x = n;
	int i = 19;
	for (;;) {
		if (!(x != 0)) break;
		u64 nextx = VSAFE_DIV_u64(x , 10);
		u64 r = VSAFE_MOD_u64(x , 10);
		buf[i] = (u8)(((u8)(r)) + 0x30);
		x = nextx;
		i--;
	}
	strings__Builder_write_ptr(b, &buf[i + 1], 19 - i);
}
inline void strings__Builder_write_string(strings__Builder* b, string s) {
	if (s.len == 0) {
		return;
	}
	builtin__array_push_many(b, s.str, s.len);
}
inline string strings__Builder_spart(strings__Builder* b, int start_pos, int n) {
	{ // Unsafe block
		u8* x = builtin__malloc_noscan(n + 1);
		builtin__vmemcpy(x, ((u8*)(b->data)) + start_pos, n);
		x[n] = 0;
		return builtin__tos(x, n);
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}
string strings__Builder_cut_last(strings__Builder* b, int n) {
	int cut_pos = b->len - n;
	string res = strings__Builder_spart(b, cut_pos, n);
	builtin__array_trim(b, cut_pos);
	return res;
}
string strings__Builder_str(strings__Builder* b) {
	builtin__array_push((array*)b, _MOV((u8[]){ ((u8)(0)) }));
	u8* bcopy = ((u8*)(builtin__memdup_noscan(b->data, b->len)));
	string s = builtin__u8_vstring_with_len(bcopy, b->len - 1);
	builtin__array_clear(b);
	return s;
}
void strings__Builder_ensure_cap(strings__Builder* b, int n) {
	Array_u8* arr = ((Array_u8*)(b));
	builtin__array_ensure_cap(arr, n);
}
void strings__Builder_free(strings__Builder* b) {
	if (b->data != 0) {
		Array_u8* arr = ((Array_u8*)(b));
		builtin__array_free(arr);
	}
}
void strings__Builder_write_repeated_rune(strings__Builder* b, rune r, int count) {
	if (count <= 0) {
		return;
	}
	Array_fixed_u8_5 buffer = {0};
	string res = builtin__utf32_to_str_no_malloc(((u32)(r)), &buffer[0]);
	if (res.len == 0) {
		return;
	}
	if (res.len == 1) {
		strings__Builder_ensure_cap(b, b->len + count);
		{ // Unsafe block
			builtin__vmemset(((u8*)(b->data)) + b->len, buffer[0], count);
			b->len += count;
		}
		return;
	} else {
		int total_needed = count * res.len;
		strings__Builder_ensure_cap(b, b->len + total_needed);
		u8* dest = ((u8*)(b->data)) + b->len;
		for (int _t1 = 0; _t1 < count; ++_t1) {
			{ // Unsafe block
				builtin__vmemcpy(dest, res.str, res.len);
				dest += res.len;
			}
		}
		{ // Unsafe block
			b->len += total_needed;
		}
	}
}
string strings__repeat(u8 c, int n) {
	if (n <= 0) {
		return _S("");
	}
	u8* bytes = builtin__malloc_noscan(n + 1);
	{ // Unsafe block
		memset(bytes, c, n);
		bytes[n] = 0;
	}
	return builtin__u8_vstring_with_len(bytes, n);
}
#if 1
#endif
inline multi_return_u64_u64 math__bits__mul_64(u64 x, u64 y) {
	u64 hi = ((u64)(0));
	u64 lo = ((u64)(0));
	#if defined(_MSC_VER)
	{
	}
	#elif defined(__V_amd64)
	{
		__asm__ (
			"mulq %%rdx\n\t"
			: [lo] "=a" (lo),
			[hi] "=d" (hi)
			: [x] "a" (x),
			[y] "d" (y)
			: "cc"
		);
		return (multi_return_u64_u64){.arg0=hi, .arg1=lo};
	}
	#endif
	return math__bits__mul_64_default(x, y);
}
inline int math__bits__trailing_zeros_32(u32 x) {
	if (x == 0) {
		return 32;
	}
	#if defined(_MSC_VER)
	{
	}
	#elif !defined(__TINYC__)
	{
	}
	#endif
	return math__bits__trailing_zeros_32_default(x);
}
inline int math__bits__trailing_zeros_64(u64 x) {
	if (x == 0) {
		return 64;
	}
	#if defined(_MSC_VER)
	{
	}
	#elif !defined(__TINYC__)
	{
	}
	#endif
	return math__bits__trailing_zeros_64_default(x);
}
inline VV_LOC int math__bits__trailing_zeros_32_default(u32 x) {
	if (x == 0) {
		return 32;
	}
	return ((int)(_const_math__bits__de_bruijn32tab[v__rshift_u32(((x & -x)) * _const_math__bits__de_bruijn32, (u64)27)]));
}
inline VV_LOC int math__bits__trailing_zeros_64_default(u64 x) {
	if (x == 0) {
		return 64;
	}
	return ((int)(_const_math__bits__de_bruijn64tab[((int)(v__rshift_u64(((x & -x)) * _const_math__bits__de_bruijn64, (u64)58)))]));
}
VV_LOC multi_return_u64_u64 math__bits__mul_64_default(u64 x, u64 y) {
	u64 x0 = (x & _const_math__bits__mask32);
	u64 x1 = v__rshift_u64(x, (u64)32);
	u64 y0 = (y & _const_math__bits__mask32);
	u64 y1 = v__rshift_u64(y, (u64)32);
	u64 w0 = x0 * y0;
	u64 t = x1 * y0 + (v__rshift_u64(w0, (u64)32));
	u64 w1 = (t & _const_math__bits__mask32);
	u64 w2 = v__rshift_u64(t, (u64)32);
	w1 += x0 * y1;
	u64 hi = x1 * y1 + w2 + (v__rshift_u64(w1, (u64)32));
	u64 lo = x * y;
	return (multi_return_u64_u64){.arg0=hi, .arg1=lo};
}
string strconv__Dec32_get_string_32(strconv__Dec32 d, bool neg, int i_n_digit, int i_pad_digit) {
	int n_digit = i_n_digit + 1;
	int pad_digit = i_pad_digit + 1;
	u32 out = d.m;
	int out_len = strconv__dec_digits(out);
	int out_len_original = out_len;
	int fw_zeros = 0;
	if (pad_digit > out_len) {
		fw_zeros = pad_digit - out_len;
	}
	Array_u8 buf = builtin____new_array_with_default(((int)(out_len + 5 + 1 + 1)), 0, sizeof(u8), 0);
	int i = 0;
	if (neg) {
		if (buf.data != 0) {
			((u8*)buf.data)[i] = '-';
		}
		i++;
	}
	int disp = 0;
	if (out_len <= 1) {
		disp = 1;
	}
	if (n_digit < out_len) {
		out += _const_strconv__ten_pow_table_32[out_len - n_digit - 1] * 5;
		out = VSAFE_DIV_u32(out,_const_strconv__ten_pow_table_32[out_len - n_digit]);
		out_len = n_digit;
	}
	int y = i + out_len;
	int x = 0;
	for (;;) {
		if (!(x < (out_len - disp - 1))) break;
		((u8*)buf.data)[y - x] = (rune)('0' + ((u8)(VSAFE_MOD_u32(out , 10))));
		out = VSAFE_DIV_u32(out,10);
		i++;
		x++;
	}
	if (i_n_digit == 0) {
		{ // Unsafe block
			((u8*)buf.data)[i] = 0;
			return builtin__tos(builtin__memdup(&((u8*)buf.data)[0], i + 1), i);
		}
	}
	if (out_len > 1 || fw_zeros > 0) {
		((u8*)buf.data)[y - x] = '.';
		i++;
	}
	x++;
	if (y - x >= 0) {
		((u8*)buf.data)[y - x] = (rune)('0' + ((u8)(VSAFE_MOD_u32(out , 10))));
		i++;
	}
	for (;;) {
		if (!(fw_zeros > 0)) break;
		((u8*)buf.data)[i] = '0';
		i++;
		fw_zeros--;
	}
	((u8*)buf.data)[i] = 'e';
	i++;
	int exp = d.e + out_len_original - 1;
	if (exp < 0) {
		((u8*)buf.data)[i] = '-';
		i++;
		exp = -exp;
	} else {
		((u8*)buf.data)[i] = '+';
		i++;
	}
	int d1 = VSAFE_MOD_int(exp , 10);
	int d0 = VSAFE_DIV_int(exp , 10);
	((u8*)buf.data)[i] = (rune)('0' + ((u8)(d0)));
	i++;
	((u8*)buf.data)[i] = (rune)('0' + ((u8)(d1)));
	i++;
	((u8*)buf.data)[i] = 0;
	return builtin__tos(builtin__memdup(&((u8*)buf.data)[0], i + 1), i);
}
VV_LOC multi_return_strconv__Dec32_bool strconv__f32_to_decimal_exact_int(u32 i_mant, u32 exp) {
	strconv__Dec32 _t1 = ((strconv__Dec32){.m = 0,.e = 0,});
	strconv__Dec32 d = _t1;
	u32 e = exp - 127;
	if (e > _const_strconv__mantbits32) {
		return (multi_return_strconv__Dec32_bool){.arg0=d, .arg1=false};
	}
	u32 shift = _const_strconv__mantbits32 - e;
	u32 mant = (i_mant | 0x00800000);
	d.m = v__rshift_u32(mant, (u64)shift);
	if ((v__lshift_u32(d.m, (u64)shift)) != mant) {
		return (multi_return_strconv__Dec32_bool){.arg0=d, .arg1=false};
	}
	for (;;) {
		if (!((VSAFE_MOD_u32(d.m , 10)) == 0)) break;
		d.m = VSAFE_DIV_u32(d.m,10);
		d.e++;
	}
	return (multi_return_strconv__Dec32_bool){.arg0=d, .arg1=true};
}
VV_LOC strconv__Dec32 strconv__f32_to_decimal(u32 mant, u32 exp) {
	int e2 = 0;
	u32 m2 = ((u32)(0));
	if (exp == 0) {
		e2 = -126 - ((int)(_const_strconv__mantbits32)) - 2;
		m2 = mant;
	} else {
		e2 = ((int)(exp)) - 127 - ((int)(_const_strconv__mantbits32)) - 2;
		m2 = ((v__lshift_u32(((u32)(1)), (u64)_const_strconv__mantbits32)) | mant);
	}
	bool even = ((m2 & 1)) == 0;
	bool accept_bounds = even;
	u32 mv = ((u32)(4 * m2));
	u32 mp = ((u32)(4 * m2 + 2));
	u32 mm_shift = strconv__bool_to_u32(mant != 0 || exp <= 1);
	u32 mm = ((u32)(4 * m2 - 1 - mm_shift));
	u32 vr = ((u32)(0));
	u32 vp = ((u32)(0));
	u32 vm = ((u32)(0));
	int e10 = 0;
	bool vm_is_trailing_zeros = false;
	bool vr_is_trailing_zeros = false;
	u8 last_removed_digit = ((u8)(0));
	if (e2 >= 0) {
		u32 q = strconv__log10_pow2(e2);
		e10 = ((int)(q));
		int k = 59 + strconv__pow5_bits(((int)(q))) - 1;
		int i = -e2 + ((int)(q)) + k;
		vr = strconv__mul_pow5_invdiv_pow2(mv, q, i);
		vp = strconv__mul_pow5_invdiv_pow2(mp, q, i);
		vm = strconv__mul_pow5_invdiv_pow2(mm, q, i);
		if (q != 0 && VSAFE_DIV_u32((vp - 1) , 10) <= VSAFE_DIV_u32(vm , 10)) {
			int l = 59 + strconv__pow5_bits(((int)(q - 1))) - 1;
			last_removed_digit = ((u8)(VSAFE_MOD_u32(strconv__mul_pow5_invdiv_pow2(mv, q - 1, -e2 + ((int)(q - 1)) + l) , 10)));
		}
		if (q <= 9) {
			if (VSAFE_MOD_u32(mv , 5) == 0) {
				vr_is_trailing_zeros = strconv__multiple_of_power_of_five_32(mv, q);
			} else if (accept_bounds) {
				vm_is_trailing_zeros = strconv__multiple_of_power_of_five_32(mm, q);
			} else if (strconv__multiple_of_power_of_five_32(mp, q)) {
				vp--;
			}
		}
	} else {
		u32 q = strconv__log10_pow5(-e2);
		e10 = ((int)(q)) + e2;
		int i = -e2 - ((int)(q));
		int k = strconv__pow5_bits(i) - 61;
		int j = ((int)(q)) - k;
		vr = strconv__mul_pow5_div_pow2(mv, ((u32)(i)), j);
		vp = strconv__mul_pow5_div_pow2(mp, ((u32)(i)), j);
		vm = strconv__mul_pow5_div_pow2(mm, ((u32)(i)), j);
		if (q != 0 && (VSAFE_DIV_u32((vp - 1) , 10)) <= VSAFE_DIV_u32(vm , 10)) {
			j = ((int)(q)) - 1 - (strconv__pow5_bits(i + 1) - 61);
			last_removed_digit = ((u8)(VSAFE_MOD_u32(strconv__mul_pow5_div_pow2(mv, ((u32)(i + 1)), j) , 10)));
		}
		if (q <= 1) {
			vr_is_trailing_zeros = true;
			if (accept_bounds) {
				vm_is_trailing_zeros = mm_shift == 1;
			} else {
				vp--;
			}
		} else if (q < 31) {
			vr_is_trailing_zeros = strconv__multiple_of_power_of_two_32(mv, q - 1);
		}
	}
	int removed = 0;
	u32 out = ((u32)(0));
	if (vm_is_trailing_zeros || vr_is_trailing_zeros) {
		for (;;) {
			if (!(VSAFE_DIV_u32(vp , 10) > VSAFE_DIV_u32(vm , 10))) break;
			vm_is_trailing_zeros = vm_is_trailing_zeros && (VSAFE_MOD_u32(vm , 10)) == 0;
			vr_is_trailing_zeros = vr_is_trailing_zeros && last_removed_digit == 0;
			last_removed_digit = ((u8)(VSAFE_MOD_u32(vr , 10)));
			vr = VSAFE_DIV_u32(vr,10);
			vp = VSAFE_DIV_u32(vp,10);
			vm = VSAFE_DIV_u32(vm,10);
			removed++;
		}
		if (vm_is_trailing_zeros) {
			for (;;) {
				if (!(VSAFE_MOD_u32(vm , 10) == 0)) break;
				vr_is_trailing_zeros = vr_is_trailing_zeros && last_removed_digit == 0;
				last_removed_digit = ((u8)(VSAFE_MOD_u32(vr , 10)));
				vr = VSAFE_DIV_u32(vr,10);
				vp = VSAFE_DIV_u32(vp,10);
				vm = VSAFE_DIV_u32(vm,10);
				removed++;
			}
		}
		if (vr_is_trailing_zeros && last_removed_digit == 5 && (VSAFE_MOD_u32(vr , 2)) == 0) {
			last_removed_digit = 4;
		}
		out = vr;
		if ((vr == vm && (!accept_bounds || !vm_is_trailing_zeros)) || last_removed_digit >= 5) {
			out++;
		}
	} else {
		for (;;) {
			if (!(VSAFE_DIV_u32(vp , 10) > VSAFE_DIV_u32(vm , 10))) break;
			last_removed_digit = ((u8)(VSAFE_MOD_u32(vr , 10)));
			vr = VSAFE_DIV_u32(vr,10);
			vp = VSAFE_DIV_u32(vp,10);
			vm = VSAFE_DIV_u32(vm,10);
			removed++;
		}
		out = vr + strconv__bool_to_u32(vr == vm || last_removed_digit >= 5);
	}
	return ((strconv__Dec32){.m = out,.e = e10 + removed,});
}
string strconv__f32_to_str(f32 f, int n_digit) {
	strconv__Uf32 _t1 = ((strconv__Uf32){0});
	strconv__Uf32 u1 = _t1;
	u1.f = f;
	u32 u = u1.u;
	bool neg = (v__rshift_u32(u, (u64)(_const_strconv__mantbits32 + _const_strconv__expbits32))) != 0;
	u32 mant = (u & ((v__lshift_u32(((u32)(1)), (u64)_const_strconv__mantbits32)) - ((u32)(1))));
	u32 exp = ((v__rshift_u32(u, (u64)_const_strconv__mantbits32)) & ((v__lshift_u32(((u32)(1)), (u64)_const_strconv__expbits32)) - ((u32)(1))));
	if (exp == 255 || (exp == 0 && mant == 0)) {
		return strconv__get_string_special(neg, exp == 0, mant == 0);
	}
	multi_return_strconv__Dec32_bool mr_8600 = strconv__f32_to_decimal_exact_int(mant, exp);
	strconv__Dec32 d = mr_8600.arg0;
	bool ok = mr_8600.arg1;
	if (!ok) {
		d = strconv__f32_to_decimal(mant, exp);
	}
	return strconv__Dec32_get_string_32(d, neg, n_digit, 0);
}
VV_LOC string strconv__Dec64_get_string_64(strconv__Dec64 d, bool neg, int i_n_digit, int i_pad_digit) {
	int n_digit = (i_n_digit < 1 ? (1) : (i_n_digit + 1));
	int pad_digit = i_pad_digit + 1;
	u64 out = d.m;
	int d_exp = d.e;
	int out_len = strconv__dec_digits(out);
	int out_len_original = out_len;
	int fw_zeros = 0;
	if (pad_digit > out_len) {
		fw_zeros = pad_digit - out_len;
	}
	Array_u8 buf = builtin____new_array_with_default((out_len + 6 + 1 + 1 + fw_zeros), 0, sizeof(u8), 0);
	int i = 0;
	if (neg) {
		((u8*)buf.data)[i] = '-';
		i++;
	}
	int disp = 0;
	if (out_len <= 1) {
		disp = 1;
	}
	if (n_digit < out_len) {
		out += _const_strconv__ten_pow_table_64[out_len - n_digit - 1] * 5;
		out = VSAFE_DIV_u64(out,_const_strconv__ten_pow_table_64[out_len - n_digit]);
		u64 out_div = VSAFE_DIV_u64(d.m , _const_strconv__ten_pow_table_64[out_len - n_digit]);
		if (out_div < out && strconv__dec_digits(out_div) < strconv__dec_digits(out)) {
			d_exp++;
			n_digit++;
		}
		out_len = n_digit;
	}
	int y = i + out_len;
	int x = 0;
	for (;;) {
		if (!(x < (out_len - disp - 1))) break;
		((u8*)buf.data)[y - x] = (rune)('0' + ((u8)(VSAFE_MOD_u64(out , 10))));
		out = VSAFE_DIV_u64(out,10);
		i++;
		x++;
	}
	if (out_len > 1 || fw_zeros > 0) {
		((u8*)buf.data)[y - x] = '.';
		i++;
	}
	x++;
	if (y - x >= 0) {
		((u8*)buf.data)[y - x] = (rune)('0' + ((u8)(VSAFE_MOD_u64(out , 10))));
		i++;
	}
	for (;;) {
		if (!(fw_zeros > 0)) break;
		((u8*)buf.data)[i] = '0';
		i++;
		fw_zeros--;
	}
	((u8*)buf.data)[i] = 'e';
	i++;
	int exp = d_exp + out_len_original - 1;
	if (exp < 0) {
		((u8*)buf.data)[i] = '-';
		i++;
		exp = -exp;
	} else {
		((u8*)buf.data)[i] = '+';
		i++;
	}
	int d2 = VSAFE_MOD_int(exp , 10);
	exp = VSAFE_DIV_int(exp,10);
	int d1 = VSAFE_MOD_int(exp , 10);
	int d0 = VSAFE_DIV_int(exp , 10);
	if (d0 > 0) {
		((u8*)buf.data)[i] = (rune)('0' + ((u8)(d0)));
		i++;
	}
	((u8*)buf.data)[i] = (rune)('0' + ((u8)(d1)));
	i++;
	((u8*)buf.data)[i] = (rune)('0' + ((u8)(d2)));
	i++;
	((u8*)buf.data)[i] = 0;
	return builtin__tos(builtin__memdup(&((u8*)buf.data)[0], i + 1), i);
}
VV_LOC multi_return_strconv__Dec64_bool strconv__f64_to_decimal_exact_int(u64 i_mant, u64 exp) {
	strconv__Dec64 _t1 = ((strconv__Dec64){.m = 0,.e = 0,});
	strconv__Dec64 d = _t1;
	u64 e = exp - 1023;
	if (e > _const_strconv__mantbits64) {
		return (multi_return_strconv__Dec64_bool){.arg0=d, .arg1=false};
	}
	u64 shift = (u64)(_const_strconv__mantbits64 - e);
	u64 mant = (i_mant | ((u64)(0x0010000000000000LL)));
	d.m = v__rshift_u64(mant, (u64)shift);
	if ((v__lshift_u64(d.m, (u64)shift)) != mant) {
		return (multi_return_strconv__Dec64_bool){.arg0=d, .arg1=false};
	}
	for (;;) {
		if (!((VSAFE_MOD_u64(d.m , 10)) == 0)) break;
		d.m = VSAFE_DIV_u64(d.m,10);
		d.e++;
	}
	return (multi_return_strconv__Dec64_bool){.arg0=d, .arg1=true};
}
VV_LOC strconv__Dec64 strconv__f64_to_decimal(u64 mant, u64 exp) {
	int e2 = 0;
	u64 m2 = ((u64)(0));
	if (exp == 0) {
		e2 = -1022 - ((int)(_const_strconv__mantbits64)) - 2;
		m2 = mant;
	} else {
		e2 = ((int)(exp)) - 1023 - ((int)(_const_strconv__mantbits64)) - 2;
		m2 = ((v__lshift_u64(((u64)(1)), (u64)_const_strconv__mantbits64)) | mant);
	}
	bool even = ((m2 & 1)) == 0;
	bool accept_bounds = even;
	u64 mv = ((u64)(4 * m2));
	u64 mm_shift = strconv__bool_to_u64(mant != 0 || exp <= 1);
	u64 vr = ((u64)(0));
	u64 vp = ((u64)(0));
	u64 vm = ((u64)(0));
	int e10 = 0;
	bool vm_is_trailing_zeros = false;
	bool vr_is_trailing_zeros = false;
	if (e2 >= 0) {
		u32 q = strconv__log10_pow2(e2) - strconv__bool_to_u32(e2 > 3);
		e10 = ((int)(q));
		int k = 122 + strconv__pow5_bits(((int)(q))) - 1;
		int i = -e2 + ((int)(q)) + k;
		strconv__Uint128 mul = *(((strconv__Uint128*)(&_const_strconv__pow5_inv_split_64_x[builtin__v_fixed_index(q * 2, 584)])));
		vr = strconv__mul_shift_64(((u64)(4)) * m2, mul, i);
		vp = strconv__mul_shift_64(((u64)(4)) * m2 + ((u64)(2)), mul, i);
		vm = strconv__mul_shift_64(((u64)(4)) * m2 - ((u64)(1)) - mm_shift, mul, i);
		if (q <= 21) {
			if (VSAFE_MOD_u64(mv , 5) == 0) {
				vr_is_trailing_zeros = strconv__multiple_of_power_of_five_64(mv, q);
			} else if (accept_bounds) {
				vm_is_trailing_zeros = strconv__multiple_of_power_of_five_64(mv - 1 - mm_shift, q);
			} else if (strconv__multiple_of_power_of_five_64(mv + 2, q)) {
				vp--;
			}
		}
	} else {
		u32 q = strconv__log10_pow5(-e2) - strconv__bool_to_u32(-e2 > 1);
		e10 = ((int)(q)) + e2;
		int i = -e2 - ((int)(q));
		int k = strconv__pow5_bits(i) - 121;
		int j = ((int)(q)) - k;
		strconv__Uint128 mul = *(((strconv__Uint128*)(&_const_strconv__pow5_split_64_x[builtin__v_fixed_index(i * 2, 652)])));
		vr = strconv__mul_shift_64(((u64)(4)) * m2, mul, j);
		vp = strconv__mul_shift_64(((u64)(4)) * m2 + ((u64)(2)), mul, j);
		vm = strconv__mul_shift_64(((u64)(4)) * m2 - ((u64)(1)) - mm_shift, mul, j);
		if (q <= 1) {
			vr_is_trailing_zeros = true;
			if (accept_bounds) {
				vm_is_trailing_zeros = (mm_shift == 1);
			} else {
				vp--;
			}
		} else if (q < 63) {
			vr_is_trailing_zeros = strconv__multiple_of_power_of_two_64(mv, q - 1);
		}
	}
	int removed = 0;
	u8 last_removed_digit = ((u8)(0));
	u64 out = ((u64)(0));
	if (vm_is_trailing_zeros || vr_is_trailing_zeros) {
		for (;;) {
			u64 vp_div_10 = VSAFE_DIV_u64(vp , 10);
			u64 vm_div_10 = VSAFE_DIV_u64(vm , 10);
			if (vp_div_10 <= vm_div_10) {
				break;
			}
			u64 vm_mod_10 = VSAFE_MOD_u64(vm , 10);
			u64 vr_div_10 = VSAFE_DIV_u64(vr , 10);
			u64 vr_mod_10 = VSAFE_MOD_u64(vr , 10);
			vm_is_trailing_zeros = vm_is_trailing_zeros && vm_mod_10 == 0;
			vr_is_trailing_zeros = vr_is_trailing_zeros && last_removed_digit == 0;
			last_removed_digit = ((u8)(vr_mod_10));
			vr = vr_div_10;
			vp = vp_div_10;
			vm = vm_div_10;
			removed++;
		}
		if (vm_is_trailing_zeros) {
			for (;;) {
				u64 vm_div_10 = VSAFE_DIV_u64(vm , 10);
				u64 vm_mod_10 = VSAFE_MOD_u64(vm , 10);
				if (vm_mod_10 != 0) {
					break;
				}
				u64 vp_div_10 = VSAFE_DIV_u64(vp , 10);
				u64 vr_div_10 = VSAFE_DIV_u64(vr , 10);
				u64 vr_mod_10 = VSAFE_MOD_u64(vr , 10);
				vr_is_trailing_zeros = vr_is_trailing_zeros && last_removed_digit == 0;
				last_removed_digit = ((u8)(vr_mod_10));
				vr = vr_div_10;
				vp = vp_div_10;
				vm = vm_div_10;
				removed++;
			}
		}
		if (vr_is_trailing_zeros && last_removed_digit == 5 && (VSAFE_MOD_u64(vr , 2)) == 0) {
			last_removed_digit = 4;
		}
		out = vr;
		if ((vr == vm && (!accept_bounds || !vm_is_trailing_zeros)) || last_removed_digit >= 5) {
			out++;
		}
	} else {
		bool round_up = false;
		for (;;) {
			if (!(VSAFE_DIV_u64(vp , 100) > VSAFE_DIV_u64(vm , 100))) break;
			round_up = (VSAFE_MOD_u64(vr , 100)) >= 50;
			vr = VSAFE_DIV_u64(vr,100);
			vp = VSAFE_DIV_u64(vp,100);
			vm = VSAFE_DIV_u64(vm,100);
			removed += 2;
		}
		for (;;) {
			if (!(VSAFE_DIV_u64(vp , 10) > VSAFE_DIV_u64(vm , 10))) break;
			round_up = (VSAFE_MOD_u64(vr , 10)) >= 5;
			vr = VSAFE_DIV_u64(vr,10);
			vp = VSAFE_DIV_u64(vp,10);
			vm = VSAFE_DIV_u64(vm,10);
			removed++;
		}
		out = vr + strconv__bool_to_u64(vr == vm || round_up);
	}
	return ((strconv__Dec64){.m = out,.e = e10 + removed,});
}
string strconv__f64_to_str(f64 f, int n_digit) {
	strconv__Uf64 _t1 = ((strconv__Uf64){0});
	strconv__Uf64 u1 = _t1;
	u1.f = f;
	u64 u = u1.u;
	bool neg = (v__rshift_u64(u, (u64)(_const_strconv__mantbits64 + _const_strconv__expbits64))) != 0;
	u64 mant = (u & ((v__lshift_u64(((u64)(1)), (u64)_const_strconv__mantbits64)) - ((u64)(1))));
	u64 exp = ((v__rshift_u64(u, (u64)_const_strconv__mantbits64)) & ((v__lshift_u64(((u64)(1)), (u64)_const_strconv__expbits64)) - ((u64)(1))));
	if (exp == 2047 || (exp == 0 && mant == 0)) {
		return strconv__get_string_special(neg, exp == 0, mant == 0);
	}
	multi_return_strconv__Dec64_bool mr_9595 = strconv__f64_to_decimal_exact_int(mant, exp);
	strconv__Dec64 d = mr_9595.arg0;
	bool ok = mr_9595.arg1;
	if (!ok) {
		d = strconv__f64_to_decimal(mant, exp);
	}
	return strconv__Dec64_get_string_64(d, neg, n_digit, 0);
}
string strconv__f64_to_str_pad(f64 f, int n_digit) {
	strconv__Uf64 _t1 = ((strconv__Uf64){0});
	strconv__Uf64 u1 = _t1;
	u1.f = f;
	u64 u = u1.u;
	bool neg = (v__rshift_u64(u, (u64)(_const_strconv__mantbits64 + _const_strconv__expbits64))) != 0;
	u64 mant = (u & ((v__lshift_u64(((u64)(1)), (u64)_const_strconv__mantbits64)) - ((u64)(1))));
	u64 exp = ((v__rshift_u64(u, (u64)_const_strconv__mantbits64)) & ((v__lshift_u64(((u64)(1)), (u64)_const_strconv__expbits64)) - ((u64)(1))));
	if (exp == 2047 || (exp == 0 && mant == 0)) {
		return strconv__get_string_special(neg, exp == 0, mant == 0);
	}
	multi_return_strconv__Dec64_bool mr_10376 = strconv__f64_to_decimal_exact_int(mant, exp);
	strconv__Dec64 d = mr_10376.arg0;
	bool ok = mr_10376.arg1;
	if (!ok) {
		d = strconv__f64_to_decimal(mant, exp);
	}
	return strconv__Dec64_get_string_64(d, neg, n_digit, n_digit);
}
void strconv__format_str_sb(string s, strconv__BF_param p, strings__Builder* sb) {
	if (p.len0 <= 0) {
		strings__Builder_write_string(sb, s);
		return;
	}
	int dif = p.len0 - builtin__utf8_str_visible_length(s);
	if (dif <= 0) {
		strings__Builder_write_string(sb, s);
		return;
	}
	if (p.align == strconv__Align_text__right) {
		for (int i1 = 0; i1 < dif; i1++) {
			strings__Builder_write_u8(sb, p.pad_ch);
		}
	}
	strings__Builder_write_string(sb, s);
	if (p.align == strconv__Align_text__left) {
		for (int i1 = 0; i1 < dif; i1++) {
			strings__Builder_write_u8(sb, p.pad_ch);
		}
	}
}
void strconv__format_dec_sb(u64 d, strconv__BF_param p, strings__Builder* res) {
	int n_char = strconv__dec_digits(d);
	int sign_len = (!p.positive || p.sign_flag ? (1) : (0));
	int number_len = sign_len + n_char;
	int dif = p.len0 - number_len;
	bool sign_written = false;
	if (p.align == strconv__Align_text__right) {
		if (p.pad_ch == '0') {
			if (p.positive) {
				if (p.sign_flag) {
					strings__Builder_write_u8(res, '+');
					sign_written = true;
				}
			} else {
				strings__Builder_write_u8(res, '-');
				sign_written = true;
			}
		}
		for (int i1 = 0; i1 < dif; i1++) {
			strings__Builder_write_u8(res, p.pad_ch);
		}
	}
	if (!sign_written) {
		if (p.positive) {
			if (p.sign_flag) {
				strings__Builder_write_u8(res, '+');
			}
		} else {
			strings__Builder_write_u8(res, '-');
		}
	}
	Array_fixed_u8_32 buf = {0};
	int i = 20;
	u64 n = d;
	u64 d_i = ((u64)(0));
	if (n > 0) {
		for (;;) {
			if (!(n > 0)) break;
			u64 n1 = VSAFE_DIV_u64(n , 100);
			d_i = v__lshift_u64((n - (n1 * 100)), (u64)1);
			n = n1;
			{ // Unsafe block
				buf[i] = _const_strconv__digit_pairs.str[d_i];
			}
			i--;
			d_i++;
			{ // Unsafe block
				buf[i] = _const_strconv__digit_pairs.str[d_i];
			}
			i--;
		}
		i++;
		if (d_i < 20) {
			i++;
		}
		strings__Builder_write_ptr(res, &buf[i], n_char);
	} else {
		strings__Builder_write_u8(res, '0');
	}
	if (p.align == strconv__Align_text__left) {
		for (int i1 = 0; i1 < dif; i1++) {
			strings__Builder_write_u8(res, p.pad_ch);
		}
	}
	return;
}
string strconv__f64_to_str_lnd1(f64 f, int dec_digit) {
	{ // Unsafe block
		int clamped_dec = (dec_digit >= 36 ? (36 - 1) : (dec_digit));
		string s = strconv__f64_to_str(f + _const_strconv__dec_round[clamped_dec], 18);
		if (s.len > 2 && (s.str[ 0] == 'n' || s.str[ 1] == 'i')) {
			return s;
		}
		bool m_sgn_flag = false;
		int sgn = 1;
		Array_fixed_u8_26 b = {0};
		int d_pos = 1;
		int i = 0;
		int i1 = 0;
		int exp = 0;
		int exp_sgn = 1;
		int dot_res_sp = -1;
		for (int _t2 = 0; _t2 < s.len; ++_t2) {
			u8 c = s.str[_t2];

			if (c == ('-')) {
				sgn = -1;
				i++;
			}
			else if (c == ('+')) {
				sgn = 1;
				i++;
			}
			else if ((c >= '0' && c <= '9')) {
				b[i1] = c;
				i1++;
				i++;
			}
			else if (c == ('.')) {
				if (sgn > 0) {
					d_pos = i;
				} else {
					d_pos = i - 1;
				}
				i++;
			}
			else if (c == ('e')) {
				i++;
				break;
			}
			else {
				builtin__string_free(&s);
				return _S("[Float conversion error!!]");
			}
		}
		b[i1] = 0;
		if (s.str[ i] == '-') {
			exp_sgn = -1;
			i++;
		} else if (s.str[ i] == '+') {
			exp_sgn = 1;
			i++;
		}
		int c = i;
		for (;;) {
			if (!(c < s.len)) break;
			exp = exp * 10 + ((int)((rune)(s.str[ c] - '0')));
			c++;
		}
		int extra_frac_digits = (dec_digit > 0 ? (dec_digit) : (0));
		int sign_len = (sgn < 0 ? (1) : (0));
		Array_u8 res = builtin____new_array_with_default(sign_len + i1 + exp + extra_frac_digits + 4, 0, sizeof(u8), &(u8[]){0});
		int r_i = 0;
		builtin__string_free(&s);
		if (sgn == 1) {
			if (m_sgn_flag) {
				((u8*)res.data)[r_i] = '+';
				r_i++;
			}
		} else {
			((u8*)res.data)[r_i] = '-';
			r_i++;
		}
		i = 0;
		if (exp_sgn >= 0) {
			for (;;) {
				if (!(b[i] != 0)) break;
				((u8*)res.data)[r_i] = b[i];
				r_i++;
				i++;
				if (i >= d_pos && exp >= 0) {
					if (exp == 0) {
						dot_res_sp = r_i;
						((u8*)res.data)[r_i] = '.';
						r_i++;
					}
					exp--;
				}
			}
			for (;;) {
				if (!(exp >= 0)) break;
				((u8*)res.data)[r_i] = '0';
				r_i++;
				exp--;
			}
		} else {
			bool dot_p = true;
			for (;;) {
				if (!(exp > 0)) break;
				((u8*)res.data)[r_i] = '0';
				r_i++;
				exp--;
				if (dot_p) {
					dot_res_sp = r_i;
					((u8*)res.data)[r_i] = '.';
					r_i++;
					dot_p = false;
				}
			}
			for (;;) {
				if (!(b[i] != 0)) break;
				((u8*)res.data)[r_i] = b[i];
				r_i++;
				i++;
			}
		}
		if (dec_digit <= 0) {
			if (dot_res_sp < 0) {
				dot_res_sp = i + 1;
			}
			string tmp_res = builtin__string_clone(builtin__tos(res.data, dot_res_sp));
			builtin__array_free(&res);
			return tmp_res;
		}
		if (dot_res_sp >= 0) {
			r_i = dot_res_sp + dec_digit + 1;
			((u8*)res.data)[r_i] = 0;
			for (int c1 = 1; c1 < dec_digit + 1; ++c1) {
				if (((u8*)res.data)[(int)(r_i - c1)] == 0) {
					((u8*)res.data)[(int)(r_i - c1)] = '0';
				}
			}
			string tmp_res = builtin__string_clone(builtin__tos(res.data, r_i));
			builtin__array_free(&res);
			return tmp_res;
		} else {
			if (dec_digit > 0) {
				int c1 = 0;
				((u8*)res.data)[r_i] = '.';
				r_i++;
				for (;;) {
					if (!(c1 < dec_digit)) break;
					((u8*)res.data)[r_i] = '0';
					r_i++;
					c1++;
				}
				((u8*)res.data)[r_i] = 0;
			}
			string tmp_res = builtin__string_clone(builtin__tos(res.data, r_i));
			builtin__array_free(&res);
			return tmp_res;
		}
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}
string strconv__format_fl(f64 f, strconv__BF_param p) {
	{ // Unsafe block
		string fs = strconv__f64_to_str_lnd1((f >= ((f64)(0.0)) ? (f) : (-f)), p.len1);
		if (fs.str[ 0] == '[') {
			return fs;
		}
		if (p.rm_tail_zero) {
			string tmp = fs;
			fs = strconv__remove_tail_zeros(fs);
			builtin__string_free(&tmp);
		}
		Array_fixed_u8_512 buf = {0};
		Array_fixed_u8_512 out = {0};
		int buf_i = 0;
		int out_i = 0;
		int sign_len_diff = 0;
		if (p.pad_ch == '0') {
			if (p.positive) {
				if (p.sign_flag) {
					out[out_i] = '+';
					out_i++;
					sign_len_diff = -1;
				}
			} else {
				out[out_i] = '-';
				out_i++;
				sign_len_diff = -1;
			}
		} else {
			if (p.positive) {
				if (p.sign_flag) {
					buf[buf_i] = '+';
					buf_i++;
				}
			} else {
				buf[buf_i] = '-';
				buf_i++;
			}
		}
		builtin__vmemcpy(&buf[buf_i], fs.str, fs.len);
		buf_i += fs.len;
		int dif = p.len0 - buf_i + sign_len_diff;
		if (p.align == strconv__Align_text__right) {
			for (int i1 = 0; i1 < dif; i1++) {
				out[out_i] = p.pad_ch;
				out_i++;
			}
		}
		builtin__vmemcpy(&out[out_i], &buf[0], buf_i);
		out_i += buf_i;
		if (p.align == strconv__Align_text__left) {
			for (int i1 = 0; i1 < dif; i1++) {
				out[out_i] = p.pad_ch;
				out_i++;
			}
		}
		out[out_i] = 0;
		string tmp = fs;
		fs = builtin__tos_clone(&out[0]);
		builtin__string_free(&tmp);
		return fs;
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}
string strconv__format_es(f64 f, strconv__BF_param p) {
	{ // Unsafe block
		string fs = strconv__f64_to_str_pad((f > 0 ? (f) : (-f)), p.len1);
		if (p.rm_tail_zero) {
			string tmp = fs;
			fs = strconv__remove_tail_zeros(fs);
			builtin__string_free(&tmp);
		}
		Array_fixed_u8_512 buf = {0};
		Array_fixed_u8_512 out = {0};
		int buf_i = 0;
		int out_i = 0;
		int sign_len_diff = 0;
		if (p.pad_ch == '0') {
			if (p.positive) {
				if (p.sign_flag) {
					out[out_i] = '+';
					out_i++;
					sign_len_diff = -1;
				}
			} else {
				out[out_i] = '-';
				out_i++;
				sign_len_diff = -1;
			}
		} else {
			if (p.positive) {
				if (p.sign_flag) {
					buf[buf_i] = '+';
					buf_i++;
				}
			} else {
				buf[buf_i] = '-';
				buf_i++;
			}
		}
		builtin__vmemcpy(&buf[buf_i], fs.str, fs.len);
		buf_i += fs.len;
		int dif = p.len0 - buf_i + sign_len_diff;
		if (p.align == strconv__Align_text__right) {
			for (int i1 = 0; i1 < dif; i1++) {
				out[out_i] = p.pad_ch;
				out_i++;
			}
		}
		builtin__vmemcpy(&out[out_i], &buf[0], buf_i);
		out_i += buf_i;
		if (p.align == strconv__Align_text__left) {
			for (int i1 = 0; i1 < dif; i1++) {
				out[out_i] = p.pad_ch;
				out_i++;
			}
		}
		out[out_i] = 0;
		string tmp = fs;
		fs = builtin__tos_clone(&out[0]);
		builtin__string_free(&tmp);
		return fs;
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}
string strconv__remove_tail_zeros(string s) {
	{ // Unsafe block
		u8* buf = builtin__malloc_noscan(s.len + 1);
		int i_d = 0;
		int i_s = 0;
		for (;;) {
			if (!(i_s < s.len && !(s.str[ i_s] == '-' || s.str[ i_s] == '+') && (s.str[ i_s] > '9' || s.str[ i_s] < '0'))) break;
			buf[i_d] = s.str[ i_s];
			i_s++;
			i_d++;
		}
		if (i_s < s.len && (s.str[ i_s] == '-' || s.str[ i_s] == '+')) {
			buf[i_d] = s.str[ i_s];
			i_s++;
			i_d++;
		}
		for (;;) {
			if (!(i_s < s.len && s.str[ i_s] >= '0' && s.str[ i_s] <= '9')) break;
			buf[i_d] = s.str[ i_s];
			i_s++;
			i_d++;
		}
		if (i_s < s.len && s.str[ i_s] == '.') {
			int i_s1 = i_s + 1;
			int sum = 0;
			int i_s2 = i_s1;
			for (;;) {
				if (!(i_s1 < s.len && s.str[ i_s1] >= '0' && s.str[ i_s1] <= '9')) break;
				sum += (s.str[ i_s1] - ((u8)('0')));
				if (s.str[ i_s1] != '0') {
					i_s2 = i_s1;
				}
				i_s1++;
			}
			if (sum > 0) {
				for (int c_i = i_s; c_i < i_s2 + 1; ++c_i) {
					buf[i_d] = s.str[ c_i];
					i_d++;
				}
			}
			i_s = i_s1;
		}
		if (i_s < s.len && s.str[ i_s] != '.') {
			for (;;) {
				buf[i_d] = s.str[ i_s];
				i_s++;
				i_d++;
				if (i_s >= s.len) {
					break;
				}
			}
		}
		buf[i_d] = 0;
		return builtin__tos(buf, i_d);
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}
inline string strconv__ftoa_64(f64 f) {
	return strconv__f64_to_str(f, 17);
}
inline string strconv__ftoa_32(f32 f) {
	return strconv__f32_to_str(f, 8);
}
string strconv__format_int(i64 n, int radix) {
	{ // Unsafe block
		if (radix < 2 || radix > 36) {
			builtin__panic_n(_S("invalid radix, it should be => 2 and <= 36, actual:"), radix);
			VUNREACHABLE();
		}
		if (n == 0) {
			return _S("0");
		}
		i64 n_copy = n;
		bool have_minus = false;
		if (n < 0) {
			have_minus = true;
			n_copy = -n_copy;
		}
		string res = _S("");
		for (;;) {
			if (!(n_copy != 0)) break;
			string tmp_0 = res;
			int bdx = ((int)((i64)(VSAFE_MOD_i64(n_copy , radix))));
			string tmp_1 = builtin__u8_ascii_str(_const_strconv__base_digits.str[ bdx]);
			res = builtin__string__plus(tmp_1, res);
			builtin__string_free(&tmp_0);
			builtin__string_free(&tmp_1);
			n_copy = VSAFE_DIV_i64(n_copy,radix);
		}
		if (have_minus) {
			string final_res = builtin__string__plus(_S("-"), res);
			builtin__string_free(&res);
			return final_res;
		}
		return res;
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}
string strconv__format_uint(u64 n, int radix) {
	{ // Unsafe block
		if (radix < 2 || radix > 36) {
			builtin__panic_n(_S("invalid radix, it should be => 2 and <= 36, actual:"), radix);
			VUNREACHABLE();
		}
		if (n == 0) {
			return _S("0");
		}
		u64 n_copy = n;
		string res = _S("");
		u64 uradix = ((u64)(radix));
		for (;;) {
			if (!(n_copy != 0)) break;
			string tmp_0 = res;
			string tmp_1 = builtin__u8_ascii_str(_const_strconv__base_digits.str[ ((int)(VSAFE_MOD_u64(n_copy , uradix)))]);
			res = builtin__string__plus(tmp_1, res);
			builtin__string_free(&tmp_0);
			builtin__string_free(&tmp_1);
			n_copy = VSAFE_DIV_u64(n_copy,uradix);
		}
		return res;
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}
string strconv__f32_to_str_l(f32 f) {
	string s = strconv__f32_to_str(f, 8);
	string res = strconv__fxx_to_str_l_parse(s);
	builtin__string_free(&s);
	return res;
}
string strconv__f32_to_str_l_with_dot(f32 f) {
	string s = strconv__f32_to_str(f, 8);
	string res = strconv__fxx_to_str_l_parse_with_dot(s);
	builtin__string_free(&s);
	return res;
}
string strconv__f64_to_str_l(f64 f) {
	string s = strconv__f64_to_str(f, 18);
	string res = strconv__fxx_to_str_l_parse(s);
	builtin__string_free(&s);
	return res;
}
string strconv__f64_to_str_l_with_dot(f64 f) {
	string s = strconv__f64_to_str(f, 18);
	string res = strconv__fxx_to_str_l_parse_with_dot(s);
	builtin__string_free(&s);
	return res;
}
string strconv__fxx_to_str_l_parse(string s) {
	if (s.len > 2 && (s.str[ 0] == 'n' || s.str[ 1] == 'i')) {
		return builtin__string_clone(s);
	}
	bool m_sgn_flag = false;
	int sgn = 1;
	Array_fixed_u8_26 b = {0};
	int d_pos = 1;
	int i = 0;
	int i1 = 0;
	int exp = 0;
	int exp_sgn = 1;
	for (int _t2 = 0; _t2 < s.len; ++_t2) {
		u8 c = s.str[_t2];
		if (c == '-') {
			sgn = -1;
			i++;
		} else if (c == '+') {
			sgn = 1;
			i++;
		} else if (c >= '0' && c <= '9') {
			b[i1] = c;
			i1++;
			i++;
		} else if (c == '.') {
			if (sgn > 0) {
				d_pos = i;
			} else {
				d_pos = i - 1;
			}
			i++;
		} else if (c == 'e') {
			i++;
			break;
		} else {
			return _S("Float conversion error!!");
		}
	}
	b[i1] = 0;
	if (s.str[ i] == '-') {
		exp_sgn = -1;
		i++;
	} else if (s.str[ i] == '+') {
		exp_sgn = 1;
		i++;
	}
	int c = i;
	for (;;) {
		if (!(c < s.len)) break;
		exp = exp * 10 + ((int)((rune)(s.str[ c] - '0')));
		c++;
	}
	Array_u8 res = builtin____new_array_with_default(exp + 32, 0, sizeof(u8), &(u8[]){0});
	int r_i = 0;
	if (sgn == 1) {
		if (m_sgn_flag) {
			((u8*)res.data)[r_i] = '+';
			r_i++;
		}
	} else {
		((u8*)res.data)[r_i] = '-';
		r_i++;
	}
	i = 0;
	if (exp_sgn >= 0) {
		for (;;) {
			if (!(b[i] != 0)) break;
			((u8*)res.data)[r_i] = b[i];
			r_i++;
			i++;
			if (i >= d_pos && exp >= 0) {
				if (exp == 0) {
					((u8*)res.data)[r_i] = '.';
					r_i++;
				}
				exp--;
			}
		}
		for (;;) {
			if (!(exp >= 0)) break;
			((u8*)res.data)[r_i] = '0';
			r_i++;
			exp--;
		}
	} else {
		bool dot_p = true;
		for (;;) {
			if (!(exp > 0)) break;
			((u8*)res.data)[r_i] = '0';
			r_i++;
			exp--;
			if (dot_p) {
				((u8*)res.data)[r_i] = '.';
				r_i++;
				dot_p = false;
			}
		}
		for (;;) {
			if (!(b[i] != 0)) break;
			((u8*)res.data)[r_i] = b[i];
			r_i++;
			i++;
		}
	}
	if (r_i > 1 && ((u8*)res.data)[r_i - 1] == '.') {
		((u8*)res.data)[r_i] = '0';
		r_i++;
	} else if (!(Array_u8_contains(res, '.'))) {
		((u8*)res.data)[r_i] = '.';
		r_i++;
		((u8*)res.data)[r_i] = '0';
		r_i++;
	}
	((u8*)res.data)[r_i] = 0;
	string tmp_res = builtin__string_clone(builtin__tos(res.data, r_i));
	builtin__array_free(&res);
	return tmp_res;
}
string strconv__fxx_to_str_l_parse_with_dot(string s) {
	if (s.len > 2 && (s.str[ 0] == 'n' || s.str[ 1] == 'i')) {
		return builtin__string_clone(s);
	}
	bool m_sgn_flag = false;
	int sgn = 1;
	Array_fixed_u8_26 b = {0};
	int d_pos = 1;
	int i = 0;
	int i1 = 0;
	int exp = 0;
	int exp_sgn = 1;
	for (int _t2 = 0; _t2 < s.len; ++_t2) {
		u8 c = s.str[_t2];
		if (c == '-') {
			sgn = -1;
			i++;
		} else if (c == '+') {
			sgn = 1;
			i++;
		} else if (c >= '0' && c <= '9') {
			b[i1] = c;
			i1++;
			i++;
		} else if (c == '.') {
			if (sgn > 0) {
				d_pos = i;
			} else {
				d_pos = i - 1;
			}
			i++;
		} else if (c == 'e') {
			i++;
			break;
		} else {
			return _S("Float conversion error!!");
		}
	}
	b[i1] = 0;
	if (s.str[ i] == '-') {
		exp_sgn = -1;
		i++;
	} else if (s.str[ i] == '+') {
		exp_sgn = 1;
		i++;
	}
	int c = i;
	for (;;) {
		if (!(c < s.len)) break;
		exp = exp * 10 + ((int)((rune)(s.str[ c] - '0')));
		c++;
	}
	Array_u8 res = builtin____new_array_with_default(exp + 32, 0, sizeof(u8), &(u8[]){0});
	int r_i = 0;
	if (sgn == 1) {
		if (m_sgn_flag) {
			((u8*)res.data)[r_i] = '+';
			r_i++;
		}
	} else {
		((u8*)res.data)[r_i] = '-';
		r_i++;
	}
	i = 0;
	if (exp_sgn >= 0) {
		for (;;) {
			if (!(b[i] != 0)) break;
			((u8*)res.data)[r_i] = b[i];
			r_i++;
			i++;
			if (i >= d_pos && exp >= 0) {
				if (exp == 0) {
					((u8*)res.data)[r_i] = '.';
					r_i++;
				}
				exp--;
			}
		}
		for (;;) {
			if (!(exp >= 0)) break;
			((u8*)res.data)[r_i] = '0';
			r_i++;
			exp--;
		}
	} else {
		bool dot_p = true;
		for (;;) {
			if (!(exp > 0)) break;
			((u8*)res.data)[r_i] = '0';
			r_i++;
			exp--;
			if (dot_p) {
				((u8*)res.data)[r_i] = '.';
				r_i++;
				dot_p = false;
			}
		}
		for (;;) {
			if (!(b[i] != 0)) break;
			((u8*)res.data)[r_i] = b[i];
			r_i++;
			i++;
		}
	}
	if (r_i > 1 && ((u8*)res.data)[r_i - 1] == '.') {
		((u8*)res.data)[r_i] = '0';
		r_i++;
	} else if (!(Array_u8_contains(res, '.'))) {
		((u8*)res.data)[r_i] = '.';
		r_i++;
		((u8*)res.data)[r_i] = '0';
		r_i++;
	}
	((u8*)res.data)[r_i] = 0;
	string tmp_res = builtin__string_clone(builtin__tos(res.data, r_i));
	builtin__array_free(&res);
	return tmp_res;
}
inline VV_LOC u32 strconv__bool_to_u32(bool b) {
	if (b) {
		return ((u32)(1));
	}
	return ((u32)(0));
}
inline VV_LOC u64 strconv__bool_to_u64(bool b) {
	if (b) {
		return ((u64)(1));
	}
	return ((u64)(0));
}
VV_LOC string strconv__get_string_special(bool neg, bool expZero, bool mantZero) {
	if (!mantZero) {
		return _S("nan");
	}
	if (!expZero) {
		if (neg) {
			return _S("-inf");
		} else {
			return _S("+inf");
		}
	}
	if (neg) {
		return _S("-0e+00");
	}
	return _S("0e+00");
}
VV_LOC u32 strconv__mul_shift_32(u32 m, u64 mul, int ishift) {
	multi_return_u64_u64 mr_750 = math__bits__mul_64(((u64)(m)), mul);
	u64 hi = mr_750.arg0;
	u64 lo = mr_750.arg1;
	u64 shifted_sum = (v__rshift_u64(lo, (u64)((u64)(ishift)))) + (v__lshift_u64(hi, (u64)((u64)(64 - ishift))));
	;
	return ((u32)(shifted_sum));
}
inline VV_LOC u32 strconv__mul_pow5_invdiv_pow2(u32 m, u32 q, int j) {
	;
	return strconv__mul_shift_32(m, _const_strconv__pow5_inv_split_32[q], j);
}
inline VV_LOC u32 strconv__mul_pow5_div_pow2(u32 m, u32 i, int j) {
	;
	return strconv__mul_shift_32(m, _const_strconv__pow5_split_32[i], j);
}
VV_LOC u32 strconv__pow5_factor_32(u32 i_v) {
	u32 v = i_v;
	for (u32 n = ((u32)(0)); true; n++) {
		u32 q = VSAFE_DIV_u32(v , 5);
		u32 r = VSAFE_MOD_u32(v , 5);
		if (r != 0) {
			return n;
		}
		v = q;
	}
	return v;
}
VV_LOC bool strconv__multiple_of_power_of_five_32(u32 v, u32 p) {
	return strconv__pow5_factor_32(v) >= p;
}
VV_LOC bool strconv__multiple_of_power_of_two_32(u32 v, u32 p) {
	return ((u32)(math__bits__trailing_zeros_32(v))) >= p;
}
VV_LOC u32 strconv__log10_pow2(int e) {
	;
	;
	return v__rshift_u32((((u32)(e)) * 78913), (u64)18);
}
VV_LOC u32 strconv__log10_pow5(int e) {
	;
	;
	return v__rshift_u32((((u32)(e)) * 732923), (u64)20);
}
VV_LOC int strconv__pow5_bits(int e) {
	;
	;
	return ((int)((v__rshift_u32((((u32)(e)) * 1217359), (u64)19)) + 1));
}
VV_LOC u64 strconv__shift_right_128(strconv__Uint128 v, int shift) {
	;
	return ((v__lshift_u64(v.hi, (u64)((u64)(64 - shift)))) | (v__rshift_u64(v.lo, (u64)((u32)(shift)))));
}
VV_LOC u64 strconv__mul_shift_64(u64 m, strconv__Uint128 mul, int shift) {
	multi_return_u64_u64 mr_3253 = math__bits__mul_64(m, mul.hi);
	u64 hihi = mr_3253.arg0;
	u64 hilo = mr_3253.arg1;
	multi_return_u64_u64 mr_3288 = math__bits__mul_64(m, mul.lo);
	u64 lohi = mr_3288.arg0;
	strconv__Uint128 sum = ((strconv__Uint128){.lo = lohi + hilo,.hi = hihi,});
	if (sum.lo < lohi) {
		sum.hi++;
	}
	return strconv__shift_right_128(sum, shift - 64);
}
VV_LOC u32 strconv__pow5_factor_64(u64 v_i) {
	u64 v = v_i;
	for (u32 n = ((u32)(0)); true; n++) {
		u64 q = VSAFE_DIV_u64(v , 5);
		u64 r = VSAFE_MOD_u64(v , 5);
		if (r != 0) {
			return n;
		}
		v = q;
	}
	return ((u32)(0));
}
VV_LOC bool strconv__multiple_of_power_of_five_64(u64 v, u32 p) {
	return strconv__pow5_factor_64(v) >= p;
}
VV_LOC bool strconv__multiple_of_power_of_two_64(u64 v, u32 p) {
	return ((u32)(math__bits__trailing_zeros_64(v))) >= p;
}
int strconv__dec_digits(u64 n) {
	if (n <= 9999999999LL) {
		if (n <= 99999) {
			if (n <= 99) {
				if (n <= 9) {
					return 1;
				} else {
					return 2;
				}
			} else {
				if (n <= 999) {
					return 3;
				} else {
					if (n <= 9999) {
						return 4;
					} else {
						return 5;
					}
				}
			}
		} else {
			if (n <= 9999999) {
				if (n <= 999999) {
					return 6;
				} else {
					return 7;
				}
			} else {
				if (n <= 99999999) {
					return 8;
				} else {
					if (n <= 999999999) {
						return 9;
					}
					return 10;
				}
			}
		}
	} else {
		if (n <= 999999999999999LL) {
			if (n <= 999999999999LL) {
				if (n <= 99999999999LL) {
					return 11;
				} else {
					return 12;
				}
			} else {
				if (n <= 9999999999999LL) {
					return 13;
				} else {
					if (n <= 99999999999999LL) {
						return 14;
					} else {
						return 15;
					}
				}
			}
		} else {
			if (n <= 99999999999999999LL) {
				if (n <= 9999999999999999LL) {
					return 16;
				} else {
					return 17;
				}
			} else {
				if (n <= 999999999999999999LL) {
					return 18;
				} else {
					if (n <= 9999999999999999999ULL) {
						return 19;
					}
					return 20;
				}
			}
		}
	}
	return 0;
}
VNORETURN VV_LOC void builtin___memory_panic(string fname, isize size) {
	v_memory_panic = true;
	builtin__eprint(fname);
	builtin__eprint(_S("("));
	#if 0
	{
	}
	#else
	{
		fprintf(stderr, "%p", ((voidptr)(size)));
	}
	#endif
	if (size < 0) {
		builtin__eprint(_S(" < 0"));
	}
	builtin__eprintln(_S(")"));
	builtin___v_panic(_S("memory allocation failure"));
	VUNREACHABLE();
	while(1);
}
u8* builtin___v_malloc(isize n) {
	if (n < 0) {
		builtin___memory_panic(_S("malloc"), n);
		VUNREACHABLE();
	} else if (n == 0) {
		return ((u8*)(((void*)0)));
	}
	u8* res = ((u8*)(((void*)0)));
	#if 0
	{
	}
	#elif defined(CUSTOM_DEFINE_vgc)
	{
	}
	#elif defined(CUSTOM_DEFINE_gcboehm)
	{
	}
	#elif 0
	{
	}
	#else
	{
		#if 0
		{
		}
		#else
		{
			res = malloc(n);
		}
		#endif
	}
	#endif
	if (res == 0) {
		builtin___memory_panic(_S("malloc"), n);
		VUNREACHABLE();
	}
	;
	return res;
}
u8* builtin__malloc_noscan(isize n) {
	if (n < 0) {
		builtin___memory_panic(_S("malloc_noscan"), n);
		VUNREACHABLE();
	}
	u8* res = ((u8*)(((void*)0)));
	#if 0
	{
	}
	#elif defined(CUSTOM_DEFINE_vgc)
	{
	}
	#elif defined(CUSTOM_DEFINE_gcboehm)
	{
	}
	#elif 0
	{
	}
	#else
	{
		#if 0
		{
		}
		#else
		{
			res = malloc(n);
		}
		#endif
	}
	#endif
	if (res == 0) {
		builtin___memory_panic(_S("malloc_noscan"), n);
		VUNREACHABLE();
	}
	;
	return res;
}
VV_LOC u8* builtin__malloc_uninit(isize n) {
	if (n < 0) {
		builtin___memory_panic(_S("malloc_uninit"), n);
		VUNREACHABLE();
	} else if (n == 0) {
		return ((u8*)(((void*)0)));
	}
	return builtin___v_malloc(n);
}
inline VV_LOC u64 builtin____at_least_one(u64 how_many) {
	if (how_many == 0) {
		return 1;
	}
	return how_many;
}
u8* builtin__v_realloc(u8* b, isize n) {
	u8* new_ptr = ((u8*)(((void*)0)));
	#if 0
	{
	}
	#elif defined(CUSTOM_DEFINE_vgc)
	{
	}
	#elif defined(CUSTOM_DEFINE_gcboehm)
	{
	}
	#else
	{
		#if 0
		{
		}
		#else
		{
			new_ptr = realloc(b, n);
		}
		#endif
	}
	#endif
	if (new_ptr == 0) {
		builtin___memory_panic(_S("v_realloc"), n);
		VUNREACHABLE();
	}
	if (b != ((void*)0)) {
		;
	}
	;
	return new_ptr;
}
u8* builtin__realloc_data(u8* old_data, int old_size, int new_size) {
	u8* nptr = ((u8*)(((void*)0)));
	#if defined(CUSTOM_DEFINE_vgc)
	{
	}
	#elif defined(CUSTOM_DEFINE_gcboehm)
	{
	}
	#else
	{
		#if 0
		{
		}
		#else
		{
			nptr = realloc(old_data, new_size);
		}
		#endif
	}
	#endif
	if (nptr == 0) {
		builtin___memory_panic(_S("realloc_data"), ((isize)(new_size)));
		VUNREACHABLE();
	}
	if (old_data != ((void*)0)) {
		;
	}
	;
	return nptr;
}
u8* builtin__vcalloc(isize n) {
	if (n < 0) {
		builtin___memory_panic(_S("vcalloc"), n);
		VUNREACHABLE();
	} else if (n == 0) {
		return ((u8*)(((void*)0)));
	}
	#if 0
	{
	}
	#elif defined(CUSTOM_DEFINE_vgc)
	{
	}
	#elif defined(CUSTOM_DEFINE_gcboehm)
	{
	}
	#else
	{
		#if 0
		{
		}
		#else
		{
			voidptr r = calloc(1, n);
			;
			return r;
		}
		#endif
	}
	#endif
	return ((u8*)(((void*)0)));
}
u8* builtin__vcalloc_noscan(isize n) {
	#if 0
	{
	}
	#elif defined(CUSTOM_DEFINE_vgc)
	{
	}
	#elif defined(CUSTOM_DEFINE_gcboehm)
	{
	}
	#else
	{
		return builtin__vcalloc(n);
	}
	#endif
	return ((u8*)(((void*)0)));
}
void builtin___v_free(voidptr ptr) {
	if (ptr == 0) {
		return;
	}
	IError* none_err = ((IError*)(&_const_none__));
	if (ptr == none_err->_object) {
		return;
	}
	IError* sentinel_err = ((IError*)(&_const_error_sentinel));
	if (ptr == sentinel_err->_object) {
		return;
	}
	#if 0
	{
	}
	#elif defined(CUSTOM_DEFINE_vgc)
	{
	}
	#elif defined(CUSTOM_DEFINE_gcboehm)
	{
	}
	#else
	{
		;
		#if 0
		{
		}
		#else
		{
			free(ptr);
		}
		#endif
	}
	#endif
}
voidptr builtin__memdup(voidptr src, isize sz) {
	if (sz == 0) {
		return builtin__vcalloc(1);
	}
	{ // Unsafe block
		u8* mem = builtin___v_malloc(sz);
		return memcpy(mem, src, sz);
	}
	return 0;
}
voidptr builtin__memdup_noscan(voidptr src, isize sz) {
	if (sz == 0) {
		return builtin__vcalloc_noscan(1);
	}
	{ // Unsafe block
		u8* mem = builtin__malloc_noscan(sz);
		return memcpy(mem, src, sz);
	}
	return 0;
}
inline VV_LOC int builtin__array_data_header_size(void) {
	return ((int)(sizeof(voidptr)));
}
inline VV_LOC u64 builtin__array_data_allocation_size(u64 total_size) {
	return ((u64)(builtin__array_data_header_size())) + builtin____at_least_one(total_size);
}
inline VV_LOC voidptr builtin__alloc_array_data(u64 total_size) {
	u8* raw = builtin__vcalloc(builtin__array_data_allocation_size(total_size));
	return ((u8*)(raw)) + builtin__array_data_header_size();
}
inline VV_LOC voidptr builtin__alloc_array_data_uninit(u64 total_size) {
	u8* raw = builtin__malloc_uninit(builtin__array_data_allocation_size(total_size));
	{ // Unsafe block
		(((ArrayDataHeader*)(raw)))->has_slices = false;
		return ((u8*)(raw)) + builtin__array_data_header_size();
	}
	return 0;
}
inline VV_LOC bool builtin__array_uses_noscan_data(array a) {
	return builtin__ArrayFlags_has(&a.flags, ArrayFlags__noscan_data);
}
inline VV_LOC voidptr builtin__array_alloc_array_data_like(array a, u64 total_size) {
	return builtin__alloc_array_data(total_size);
}
inline VV_LOC voidptr builtin__array_alloc_array_data_like_uninit(array a, u64 total_size) {
	return builtin__alloc_array_data_uninit(total_size);
}
inline VV_LOC ArrayDataHeader* builtin__array_data_header(array a) {
	if (!builtin__ArrayFlags_has(&a.flags, ArrayFlags__managed) || a.data == ((void*)0)) {
		return ((void*)0);
	}
	u8* base_data = ((u8*)(a.data)) - ((u64)(a.offset));
	return ((ArrayDataHeader*)(base_data - builtin__array_data_header_size()));
}
inline VV_LOC bool builtin__array_buffer_has_slices(array a) {
	if (!builtin__ArrayFlags_has(&a.flags, ArrayFlags__managed) || a.data == ((void*)0)) {
		return false;
	}
	ArrayDataHeader* header = builtin__array_data_header(a);
	if (header == ((void*)0)) {
		return false;
	}
	return header->has_slices;
}
inline VV_LOC void builtin__array_mark_buffer_has_slices(array* a) {
	if (!builtin__ArrayFlags_has(&a->flags, ArrayFlags__managed) || a->data == ((void*)0)) {
		return;
	}
	{ // Unsafe block
		u8* base_data = ((u8*)(a->data)) - ((u64)(a->offset));
		ArrayDataHeader* header = ((ArrayDataHeader*)(base_data - builtin__array_data_header_size()));
		if (!header->has_slices) {
			header->has_slices = true;
		}
	}
}
inline VV_LOC void builtin__array_set_managed_flags(array* a, bool is_slice) {
	{ // Unsafe block
		builtin__ArrayFlags_set(&a->flags, ArrayFlags__managed);
		if (is_slice) {
			builtin__ArrayFlags_set(&a->flags, ArrayFlags__is_slice);
		} else {
			builtin__ArrayFlags_clear(&a->flags, ArrayFlags__is_slice);
		}
	}
}
inline VV_LOC void builtin__array_clone_shallow_to_cap(array* a, int new_cap) {
	if (new_cap <= 0) {
		builtin__ArrayFlags_clear(&a->flags, ((ArrayFlags__managed | ArrayFlags__noscan_data) | ArrayFlags__is_slice));
		a->data = ((void*)0);
		a->offset = 0;
		a->cap = 0;
		return;
	}
	bool use_noscan_data = builtin__array_uses_noscan_data(*a);
	u64 total_size = ((u64)(new_cap)) * ((u64)(a->element_size));
	voidptr new_data = builtin__array_alloc_array_data_like_uninit(*a, total_size);
	u64 copy_size = ((u64)(a->len)) * ((u64)(a->element_size));
	if (a->data != ((void*)0) && copy_size > 0) {
		builtin__vmemcpy(new_data, a->data, copy_size);
	}
	a->data = new_data;
	a->offset = 0;
	a->cap = new_cap;
	{ // Unsafe block
		if (use_noscan_data) {
			builtin__ArrayFlags_set(&a->flags, ArrayFlags__noscan_data);
		} else {
			builtin__ArrayFlags_clear(&a->flags, ArrayFlags__noscan_data);
		}
	}
	builtin__array_set_managed_flags(a, false);
}
inline VV_LOC int builtin__v_ni_index(int i, int len) {
	return (i < 0 ? (len + i) : (i));
}
VV_LOC array builtin____new_array(int mylen, int cap, int elm_size) {
	builtin__panic_on_negative_len(mylen);
	builtin__panic_on_negative_cap(cap);
	int cap_ = (cap < mylen ? (mylen) : (cap));
	u64 total_size = ((u64)(cap_)) * ((u64)(elm_size));
	voidptr data = ((void*)0);
	if (cap_ > 0 && mylen == 0) {
		data = builtin__alloc_array_data_uninit(total_size);
	} else if (cap_ > 0) {
		data = builtin__alloc_array_data(total_size);
	}
	array _t1 = ((array){.data = (voidptr)data,.offset = 0,.len = mylen,.cap = cap_,.flags = ArrayFlags__managed,.element_size = elm_size,});
	array arr = _t1;
	return arr;
}
VV_LOC array builtin____new_array_with_default(int mylen, int cap, int elm_size, voidptr val) {
	builtin__panic_on_negative_len(mylen);
	builtin__panic_on_negative_cap(cap);
	int cap_ = (cap < mylen ? (mylen) : (cap));
	array _t1 = ((array){.data = 0,.offset = 0,.len = mylen,.cap = cap_,.flags = ArrayFlags__managed,.element_size = elm_size,});
	array arr = _t1;
	u64 total_size = ((u64)(cap_)) * ((u64)(elm_size));
	if (cap_ > 0 && mylen == 0) {
		arr.data = builtin__alloc_array_data_uninit(total_size);
	} else if (cap_ > 0) {
		arr.data = builtin__alloc_array_data(total_size);
	}
	if (val != 0) {
		u8* eptr = ((u8*)(arr.data));
		{ // Unsafe block
			if (eptr != ((void*)0)) {
				if (arr.element_size == 1) {
					u8 byte_value = *(((u8*)(val)));
					for (int i = 0; i < arr.len; ++i) {
						eptr[i] = byte_value;
					}
				} else {
					for (int _t2 = 0; _t2 < arr.len; ++_t2) {
						builtin__vmemcpy(eptr, val, arr.element_size);
						eptr += arr.element_size;
					}
				}
			}
		}
	}
	return arr;
}
VV_LOC array builtin____new_array_with_multi_default(int mylen, int cap, int elm_size, voidptr val) {
	builtin__panic_on_negative_len(mylen);
	builtin__panic_on_negative_cap(cap);
	int cap_ = (cap < mylen ? (mylen) : (cap));
	array _t1 = ((array){.data = 0,.offset = 0,.len = mylen,.cap = cap_,.flags = ArrayFlags__managed,.element_size = elm_size,});
	array arr = _t1;
	u64 total_size = ((u64)(cap_)) * ((u64)(elm_size));
	if (cap_ > 0) {
		arr.data = builtin__alloc_array_data(total_size);
	}
	if (val != 0) {
		u8* eptr = ((u8*)(arr.data));
		{ // Unsafe block
			if (eptr != ((void*)0)) {
				for (int i = 0; i < arr.len; ++i) {
					builtin__vmemcpy(eptr, ((charptr)(val)) + (int)(i * arr.element_size), arr.element_size);
					eptr += arr.element_size;
				}
			}
		}
	}
	return arr;
}
VV_LOC array builtin____new_array_with_array_default(int mylen, int cap, int elm_size, array val, int depth) {
	builtin__panic_on_negative_len(mylen);
	builtin__panic_on_negative_cap(cap);
	int cap_ = (cap < mylen ? (mylen) : (cap));
	array _t1 = ((array){.data = 0,.offset = 0,.len = mylen,.cap = cap_,.flags = ArrayFlags__managed,.element_size = elm_size,});
	array arr = _t1;
	if (cap_ > 0) {
		arr.data = builtin__alloc_array_data(((u64)(cap_)) * ((u64)(elm_size)));
	}
	u8* eptr = ((u8*)(arr.data));
	{ // Unsafe block
		if (eptr != ((void*)0)) {
			for (int _t2 = 0; _t2 < arr.len; ++_t2) {
				array val_clone = builtin__array_clone_to_depth(&val, depth);
				builtin__vmemcpy(eptr, &val_clone, arr.element_size);
				eptr += arr.element_size;
			}
		}
	}
	return arr;
}
VV_LOC array builtin__new_array_from_c_array(int len, int cap, int elm_size, voidptr c_array) {
	builtin__panic_on_negative_len(len);
	builtin__panic_on_negative_cap(cap);
	int cap_ = cap;
	if (cap < len) {
		cap_ = len;
	}
	array _t1 = ((array){.data = builtin__alloc_array_data(((u64)(cap_)) * ((u64)(elm_size))),.offset = 0,.len = len,.cap = cap_,.flags = ArrayFlags__managed,.element_size = elm_size,});
	array arr = _t1;
	builtin__vmemcpy(arr.data, c_array, ((u64)(len)) * ((u64)(elm_size)));
	return arr;
}
void builtin__array_ensure_cap(array* a, int required) {
	if (required <= a->cap) {
		return;
	}
	if (builtin__ArrayFlags_has(&a->flags, ArrayFlags__nogrow)) {
		builtin__panic_n(_S("array.ensure_cap: array with the flag `.nogrow` cannot grow in size, array required new size:"), required);
		VUNREACHABLE();
	}
	i64 cap = (a->cap > 0 ? (((i64)(a->cap))) : (((i64)(2))));
	for (;;) {
		if (!(required > cap)) break;
		cap *= 2;
	}
	if (cap > _const_max_int) {
		if (a->cap < _const_max_int) {
			cap = _const_max_int;
		} else {
			builtin__panic_n(_S("array.ensure_cap: array needs to grow to cap (which is > 2^31):"), cap);
			VUNREACHABLE();
		}
	}
	u64 new_size = ((u64)(cap)) * ((u64)(a->element_size));
	bool use_noscan_data = builtin__array_uses_noscan_data(*a);
	voidptr new_data = builtin__array_alloc_array_data_like_uninit(*a, new_size);
	if (a->data != ((void*)0)) {
		builtin__vmemcpy(new_data, a->data, ((u64)(a->len)) * ((u64)(a->element_size)));
		if (builtin__ArrayFlags_has(&a->flags, ArrayFlags__noslices) && !builtin__ArrayFlags_has(&a->flags, ArrayFlags__is_slice) && !builtin__array_buffer_has_slices(*a)) {
			{ // Unsafe block
				if (builtin__ArrayFlags_has(&a->flags, ArrayFlags__managed)) {
					builtin___v_free(((u8*)(a->data)) - ((u64)(builtin__array_data_header_size())));
				} else {
					builtin___v_free(a->data);
				}
			}
		}
	}
	a->data = new_data;
	a->offset = 0;
	a->cap = ((int)(cap));
	{ // Unsafe block
		if (use_noscan_data) {
			builtin__ArrayFlags_set(&a->flags, ArrayFlags__noscan_data);
		} else {
			builtin__ArrayFlags_clear(&a->flags, ArrayFlags__noscan_data);
		}
	}
	builtin__array_set_managed_flags(a, false);
}
inline VV_LOC bool builtin__array_needs_unique_shift(array a, int required) {
	return required <= a.cap && (builtin__ArrayFlags_has(&a.flags, ArrayFlags__is_slice) || builtin__array_buffer_has_slices(a));
}
inline VV_LOC bool builtin__array_needs_unique_append(array a, int required) {
	return required <= a.cap && builtin__ArrayFlags_has(&a.flags, ArrayFlags__is_slice);
}
inline VV_LOC bool builtin__array_needs_unique_shrink(array a) {
	return builtin__ArrayFlags_has(&a.flags, ArrayFlags__is_slice) || builtin__array_buffer_has_slices(a);
}
void builtin__array_insert(array* a, int i, voidptr val) {
	if (i < 0 || i > a->len) {
		builtin__panic_n2(_S("array.insert: index out of range (i,a.len):"), i, a->len);
		VUNREACHABLE();
	}
	if (a->len == _const_max_int) {
		builtin___v_panic(_S("array.insert: a.len reached max_int"));
		VUNREACHABLE();
	}
	int required = a->len + 1;
	if (builtin__array_needs_unique_shift(*a, required)) {
		builtin__array_clone_shallow_to_cap(a, a->cap);
	} else if (required > a->cap) {
		builtin__array_ensure_cap(a, required);
	}
	{ // Unsafe block
		builtin__vmemmove(builtin__array_get_unsafe(*a, i + 1), builtin__array_get_unsafe(*a, i), ((u64)((a->len - i))) * ((u64)(a->element_size)));
		builtin__array_set_unsafe(a, i, val);
	}
	a->len++;
}
VV_LOC void builtin__array_insert_many(array* a, int i, voidptr val, int size) {
	if (i < 0 || i > a->len) {
		builtin__panic_n2(_S("array.insert_many: index out of range (i,a.len):"), i, a->len);
		VUNREACHABLE();
	}
	i64 new_len = ((i64)(a->len)) + ((i64)(size));
	if (new_len > _const_max_int) {
		builtin__panic_n(_S("array.insert_many: max_int will be exceeded by a.len:"), new_len);
		VUNREACHABLE();
	}
	if (builtin__array_needs_unique_shift(*a, ((int)(new_len)))) {
		builtin__array_clone_shallow_to_cap(a, a->cap);
	} else if (((int)(new_len)) > a->cap) {
		builtin__array_ensure_cap(a, ((int)(new_len)));
	}
	int elem_size = a->element_size;
	{ // Unsafe block
		voidptr iptr = builtin__array_get_unsafe(*a, i);
		builtin__vmemmove(builtin__array_get_unsafe(*a, i + size), iptr, ((u64)(a->len - i)) * ((u64)(elem_size)));
		builtin__vmemcpy(iptr, val, ((u64)(size)) * ((u64)(elem_size)));
	}
	a->len = ((int)(new_len));
}
void builtin__array_prepend(array* a, voidptr val) {
	builtin__array_insert(a, 0, val);
}
VV_LOC void builtin__array_prepend_many(array* a, voidptr val, int size) {
	builtin__array_insert_many(a, 0, val, size);
}
void builtin__array_delete(array* a, int i) {
	if (i < 0 || i >= a->len) {
		builtin__panic_n2(_S("array.delete: index out of range (i,a.len):"), i, a->len);
		VUNREACHABLE();
	}
	if (i == a->len - 1 && !builtin__array_needs_unique_shrink(*a)) {
		a->len--;
		builtin__vmemset(((u8*)(a->data)) + ((u64)(a->len)) * ((u64)(a->element_size)), 0, ((u64)(a->element_size)));
		return;
	}
	builtin__array_delete_many(a, i, 1);
}
void builtin__array_delete_many(array* a, int i, int size) {
	if (i < 0 || ((i64)(i)) + ((i64)(size)) > ((i64)(a->len))) {
		if (size > 1) {
			builtin__panic_n3(_S("array.delete: index out of range (i,i+size,a.len):"), i, i + size, a->len);
			VUNREACHABLE();
		} else {
			builtin__panic_n2(_S("array.delete: index out of range (i,a.len):"), i, a->len);
			VUNREACHABLE();
		}
	}
	if (size == 0) {
		if (builtin__array_needs_unique_shrink(*a)) {
			builtin__array_clone_shallow_to_cap(a, a->len);
		}
		return;
	}
	if (!builtin__array_needs_unique_shrink(*a)) {
		int new_len = a->len - size;
		{ // Unsafe block
			builtin__vmemmove(((u8*)(a->data)) + ((u64)(i)) * ((u64)(a->element_size)), ((u8*)(a->data)) + ((u64)(i + size)) * ((u64)(a->element_size)), ((u64)(a->len - i - size)) * ((u64)(a->element_size)));
			builtin__vmemset(((u8*)(a->data)) + ((u64)(new_len)) * ((u64)(a->element_size)), 0, ((u64)(size)) * ((u64)(a->element_size)));
		}
		a->len = new_len;
		return;
	}
	voidptr old_data = a->data;
	int new_size = a->len - size;
	if (new_size == 0) {
		builtin__ArrayFlags_clear(&a->flags, ((ArrayFlags__managed | ArrayFlags__noscan_data) | ArrayFlags__is_slice));
		a->data = ((void*)0);
		a->offset = 0;
		a->len = 0;
		a->cap = 0;
		return;
	}
	int new_cap = new_size;
	bool use_noscan_data = builtin__array_uses_noscan_data(*a);
	a->data = builtin__array_alloc_array_data_like(*a, ((u64)(new_cap)) * ((u64)(a->element_size)));
	builtin__vmemcpy(a->data, old_data, ((u64)(i)) * ((u64)(a->element_size)));
	builtin__vmemcpy(((u8*)(a->data)) + ((u64)(i)) * ((u64)(a->element_size)), ((u8*)(old_data)) + ((u64)(i + size)) * ((u64)(a->element_size)), ((u64)(a->len - i - size)) * ((u64)(a->element_size)));
	if (builtin__ArrayFlags_has(&a->flags, ArrayFlags__noslices) && !builtin__ArrayFlags_has(&a->flags, ArrayFlags__managed)) {
		builtin___v_free(old_data);
	}
	a->len = new_size;
	a->cap = new_cap;
	a->offset = 0;
	{ // Unsafe block
		if (use_noscan_data) {
			builtin__ArrayFlags_set(&a->flags, ArrayFlags__noscan_data);
		} else {
			builtin__ArrayFlags_clear(&a->flags, ArrayFlags__noscan_data);
		}
	}
	builtin__array_set_managed_flags(a, false);
}
void builtin__array_clear(array* a) {
	if (builtin__array_needs_unique_shrink(*a)) {
		builtin__ArrayFlags_clear(&a->flags, ((ArrayFlags__managed | ArrayFlags__noscan_data) | ArrayFlags__is_slice));
		a->data = ((void*)0);
		a->offset = 0;
		a->cap = 0;
	}
	a->len = 0;
}
void builtin__array_trim(array* a, int index) {
	if (index < a->len) {
		if (index >= 0 && builtin__array_needs_unique_shrink(*a)) {
			builtin__array_delete_many(a, index, a->len - index);
			return;
		}
		a->len = index;
	}
}
inline VV_LOC voidptr builtin__array_get_unsafe(array a, int i) {
	{ // Unsafe block
		return ((u8*)(a.data)) + ((u64)(i)) * ((u64)(a.element_size));
	}
	return 0;
}
VV_LOC voidptr builtin__array_get(array a, int i) {
	#if 1
	{
		if (i < 0 || i >= a.len) {
			builtin__panic_n2(_S("array.get: index out of range (i,a.len):"), i, a.len);
			VUNREACHABLE();
		}
	}
	#endif
	{ // Unsafe block
		return ((u8*)(a.data)) + ((u64)(i)) * ((u64)(a.element_size));
	}
	return 0;
}
VV_LOC voidptr builtin__array_get_i64(array a, i64 i) {
	#if 1
	{
		if (i < 0 || i >= ((i64)(a.len))) {
			builtin__panic_n2(_S("array.get: index out of range (i,a.len):"), i, a.len);
			VUNREACHABLE();
		}
	}
	#endif
	{ // Unsafe block
		return ((u8*)(a.data)) + ((u64)(i)) * ((u64)(a.element_size));
	}
	return 0;
}
VV_LOC voidptr builtin__array_get_u64(array a, u64 i) {
	#if 1
	{
		if (i >= ((u64)(a.len))) {
			builtin___v_panic(builtin__string_plus_many(4, _MOV((string[4]){_S("array.get: index out of range (i,a.len): "), builtin__u64_str(i), _S(", "), builtin__impl_i64_to_string(a.len)})));
			VUNREACHABLE();
		}
	}
	#endif
	{ // Unsafe block
		return ((u8*)(a.data)) + i * ((u64)(a.element_size));
	}
	return 0;
}
VV_LOC voidptr builtin__array_get_ni(array a, int i) {
	return builtin__array_get(a, builtin__v_ni_index(i, a.len));
}
VV_LOC voidptr builtin__array_get_with_check(array a, int i) {
	if (i < 0 || i >= a.len) {
		return 0;
	}
	{ // Unsafe block
		return ((u8*)(a.data)) + ((u64)(i)) * ((u64)(a.element_size));
	}
	return 0;
}
VV_LOC voidptr builtin__array_get_with_check_i64(array a, i64 i) {
	if (i < 0 || i >= ((i64)(a.len))) {
		return 0;
	}
	{ // Unsafe block
		return ((u8*)(a.data)) + ((u64)(i)) * ((u64)(a.element_size));
	}
	return 0;
}
VV_LOC voidptr builtin__array_get_with_check_u64(array a, u64 i) {
	if (i >= ((u64)(a.len))) {
		return 0;
	}
	{ // Unsafe block
		return ((u8*)(a.data)) + i * ((u64)(a.element_size));
	}
	return 0;
}
VV_LOC voidptr builtin__array_get_with_check_ni(array a, int i) {
	return builtin__array_get_with_check(a, builtin__v_ni_index(i, a.len));
}
VV_LOC array builtin__array_slice(array a, int start, int _end) {
	int end = (_end == _const_max_i64 || _end == _const_max_i32 ? (a.len) : (_end));
	#if 1
	{
		if (start > end) {
			builtin___v_panic(builtin__string_plus_many(4, _MOV((string[4]){_S("array.slice: invalid slice index (start>end):"), builtin__impl_i64_to_string(((i64)(start))), _S(", "), builtin__impl_i64_to_string(end)})));
			VUNREACHABLE();
		}
		if (end > a.len) {
			builtin___v_panic(builtin__string_plus_many(5, _MOV((string[5]){_S("array.slice: slice bounds out of range ("), builtin__impl_i64_to_string(end), _S(" >= "), builtin__impl_i64_to_string(a.len), _S(")")})));
			VUNREACHABLE();
		}
		if (start < 0) {
			builtin___v_panic(builtin__string__plus(_S("array.slice: slice bounds out of range (start<0):"), builtin__impl_i64_to_string(start)));
			VUNREACHABLE();
		}
	}
	#endif
	builtin__array_mark_buffer_has_slices(&a);
	u64 offset = ((u64)(start)) * ((u64)(a.element_size));
	u8* data = ((u8*)(a.data)) + offset;
	int l = end - start;
	ArrayFlags flags = ArrayFlags__is_slice;
	if (builtin__array_uses_noscan_data(a)) {
		builtin__ArrayFlags_set(&flags, ArrayFlags__noscan_data);
	}
	array res = ((array){
		.data = (voidptr)data,
		.offset = a.offset + ((int)(offset)),
		.len = l,
		.cap = l,
		.flags = flags,
		.element_size = a.element_size,
	});
	return res;
}
VV_LOC array builtin__array_clone_static_to_depth(array a, int depth) {
	return builtin__array_clone_to_depth(&a, depth);
}
array builtin__array_clone(array* a) {
	return builtin__array_clone_to_depth(a, 0);
}
array builtin__array_clone_to_depth(array* a, int depth) {
	u64 source_capacity_in_bytes = ((u64)(a->cap)) * ((u64)(a->element_size));
	bool use_noscan_data = depth == 0 && builtin__array_uses_noscan_data(*a);
	voidptr data = ((void*)0);
	if (a->cap > 0) {
		if (use_noscan_data) {
			data = builtin__array_alloc_array_data_like(*a, source_capacity_in_bytes);
		} else {
			data = builtin__alloc_array_data(source_capacity_in_bytes);
		}
	}
	array _t1 = ((array){.data = (voidptr)data,.offset = 0,.len = a->len,.cap = a->cap,.flags = (use_noscan_data ? ((ArrayFlags__managed | ArrayFlags__noscan_data)) : (ArrayFlags__managed)),.element_size = a->element_size,});
	array arr = _t1;
	if (depth > 0 && _us32_eq(sizeof(array),a->element_size) && a->len >= 0 && a->cap >= a->len) {
		array _t2 = ((array){.data = 0,.offset = 0,.len = 0,.cap = 0,.flags = 0,.element_size = 0,});
		array ar = _t2;
		int asize = ((int)(sizeof(array)));
		for (int i = 0; i < a->len; ++i) {
			builtin__vmemcpy(&ar, builtin__array_get_unsafe(*a, i), asize);
			array ar_clone = builtin__array_clone_to_depth(&ar, depth - 1);
			builtin__array_set_unsafe(&arr, i, &ar_clone);
		}
		return arr;
	} else if (depth > 0 && _us32_eq(sizeof(string),a->element_size) && a->len >= 0 && a->cap >= a->len) {
		for (int i = 0; i < a->len; ++i) {
			string* str_ptr = ((string*)(builtin__array_get_unsafe(*a, i)));
			string str_clone = builtin__string_clone((*str_ptr));
			builtin__array_set_unsafe(&arr, i, &str_clone);
		}
		return arr;
	}
	if (a->data != 0 && source_capacity_in_bytes > 0) {
		builtin__vmemcpy(arr.data, a->data, source_capacity_in_bytes);
	}
	return arr;
}
inline VV_LOC void builtin__array_set_unsafe(array* a, int i, voidptr val) {
	builtin__vmemcpy(((u8*)(a->data)) + ((u64)(a->element_size)) * ((u64)(i)), val, a->element_size);
}
VV_LOC void builtin__array_set(array* a, int i, voidptr val) {
	#if 1
	{
		if (i < 0 || i >= a->len) {
			builtin__panic_n2(_S("array.set: index out of range (i,a.len):"), i, a->len);
			VUNREACHABLE();
		}
	}
	#endif
	builtin__vmemcpy(((u8*)(a->data)) + ((u64)(a->element_size)) * ((u64)(i)), val, a->element_size);
}
VV_LOC void builtin__array_set_i64(array* a, i64 i, voidptr val) {
	#if 1
	{
		if (i < 0 || i >= ((i64)(a->len))) {
			builtin__panic_n2(_S("array.set: index out of range (i,a.len):"), i, a->len);
			VUNREACHABLE();
		}
	}
	#endif
	builtin__vmemcpy(((u8*)(a->data)) + ((u64)(a->element_size)) * ((u64)(i)), val, a->element_size);
}
VV_LOC void builtin__array_set_u64(array* a, u64 i, voidptr val) {
	#if 1
	{
		if (i >= ((u64)(a->len))) {
			builtin___v_panic(builtin__string_plus_many(4, _MOV((string[4]){_S("array.set: index out of range (i,a.len): "), builtin__u64_str(i), _S(", "), builtin__impl_i64_to_string(a->len)})));
			VUNREACHABLE();
		}
	}
	#endif
	builtin__vmemcpy(((u8*)(a->data)) + ((u64)(a->element_size)) * i, val, a->element_size);
}
VV_LOC void builtin__array_set_ni(array* a, int i, voidptr val) {
	builtin__array_set(a, builtin__v_ni_index(i, a->len), val);
}
inline VV_LOC void builtin__copy_element_to(voidptr dest, voidptr src, int element_size) {
	{ // Unsafe block
		switch (element_size) {
			case 1: {
				builtin__vmemcpy(dest, src, 1);
				break;
			}
			case 2: {
				builtin__vmemcpy(dest, src, 2);
				break;
			}
			case 4: {
				builtin__vmemcpy(dest, src, 4);
				break;
			}
			case 8: {
				builtin__vmemcpy(dest, src, 8);
				break;
			}
			case 16: {
				builtin__vmemcpy(dest, src, 16);
				break;
			}
			default: {
				{
					builtin__vmemcpy(dest, src, element_size);
					break;
				}
			}
		}
		
	}
}
VV_LOC void builtin__array_push(array* a, voidptr val) {
	#if 1
	{
		if (a->len < 0) {
			builtin___v_panic(_S("array.push: negative len"));
			VUNREACHABLE();
		}
	}
	#endif
	if (a->len >= _const_max_int) {
		builtin___v_panic(_S("array.push: len bigger than max_int"));
		VUNREACHABLE();
	}
	int required = a->len + 1;
	if (required > a->cap) {
		builtin__array_ensure_cap(a, required);
	} else if (builtin__ArrayFlags_has(&a->flags, ArrayFlags__is_slice)) {
		builtin__array_clone_shallow_to_cap(a, a->cap);
	}
	builtin__copy_element_to(((u8*)(a->data)) + ((u64)(a->element_size)) * ((u64)(a->len)), val, a->element_size);
	a->len++;
}
void builtin__array_push_many(array* a, voidptr val, int size) {
	if (size <= 0 || val == ((void*)0)) {
		return;
	}
	i64 new_len = ((i64)(a->len)) + ((i64)(size));
	if (new_len > _const_max_int) {
		builtin___v_panic(_S("array.push_many: new len exceeds max_int"));
		VUNREACHABLE();
	}
	if (builtin__array_needs_unique_append(*a, ((int)(new_len)))) {
		builtin__array_clone_shallow_to_cap(a, a->cap);
	}
	bool is_self_append = a->data == val && a->data != 0;
	if (((int)(new_len)) > a->cap) {
		builtin__array_ensure_cap(a, ((int)(new_len)));
	}
	if (is_self_append) {
		array cloned = builtin__array_clone(a);
		builtin__vmemcpy(((u8*)(a->data)) + ((u64)(a->element_size)) * ((u64)(a->len)), cloned.data, ((u64)(a->element_size)) * ((u64)(size)));
	} else {
		if (a->data != 0 && val != 0) {
			builtin__vmemcpy(((u8*)(a->data)) + ((u64)(a->element_size)) * ((u64)(a->len)), val, ((u64)(a->element_size)) * ((u64)(size)));
		}
	}
	a->len = ((int)(new_len));
}
void builtin__array_free(array* a) {
	if (builtin__ArrayFlags_has(&a->flags, ArrayFlags__nofree)) {
		return;
	}
	u8* mblock_ptr = ((u8*)(((u64)(a->data)) - ((u64)(a->offset))));
	if (mblock_ptr != ((void*)0)) {
		{ // Unsafe block
			if (builtin__ArrayFlags_has(&a->flags, ArrayFlags__managed)) {
				builtin___v_free(mblock_ptr - builtin__array_data_header_size());
			} else {
				builtin___v_free(mblock_ptr);
			}
		}
	}
	{ // Unsafe block
		a->data = ((void*)0);
		a->offset = 0;
		a->len = 0;
		a->cap = 0;
	}
}
bool builtin__array_contains(array a, voidptr value);
void Array_string_free(Array_string* a) {
	for (int _t1 = 0; _t1 < a->len; ++_t1) {
		string* s = ((string*)a->data) + _t1;
		builtin__string_free(s);
	}
	array* arr = ((array*)(a));
	builtin__array_free(arr);
}
string Array_string_str(Array_string a) {
	int sb_len = 4;
	if (a.len > 0) {
		sb_len += ((string*)a.data)[0].len;
		sb_len *= a.len;
	}
	sb_len += 2;
	strings__Builder sb = strings__new_builder(sb_len);
	strings__Builder_write_u8(&sb, '[');
	for (int i = 0; i < a.len; ++i) {
		string val = ((string*)a.data)[i];
		strings__Builder_write_u8(&sb, '\'');
		strings__Builder_write_string(&sb, val);
		strings__Builder_write_u8(&sb, '\'');
		if (i < a.len - 1) {
			strings__Builder_write_string(&sb, _S(", "));
		}
	}
	strings__Builder_write_u8(&sb, ']');
	string res = strings__Builder_str(&sb);
	strings__Builder_free(&sb);
	return res;
}
void builtin__u8_free(u8* data) {
	builtin___v_free(data);
}
inline VV_LOC void builtin__panic_on_negative_len(int len) {
	if (len < 0) {
		builtin__panic_n(_S("negative .len:"), len);
		VUNREACHABLE();
	}
}
inline VV_LOC void builtin__panic_on_negative_cap(int cap) {
	if (cap < 0) {
		builtin__panic_n(_S("negative .cap:"), cap);
		VUNREACHABLE();
	}
}
VV_LOC array builtin____new_array_with_default_noscan(int mylen, int cap, int elm_size, voidptr val) {
	return builtin____new_array_with_default(mylen, cap, elm_size, val);
}
VV_LOC void builtin__array_prepend_noscan(array* a, voidptr val) {
	builtin__array_prepend(a, val);
}
VV_LOC void builtin__array_push_noscan(array* a, voidptr val) {
	builtin__array_push(a, val);
}
VV_LOC void builtin__array_push_many_noscan(array* a, voidptr val, int size) {
	builtin__array_push_many(a, val, size);
}
VV_LOC bool builtin__autostr_type_in_stack(int typ) {
	for (int i = 0; i < g_autostr_type_stack_len; i++) {
		if (g_autostr_type_stack[builtin__v_fixed_index(i, 64)] == typ) {
			return true;
		}
	}
	return false;
}
VV_LOC void builtin__autostr_type_push(int typ) {
	if (g_autostr_type_stack_len >= _const_autostr_type_stack_max_depth) {
		return;
	}
	g_autostr_type_stack[builtin__v_fixed_index(g_autostr_type_stack_len, 64)] = typ;
	g_autostr_type_stack_len++;
}
VV_LOC void builtin__autostr_type_pop(void) {
	if (g_autostr_type_stack_len > 0) {
		g_autostr_type_stack_len--;
	}
}
VV_LOC bool builtin__autostr_addr_in_stack(voidptr addr) {
	for (int i = 0; i < g_autostr_addr_stack_len; i++) {
		if (g_autostr_addr_stack[builtin__v_fixed_index(i, 64)] == addr) {
			return true;
		}
	}
	return false;
}
VV_LOC void builtin__autostr_addr_push(voidptr addr) {
	if (g_autostr_addr_stack_len >= _const_autostr_type_stack_max_depth) {
		return;
	}
	g_autostr_addr_stack[builtin__v_fixed_index(g_autostr_addr_stack_len, 64)] = addr;
	g_autostr_addr_stack_len++;
}
VV_LOC void builtin__autostr_addr_pop(void) {
	if (g_autostr_addr_stack_len > 0) {
		g_autostr_addr_stack_len--;
	}
}
VV_LOC string builtin__autostr_array_circular(int len) {
	if (len <= 0) {
		return _S("[]");
	}
	strings__Builder sb = strings__new_builder(2 + len * 12);
	strings__Builder_write_string(&sb, _S("["));
	for (int i = 0; i < len; ++i) {
		if (i > 0) {
			strings__Builder_write_string(&sb, _S(", "));
		}
		strings__Builder_write_string(&sb, _S("<circular>"));
	}
	strings__Builder_write_string(&sb, _S("]"));
	string res = strings__Builder_str(&sb);
	strings__Builder_free(&sb);
	return res;
}
bool builtin__print_backtrace_skipping_top_frames(int xskipframes) {
	#if defined(CUSTOM_DEFINE_no_backtrace)
	{
		return false;
	}
	#else
	{
	}
	#endif
	return false;
}
VNORETURN void builtin___v_exit(int code) {
	exit(code);
	VUNREACHABLE();
	for (;;) {
	}
	while(1);
}
VV_LOC void builtin__v_segmentation_fault_handler(i32 signal_number) {
	#if defined(CUSTOM_DEFINE_v2_native_windows_pe_minimal)
	{
	}
	#else
	{
		#if 0
		{
		}
		#else
		{
			fprintf(stderr, "signal %d: segmentation fault\n", signal_number);
		}
		#endif
		#if defined(CUSTOM_DEFINE_use_libbacktrace) && !defined(__TINYC__)
		{
		}
		#elif 1
		{
			builtin__print_backtrace_skipping_top_frames(1);
		}
		#else
		{
		}
		#endif
		builtin___v_exit(128 + signal_number);
		VUNREACHABLE();
	}
	#endif
}
inline VV_LOC int builtin__v_fixed_index(int i, int len) {
	#if 1
	{
		if (i < 0 || i >= len) {
			builtin___v_panic(builtin__string_plus_many(5, _MOV((string[5]){_S("fixed array index out of range (index: "), builtin__i64_str(((i64)(i))), _S(", len: "), builtin__i64_str(((i64)(len))), _S(")")})));
			VUNREACHABLE();
		}
	}
	#endif
	return i;
}
inline VV_LOC int builtin__v_fixed_index_i64(i64 i, int len) {
	#if 1
	{
		if (i < 0 || i >= ((i64)(len))) {
			builtin___v_panic(builtin__string_plus_many(5, _MOV((string[5]){_S("fixed array index out of range (index: "), builtin__i64_str(i), _S(", len: "), builtin__i64_str(((i64)(len))), _S(")")})));
			VUNREACHABLE();
		}
	}
	#endif
	return ((int)(i));
}
inline VV_LOC int builtin__v_fixed_index_u64(u64 i, int len) {
	#if 1
	{
		if (i >= ((u64)(len))) {
			builtin___v_panic(builtin__string_plus_many(5, _MOV((string[5]){_S("fixed array index out of range (index: "), builtin__u64_str(i), _S(", len: "), builtin__i64_str(((i64)(len))), _S(")")})));
			VUNREACHABLE();
		}
	}
	#endif
	return ((int)(i));
}
inline VV_LOC int builtin__v_fixed_index_ni(int i, int len) {
	return builtin__v_fixed_index(builtin__v_ni_index(i, len), len);
}
inline VV_LOC int builtin__v_slice_index_i64(i64 i) {
	if (i < ((i64)(_const_min_int)) || i > ((i64)(_const_max_int))) {
		builtin___v_panic(builtin__string__plus(_S("slice index out of range for int: "), builtin__i64_str(i)));
		VUNREACHABLE();
	}
	return ((int)(i));
}
inline VV_LOC int builtin__v_slice_index_u64(u64 i) {
	if (i > ((u64)(_const_max_int))) {
		builtin___v_panic(builtin__string__plus(_S("slice index out of range for int: "), builtin__u64_str(i)));
		VUNREACHABLE();
	}
	return ((int)(i));
}
Array_string builtin__arguments(void) {
	u8** argv = ((u8**)(g_main_argv));
	Array_string res = builtin____new_array_with_default(0, g_main_argc, sizeof(string), 0);
	for (int i = 0; i < g_main_argc; ++i) {
		#if 0
		{
		}
		#else
		{
			builtin__array_push((array*)&res, _MOV((string[]){ builtin__tos_clone(argv[i]) }));
		}
		#endif
	}
	return res;
}
string builtin__vcurrent_hash(void) {
	return _S("7647ce1");
}
u64 builtin__v_getpid(void) {
	#if defined(CUSTOM_DEFINE_no_getpid)
	{
	}
	#elif 0
	{
	}
	#else
	{
		return ((u64)(getpid()));
	}
	#endif
	return 0;
}
u64 builtin__v_gettid(void) {
	#if defined(CUSTOM_DEFINE_no_gettid)
	{
	}
	#elif 0
	{
	}
	#elif 1
	{
		return ((u64)(gettid()));
	}
	#elif 0
	{
	}
	#else
	{
	}
	#endif
	return 0;
}
inline bool builtin__isnil(voidptr v) {
	return v == 0;
}
VV_LOC void builtin__builtin_init(void) {
	#if 1
	{
		builtin__unbuffer_stdout();
	}
	#endif
}
#if 0
#else
#endif
inline int builtin__vstrlen(u8* s) {
	return ((int)(strlen(((char*)(s)))));
}
inline int builtin__vstrlen_char(char* s) {
	return ((int)(strlen(s)));
}
inline voidptr builtin__vmemcpy(voidptr dest, const void* const_src, isize n) {
	if (n == 0 || ((u64)(dest)) <= 0xFFFF || ((u64)(const_src)) <= 0xFFFF) {
		return dest;
	}
	{ // Unsafe block
		return memcpy(dest, const_src, n);
	}
	return 0;
}
inline voidptr builtin__vmemmove(voidptr dest, const void* const_src, isize n) {
	if (n == 0 || ((u64)(dest)) <= 0xFFFF || ((u64)(const_src)) <= 0xFFFF) {
		return dest;
	}
	{ // Unsafe block
		return memmove(dest, const_src, n);
	}
	return 0;
}
inline int builtin__vmemcmp(const void* const_s1, const void* const_s2, isize n) {
	if (n == 0 || ((u64)(const_s1)) <= 0xFFFF || ((u64)(const_s2)) <= 0xFFFF) {
		return 0;
	}
	{ // Unsafe block
		return memcmp(const_s1, const_s2, n);
	}
	return 0;
}
inline voidptr builtin__vmemset(voidptr s, int c, isize n) {
	if (n == 0 || ((u64)(s)) <= 0xFFFF) {
		return s;
	}
	{ // Unsafe block
		return memset(s, c, n);
	}
	return 0;
}
VV_LOC void builtin___result_ok(voidptr data, _result* res, int size) {
	{ // Unsafe block
		*res = ((_result){.is_error = 0,.err = _const_none__,});
		builtin__vmemcpy(((u8*)(&res->err)) + sizeof(IError), data, size);
	}
}
VV_LOC void builtin___result_clone(_result* current, _result* res, int size) {
	{ // Unsafe block
		*res = ((_result){.is_error = current->is_error,.err = current->err,});
		builtin__vmemcpy(((u8*)(&res->err)) + sizeof(IError), ((u8*)(&current->err)) + sizeof(IError), size);
	}
}
string builtin__IError_str(IError err) {
	if ((err)._typ == _IError_None___index) {
		return _S("none");
	}
	int c = ((struct _IError_interface_methods*)(err._methods))->_method_code(err._object);
	if (c > 0) {
		return builtin__string_plus_many(3, _MOV((string[3]){((struct _IError_interface_methods*)(err._methods))->_method_msg(err._object), _S("; code: "), builtin__int_str(c)}));
	}
	return ((struct _IError_interface_methods*)(err._methods))->_method_msg(err._object);
}
string builtin__Error_msg(Error err) {
	return _S("");
}
int builtin__Error_code(Error err) {
	return 0;
}
string builtin__MessageError_str(MessageError err) {
	if (err.code > 0) {
		return builtin__string_plus_many(3, _MOV((string[3]){err.msg, _S("; code: "), builtin__int_str(err.code)}));
	}
	return err.msg;
}
string builtin__MessageError_msg(MessageError err) {
	return err.msg;
}
int builtin__MessageError_code(MessageError err) {
	return err.code;
}
void builtin__MessageError_free(MessageError* err) {
	builtin__string_free(&err->msg);
}
inline IError builtin___v_error(string message) {
	;
	return I_MessageError_to_Interface_IError((HEAP(MessageError, ((MessageError){.msg = message,.code = 0,}))));
}
inline IError builtin__error_with_code(string message, int code) {
	;
	MessageError* _t2 = (MessageError*)builtin___v_malloc(sizeof(MessageError) == 0 ? 1 : sizeof(MessageError));
	_t2->msg = message;
	_t2->code = code;
	return I_MessageError_to_Interface_IError( _t2);
}
VV_LOC void builtin___option_none(voidptr data, _option* option, int size) {
	{ // Unsafe block
		*option = ((_option){.state = 2,.err = _const_none__,});
		builtin__vmemcpy(((u8*)(&option->err)) + sizeof(IError), data, size);
	}
}
VV_LOC void builtin___option_ok(voidptr data, _option* option, int size) {
	{ // Unsafe block
		*option = ((_option){.state = 0,.err = _const_none__,});
		builtin__vmemcpy(((u8*)(&option->err)) + sizeof(IError), data, size);
	}
}
VV_LOC void builtin___option_clone(_option* current, _option* option, int size) {
	{ // Unsafe block
		*option = ((_option){.state = current->state,.err = current->err,});
		builtin__vmemcpy(((u8*)(&option->err)) + sizeof(IError), ((u8*)(&current->err)) + sizeof(IError), size);
	}
}
VV_LOC void builtin___result_ok_markused(void) {
	_result _t1 = ((_result){.is_error = 0,.err = _const_none__,});
	_result res = _t1;
	builtin___result_ok(((void*)0), (voidptr)&res, 0);
}
VV_LOC string builtin__None___str(None__ _d1) {
	return _S("none");
}
#if !defined(CUSTOM_DEFINE_nofloat)
#endif
inline string builtin__f64_str(f64 x) {
	{ // Unsafe block
		strconv__Float64u _t1 = ((strconv__Float64u){.f = x,});
		strconv__Float64u f = _t1;
		if (f.u == _const_strconv__double_minus_zero) {
			return _S("-0.0");
		}
		if (f.u == _const_strconv__double_plus_zero) {
			return _S("0.0");
		}
	}
	f64 abs_x = builtin__f64_abs(x);
	if (abs_x >= ((f64)(0.0001)) && abs_x < ((f64)(1.0e6))) {
		return strconv__f64_to_str_l(x);
	} else {
		return strconv__ftoa_64(x);
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}
inline string builtin__f64_strg(f64 x) {
	{ // Unsafe block
		strconv__Float64u _t1 = ((strconv__Float64u){.f = x,});
		strconv__Float64u f = _t1;
		if (f.u == _const_strconv__double_minus_zero || f.u == _const_strconv__double_plus_zero) {
			return _S("0.0");
		}
	}
	f64 abs_x = builtin__f64_abs(x);
	if (abs_x >= ((f64)(0.0001)) && abs_x < ((f64)(1.0e6))) {
		return strconv__f64_to_str_l_with_dot(x);
	} else {
		return strconv__ftoa_64(x);
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}
inline string builtin__f32_str(f32 x) {
	{ // Unsafe block
		strconv__Float32u _t1 = ((strconv__Float32u){.f = x,});
		strconv__Float32u f = _t1;
		if (f.u == _const_strconv__single_minus_zero) {
			return _S("-0.0");
		}
		if (f.u == _const_strconv__single_plus_zero) {
			return _S("0.0");
		}
	}
	f32 abs_x = builtin__f32_abs(x);
	if (abs_x >= ((f32)(0.0001)) && abs_x < ((f32)(1.0e6))) {
		return strconv__f32_to_str_l(x);
	} else {
		return strconv__ftoa_32(x);
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}
inline string builtin__f32_strg(f32 x) {
	{ // Unsafe block
		strconv__Float32u _t1 = ((strconv__Float32u){.f = x,});
		strconv__Float32u f = _t1;
		if (f.u == _const_strconv__single_minus_zero || f.u == _const_strconv__single_plus_zero) {
			return _S("0.0");
		}
	}
	f32 abs_x = builtin__f32_abs(x);
	if (abs_x >= ((f32)(0.0001)) && abs_x < ((f32)(1.0e6))) {
		return strconv__f32_to_str_l_with_dot(x);
	} else {
		return strconv__ftoa_32(x);
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}
inline f32 builtin__f32_abs(f32 a) {
	if (a < 0) {
		return -a;
	}
	return a;
}
inline f64 builtin__f64_abs(f64 a) {
	if (a < 0) {
		return -a;
	}
	return a;
}
inline VV_LOC u32 builtin__grapheme_hex_nibble(u8 c) {
	return (c <= '9' ? (((u32)((rune)(c - '0')))) : (((u32)((rune)(((c | 0x20)) - 'a') + 10))));
}
inline VV_LOC u32 builtin__grapheme_hex_byte(string ranges, int i) {
	return ((v__lshift_u32(builtin__grapheme_hex_nibble(builtin__string_at(ranges, i)), (u64)4)) | builtin__grapheme_hex_nibble(builtin__string_at(ranges, i + 1)));
}
inline VV_LOC u32 builtin__grapheme_range_value(string ranges, int value_idx) {
	int i = value_idx * 8;
	u32 b0 = builtin__grapheme_hex_byte(ranges, i);
	u32 b1 = builtin__grapheme_hex_byte(ranges, i + 2);
	u32 b2 = builtin__grapheme_hex_byte(ranges, i + 4);
	u32 b3 = builtin__grapheme_hex_byte(ranges, i + 6);
	return (((b0 | (v__lshift_u32(b1, (u64)8))) | (v__lshift_u32(b2, (u64)16))) | (v__lshift_u32(b3, (u64)24)));
}
inline VV_LOC bool builtin__in_grapheme_ranges(rune r, string ranges) {
	u32 target = ((u32)(r));
	int low = 0;
	int high = VSAFE_DIV_int(ranges.len , 16);
	for (;;) {
		if (!(low < high)) break;
		int mid = low + VSAFE_DIV_int((high - low) , 2);
		u32 lo = builtin__grapheme_range_value(ranges, mid * 2);
		u32 hi = builtin__grapheme_range_value(ranges, mid * 2 + 1);
		if (target < lo) {
			high = mid;
		} else if (target > hi) {
			low = mid + 1;
		} else {
			return true;
		}
	}
	return false;
}
inline VV_LOC GraphemeBreakProperty builtin__grapheme_break_property(rune r) {
	if (r == '\r') {
		return GraphemeBreakProperty__cr;
	}
	if (r == '\n') {
		return GraphemeBreakProperty__lf;
	}
	if (r == 0x200d) {
		return GraphemeBreakProperty__zwj;
	}
	if (r >= 0x1f1e6 && r <= 0x1f1ff) {
		return GraphemeBreakProperty__regional_indicator;
	}
	if (r >= 0xac00 && r <= 0xd7a3) {
		return (VSAFE_MOD_u32((((u32)(r)) - 0xac00) , 28) == 0 ? (GraphemeBreakProperty__lv) : (GraphemeBreakProperty__lvt));
	}
	if ((r >= 0x1100 && r <= 0x115f) || (r >= 0xa960 && r <= 0xa97c)) {
		return GraphemeBreakProperty__l;
	}
	if ((r >= 0x1160 && r <= 0x11a7) || (r >= 0xd7b0 && r <= 0xd7c6)) {
		return GraphemeBreakProperty__v;
	}
	if ((r >= 0x11a8 && r <= 0x11ff) || (r >= 0xd7cb && r <= 0xd7fb)) {
		return GraphemeBreakProperty__t;
	}
	if (builtin__in_grapheme_ranges(r, _const_grapheme_control_ranges)) {
		return GraphemeBreakProperty__control;
	}
	if (builtin__in_grapheme_ranges(r, _const_grapheme_extend_ranges)) {
		return GraphemeBreakProperty__extend;
	}
	if (builtin__in_grapheme_ranges(r, _const_grapheme_spacing_mark_ranges)) {
		return GraphemeBreakProperty__spacing_mark;
	}
	if (builtin__in_grapheme_ranges(r, _const_grapheme_prepend_ranges)) {
		return GraphemeBreakProperty__prepend;
	}
	return GraphemeBreakProperty__other;
}
inline VV_LOC bool builtin__is_extended_pictographic(rune r) {
	return builtin__in_grapheme_ranges(r, _const_grapheme_extended_pictographic_ranges);
}
inline VV_LOC GraphemeState builtin__grapheme_state_from_rune(rune r, GraphemeBreakProperty prop) {
	return ((GraphemeState){.prev_prop = prop,.ri_count = (prop == GraphemeBreakProperty__regional_indicator ? (1) : (0)),.extended_pictographic_state = (builtin__is_extended_pictographic(r) ? (((u8)(1))) : (((u8)(0)))),});
}
inline VV_LOC void builtin__GraphemeState_push(GraphemeState* gs, rune r, GraphemeBreakProperty prop) {
	gs->prev_prop = prop;
	gs->ri_count = (prop == GraphemeBreakProperty__regional_indicator ? (gs->ri_count + 1) : (0));
	if (builtin__is_extended_pictographic(r)) {
		gs->extended_pictographic_state = 1;
	} else if (prop == GraphemeBreakProperty__extend && gs->extended_pictographic_state == 1) {
	} else if (prop == GraphemeBreakProperty__zwj && gs->extended_pictographic_state == 1) {
		gs->extended_pictographic_state = 2;
	} else {
		gs->extended_pictographic_state = 0;
	}
}
inline VV_LOC bool builtin__should_break_grapheme(GraphemeState gs, rune r, GraphemeBreakProperty prop) {
	switch (gs.prev_prop) {
		case GraphemeBreakProperty__cr: {
			if (prop == GraphemeBreakProperty__lf) {
				return false;
			}
			return true;
		}
		case GraphemeBreakProperty__lf: case GraphemeBreakProperty__control: {
			return true;
		}
		case GraphemeBreakProperty__l: {
			if (prop == GraphemeBreakProperty__l || prop == GraphemeBreakProperty__v || prop == GraphemeBreakProperty__lv || prop == GraphemeBreakProperty__lvt) {
				return false;
			}
			break;
		}
		case GraphemeBreakProperty__lv: case GraphemeBreakProperty__v: {
			if (prop == GraphemeBreakProperty__v || prop == GraphemeBreakProperty__t) {
				return false;
			}
			break;
		}
		case GraphemeBreakProperty__lvt: case GraphemeBreakProperty__t: {
			if (prop == GraphemeBreakProperty__t) {
				return false;
			}
			break;
		}
		case GraphemeBreakProperty__prepend: {
			return false;
		}
		case GraphemeBreakProperty__regional_indicator: {
			if (prop == GraphemeBreakProperty__regional_indicator && VSAFE_MOD_int(gs.ri_count , 2) == 1) {
				return false;
			}
			break;
		}
		case GraphemeBreakProperty__other:
		case GraphemeBreakProperty__extend:
		case GraphemeBreakProperty__spacing_mark:
		case GraphemeBreakProperty__zwj:
		default: {
			{
				break;
			}
		}
	}
	
	if (prop == GraphemeBreakProperty__cr || prop == GraphemeBreakProperty__lf || prop == GraphemeBreakProperty__control) {
		return true;
	}
	if (prop == GraphemeBreakProperty__extend || prop == GraphemeBreakProperty__zwj || prop == GraphemeBreakProperty__spacing_mark) {
		return false;
	}
	if (gs.extended_pictographic_state == 2 && builtin__is_extended_pictographic(r)) {
		return false;
	}
	return true;
}
inline VV_LOC int builtin__utf8_rune_visible_width(rune r, GraphemeBreakProperty prop) {
	if (prop == GraphemeBreakProperty__extend || prop == GraphemeBreakProperty__zwj || prop == GraphemeBreakProperty__spacing_mark || prop == GraphemeBreakProperty__prepend) {
		return 0;
	}
	if (r >= 0x1100 && (r <= 0x115f || r == 0x2329 || r == 0x232a || (r >= 0x2e80 && r <= 0xa4cf && r != 0x303f) || (r >= 0xac00 && r <= 0xd7a3) || (r >= 0xf900 && r <= 0xfaff) || (r >= 0xfe10 && r <= 0xfe19) || (r >= 0xfe30 && r <= 0xfe6f) || (r >= 0xff00 && r <= 0xff60) || (r >= 0xffe0 && r <= 0xffe6) || (r >= 0x1f300 && r <= 0x1f64f) || (r >= 0x1f680 && r <= 0x1f6ff) || (r >= 0x1f900 && r <= 0x1f9ff) || (r >= 0x1fa70 && r <= 0x1faff) || (r >= 0x20000 && r <= 0x3fffd))) {
		return 2;
	}
	return 1;
}
inline VV_LOC int builtin__utf8_grapheme_visible_length(string s) {
	Array_rune runes = builtin__string_runes(s);
	if (runes.len == 0) {
		return 0;
	}
	GraphemeBreakProperty first_prop = builtin__grapheme_break_property((*(rune*)builtin__array_get(runes, 0)));
	GraphemeState state = builtin__grapheme_state_from_rune((*(rune*)builtin__array_get(runes, 0)), first_prop);
	int total = 0;
	int cluster_width = builtin__utf8_rune_visible_width((*(rune*)builtin__array_get(runes, 0)), first_prop);
	Array_rune _t2 = builtin__array_slice(runes, 1, 2147483647);
	for (int _t3 = 0; _t3 < _t2.len; ++_t3) {
		rune r = ((rune*)_t2.data)[_t3];
		GraphemeBreakProperty prop = builtin__grapheme_break_property(r);
		if (builtin__should_break_grapheme(state, r, prop)) {
			total += cluster_width;
			cluster_width = builtin__utf8_rune_visible_width(r, prop);
			state = builtin__grapheme_state_from_rune(r, prop);
			continue;
		}
		int rune_width = builtin__utf8_rune_visible_width(r, prop);
		if (rune_width > cluster_width) {
			cluster_width = rune_width;
		}
		builtin__GraphemeState_push(&state, r, prop);
	}
	return total + cluster_width;
}
string builtin__ptr_str(voidptr ptr) {
	string buf1 = builtin__u64_to_hex_no_leading_zeros(((u64)(ptr)), 16);
	return buf1;
}
string builtin__isize_str(isize x) {
	return builtin__i64_str(((i64)(x)));
}
string builtin__usize_str(usize x) {
	return builtin__u64_str(((u64)(x)));
}
string builtin__char_str(char* cptr) {
	return builtin__u64_hex(((u64)(cptr)));
}
inline VV_LOC string builtin__int_str_l(int nn, int max) {
	{ // Unsafe block
		i64 n = ((i64)(nn));
		int d = 0;
		if (n == 0) {
			return _S("0");
		}
		#if 0
		{
		}
		#else
		{
			if (n == _const_min_i32) {
				return _S("-2147483648");
			}
		}
		#endif
		bool is_neg = false;
		if (n < 0) {
			n = -n;
			is_neg = true;
		}
		int index = max;
		u8* buf = builtin__malloc_noscan(max + 1);
		buf[index] = 0;
		index--;
		for (;;) {
			if (!(n > 0)) break;
			int n1 = ((int)(VSAFE_DIV_i64(n , 100)));
			d = ((int)(v__lshift_u32(((u32)(((int)(n)) - (n1 * 100))), (u64)1)));
			n = n1;
			buf[index] = _const_digit_pairs.str[d];
			index--;
			d++;
			buf[index] = _const_digit_pairs.str[d];
			index--;
		}
		index++;
		if (d < 20) {
			index++;
		}
		if (is_neg) {
			index--;
			buf[index] = '-';
		}
		int diff = max - index;
		builtin__vmemmove(buf, ((voidptr)(buf + index)), diff + 1);
		return builtin__tos(buf, diff);
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}
string builtin__i8_str(i8 n) {
	return builtin__int_str_l(((int)(n)), 4);
}
string builtin__i16_str(i16 n) {
	return builtin__int_str_l(((int)(n)), 6);
}
string builtin__u16_str(u16 n) {
	return builtin__int_str_l(((int)(n)), 6);
}
string builtin__i32_str(i32 n) {
	return builtin__int_str_l(((int)(n)), 11);
}
string builtin__int_str(int n) {
	#if defined(CUSTOM_DEFINE_new_int)
	{
	}
	#else
	{
		return builtin__int_str_l(n, 11);
	}
	#endif
	return (string){.str=(byteptr)"", .is_lit=1};
}
inline string builtin__u32_str(u32 nn) {
	{ // Unsafe block
		u32 n = nn;
		u32 d = ((u32)(0));
		if (n == 0) {
			return _S("0");
		}
		int max = 10;
		u8* buf = builtin__malloc_noscan(max + 1);
		int index = max;
		buf[index] = 0;
		index--;
		for (;;) {
			if (!(n > 0)) break;
			u32 n1 = VSAFE_DIV_u32(n , ((u32)(100)));
			d = (v__lshift_u32((n - (n1 * ((u32)(100)))), (u64)((u32)(1))));
			n = n1;
			buf[index] = _const_digit_pairs.str[ ((int)(d))];
			index--;
			d++;
			buf[index] = _const_digit_pairs.str[ ((int)(d))];
			index--;
		}
		index++;
		if (d < ((u32)(20))) {
			index++;
		}
		int diff = max - index;
		builtin__vmemmove(buf, ((voidptr)(buf + index)), diff + 1);
		return builtin__tos(buf, diff);
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}
inline string builtin__int_literal_str(int_literal n) {
	return builtin__impl_i64_to_string(n);
}
inline string builtin__i64_str(i64 nn) {
	return builtin__impl_i64_to_string(nn);
}
VV_LOC string builtin__impl_i64_to_string(i64 nn) {
	{ // Unsafe block
		i64 n = nn;
		i64 d = ((i64)(0));
		if (n == 0) {
			return _S("0");
		} else if (n == _const_min_i64) {
			return _S("-9223372036854775808");
		}
		int max = 20;
		u8* buf = builtin__malloc_noscan(max + 1);
		bool is_neg = false;
		if (n < 0) {
			n = -n;
			is_neg = true;
		}
		int index = max;
		buf[index] = 0;
		index--;
		for (;;) {
			if (!(n > 0)) break;
			i64 n1 = VSAFE_DIV_i64(n , ((i64)(100)));
			d = (v__lshift_u32(((u32)(n - (n1 * ((i64)(100))))), (u64)((i64)(1))));
			n = n1;
			buf[index] = _const_digit_pairs.str[ ((int)(d))];
			index--;
			d++;
			buf[index] = _const_digit_pairs.str[ ((int)(d))];
			index--;
		}
		index++;
		if (d < ((i64)(20))) {
			index++;
		}
		if (is_neg) {
			index--;
			buf[index] = '-';
		}
		int diff = max - index;
		builtin__vmemmove(buf, ((voidptr)(buf + index)), diff + 1);
		return builtin__tos(buf, diff);
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}
inline string builtin__u64_str(u64 nn) {
	{ // Unsafe block
		u64 n = nn;
		u64 d = ((u64)(0));
		if (n == 0) {
			return _S("0");
		}
		int max = 20;
		u8* buf = builtin__malloc_noscan(max + 1);
		int index = max;
		buf[index] = 0;
		index--;
		for (;;) {
			if (!(n > 0)) break;
			u64 n1 = VSAFE_DIV_u64(n , 100);
			d = (v__lshift_u64((n - (n1 * 100)), (u64)1));
			n = n1;
			buf[index] = _const_digit_pairs.str[ ((int)(d))];
			index--;
			d++;
			buf[index] = _const_digit_pairs.str[ ((int)(d))];
			index--;
		}
		index++;
		if (d < 20) {
			index++;
		}
		int diff = max - index;
		builtin__vmemmove(buf, ((voidptr)(buf + index)), diff + 1);
		return builtin__tos(buf, diff);
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}
string builtin__bool_str(bool b) {
	if (b) {
		return _S("true");
	}
	return _S("false");
}
inline VV_LOC string builtin__u64_to_hex_no_leading_zeros(u64 nn, u8 len) {
	u64 n = nn;
	Array_fixed_u8_17 buf = {0};
	buf[len] = 0;
	int i = 0;
	for (i = (len - 1); i >= 0; i--) {
		u8 d = ((u8)((n & 0xF)));
		buf[i] = (d < 10 ? ((rune)(d + '0')) : ((u8)(d + 87)));
		n = v__rshift_u64(n, (u64)4);
		if (n == 0) {
			break;
		}
	}
	int res_len = (int)(len - i);
	return builtin__tos(builtin__memdup(&buf[i], res_len + 1), res_len);
}
string builtin__u64_hex(u64 nn) {
	if (nn == 0) {
		return _S("0");
	}
	return builtin__u64_to_hex_no_leading_zeros(nn, 16);
}
string builtin__voidptr_str(voidptr nn) {
	return builtin__string__plus(_S("0x"), builtin__u64_hex(((u64)(nn))));
}
string builtin__byteptr_str(byteptr nn) {
	return builtin__string__plus(_S("0x"), builtin__u64_hex(((u64)(nn))));
}
string builtin__charptr_str(charptr nn) {
	return builtin__string__plus(_S("0x"), builtin__u64_hex(((u64)(nn))));
}
string builtin__u8_str(u8 b) {
	return builtin__int_str_l(((int)(b)), 4);
}
string builtin__u8_ascii_str(u8 b) {
	string _t1 = ((string){.str = builtin__malloc_noscan(2), .len = 1});
	string str = _t1;
	{ // Unsafe block
		str.str[0] = b;
		str.str[1] = 0;
	}
	return str;
}
inline VV_LOC bool builtin__fast_string_eq(string a, string b) {
	if (a.len != b.len) {
		return false;
	}
	{ // Unsafe block
		return memcmp(a.str, b.str, b.len) == 0;
	}
	return 0;
}
VV_LOC u64 builtin__map_hash_string(voidptr pkey) {
	string key = *((string*)(pkey));
	return wyhash(key.str, ((u64)(key.len)), 0, ((u64*)(((voidptr)(_wyp)))));
}
VV_LOC u64 builtin__map_hash_int_1(voidptr pkey) {
	return wyhash64(*((u8*)(pkey)), 0);
}
VV_LOC u64 builtin__map_hash_int_2(voidptr pkey) {
	return wyhash64(*((u16*)(pkey)), 0);
}
VV_LOC u64 builtin__map_hash_int_4(voidptr pkey) {
	return wyhash64(*((u32*)(pkey)), 0);
}
VV_LOC u64 builtin__map_hash_int_8(voidptr pkey) {
	return wyhash64(*((u64*)(pkey)), 0);
}
VV_LOC voidptr builtin__map_enum_fn(int kind, int esize) {
	if (!(kind == 1 || kind == 2 || kind == 3)) {
		builtin___v_panic(_S("map_enum_fn: invalid kind"));
		VUNREACHABLE();
	}
	if (esize > 8 || esize < 0) {
		builtin___v_panic(_S("map_enum_fn: invalid esize"));
		VUNREACHABLE();
	}
	if (kind == 1) {
		if (esize > 4) {
			return ((voidptr)(builtin__map_hash_int_8));
		}
		if (esize > 2) {
			return ((voidptr)(builtin__map_hash_int_4));
		}
		if (esize > 1) {
			return ((voidptr)(builtin__map_hash_int_2));
		}
		if (esize > 0) {
			return ((voidptr)(builtin__map_hash_int_1));
		}
	}
	if (kind == 2) {
		if (esize > 4) {
			return ((voidptr)(builtin__map_eq_int_8));
		}
		if (esize > 2) {
			return ((voidptr)(builtin__map_eq_int_4));
		}
		if (esize > 1) {
			return ((voidptr)(builtin__map_eq_int_2));
		}
		if (esize > 0) {
			return ((voidptr)(builtin__map_eq_int_1));
		}
	}
	if (kind == 3) {
		if (esize > 4) {
			return ((voidptr)(builtin__map_clone_int_8));
		}
		if (esize > 2) {
			return ((voidptr)(builtin__map_clone_int_4));
		}
		if (esize > 1) {
			return ((voidptr)(builtin__map_clone_int_2));
		}
		if (esize > 0) {
			return ((voidptr)(builtin__map_clone_int_1));
		}
	}
	return ((void*)0);
}
VV_LOC void builtin__DenseArray_zeros_to_end(DenseArray* d) {
	u8* tmp_value = builtin___v_malloc(d->value_bytes);
	u8* tmp_key = builtin___v_malloc(d->key_bytes);
	int count = 0;
	for (int i = 0; i < d->len; ++i) {
		if (builtin__DenseArray_has_index(d, i)) {
			{ // Unsafe block
				if (count != i) {
					memcpy(tmp_key, builtin__DenseArray_key(d, count), d->key_bytes);
					memcpy(builtin__DenseArray_key(d, count), builtin__DenseArray_key(d, i), d->key_bytes);
					memcpy(builtin__DenseArray_key(d, i), tmp_key, d->key_bytes);
					memcpy(tmp_value, builtin__DenseArray_value(d, count), d->value_bytes);
					memcpy(builtin__DenseArray_value(d, count), builtin__DenseArray_value(d, i), d->value_bytes);
					memcpy(builtin__DenseArray_value(d, i), tmp_value, d->value_bytes);
				}
			}
			count++;
		}
	}
	{ // Unsafe block
		builtin___v_free(tmp_value);
		builtin___v_free(tmp_key);
		d->deletes = 0;
		builtin___v_free(d->all_deleted);
		d->all_deleted = ((void*)0);
	}
	d->len = count;
	int old_cap = d->cap;
	if (count < 8) {
		d->cap = 8;
	} else {
		d->cap = count;
	}
	{ // Unsafe block
		d->values = builtin__realloc_data(d->values, d->value_bytes * old_cap, d->value_bytes * d->cap);
		d->keys = builtin__realloc_data(d->keys, d->key_bytes * old_cap, d->key_bytes * d->cap);
	}
}
inline VV_LOC DenseArray builtin__new_dense_array(int key_bytes, int value_bytes) {
	int cap = 8;
	return ((DenseArray){
		.key_bytes = key_bytes,
		.value_bytes = value_bytes,
		.cap = cap,
		.len = 0,
		.deletes = 0,
		.all_deleted = ((void*)0),
		.keys = builtin___v_malloc(builtin____at_least_one(((u64)(cap)) * ((u64)(key_bytes)))),
		.values = builtin___v_malloc(builtin____at_least_one(((u64)(cap)) * ((u64)(value_bytes)))),
	});
}
inline VV_LOC voidptr builtin__DenseArray_key(DenseArray* d, int i) {
	return ((voidptr)(d->keys + i * d->key_bytes));
}
inline VV_LOC voidptr builtin__DenseArray_value(DenseArray* d, int i) {
	return ((voidptr)(d->values + i * d->value_bytes));
}
inline VV_LOC bool builtin__DenseArray_has_index(DenseArray* d, int i) {
	return d->deletes == 0 || d->all_deleted[i] == 0;
}
inline VV_LOC void builtin__DenseArray_trim_deleted_tail(DenseArray* d) {
	if (d->deletes == 0) {
		return;
	}
	for (;;) {
		if (!(d->len > 0 && d->all_deleted[d->len - 1] != 0)) break;
		{ // Unsafe block
			d->all_deleted[d->len - 1] = 0;
		}
		d->deletes--;
		d->len--;
	}
	if (d->deletes == 0) {
		{ // Unsafe block
			builtin___v_free(d->all_deleted);
			d->all_deleted = ((void*)0);
		}
	}
}
inline VV_LOC int builtin__DenseArray_expand(DenseArray* d) {
	int old_cap = d->cap;
	int old_key_size = d->key_bytes * old_cap;
	int old_value_size = d->value_bytes * old_cap;
	if (d->cap == d->len) {
		d->cap += v__rshift_int(d->cap, (u64)3);
		{ // Unsafe block
			d->keys = builtin__realloc_data(d->keys, old_key_size, d->key_bytes * d->cap);
			d->values = builtin__realloc_data(d->values, old_value_size, d->value_bytes * d->cap);
			if (d->deletes != 0) {
				d->all_deleted = builtin__realloc_data(d->all_deleted, old_cap, d->cap);
				builtin__vmemset(((voidptr)(d->all_deleted + d->len)), 0, d->cap - d->len);
			}
		}
	}
	int push_index = d->len;
	{ // Unsafe block
		if (d->deletes != 0) {
			d->all_deleted[push_index] = 0;
		}
	}
	d->len++;
	return push_index;
}
inline VV_LOC bool builtin__map_eq_string(voidptr a, voidptr b) {
	return builtin__fast_string_eq(*((string*)(a)), *((string*)(b)));
}
inline VV_LOC bool builtin__map_eq_int_1(voidptr a, voidptr b) {
	return *((u8*)(a)) == *((u8*)(b));
}
inline VV_LOC bool builtin__map_eq_int_2(voidptr a, voidptr b) {
	return *((u16*)(a)) == *((u16*)(b));
}
inline VV_LOC bool builtin__map_eq_int_4(voidptr a, voidptr b) {
	return *((u32*)(a)) == *((u32*)(b));
}
inline VV_LOC bool builtin__map_eq_int_8(voidptr a, voidptr b) {
	return *((u64*)(a)) == *((u64*)(b));
}
VV_LOC bool builtin__map_map_eq(map a, map b) {
	if (a.len != b.len) {
		return false;
	}
	for (int i = 0; i < a.key_values.len; i++) {
		if (!builtin__DenseArray_has_index(&a.key_values, i)) {
			continue;
		}
		voidptr k = builtin__DenseArray_key(&a.key_values, i);
		if (!builtin__map_exists(&b, k)) {
			return false;
		}
		voidptr va = builtin__DenseArray_value(&a.key_values, i);
		voidptr vb = builtin__map_get(&b, k, va);
		if (builtin__vmemcmp(va, vb, a.value_bytes) != 0) {
			return false;
		}
	}
	return true;
}
inline VV_LOC void builtin__map_clone_string(voidptr dest, voidptr pkey) {
	{ // Unsafe block
		string s = *((string*)(pkey));
		string cloned = builtin__string_clone(s);
		builtin__vmemcpy(dest, ((voidptr)(&cloned)), sizeof(string));
	}
}
inline VV_LOC void builtin__map_clone_int_1(voidptr dest, voidptr pkey) {
	{ // Unsafe block
		*((u8*)(dest)) = *((u8*)(pkey));
	}
}
inline VV_LOC void builtin__map_clone_int_2(voidptr dest, voidptr pkey) {
	{ // Unsafe block
		*((u16*)(dest)) = *((u16*)(pkey));
	}
}
inline VV_LOC void builtin__map_clone_int_4(voidptr dest, voidptr pkey) {
	{ // Unsafe block
		*((u32*)(dest)) = *((u32*)(pkey));
	}
}
inline VV_LOC void builtin__map_clone_int_8(voidptr dest, voidptr pkey) {
	{ // Unsafe block
		*((u64*)(dest)) = *((u64*)(pkey));
	}
}
inline VV_LOC void builtin__map_free_string(voidptr pkey) {
	builtin__string_free(ADDR(string, (*((string*)(pkey)))));
}
inline VV_LOC void builtin__map_free_nop(voidptr _d1) {
}
VV_LOC map builtin__new_map(int key_bytes, int value_bytes, u64 (*hash_fn)(voidptr _d1), bool (*key_eq_fn)(voidptr _d1, voidptr _d2), void (*clone_fn)(voidptr _d1, voidptr _d2), void (*free_fn)(voidptr _d1)) {
	int metasize = ((int)((u32)(sizeof(u32) * (_const_init_capicity + _const_extra_metas_inc))));
	bool has_string_keys = key_bytes > ((int)(sizeof(voidptr)));
	return ((map){
		.key_bytes = key_bytes,
		.value_bytes = value_bytes,
		.even_index = _const_init_even_index,
		.cached_hashbits = _const_max_cached_hashbits,
		.shift = _const_init_log_capicity,
		.key_values = builtin__new_dense_array(key_bytes, value_bytes),
		.metas = ((u32*)(builtin__vcalloc_noscan(metasize))),
		.extra_metas = _const_extra_metas_inc,
		.has_string_keys = has_string_keys,
		.hash_fn = hash_fn,
		.key_eq_fn = key_eq_fn,
		.clone_fn = clone_fn,
		.free_fn = free_fn,
		.len = 0,
	});
}
VV_LOC map builtin__new_map_init(u64 (*hash_fn)(voidptr _d1), bool (*key_eq_fn)(voidptr _d1, voidptr _d2), void (*clone_fn)(voidptr _d1, voidptr _d2), void (*free_fn)(voidptr _d1), int n, int key_bytes, int value_bytes, voidptr keys, voidptr values) {
	map out = builtin__new_map(key_bytes, value_bytes, hash_fn, key_eq_fn, clone_fn, free_fn);
	u8* pkey = ((u8*)(keys));
	u8* pval = ((u8*)(values));
	for (int _t1 = 0; _t1 < n; ++_t1) {
		{ // Unsafe block
			builtin__map_set(&out, pkey, pval);
			pkey = pkey + key_bytes;
			pval = pval + value_bytes;
		}
	}
	return out;
}
map builtin__map_move(map* m) {
	map r = *m;
	builtin__vmemset(m, 0, ((int)(sizeof(map))));
	return r;
}
void builtin__map_clear(map* m) {
	{ // Unsafe block
		if (m->key_values.all_deleted != 0) {
			builtin___v_free(m->key_values.all_deleted);
			m->key_values.all_deleted = ((void*)0);
		}
		builtin__vmemset(m->key_values.keys, 0, m->key_values.key_bytes * m->key_values.cap);
		builtin__vmemset(m->metas, 0, sizeof(u32) * (m->even_index + 2 + m->extra_metas));
	}
	m->key_values.len = 0;
	m->key_values.deletes = 0;
	m->even_index = _const_init_even_index;
	m->cached_hashbits = _const_max_cached_hashbits;
	m->shift = _const_init_log_capicity;
	m->len = 0;
}
inline VV_LOC multi_return_u32_u32 builtin__map_key_to_index(map* m, voidptr pkey) {
	if (((voidptr)(m->hash_fn)) == ((void*)0)) {
		{ // Unsafe block
			u64* p = ((u64*)(m));
			u64 prev2 = (((u64*)(((usize)(m)) - ((usize)(16)))))[0];
			u64 prev1 = (((u64*)(((usize)(m)) - ((usize)(8)))))[0];
			builtin___v_panic(builtin__string_plus_many(34, _MOV((string[34]){_S("map.hash_fn is nil map_ptr="), builtin__usize_str(((usize)(m))), _S(" key_bytes="), builtin__int_str(m->key_bytes), _S(" value_bytes="), builtin__int_str(m->value_bytes), _S(" even_index="), builtin__u32_str(m->even_index), _S(" shift="), builtin__u8_str(m->shift), _S(" metas="), builtin__usize_str(((usize)(m->metas))), _S(" prev2="), builtin__u64_str(prev2), _S(" prev1="), builtin__u64_str(prev1), _S(" w0="), builtin__u64_str(p[0]), _S(" w1="), builtin__u64_str(p[1]), _S(" w2="), builtin__u64_str(p[2]), _S(" w3="), builtin__u64_str(p[3]), _S(" w4="), builtin__u64_str(p[4]), _S(" w5="), builtin__u64_str(p[5]), _S(" w6="), builtin__u64_str(p[6]), _S(" w7="), builtin__u64_str(p[7]), _S(" hash_fn="), builtin__usize_str(((usize)(((voidptr)(m->hash_fn)))))})));
			VUNREACHABLE();
		}
	}
	u64 hash = m->hash_fn(pkey);
	u64 index = (hash & m->even_index);
	u64 meta = ((((v__rshift_u64(hash, (u64)m->shift)) & _const_hash_mask)) | _const_probe_inc);
	return (multi_return_u32_u32){.arg0=((u32)(index)), .arg1=((u32)(meta))};
}
inline VV_LOC multi_return_u32_u32 builtin__map_meta_less(map* m, u32 _index, u32 _metas) {
	u32 index = _index;
	u32 meta = _metas;
	for (;;) {
		if (!(meta < m->metas[index])) break;
		index += 2;
		meta += _const_probe_inc;
	}
	return (multi_return_u32_u32){.arg0=index, .arg1=meta};
}
inline VV_LOC void builtin__map_meta_greater(map* m, u32 _index, u32 _metas, u32 kvi) {
	u32 meta = _metas;
	u32 index = _index;
	u32 kv_index = kvi;
	for (;;) {
		if (!(m->metas[index] != 0)) break;
		if (meta > m->metas[index]) {
			{ // Unsafe block
				u32 tmp_meta = m->metas[index];
				m->metas[index] = meta;
				meta = tmp_meta;
				u32 tmp_index = m->metas[index + 1];
				m->metas[index + 1] = kv_index;
				kv_index = tmp_index;
			}
		}
		index += 2;
		meta += _const_probe_inc;
		if (index + 2 >= m->even_index + 2 + m->extra_metas) {
			builtin__map_ensure_extra_metas_grow(m);
		}
	}
	{ // Unsafe block
		m->metas[index] = meta;
		m->metas[index + 1] = kv_index;
	}
	u32 probe_count = (v__rshift_u32(meta, (u64)_const_hashbits)) - 1;
	builtin__map_ensure_extra_metas(m, probe_count);
}
VV_LOC void builtin__map_ensure_extra_metas_grow(map* m) {
	u32 size_of_u32 = sizeof(u32);
	u32 old_mem_size = (m->even_index + 2 + m->extra_metas);
	m->extra_metas += _const_extra_metas_inc;
	u32 mem_size = (m->even_index + 2 + m->extra_metas);
	{ // Unsafe block
		u8* x = builtin__realloc_data(((byteptr)(m->metas)), ((int)(size_of_u32 * old_mem_size)), ((int)(size_of_u32 * mem_size)));
		m->metas = ((u32*)(x));
		builtin__vmemset(((byteptr)(m->metas)) + (mem_size - _const_extra_metas_inc) * size_of_u32, 0, ((int)(sizeof(u32) * _const_extra_metas_inc)));
	}
}
inline VV_LOC void builtin__map_ensure_extra_metas(map* m, u32 probe_count) {
	if ((v__lshift_u32(probe_count, (u64)1)) == m->extra_metas) {
		u32 size_of_u32 = sizeof(u32);
		u32 old_mem_size = (m->even_index + 2 + m->extra_metas);
		m->extra_metas += _const_extra_metas_inc;
		u32 mem_size = (m->even_index + 2 + m->extra_metas);
		{ // Unsafe block
			u8* x = builtin__realloc_data(((byteptr)(m->metas)), ((int)(size_of_u32 * old_mem_size)), ((int)(size_of_u32 * mem_size)));
			m->metas = ((u32*)(x));
			builtin__vmemset(((byteptr)(m->metas)) + (mem_size - _const_extra_metas_inc) * size_of_u32, 0, ((int)(sizeof(u32) * _const_extra_metas_inc)));
		}
		if (probe_count == 252) {
			builtin___v_panic(_S("Probe overflow"));
			VUNREACHABLE();
		}
	}
}
VV_LOC void builtin__map_set(map* m, voidptr key, voidptr value) {
	if (((u32)(5)) * ((u32)(m->len)) > ((u32)(2)) * m->even_index) {
		builtin__map_expand(m);
	}
	multi_return_u32_u32 mr_14546 = builtin__map_key_to_index(m, key);
	u32 index = mr_14546.arg0;
	u32 meta = mr_14546.arg1;
	multi_return_u32_u32 mr_14582 = builtin__map_meta_less(m, index, meta);
	index = mr_14582.arg0;
	meta = mr_14582.arg1;
	for (;;) {
		if (!(meta == m->metas[index])) break;
		int kv_index = ((int)(m->metas[index + 1]));
		voidptr pkey = builtin__DenseArray_key(&m->key_values, kv_index);
		if (m->key_eq_fn(key, pkey)) {
			{ // Unsafe block
				voidptr pval = builtin__DenseArray_value(&m->key_values, kv_index);
				builtin__vmemcpy(pval, value, m->value_bytes);
			}
			return;
		}
		index += 2;
		meta += _const_probe_inc;
	}
	int kv_index = builtin__DenseArray_expand(&m->key_values);
	{ // Unsafe block
		voidptr pkey = builtin__DenseArray_key(&m->key_values, kv_index);
		voidptr pvalue = builtin__DenseArray_value(&m->key_values, kv_index);
		m->clone_fn(pkey, key);
		builtin__vmemcpy(pvalue, value, m->value_bytes);
	}
	builtin__map_meta_greater(m, index, meta, ((u32)(kv_index)));
	m->len++;
}
VV_LOC void builtin__map_expand(map* m) {
	u32 old_cap = m->even_index;
	m->even_index = (v__lshift_u32((m->even_index + 2), (u64)1)) - 2;
	if (m->cached_hashbits == 0) {
		m->shift += _const_max_cached_hashbits;
		m->cached_hashbits = _const_max_cached_hashbits;
		builtin__map_rehash(m);
	} else {
		builtin__map_cached_rehash(m, old_cap);
		m->cached_hashbits--;
	}
}
VV_LOC void builtin__map_rehash(map* m) {
	u32 meta_bytes = sizeof(u32) * (m->even_index + 2 + m->extra_metas);
	builtin__map_reserve_metas(m, meta_bytes);
}
VV_LOC void builtin__map_reserve_metas(map* m, u32 meta_bytes) {
	{ // Unsafe block
		u8* x = builtin__v_realloc(((byteptr)(m->metas)), ((int)(meta_bytes)));
		m->metas = ((u32*)(x));
		builtin__vmemset(m->metas, 0, ((int)(meta_bytes)));
	}
	for (int i = 0; i < m->key_values.len; i++) {
		if (!builtin__DenseArray_has_index(&m->key_values, i)) {
			continue;
		}
		voidptr pkey = builtin__DenseArray_key(&m->key_values, i);
		multi_return_u32_u32 mr_16309 = builtin__map_key_to_index(m, pkey);
		u32 index = mr_16309.arg0;
		u32 meta = mr_16309.arg1;
		multi_return_u32_u32 mr_16347 = builtin__map_meta_less(m, index, meta);
		index = mr_16347.arg0;
		meta = mr_16347.arg1;
		builtin__map_meta_greater(m, index, meta, ((u32)(i)));
	}
}
void builtin__map_reserve(map* m, u32 n) {
	for (;;) {
		if (!(((u64)(n)) * 5 > ((u64)(m->even_index)) * 2)) break;
		builtin__map_expand(m);
	}
}
VV_LOC void builtin__map_cached_rehash(map* m, u32 old_cap) {
	u32* old_metas = m->metas;
	int metasize = ((int)(sizeof(u32) * (m->even_index + 2 + m->extra_metas)));
	m->metas = ((u32*)(builtin__vcalloc(metasize)));
	u32 old_extra_metas = m->extra_metas;
	for (u32 i = ((u32)(0)); i <= old_cap + old_extra_metas; i += 2) {
		if (old_metas[i] == 0) {
			continue;
		}
		u32 old_meta = old_metas[i];
		u32 old_probe_count = v__lshift_u32(((v__rshift_u32(old_meta, (u64)_const_hashbits)) - 1), (u64)1);
		u32 old_index = ((i - old_probe_count) & (v__rshift_u32(m->even_index, (u64)1)));
		u32 index = (((old_index | (v__lshift_u32(old_meta, (u64)m->shift)))) & m->even_index);
		u32 meta = (((old_meta & _const_hash_mask)) | _const_probe_inc);
		u32 kv_index = old_metas[i + 1];
		multi_return_u32_u32 mr_17370 = builtin__map_meta_less(m, index, meta);
		index = mr_17370.arg0;
		meta = mr_17370.arg1;
		builtin__map_meta_greater(m, index, meta, kv_index);
	}
	builtin___v_free(old_metas);
}
VV_LOC voidptr builtin__map_get_and_set(map* m, voidptr key, voidptr zero) {
	for (;;) {
		multi_return_u32_u32 mr_17776 = builtin__map_key_to_index(m, key);
		u32 index = mr_17776.arg0;
		u32 meta = mr_17776.arg1;
		for (;;) {
			if (meta == m->metas[index]) {
				int kv_index = ((int)(m->metas[index + 1]));
				voidptr pkey = builtin__DenseArray_key(&m->key_values, kv_index);
				if (m->key_eq_fn(key, pkey)) {
					voidptr pval = builtin__DenseArray_value(&m->key_values, kv_index);
					return ((u8*)(pval));
				}
			}
			index += 2;
			meta += _const_probe_inc;
			if (meta > m->metas[index]) {
				break;
			}
		}
		builtin__map_set(m, key, zero);
	}
	return ((void*)0);
}
VV_LOC voidptr builtin__map_get(map* m, voidptr key, voidptr zero) {
	if (m->len == 0) {
		return zero;
	}
	multi_return_u32_u32 mr_18537 = builtin__map_key_to_index(m, key);
	u32 index = mr_18537.arg0;
	u32 meta = mr_18537.arg1;
	for (;;) {
		if (meta == m->metas[index]) {
			int kv_index = ((int)(m->metas[index + 1]));
			voidptr pkey = builtin__DenseArray_key(&m->key_values, kv_index);
			if (m->key_eq_fn(key, pkey)) {
				voidptr pval = builtin__DenseArray_value(&m->key_values, kv_index);
				return ((u8*)(pval));
			}
		}
		index += 2;
		meta += _const_probe_inc;
		if (meta > m->metas[index]) {
			break;
		}
	}
	return zero;
}
VV_LOC voidptr builtin__map_get_check(map* m, voidptr key) {
	if (m->len == 0) {
		return 0;
	}
	multi_return_u32_u32 mr_19233 = builtin__map_key_to_index(m, key);
	u32 index = mr_19233.arg0;
	u32 meta = mr_19233.arg1;
	for (;;) {
		if (meta == m->metas[index]) {
			int kv_index = ((int)(m->metas[index + 1]));
			voidptr pkey = builtin__DenseArray_key(&m->key_values, kv_index);
			if (m->key_eq_fn(key, pkey)) {
				voidptr pval = builtin__DenseArray_value(&m->key_values, kv_index);
				return ((u8*)(pval));
			}
		}
		index += 2;
		meta += _const_probe_inc;
		if (meta > m->metas[index]) {
			break;
		}
	}
	return 0;
}
VV_LOC bool builtin__map_exists(map* m, voidptr key) {
	if (m->len == 0) {
		return false;
	}
	multi_return_u32_u32 mr_19778 = builtin__map_key_to_index(m, key);
	u32 index = mr_19778.arg0;
	u32 meta = mr_19778.arg1;
	for (;;) {
		if (meta == m->metas[index]) {
			int kv_index = ((int)(m->metas[index + 1]));
			voidptr pkey = builtin__DenseArray_key(&m->key_values, kv_index);
			if (m->key_eq_fn(key, pkey)) {
				return true;
			}
		}
		index += 2;
		meta += _const_probe_inc;
		if (meta > m->metas[index]) {
			break;
		}
	}
	return false;
}
inline VV_LOC void builtin__DenseArray_delete(DenseArray* d, int i) {
	if (i == d->len - 1) {
		d->len--;
		builtin__DenseArray_trim_deleted_tail(d);
		return;
	}
	if (d->deletes == 0) {
		d->all_deleted = builtin__vcalloc(d->cap);
	}
	d->deletes++;
	{ // Unsafe block
		d->all_deleted[i] = 1;
	}
}
void builtin__map_delete(map* m, voidptr key) {
	multi_return_u32_u32 mr_20483 = builtin__map_key_to_index(m, key);
	u32 index = mr_20483.arg0;
	u32 meta = mr_20483.arg1;
	multi_return_u32_u32 mr_20519 = builtin__map_meta_less(m, index, meta);
	index = mr_20519.arg0;
	meta = mr_20519.arg1;
	for (;;) {
		if (!(meta == m->metas[index])) break;
		int kv_index = ((int)(m->metas[index + 1]));
		voidptr pkey = builtin__DenseArray_key(&m->key_values, kv_index);
		if (m->key_eq_fn(key, pkey)) {
			for (;;) {
				if (!((v__rshift_u32(m->metas[index + 2], (u64)_const_hashbits)) > 1)) break;
				{ // Unsafe block
					m->metas[index] = m->metas[index + 2] - _const_probe_inc;
					m->metas[index + 1] = m->metas[index + 3];
				}
				index += 2;
			}
			m->len--;
			builtin__DenseArray_delete(&m->key_values, kv_index);
			{ // Unsafe block
				m->metas[index] = 0;
				m->free_fn(pkey);
				builtin__vmemset(pkey, 0, m->key_bytes);
			}
			if (m->key_values.len <= 32) {
				return;
			}
			if (_us32_ge(m->key_values.deletes,(v__rshift_int(m->key_values.len, (u64)1)))) {
				builtin__DenseArray_zeros_to_end(&m->key_values);
				builtin__map_rehash(m);
			}
			return;
		}
		index += 2;
		meta += _const_probe_inc;
	}
}
array builtin__map_keys(map* m) {
	array keys = builtin____new_array(m->len, 0, m->key_bytes);
	u8* item = ((u8*)(keys.data));
	if (m->key_values.deletes == 0) {
		for (int i = 0; i < m->key_values.len; i++) {
			{ // Unsafe block
				voidptr pkey = builtin__DenseArray_key(&m->key_values, i);
				m->clone_fn(item, pkey);
				item = item + m->key_bytes;
			}
		}
		return keys;
	}
	for (int i = 0; i < m->key_values.len; i++) {
		if (!builtin__DenseArray_has_index(&m->key_values, i)) {
			continue;
		}
		{ // Unsafe block
			voidptr pkey = builtin__DenseArray_key(&m->key_values, i);
			m->clone_fn(item, pkey);
			item = item + m->key_bytes;
		}
	}
	return keys;
}
array builtin__map_values(map* m) {
	array values = builtin____new_array(m->len, 0, m->value_bytes);
	u8* item = ((u8*)(values.data));
	if (m->key_values.deletes == 0) {
		builtin__vmemcpy(item, m->key_values.values, m->value_bytes * m->key_values.len);
		return values;
	}
	for (int i = 0; i < m->key_values.len; i++) {
		if (!builtin__DenseArray_has_index(&m->key_values, i)) {
			continue;
		}
		{ // Unsafe block
			voidptr pvalue = builtin__DenseArray_value(&m->key_values, i);
			builtin__vmemcpy(item, pvalue, m->value_bytes);
			item = item + m->value_bytes;
		}
	}
	return values;
}
VV_LOC DenseArray builtin__DenseArray_clone(DenseArray* d) {
	DenseArray res = ((DenseArray){
		.key_bytes = d->key_bytes,
		.value_bytes = d->value_bytes,
		.cap = d->cap,
		.len = d->len,
		.deletes = d->deletes,
		.all_deleted = ((void*)0),
		.keys = ((void*)0),
		.values = ((void*)0),
	});
	{ // Unsafe block
		if (d->deletes != 0) {
			res.all_deleted = builtin__memdup(d->all_deleted, d->cap);
		}
		res.keys = builtin__memdup(d->keys, d->cap * d->key_bytes);
		res.values = builtin__memdup(d->values, d->cap * d->value_bytes);
	}
	return res;
}
map builtin__map_clone(map* m) {
	int metasize = ((int)(sizeof(u32) * (m->even_index + 2 + m->extra_metas)));
	map res = ((map){
		.key_bytes = m->key_bytes,
		.value_bytes = m->value_bytes,
		.even_index = m->even_index,
		.cached_hashbits = m->cached_hashbits,
		.shift = m->shift,
		.key_values = builtin__DenseArray_clone(&m->key_values),
		.metas = ((u32*)(builtin__malloc_noscan(metasize))),
		.extra_metas = m->extra_metas,
		.has_string_keys = m->has_string_keys,
		.hash_fn = m->hash_fn,
		.key_eq_fn = m->key_eq_fn,
		.clone_fn = m->clone_fn,
		.free_fn = m->free_fn,
		.len = m->len,
	});
	builtin__vmemcpy(res.metas, m->metas, metasize);
	if (!m->has_string_keys) {
		return res;
	}
	for (int i = 0; i < m->key_values.len; ++i) {
		if (!builtin__DenseArray_has_index(&m->key_values, i)) {
			continue;
		}
		m->clone_fn(builtin__DenseArray_key(&res.key_values, i), builtin__DenseArray_key(&m->key_values, i));
	}
	return res;
}
void builtin__map_free(map* m) {
	builtin___v_free(m->metas);
	{ // Unsafe block
		m->metas = ((void*)0);
	}
	if (m->key_values.deletes == 0) {
		for (int i = 0; i < m->key_values.len; i++) {
			{ // Unsafe block
				voidptr pkey = builtin__DenseArray_key(&m->key_values, i);
				m->free_fn(pkey);
				builtin__vmemset(pkey, 0, m->key_bytes);
			}
		}
	} else {
		for (int i = 0; i < m->key_values.len; i++) {
			if (!builtin__DenseArray_has_index(&m->key_values, i)) {
				continue;
			}
			{ // Unsafe block
				voidptr pkey = builtin__DenseArray_key(&m->key_values, i);
				m->free_fn(pkey);
				builtin__vmemset(pkey, 0, m->key_bytes);
			}
		}
	}
	{ // Unsafe block
		if (m->key_values.all_deleted != ((void*)0)) {
			builtin___v_free(m->key_values.all_deleted);
			m->key_values.all_deleted = ((void*)0);
		}
		if (m->key_values.keys != ((void*)0)) {
			builtin___v_free(m->key_values.keys);
			m->key_values.keys = ((void*)0);
		}
		if (m->key_values.values != ((void*)0)) {
			builtin___v_free(m->key_values.values);
			m->key_values.values = ((void*)0);
		}
		m->hash_fn = ((void*)0);
		m->key_eq_fn = ((void*)0);
		m->clone_fn = ((void*)0);
		m->free_fn = ((void*)0);
		m->key_values.cap = 0;
		m->key_values.len = 0;
		m->key_values.deletes = 0;
		m->even_index = 0;
		m->cached_hashbits = 0;
		m->shift = 0;
		m->extra_metas = 0;
		m->has_string_keys = false;
		m->len = 0;
	}
}
void builtin__IError_free(IError* ie) {
	{ // Unsafe block
		IError* cie = ((IError*)(ie));
		builtin___v_free(cie->_object);
	}
}
VNORETURN void builtin__panic_option_not_set(string s) {
	builtin___v_panic(builtin__string_plus_many(3, _MOV((string[3]){_S("option not set ("), s, _S(")")})));
	VUNREACHABLE();
	while(1);
}
VNORETURN void builtin__panic_result_not_set(string s) {
	builtin___v_panic(builtin__string_plus_many(3, _MOV((string[3]){_S("result not set ("), s, _S(")")})));
	VUNREACHABLE();
	while(1);
}
VNORETURN void builtin___v_panic(string s) {
	#if 0
	{
	}
	#elif defined(CUSTOM_DEFINE_v2_native_windows_pe_minimal)
	{
	}
	#else
	{
		builtin__flush_stdout();
		builtin__eprint(_S("V panic: "));
		builtin__eprintln(s);
		builtin__eprint(_S(" v hash: "));
		builtin__eprintln(builtin__vcurrent_hash());
		#if 1
		{
			builtin__eprint(_S("    pid: "));
			;
			fprintf(stderr, "%p\n", ((voidptr)(builtin__v_getpid())));
			builtin__eprint(_S("    tid: "));
			;
			fprintf(stderr, "%p\n", ((voidptr)(builtin__v_gettid())));
		}
		#endif
		builtin__flush_stdout();
		#if defined(CUSTOM_DEFINE_exit_after_panic_message)
		{
		}
		#elif defined(CUSTOM_DEFINE_no_backtrace)
		{
			exit(1);
			VUNREACHABLE();
		}
		#elif 0
		{
		}
		#else
		{
		}
		#endif
	}
	#endif
	exit(1);
	VUNREACHABLE();
	for (;;) {
	}
	while(1);
}
VNORETURN void builtin__panic_n(string s, i64 number1) {
	builtin___v_panic(builtin__string__plus(s, builtin__impl_i64_to_string(number1)));
	VUNREACHABLE();
	while(1);
}
VNORETURN void builtin__panic_n2(string s, i64 number1, i64 number2) {
	builtin___v_panic(builtin__string_plus_many(4, _MOV((string[4]){s, builtin__impl_i64_to_string(number1), _S(", "), builtin__impl_i64_to_string(number2)})));
	VUNREACHABLE();
	while(1);
}
VNORETURN VV_LOC void builtin__panic_n3(string s, i64 number1, i64 number2, i64 number3) {
	builtin___v_panic(builtin__string_plus_many(6, _MOV((string[6]){s, builtin__impl_i64_to_string(number1), _S(", "), builtin__impl_i64_to_string(number2), _S(", "), builtin__impl_i64_to_string(number3)})));
	VUNREACHABLE();
	while(1);
}
VV_LOC void builtin__set_stream_unbuffered(FILE* stream) {
	setvbuf(stream, ((char*)(((void*)0))), _IONBF, ((usize)(0)));
}
void builtin__eprintln(string s) {
	#if 0
	{
	}
	#elif 0
	{
	}
	#else
	{
		builtin__flush_stdout();
		builtin__flush_stderr();
		builtin___writeln_to_fd(2, s);
		builtin__flush_stderr();
	}
	#endif
}
void builtin__eprint(string s) {
	#if 0
	{
	}
	#elif 0
	{
	}
	#else
	{
		builtin__flush_stdout();
		builtin__flush_stderr();
		builtin___write_buf_to_fd(2, s.str, s.len);
		builtin__flush_stderr();
	}
	#endif
}
void builtin__flush_stdout(void) {
	#if defined(CUSTOM_DEFINE_v2_native_windows_pe_minimal)
	{
	}
	#elif 0
	{
	}
	#elif defined(CUSTOM_DEFINE_builtin_write_buf_to_fd_should_use_c_write)
	{
	}
	#else
	{
		fflush(stdout);
	}
	#endif
}
void builtin__flush_stderr(void) {
	#if defined(CUSTOM_DEFINE_v2_native_windows_pe_minimal)
	{
	}
	#elif 0
	{
	}
	#elif defined(CUSTOM_DEFINE_builtin_write_buf_to_fd_should_use_c_write)
	{
	}
	#else
	{
		fflush(stderr);
	}
	#endif
}
void builtin__unbuffer_stdout(void) {
	#if 0
	{
	}
	#elif 0
	{
	}
	#elif defined(CUSTOM_DEFINE_builtin_write_buf_to_fd_should_use_c_write)
	{
	}
	#else
	{
		builtin__set_stream_unbuffered(stdout);
	}
	#endif
}
void builtin__print(string s) {
	#if 0
	{
	}
	#elif 0
	{
	}
	#elif 0
	{
	}
	#else
	{
		builtin___write_buf_to_fd(1, s.str, s.len);
	}
	#endif
}
void builtin__println(string s) {
	#if 0
	{
	}
	#elif 0
	{
	}
	#elif 0
	{
	}
	#else
	{
		builtin___writeln_to_fd(1, s);
	}
	#endif
}
VV_LOC void builtin___writeln_to_fd(int fd, string s) {
	#if defined(CUSTOM_DEFINE_builtin_writeln_should_write_at_once)
	{
	}
	#else
	{
		u8 lf = ((u8)('\n'));
		builtin___write_buf_to_fd(fd, s.str, s.len);
		builtin___write_buf_to_fd(fd, &lf, 1);
	}
	#endif
}
VV_LOC void builtin___write_buf_to_fd(int fd, u8* buf, int buf_len) {
	if (buf_len <= 0) {
		return;
	}
	#if 0
	{
	}
	#else
	{
		u8* ptr = buf;
		isize remaining_bytes = ((isize)(buf_len));
		isize x = ((isize)(0));
		#if 0
		{
		}
		#else
		{
			voidptr stream = ((voidptr)(stdout));
			if (fd == 2) {
				stream = ((voidptr)(stderr));
			}
			{ // Unsafe block
				for (;;) {
					if (!(remaining_bytes > 0)) break;
					x = ((isize)(fwrite(ptr, 1, remaining_bytes, stream)));
					if (x <= 0) {
						break;
					}
					ptr += x;
					remaining_bytes -= x;
				}
			}
		}
		#endif
	}
	#endif
}
string builtin__rune_str(rune c) {
	return builtin__utf32_to_str(((u32)(c)));
}
string Array_rune_string(Array_rune ra) {
	strings__Builder sb = strings__new_builder(ra.len);
	strings__Builder_write_runes(&sb, ra);
	string res = strings__Builder_str(&sb);
	strings__Builder_free(&sb);
	return res;
}
Array_u8 builtin__rune_bytes(rune c) {
	Array_u8 res = builtin____new_array_with_default(0, 5, sizeof(u8), 0);
	u8* buf = ((u8*)(res.data));
	res.len = builtin__utf32_decode_to_buffer(((u32)(c)), buf);
	return res;
}
rune builtin__rune_to_upper(rune c) {
	if (c < 0x80) {
		if (c >= 'a' && c <= 'z') {
			return c - 32;
		}
		return c;
	}
	return builtin__rune_map_to(c, MapMode__to_upper);
}
rune builtin__rune_to_lower(rune c) {
	if (c < 0x80) {
		if (c >= 'A' && c <= 'Z') {
			return c + 32;
		}
		return c;
	}
	return builtin__rune_map_to(c, MapMode__to_lower);
}
VV_LOC rune builtin__rune_map_to(rune c, MapMode mode) {
	int start = 0;
	int end = VSAFE_DIV_int(1264 , _const_rune_maps_columns_in_row);
	for (;;) {
		if (!(start < end)) break;
		int middle = VSAFE_DIV_int((start + end) , 2);
		i32* cur_map = &_const_rune_maps[middle * _const_rune_maps_columns_in_row];
		if (c >= ((u32)(*cur_map)) && c <= ((u32)(*(cur_map + 1)))) {
			i32 offset = ((mode == MapMode__to_upper || mode == MapMode__to_title) ? (*(cur_map + 2)) : (*(cur_map + 3)));
			if (offset == _const_rune_maps_ul) {
				rune cnt = VSAFE_MOD_rune(((rune)(c - *cur_map)) , 2);
				if (mode == MapMode__to_lower) {
					return c + 1 - cnt;
				}
				return c - cnt;
			} else if (offset == _const_rune_maps_utl) {
				rune cnt = VSAFE_MOD_rune(((rune)(c - *cur_map)) , 3);
				if (mode == MapMode__to_upper) {
					return c - cnt;
				} else if (mode == MapMode__to_lower) {
					return c + 2 - cnt;
				}
				return c + 1 - cnt;
			}
			return (rune)(c + offset);
		}
		if (c < ((u32)(*cur_map))) {
			end = middle;
		} else {
			start = middle + 1;
		}
	}
	return c;
}
Array_rune builtin__string_runes(string s) {
	Array_rune runes = builtin____new_array_with_default(0, s.len, sizeof(rune), 0);
	for (int i = 0; i < s.len; i++) {
		multi_return_rune_int mr_2797 = builtin__utf8_decode_rune(&s.str[i], s.len - i);
		rune r = mr_2797.arg0;
		int char_len = mr_2797.arg1;
		builtin__array_push((array*)&runes, _MOV((rune[]){ r }));
		if (char_len > 1) {
			i += char_len - 1;
		}
	}
	return runes;
}
string builtin__cstring_to_vstring(const char* const_s) {
	string s = builtin__tos2(((byteptr)(const_s)));
	return builtin__string_clone(s);
}
string builtin__tos_clone(const u8* const_s) {
	string s = builtin__tos2(((u8*)(const_s)));
	return builtin__string_clone(s);
}
string builtin__tos(u8* s, int len) {
	if (s == 0) {
		builtin___v_panic(_S("tos(): nil string"));
		VUNREACHABLE();
	}
	return ((string){.str = s, .len = len});
}
string builtin__tos2(u8* s) {
	if (s == 0) {
		builtin___v_panic(_S("tos2: nil string"));
		VUNREACHABLE();
	}
	return ((string){.str = s, .len = builtin__vstrlen(s)});
}
string builtin__tos3(char* s) {
	if (s == 0) {
		builtin___v_panic(_S("tos3: nil string"));
		VUNREACHABLE();
	}
	return ((string){.str = ((u8*)(s)), .len = builtin__vstrlen_char(s)});
}
string builtin__u8_vstring(u8* bp) {
	return ((string){.str = bp, .len = builtin__vstrlen(bp)});
}
string builtin__u8_vstring_with_len(u8* bp, int len) {
	return ((string){.str = bp, .len = len, .is_lit = 0});
}
bool builtin__string_is_pure_ascii(string s) {
	for (int i = 0; i < s.len; ++i) {
		if (s.str[ i] >= 0x80) {
			return false;
		}
	}
	return true;
}
string builtin__string_clone(string a) {
	if (a.len <= 0) {
		return _S("");
	}
	string _t2 = ((string){.str = builtin__malloc_noscan(a.len + 1), .len = a.len});
	string b = _t2;
	{ // Unsafe block
		builtin__vmemcpy(b.str, a.str, a.len);
		b.str[a.len] = 0;
	}
	return b;
}
string builtin__string_replace(string s, string rep, string with) {
	if (s.len == 0 || rep.len == 0 || rep.len > s.len) {
		return builtin__string_clone(s);
	}
	if (!builtin__string_contains(s, rep)) {
		return builtin__string_clone(s);
	}
	int pidxs_len = 0;
	int pidxs_cap = VSAFE_DIV_int(s.len , rep.len);
	Array_fixed_int_10 stack_idxs = {0};
	int* pidxs = &stack_idxs[0];
	if (pidxs_cap > _const_replace_stack_buffer_size) {
		pidxs = ((int*)(builtin___v_malloc(((int)(sizeof(int))) * pidxs_cap)));
	}
	int idx = 0;
	for (;;) {
		idx = builtin__string_index_after_(s, rep, idx);
		if (idx == -1) {
			break;
		}
		{ // Unsafe block
			pidxs[pidxs_len] = idx;
			pidxs_len++;
		}
		idx += rep.len;
	}
	if (pidxs_len == 0) {
		string _t3 = builtin__string_clone(s);
			{ // defer begin
				if (pidxs_cap > _const_replace_stack_buffer_size) {
					builtin___v_free(pidxs);
				}
			} // defer end
		return _t3;
	}
	int new_len = s.len + pidxs_len * (with.len - rep.len);
	u8* b = builtin__malloc_noscan(new_len + 1);
	int b_i = 0;
	int s_idx = 0;
	for (int j = 0; j < pidxs_len; ++j) {
		int rep_pos = pidxs[j];
		int before_len = rep_pos - s_idx;
		builtin__vmemcpy(&b[b_i], &s.str[s_idx], before_len);
		b_i += before_len;
		s_idx = rep_pos + rep.len;
		builtin__vmemcpy(&b[b_i], &with.str[0], with.len);
		b_i += with.len;
	}
	if (s_idx < s.len) {
		builtin__vmemcpy(&b[b_i], &s.str[s_idx], s.len - s_idx);
	}
	{ // Unsafe block
		b[new_len] = 0;
		string _t4 = builtin__tos(b, new_len);
			{ // defer begin
				if (pidxs_cap > _const_replace_stack_buffer_size) {
					builtin___v_free(pidxs);
				}
			} // defer end
		return _t4;
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}
VV_LOC bool builtin__string__eq(string s, string a) {
	if (s.str == 0) {
		return a.str == 0 || a.len == 0;
	}
	if (s.len != a.len) {
		return false;
	}
	{ // Unsafe block
		return builtin__vmemcmp(s.str, a.str, a.len) == 0;
	}
	return 0;
}
VV_LOC bool builtin__string__lt(string s, string a) {
	for (int i = 0; i < s.len; ++i) {
		if (i >= a.len || s.str[ i] > a.str[ i]) {
			return false;
		} else if (s.str[ i] < a.str[ i]) {
			return true;
		}
	}
	if (s.len < a.len) {
		return true;
	}
	return false;
}
VV_LOC string builtin__string__plus(string s, string a) {
	int slen = (s.len > 0 ? (s.len) : (0));
	int alen = (a.len > 0 ? (a.len) : (0));
	int new_len = alen + slen;
	string _t1 = ((string){.str = builtin__malloc_noscan(new_len + 1), .len = new_len});
	string res = _t1;
	{ // Unsafe block
		if (slen > 0) {
			builtin__vmemcpy(res.str, s.str, slen);
		}
		if (alen > 0) {
			builtin__vmemcpy(res.str + slen, a.str, alen);
		}
		res.str[new_len] = 0;
	}
	return res;
}
VV_LOC string builtin__string_plus_many(int data_len, string* input_base) {
	int new_len = 0;
	for (int i = 0; i < data_len; i++) {
		string part = input_base[i];
		new_len += (part.len > 0 ? (part.len) : (0));
	}
	string _t1 = ((string){.str = builtin__malloc_noscan(new_len + 1), .len = new_len});
	string res = _t1;
	int offset = 0;
	{ // Unsafe block
		for (int i = 0; i < data_len; i++) {
			string part = input_base[i];
			int part_len = (part.len > 0 ? (part.len) : (0));
			if (part_len > 0) {
				builtin__vmemcpy(res.str + offset, part.str, part_len);
				offset += part_len;
			}
		}
		res.str[new_len] = 0;
	}
	return res;
}
inline Array_string builtin__string_split(string s, string delim) {
	return builtin__string_split_nth(s, delim, 0);
}
Array_string builtin__string_split_nth(string s, string delim, int nth) {
	Array_string res = builtin____new_array_with_default(0, 0, sizeof(string), 0);
	builtin__ArrayFlags_set(&res.flags, ArrayFlags__noslices);
	switch (delim.len) {
		case 0: {
			for (int i = 0; i < s.len; ++i) {
				u8 ch = s.str[i];
				if (nth > 0 && res.len == nth - 1) {
					builtin__array_push((array*)&res, _MOV((string[]){ builtin__string_substr(s, i, 2147483647) }));
					break;
				}
				builtin__array_push((array*)&res, _MOV((string[]){ builtin__u8_ascii_str(ch) }));
			}
			break;
		}
		case 1: {
			u8 delim_byte = delim.str[ 0];
			int start = 0;
			for (int i = 0; i < s.len; ++i) {
				u8 ch = s.str[i];
				if (ch == delim_byte) {
					if (nth > 0 && res.len == nth - 1) {
						break;
					}
					builtin__array_push((array*)&res, _MOV((string[]){ builtin__string_substr(s, start, i) }));
					start = i + 1;
				}
			}
			if (nth < 1 || res.len < nth) {
				builtin__array_push((array*)&res, _MOV((string[]){ builtin__string_substr(s, start, 2147483647) }));
			}
			break;
		}
		default: {
			{
				int start = 0;
				for (int i = 0; i + delim.len <= s.len; ) {
					if (builtin__string__eq(builtin__string_substr_unsafe(s, i, i + delim.len), delim)) {
						if (nth > 0 && res.len == nth - 1) {
							break;
						}
						builtin__array_push((array*)&res, _MOV((string[]){ builtin__string_substr(s, start, i) }));
						i += delim.len;
						start = i;
					} else {
						i++;
					}
				}
				if (nth < 1 || res.len < nth) {
					builtin__array_push((array*)&res, _MOV((string[]){ builtin__string_substr(s, start, 2147483647) }));
				}
				break;
			}
		}
	}
	
	Array_string _t7 = res;
		{ // defer begin
			builtin__ArrayFlags_clear(&res.flags, ArrayFlags__noslices);
		} // defer end
	return _t7;
}
Array_string builtin__string_split_into_lines(string s) {
	Array_string res = builtin____new_array_with_default(0, 0, sizeof(string), 0);
	if (s.len == 0) {
		return res;
	}
	builtin__ArrayFlags_set(&res.flags, ArrayFlags__noslices);
	rune cr = '\r';
	rune lf = '\n';
	int line_start = 0;
	for (int i = 0; i < s.len; i++) {
		if (line_start <= i) {
			if (s.str[ i] == lf) {
				builtin__array_push((array*)&res, _MOV((string[]){ (line_start == i ? (_S("")) : (builtin__string_substr(s, line_start, i))) }));
				line_start = i + 1;
			} else if (s.str[ i] == cr) {
				builtin__array_push((array*)&res, _MOV((string[]){ (line_start == i ? (_S("")) : (builtin__string_substr(s, line_start, i))) }));
				if ((i + 1) < s.len && s.str[ i + 1] == lf) {
					line_start = i + 2;
				} else {
					line_start = i + 1;
				}
			}
		}
	}
	if (line_start < s.len) {
		builtin__array_push((array*)&res, _MOV((string[]){ builtin__string_substr(s, line_start, 2147483647) }));
	}
	Array_string _t5 = res;
		{ // defer begin
			builtin__ArrayFlags_clear(&res.flags, ArrayFlags__noslices);
		} // defer end
	return _t5;
}
string builtin__string_substr(string s, int start, int _end) {
	int end = (_end == _const_max_i64 || _end == _const_max_i32 ? (s.len) : (_end));
	#if 1
	{
		if (start > end || start > s.len || end > s.len || start < 0 || end < 0) {
			builtin___v_panic(builtin__string_plus_many(8, _MOV((string[8]){_S("substr("), builtin__impl_i64_to_string(start), _S(", "), builtin__impl_i64_to_string(end), _S(") out of bounds (len="), builtin__impl_i64_to_string(s.len), _S(") s="), s})));
			VUNREACHABLE();
		}
	}
	#endif
	int len = end - start;
	if (len == s.len) {
		return builtin__string_clone(s);
	}
	string _t3 = ((string){.str = builtin__malloc_noscan(len + 1), .len = len});
	string res = _t3;
	{ // Unsafe block
		builtin__vmemcpy(res.str, s.str + start, len);
		res.str[len] = 0;
	}
	return res;
}
string builtin__string_substr_unsafe(string s, int start, int _end) {
	int end = (_end == 2147483647 ? (s.len) : (_end));
	int len = end - start;
	if (len == s.len) {
		return s;
	}
	return ((string){.str = s.str + start, .len = len});
}
int builtin__string_index_(string s, string p) {
	if (p.len > s.len || p.len == 0 || ((u64)(s.str)) <= 0xFFFF || ((u64)(p.str)) <= 0xFFFF) {
		return -1;
	}
	if (p.len > 2) {
		return builtin__string_index_kmp(s, p);
	}
	int i = 0;
	for (;;) {
		if (!(i < s.len)) break;
		int j = 0;
		for (;;) {
			if (!(j < p.len && s.str[i + j] == p.str[j])) break;
			j++;
		}
		if (j == p.len) {
			return i;
		}
		i++;
	}
	return -1;
}
inline _option_int builtin__string_last_index(string s, string needle) {
	int idx = builtin__string_index_last_(s, needle);
	if (idx == -1) {
		return (_option_int){ .state=2, .err=_const_none__, .data={E_STRUCT} };
	}
	_option_int _t2;
	builtin___option_ok(&(int[]) { idx }, (_option*)(&_t2), sizeof(int));
	 
	return _t2;
}
VV_LOC int builtin__string_index_kmp(string s, string p) {
	if (p.len > s.len) {
		return -1;
	}
	Array_fixed_int_20 stack_prefixes = {0};
	int* p_prefixes = &stack_prefixes[0];
	if (p.len > _const_kmp_stack_buffer_size) {
		p_prefixes = ((int*)(builtin__vcalloc(p.len * ((int)(sizeof(int))))));
	}
	int j = 0;
	for (int i = 1; i < p.len; i++) {
		for (;;) {
			if (!(p.str[j] != p.str[i] && j > 0)) break;
			j = p_prefixes[j - 1];
		}
		if (p.str[j] == p.str[i]) {
			j++;
		}
		{ // Unsafe block
			p_prefixes[i] = j;
		}
	}
	j = 0;
	for (int i = 0; i < s.len; ++i) {
		for (;;) {
			if (!(p.str[j] != s.str[i] && j > 0)) break;
			j = p_prefixes[j - 1];
		}
		if (p.str[j] == s.str[i]) {
			j++;
		}
		if (j == p.len) {
			int _t2 = (int)(i - p.len) + 1;
				{ // defer begin
					if (p.len > _const_kmp_stack_buffer_size) {
						builtin___v_free(p_prefixes);
					}
				} // defer end
			return _t2;
		}
	}
	int _t3 = -1;
		{ // defer begin
			if (p.len > _const_kmp_stack_buffer_size) {
				builtin___v_free(p_prefixes);
			}
		} // defer end
	return _t3;
}
VV_LOC int builtin__string_index_last_(string s, string p) {
	if (p.len > s.len || p.len == 0) {
		return -1;
	}
	int i = s.len - p.len;
	for (;;) {
		if (!(i >= 0)) break;
		int j = 0;
		for (;;) {
			if (!(j < p.len && s.str[i + j] == p.str[j])) break;
			j++;
		}
		if (j == p.len) {
			return i;
		}
		i--;
	}
	return -1;
}
int builtin__string_index_after_(string s, string p, int start) {
	if (p.len > s.len) {
		return -1;
	}
	int strt = start;
	if (start < 0) {
		strt = 0;
	}
	if (start >= s.len) {
		return -1;
	}
	int i = strt;
	for (;;) {
		if (!(i < s.len)) break;
		int j = 0;
		int ii = i;
		for (;;) {
			if (!(j < p.len && s.str[ii] == p.str[j])) break;
			j++;
			ii++;
		}
		if (j == p.len) {
			return i;
		}
		i++;
	}
	return -1;
}
bool builtin__string_contains_u8(string s, u8 x) {
	for (int _t1 = 0; _t1 < s.len; ++_t1) {
		u8 c = s.str[_t1];
		if (x == c) {
			return true;
		}
	}
	return false;
}
bool builtin__string_contains(string s, string substr) {
	if (substr.len == 0) {
		return true;
	}
	if (substr.len == 1) {
		return builtin__string_contains_u8(s, substr.str[0]);
	}
	return builtin__string_index_(s, substr) != -1;
}
bool builtin__string_starts_with(string s, string p) {
	if (p.len > s.len || ((u64)(s.str)) <= 0xFFFF || ((u64)(p.str)) <= 0xFFFF) {
		return false;
	} else if (builtin__vmemcmp(s.str, p.str, p.len) == 0) {
		return true;
	}
	return false;
}
bool builtin__string_ends_with(string s, string p) {
	if (p.len > s.len || ((u64)(s.str)) <= 0xFFFF || ((u64)(p.str)) <= 0xFFFF) {
		return false;
	} else if (builtin__vmemcmp(s.str + s.len - p.len, p.str, p.len) == 0) {
		return true;
	}
	return false;
}
string builtin__string_to_lower_ascii(string s) {
	{ // Unsafe block
		u8* b = builtin__malloc_noscan(s.len + 1);
		for (int i = 0; i < s.len; ++i) {
			if (s.str[i] >= 'A' && s.str[i] <= 'Z') {
				b[i] = (u8)(s.str[i] + 32);
			} else {
				b[i] = s.str[i];
			}
		}
		b[s.len] = 0;
		return builtin__tos(b, s.len);
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}
string builtin__string_to_lower(string s) {
	if (builtin__string_is_pure_ascii(s)) {
		return builtin__string_to_lower_ascii(s);
	}
	Array_rune runes = builtin__string_runes(s);
	for (int i = 0; i < runes.len; ++i) {
		((rune*)runes.data)[i] = builtin__rune_to_lower(((rune*)runes.data)[i]);
	}
	return Array_rune_string(runes);
}
string builtin__string_to_upper_ascii(string s) {
	{ // Unsafe block
		u8* b = builtin__malloc_noscan(s.len + 1);
		for (int i = 0; i < s.len; ++i) {
			if (s.str[i] >= 'a' && s.str[i] <= 'z') {
				b[i] = (u8)(s.str[i] - 32);
			} else {
				b[i] = s.str[i];
			}
		}
		b[s.len] = 0;
		return builtin__tos(b, s.len);
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}
string builtin__string_to_upper(string s) {
	if (builtin__string_is_pure_ascii(s)) {
		return builtin__string_to_upper_ascii(s);
	}
	Array_rune runes = builtin__string_runes(s);
	for (int i = 0; i < runes.len; ++i) {
		((rune*)runes.data)[i] = builtin__rune_to_upper(((rune*)runes.data)[i]);
	}
	return Array_rune_string(runes);
}
inline string builtin__string_trim_space(string s) {
	return builtin__string_trim(s, _S(" \n\t\v\f\r"));
}
string builtin__string_trim(string s, string cutset) {
	if ((s).len == 0 || (cutset).len == 0) {
		return builtin__string_clone(s);
	}
	if (builtin__string_is_pure_ascii(cutset)) {
		return builtin__string_trim_chars(s, cutset, TrimMode__trim_both);
	} else {
		return builtin__string_trim_runes(s, cutset, TrimMode__trim_both);
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}
VV_LOC string builtin__string_trim_chars(string s, string cutset, TrimMode mode) {
	int pos_left = 0;
	int pos_right = s.len - 1;
	bool cs_match = true;
	for (;;) {
		if (!(pos_left <= s.len && pos_right >= -1 && cs_match)) break;
		cs_match = false;
		if (mode == TrimMode__trim_left || mode == TrimMode__trim_both) {
			for (int _t1 = 0; _t1 < cutset.len; ++_t1) {
				u8 cs = cutset.str[_t1];
				if (s.str[ pos_left] == cs) {
					pos_left++;
					cs_match = true;
					break;
				}
			}
		}
		if (mode == TrimMode__trim_right || mode == TrimMode__trim_both) {
			for (int _t2 = 0; _t2 < cutset.len; ++_t2) {
				u8 cs = cutset.str[_t2];
				if (s.str[ pos_right] == cs) {
					pos_right--;
					cs_match = true;
					break;
				}
			}
		}
		if (pos_left > pos_right) {
			return _S("");
		}
	}
	return builtin__string_substr(s, pos_left, pos_right + 1);
}
VV_LOC string builtin__string_trim_runes(string s, string cutset, TrimMode mode) {
	Array_rune s_runes = builtin__string_runes(s);
	Array_rune cs_runes = builtin__string_runes(cutset);
	int pos_left = 0;
	int pos_right = s_runes.len - 1;
	bool cs_match = true;
	for (;;) {
		if (!(pos_left <= s_runes.len && pos_right >= -1 && cs_match)) break;
		cs_match = false;
		if (mode == TrimMode__trim_left || mode == TrimMode__trim_both) {
			for (int _t1 = 0; _t1 < cs_runes.len; ++_t1) {
				rune cs = ((rune*)cs_runes.data)[_t1];
				if (((rune*)s_runes.data)[pos_left] == cs) {
					pos_left++;
					cs_match = true;
					break;
				}
			}
		}
		if (mode == TrimMode__trim_right || mode == TrimMode__trim_both) {
			for (int _t2 = 0; _t2 < cs_runes.len; ++_t2) {
				rune cs = ((rune*)cs_runes.data)[_t2];
				if (((rune*)s_runes.data)[pos_right] == cs) {
					pos_right--;
					cs_match = true;
					break;
				}
			}
		}
		if (pos_left > pos_right) {
			return _S("");
		}
	}
	return Array_rune_string(builtin__array_slice(s_runes, pos_left, pos_right + 1));
}
string builtin__string_trim_left(string s, string cutset) {
	if ((s).len == 0 || (cutset).len == 0) {
		return builtin__string_clone(s);
	}
	if (builtin__string_is_pure_ascii(cutset)) {
		return builtin__string_trim_chars(s, cutset, TrimMode__trim_left);
	} else {
		return builtin__string_trim_runes(s, cutset, TrimMode__trim_left);
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}
string builtin__string_trim_right(string s, string cutset) {
	if (s.len < 1 || cutset.len < 1) {
		return builtin__string_clone(s);
	}
	if (cutset.len == 1) {
		u8 cut = cutset.str[ 0];
		int pos_right = s.len - 1;
		for (;;) {
			if (!(pos_right >= 0 && s.str[ pos_right] == cut)) break;
			pos_right--;
		}
		if (pos_right < 0) {
			return _S("");
		}
		return builtin__string_substr(s, 0, pos_right + 1);
	}
	if (cutset.len == 2 && builtin__string_is_pure_ascii(cutset)) {
		u8 cut0 = cutset.str[ 0];
		u8 cut1 = cutset.str[ 1];
		int pos_right = s.len - 1;
		for (;;) {
			if (!(pos_right >= 0 && (s.str[ pos_right] == cut0 || s.str[ pos_right] == cut1))) break;
			pos_right--;
		}
		if (pos_right < 0) {
			return _S("");
		}
		return builtin__string_substr(s, 0, pos_right + 1);
	}
	if (builtin__string_is_pure_ascii(cutset)) {
		return builtin__string_trim_chars(s, cutset, TrimMode__trim_right);
	} else {
		return builtin__string_trim_runes(s, cutset, TrimMode__trim_right);
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}
string builtin__string_trim_string_right(string s, string str) {
	if (builtin__string_ends_with(s, str)) {
		return builtin__string_substr(s, 0, s.len - str.len);
	}
	return builtin__string_clone(s);
}
inline string builtin__string_str(string s) {
	return builtin__string_clone(s);
}
VV_LOC u8 builtin__string_at(string s, int idx) {
	#if 1
	{
		if (idx < 0 || idx >= s.len) {
			builtin__panic_n2(_S("string index out of range(idx,s.len):"), idx, s.len);
			VUNREACHABLE();
		}
	}
	#endif
	return s.str[idx];
}
VV_LOC u8 builtin__string_at_i64(string s, i64 idx) {
	#if 1
	{
		if (idx < 0 || idx >= ((i64)(s.len))) {
			builtin__panic_n2(_S("string index out of range(idx,s.len):"), idx, s.len);
			VUNREACHABLE();
		}
	}
	#endif
	return s.str[((int)(idx))];
}
VV_LOC u8 builtin__string_at_u64(string s, u64 idx) {
	#if 1
	{
		if (idx >= ((u64)(s.len))) {
			builtin___v_panic(builtin__string_plus_many(4, _MOV((string[4]){_S("string index out of range(idx,s.len): "), builtin__u64_str(idx), _S(", "), builtin__impl_i64_to_string(s.len)})));
			VUNREACHABLE();
		}
	}
	#endif
	return s.str[((int)(idx))];
}
VV_LOC u8 builtin__string_at_ni(string s, int idx) {
	return builtin__string_at(s, builtin__v_ni_index(idx, s.len));
}
VV_LOC _option_u8 builtin__string_at_with_check(string s, int idx) {
	if (idx < 0 || idx >= s.len) {
		return (_option_u8){ .state=2, .err=_const_none__, .data={E_STRUCT} };
	}
	{ // Unsafe block
		_option_u8 _t2;
		builtin___option_ok(&(u8[]) { s.str[idx] }, (_option*)(&_t2), sizeof(u8));
		 
		return _t2;
	}
	return (_option_u8){.state=2, .err=_const_none__, .data={E_STRUCT}};
}
VV_LOC _option_u8 builtin__string_at_with_check_i64(string s, i64 idx) {
	if (idx < 0 || idx >= ((i64)(s.len))) {
		return (_option_u8){ .state=2, .err=_const_none__, .data={E_STRUCT} };
	}
	{ // Unsafe block
		_option_u8 _t2;
		builtin___option_ok(&(u8[]) { s.str[((int)(idx))] }, (_option*)(&_t2), sizeof(u8));
		 
		return _t2;
	}
	return (_option_u8){.state=2, .err=_const_none__, .data={E_STRUCT}};
}
VV_LOC _option_u8 builtin__string_at_with_check_u64(string s, u64 idx) {
	if (idx >= ((u64)(s.len))) {
		return (_option_u8){ .state=2, .err=_const_none__, .data={E_STRUCT} };
	}
	{ // Unsafe block
		_option_u8 _t2;
		builtin___option_ok(&(u8[]) { s.str[((int)(idx))] }, (_option*)(&_t2), sizeof(u8));
		 
		return _t2;
	}
	return (_option_u8){.state=2, .err=_const_none__, .data={E_STRUCT}};
}
VV_LOC _option_u8 builtin__string_at_with_check_ni(string s, int idx) {
	return builtin__string_at_with_check(s, builtin__v_ni_index(idx, s.len));
}
void builtin__string_free(string* s) {
	if (s->is_lit == -98761234) {
		u8* double_free_msg = ((u8*)("double string.free() detected\n"));
		int double_free_msg_len = builtin__vstrlen(double_free_msg);
		#if 0
		{
		}
		#else
		{
			builtin___write_buf_to_fd(1, double_free_msg, double_free_msg_len);
		}
		#endif
		return;
	}
	if (s->is_lit == 1 || s->str == 0) {
		return;
	}
	{ // Unsafe block
		builtin___v_free(s->str);
		s->str = ((void*)0);
	}
	s->len = 0;
	s->is_lit = -98761234;
}
string builtin__string_all_before(string s, string sub) {
	int pos = builtin__string_index_(s, sub);
	if (pos == -1) {
		return builtin__string_clone(s);
	}
	return builtin__string_substr(s, 0, pos);
}
string builtin__string_all_before_last(string s, string sub) {
	int pos = builtin__string_index_last_(s, sub);
	if (pos == -1) {
		return builtin__string_clone(s);
	}
	return builtin__string_substr(s, 0, pos);
}
string builtin__string_all_after(string s, string sub) {
	int pos = builtin__string_index_(s, sub);
	if (pos == -1) {
		return builtin__string_clone(s);
	}
	return builtin__string_substr(s, pos + sub.len, 2147483647);
}
string builtin__string_all_after_last(string s, string sub) {
	int pos = builtin__string_index_last_(s, sub);
	if (pos == -1) {
		return builtin__string_clone(s);
	}
	return builtin__string_substr(s, pos + sub.len, 2147483647);
}
string Array_string_join(Array_string a, string sep) {
	if (a.len == 0) {
		return _S("");
	}
	int len = 0;
	for (int _t2 = 0; _t2 < a.len; ++_t2) {
		string val = ((string*)a.data)[_t2];
		len += val.len + sep.len;
	}
	len -= sep.len;
	string _t3 = ((string){.str = builtin__malloc_noscan(len + 1), .len = len});
	string res = _t3;
	int idx = 0;
	for (int i = 0; i < a.len; ++i) {
		string val = ((string*)a.data)[i];
		{ // Unsafe block
			builtin__vmemcpy(((voidptr)(res.str + idx)), val.str, val.len);
			idx += val.len;
		}
		if (i != a.len - 1) {
			{ // Unsafe block
				builtin__vmemcpy(((voidptr)(res.str + idx)), sep.str, sep.len);
				idx += sep.len;
			}
		}
	}
	{ // Unsafe block
		res.str[res.len] = 0;
	}
	return res;
}
Array_string builtin__string_fields(string s) {
	Array_string res = builtin____new_array_with_default(0, 0, sizeof(string), 0);
	builtin__ArrayFlags_set(&res.flags, ArrayFlags__noslices);
	int word_start = 0;
	int word_len = 0;
	bool is_in_word = false;
	bool is_space = false;
	for (int i = 0; i < s.len; ++i) {
		u8 c = s.str[i];
		is_space = (c == 32 || c == 9 || c == 10);
		if (!is_space) {
			word_len++;
		}
		if (!is_in_word && !is_space) {
			word_start = i;
			is_in_word = true;
			continue;
		}
		if (is_space && is_in_word) {
			builtin__array_push((array*)&res, _MOV((string[]){ builtin__string_substr(s, word_start, word_start + word_len) }));
			is_in_word = false;
			word_len = 0;
			word_start = 0;
			continue;
		}
	}
	if (is_in_word && word_len > 0) {
		builtin__array_push((array*)&res, _MOV((string[]){ builtin__string_substr(s, word_start, s.len) }));
	}
	Array_string _t3 = res;
		{ // defer begin
			builtin__ArrayFlags_clear(&res.flags, ArrayFlags__noslices);
		} // defer end
	return _t3;
}
string builtin__StrIntpType_str(StrIntpType x) {
	string _t2 = (string){.str=(byteptr)"", .is_lit=1};
	switch (x) {
		case StrIntpType__si_no_str: {
			_t2 = _S("no_str");
			break;
		}
		case StrIntpType__si_c: {
			_t2 = _S("c");
			break;
		}
		case StrIntpType__si_u8: {
			_t2 = _S("u8");
			break;
		}
		case StrIntpType__si_i8: {
			_t2 = _S("i8");
			break;
		}
		case StrIntpType__si_u16: {
			_t2 = _S("u16");
			break;
		}
		case StrIntpType__si_i16: {
			_t2 = _S("i16");
			break;
		}
		case StrIntpType__si_u32: {
			_t2 = _S("u32");
			break;
		}
		case StrIntpType__si_i32: {
			_t2 = _S("i32");
			break;
		}
		case StrIntpType__si_u64: {
			_t2 = _S("u64");
			break;
		}
		case StrIntpType__si_i64: {
			_t2 = _S("i64");
			break;
		}
		case StrIntpType__si_f32: {
			_t2 = _S("f32");
			break;
		}
		case StrIntpType__si_f64: {
			_t2 = _S("f64");
			break;
		}
		case StrIntpType__si_g32: {
			_t2 = _S("f32");
			break;
		}
		case StrIntpType__si_g64: {
			_t2 = _S("f64");
			break;
		}
		case StrIntpType__si_e32: {
			_t2 = _S("f32");
			break;
		}
		case StrIntpType__si_e64: {
			_t2 = _S("f64");
			break;
		}
		case StrIntpType__si_s: {
			_t2 = _S("s");
			break;
		}
		case StrIntpType__si_p: {
			_t2 = _S("p");
			break;
		}
		case StrIntpType__si_r: {
			_t2 = _S("r");
			break;
		}
		case StrIntpType__si_vp: {
			_t2 = _S("vp");
			break;
		}
	}
	return _t2;
}
inline VV_LOC f32 builtin__fabs32(f32 x) {
	return (x < 0 ? (-x) : (x));
}
inline VV_LOC f64 builtin__fabs64(f64 x) {
	return (x < 0 ? (-x) : (x));
}
inline VV_LOC u64 builtin__abs64(i64 x) {
	return (x < 0 ? (((u64)(-x))) : (((u64)(x))));
}
VV_LOC void builtin__StrIntpData_process_str_intp_data(StrIntpData* data, strings__Builder* sb) {
	u32 x = data->fmt;
	StrIntpType typ = ((StrIntpType)((x & 0x1F)));
	int align = ((int)(((v__rshift_u32(x, (u64)5)) & 0x01)));
	bool upper_case = (((v__rshift_u32(x, (u64)7)) & 0x01)) > 0;
	int sign = ((int)(((v__rshift_u32(x, (u64)8)) & 0x01)));
	int precision = ((int)(((v__rshift_u32(x, (u64)9)) & 0x7F)));
	bool tail_zeros = (((v__rshift_u32(x, (u64)16)) & 0x01)) > 0;
	int width = ((int)(((i16)(((v__rshift_u32(x, (u64)17)) & 0x3FF)))));
	int base = (((int)(v__rshift_u32(x, (u64)27))) & 0xF);
	u8 fmt_pad_ch = ((u8)(((v__rshift_u32(x, (u64)31)) & 0xFF)));
	bool has_dynamic_width = ((data->dyn_flags & _const_str_intp_has_dynamic_width)) != 0;
	bool has_dynamic_precision = ((data->dyn_flags & _const_str_intp_has_dynamic_precision)) != 0;
	if (typ == StrIntpType__si_no_str) {
		return;
	}
	if (base > 0) {
		base += 2;
	}
	if (has_dynamic_width) {
		width = data->dyn_width;
		if (width < 0) {
			width = -width;
			align = 0;
		} else if (width > 0) {
			align = 1;
		}
	}
	if (has_dynamic_precision) {
		precision = data->dyn_precision;
	}
	u8 pad_ch = ((u8)(' '));
	if (fmt_pad_ch > 0) {
		pad_ch = '0';
	}
	int len0_set = (width > 0 ? (width) : (-1));
	int len1_set = (has_dynamic_precision ? ((precision >= 0 ? (precision) : (-1))) : precision == 0x7F ? (-1) : (precision));
	bool sign_set = sign == 1;
	strconv__BF_param bf = ((strconv__BF_param){
		.pad_ch = pad_ch,
		.len0 = len0_set,
		.len1 = len1_set,
		.positive = true,
		.sign_flag = sign_set,
		.align = strconv__Align_text__left,
		.rm_tail_zero = tail_zeros,
	});
	if (fmt_pad_ch == 0 || pad_ch == '0') {
		switch (align) {
			case 0: {
				bf.align = strconv__Align_text__left;
				break;
			}
			case 1: {
				bf.align = strconv__Align_text__right;
				break;
			}
			default: {
				{
					bf.align = strconv__Align_text__left;
					break;
				}
			}
		}
		
	} else {
		bf.align = strconv__Align_text__right;
	}
	{ // Unsafe block
		if (typ == StrIntpType__si_s) {
			if (upper_case) {
				string s = builtin__string_to_upper(data->d.d_s);
				if (width == 0) {
					strings__Builder_write_string(sb, s);
				} else {
					strconv__format_str_sb(s, bf, sb);
				}
				builtin__string_free(&s);
			} else {
				if (width == 0) {
					strings__Builder_write_string(sb, data->d.d_s);
				} else {
					strconv__format_str_sb(data->d.d_s, bf, sb);
				}
			}
			return;
		}
		if (typ == StrIntpType__si_r) {
			if (width > 0) {
				if (upper_case) {
					string s = builtin__string_to_upper(data->d.d_s);
					for (int _t1 = 1; _t1 < (1 + ((width > 0 ? (width) : (0)))); ++_t1) {
						strings__Builder_write_string(sb, s);
					}
					builtin__string_free(&s);
				} else {
					for (int _t2 = 1; _t2 < (1 + ((width > 0 ? (width) : (0)))); ++_t2) {
						strings__Builder_write_string(sb, data->d.d_s);
					}
				}
			}
			return;
		}
		if (typ == StrIntpType__si_i8 || typ == StrIntpType__si_i16 || typ == StrIntpType__si_i32 || typ == StrIntpType__si_i64) {
			i64 d = data->d.d_i64;
			if (typ == StrIntpType__si_i8) {
				d = ((i64)(data->d.d_i8));
			} else if (typ == StrIntpType__si_i16) {
				d = ((i64)(data->d.d_i16));
			} else if (typ == StrIntpType__si_i32) {
				d = ((i64)(data->d.d_i32));
			}
			if (base == 0) {
				if (d < 0) {
					bf.positive = false;
				}
				strconv__format_dec_sb(builtin__abs64(d), bf, sb);
			} else {
				if (base == 3) {
					base = 2;
				}
				i64 absd = d;
				bool write_minus = false;
				if (d < 0 && pad_ch != ' ') {
					absd = -d;
					write_minus = true;
				}
				string hx = strconv__format_int(absd, base);
				if (upper_case) {
					string tmp = hx;
					hx = builtin__string_to_upper(hx);
					builtin__string_free(&tmp);
				}
				if (write_minus) {
					strings__Builder_write_u8(sb, '-');
					bf.len0--;
				}
				if (width == 0) {
					strings__Builder_write_string(sb, hx);
				} else {
					strconv__format_str_sb(hx, bf, sb);
				}
				builtin__string_free(&hx);
			}
			return;
		}
		if (typ == StrIntpType__si_u8 || typ == StrIntpType__si_u16 || typ == StrIntpType__si_u32 || typ == StrIntpType__si_u64) {
			u64 d = data->d.d_u64;
			if (typ == StrIntpType__si_u8) {
				d = ((u64)(data->d.d_u8));
			} else if (typ == StrIntpType__si_u16) {
				d = ((u64)(data->d.d_u16));
			} else if (typ == StrIntpType__si_u32) {
				d = ((u64)(data->d.d_u32));
			}
			if (base == 0) {
				strconv__format_dec_sb(d, bf, sb);
			} else {
				if (base == 3) {
					base = 2;
				}
				string hx = strconv__format_uint(d, base);
				if (upper_case) {
					string tmp = hx;
					hx = builtin__string_to_upper(hx);
					builtin__string_free(&tmp);
				}
				if (width == 0) {
					strings__Builder_write_string(sb, hx);
				} else {
					strconv__format_str_sb(hx, bf, sb);
				}
				builtin__string_free(&hx);
			}
			return;
		}
		if (typ == StrIntpType__si_p) {
			u64 d = ((u64)(data->d.d_p));
			base = 16;
			if (base == 0) {
				if (width == 0) {
					string d_str = builtin__u64_str(d);
					strings__Builder_write_string(sb, d_str);
					builtin__string_free(&d_str);
					return;
				}
				strconv__format_dec_sb(d, bf, sb);
			} else {
				string hx = strconv__format_uint(d, base);
				if (upper_case) {
					string tmp = hx;
					hx = builtin__string_to_upper(hx);
					builtin__string_free(&tmp);
				}
				if (width == 0) {
					strings__Builder_write_string(sb, hx);
				} else {
					strconv__format_str_sb(hx, bf, sb);
				}
				builtin__string_free(&hx);
			}
			return;
		}
		bool use_default_str = false;
		if (width == 0 && precision == 0x7F) {
			bf.len1 = 3;
			use_default_str = true;
		}
		if (bf.len1 < 0) {
			bf.len1 = 3;
		}
		switch (typ) {
			case StrIntpType__si_f32: {
				#if !defined(CUSTOM_DEFINE_nofloat)
				{
					if (use_default_str) {
						string f = builtin__f32_str(data->d.d_f32);
						if (upper_case) {
							string tmp = f;
							f = builtin__string_to_upper(f);
							builtin__string_free(&tmp);
						}
						strings__Builder_write_string(sb, f);
						builtin__string_free(&f);
					} else {
						if (data->d.d_f32 < 0) {
							bf.positive = false;
						}
						string f = strconv__format_fl(data->d.d_f32, bf);
						if (upper_case) {
							string tmp = f;
							f = builtin__string_to_upper(f);
							builtin__string_free(&tmp);
						}
						strings__Builder_write_string(sb, f);
						builtin__string_free(&f);
					}
				}
				#endif
				break;
			}
			case StrIntpType__si_f64: {
				#if !defined(CUSTOM_DEFINE_nofloat)
				{
					if (use_default_str) {
						string f = builtin__f64_str(data->d.d_f64);
						if (upper_case) {
							string tmp = f;
							f = builtin__string_to_upper(f);
							builtin__string_free(&tmp);
						}
						strings__Builder_write_string(sb, f);
						builtin__string_free(&f);
					} else {
						if (data->d.d_f64 < 0) {
							bf.positive = false;
						}
						strconv__Float64u _t5 = ((strconv__Float64u){.f = data->d.d_f64,});
						strconv__Float64u f_union = _t5;
						if (f_union.u == _const_strconv__double_minus_zero) {
							bf.positive = false;
						}
						string f = strconv__format_fl(data->d.d_f64, bf);
						if (upper_case) {
							string tmp = f;
							f = builtin__string_to_upper(f);
							builtin__string_free(&tmp);
						}
						strings__Builder_write_string(sb, f);
						builtin__string_free(&f);
					}
				}
				#endif
				break;
			}
			case StrIntpType__si_g32: {
				if (use_default_str) {
					#if !defined(CUSTOM_DEFINE_nofloat)
					{
						string f = builtin__f32_strg(data->d.d_f32);
						if (upper_case) {
							string tmp = f;
							f = builtin__string_to_upper(f);
							builtin__string_free(&tmp);
						}
						strings__Builder_write_string(sb, f);
						builtin__string_free(&f);
					}
					#endif
				} else {
					if (data->d.d_f32 == _const_strconv__single_plus_zero) {
						string tmp_str = _S("0");
						strconv__format_str_sb(tmp_str, bf, sb);
						builtin__string_free(&tmp_str);
						return;
					}
					if (data->d.d_f32 == _const_strconv__single_minus_zero) {
						string tmp_str = _S("-0");
						strconv__format_str_sb(tmp_str, bf, sb);
						builtin__string_free(&tmp_str);
						return;
					}
					if (data->d.d_f32 == _const_strconv__single_plus_infinity) {
						string tmp_str = _S("+inf");
						if (upper_case) {
							tmp_str = _S("+INF");
						}
						strconv__format_str_sb(tmp_str, bf, sb);
						builtin__string_free(&tmp_str);
					}
					if (data->d.d_f32 == _const_strconv__single_minus_infinity) {
						string tmp_str = _S("-inf");
						if (upper_case) {
							tmp_str = _S("-INF");
						}
						strconv__format_str_sb(tmp_str, bf, sb);
						builtin__string_free(&tmp_str);
					}
					if (data->d.d_f32 < 0) {
						bf.positive = false;
					}
					f32 d = builtin__fabs32(data->d.d_f32);
					if (d < ((f32)(999999.0)) && d >= ((f32)(0.00001))) {
						string f = strconv__format_fl(data->d.d_f32, bf);
						if (upper_case) {
							string tmp = f;
							f = builtin__string_to_upper(f);
							builtin__string_free(&tmp);
						}
						strings__Builder_write_string(sb, f);
						builtin__string_free(&f);
						return;
					}
					bf.len1--;
					string f = strconv__format_es(data->d.d_f32, bf);
					if (upper_case) {
						string tmp = f;
						f = builtin__string_to_upper(f);
						builtin__string_free(&tmp);
					}
					strings__Builder_write_string(sb, f);
					builtin__string_free(&f);
				}
				break;
			}
			case StrIntpType__si_g64: {
				if (use_default_str) {
					#if !defined(CUSTOM_DEFINE_nofloat)
					{
						string f = builtin__f64_strg(data->d.d_f64);
						if (upper_case) {
							string tmp = f;
							f = builtin__string_to_upper(f);
							builtin__string_free(&tmp);
						}
						strings__Builder_write_string(sb, f);
						builtin__string_free(&f);
					}
					#endif
				} else {
					if (data->d.d_f64 == _const_strconv__double_plus_zero) {
						string tmp_str = _S("0");
						strconv__format_str_sb(tmp_str, bf, sb);
						builtin__string_free(&tmp_str);
						return;
					}
					if (data->d.d_f64 == _const_strconv__double_minus_zero) {
						string tmp_str = _S("-0");
						strconv__format_str_sb(tmp_str, bf, sb);
						builtin__string_free(&tmp_str);
						return;
					}
					if (data->d.d_f64 == _const_strconv__double_plus_infinity) {
						string tmp_str = _S("+inf");
						if (upper_case) {
							tmp_str = _S("+INF");
						}
						strconv__format_str_sb(tmp_str, bf, sb);
						builtin__string_free(&tmp_str);
					}
					if (data->d.d_f64 == _const_strconv__double_minus_infinity) {
						string tmp_str = _S("-inf");
						if (upper_case) {
							tmp_str = _S("-INF");
						}
						strconv__format_str_sb(tmp_str, bf, sb);
						builtin__string_free(&tmp_str);
					}
					if (data->d.d_f64 < 0) {
						bf.positive = false;
					}
					f64 d = builtin__fabs64(data->d.d_f64);
					if (d < ((f64)(999999.0)) && d >= ((f64)(0.00001))) {
						string f = strconv__format_fl(data->d.d_f64, bf);
						if (upper_case) {
							string tmp = f;
							f = builtin__string_to_upper(f);
							builtin__string_free(&tmp);
						}
						strings__Builder_write_string(sb, f);
						builtin__string_free(&f);
						return;
					}
					bf.len1--;
					string f = strconv__format_es(data->d.d_f64, bf);
					if (upper_case) {
						string tmp = f;
						f = builtin__string_to_upper(f);
						builtin__string_free(&tmp);
					}
					strings__Builder_write_string(sb, f);
					builtin__string_free(&f);
				}
				break;
			}
			case StrIntpType__si_e32: {
				#if !defined(CUSTOM_DEFINE_nofloat)
				{
					if (use_default_str) {
						string f = builtin__f32_str(data->d.d_f32);
						if (upper_case) {
							string tmp = f;
							f = builtin__string_to_upper(f);
							builtin__string_free(&tmp);
						}
						strings__Builder_write_string(sb, f);
						builtin__string_free(&f);
					} else {
						if (data->d.d_f32 < 0) {
							bf.positive = false;
						}
						string f = strconv__format_es(data->d.d_f32, bf);
						if (upper_case) {
							string tmp = f;
							f = builtin__string_to_upper(f);
							builtin__string_free(&tmp);
						}
						strings__Builder_write_string(sb, f);
						builtin__string_free(&f);
					}
				}
				#endif
				break;
			}
			case StrIntpType__si_e64: {
				#if !defined(CUSTOM_DEFINE_nofloat)
				{
					if (use_default_str) {
						string f = builtin__f64_str(data->d.d_f64);
						if (upper_case) {
							string tmp = f;
							f = builtin__string_to_upper(f);
							builtin__string_free(&tmp);
						}
						strings__Builder_write_string(sb, f);
						builtin__string_free(&f);
					} else {
						if (data->d.d_f64 < 0) {
							bf.positive = false;
						}
						string f = strconv__format_es(data->d.d_f64, bf);
						if (upper_case) {
							string tmp = f;
							f = builtin__string_to_upper(f);
							builtin__string_free(&tmp);
						}
						strings__Builder_write_string(sb, f);
						builtin__string_free(&f);
					}
				}
				#endif
				break;
			}
			case StrIntpType__si_c: {
				string ss = builtin__utf32_to_str(data->d.d_c);
				strings__Builder_write_string(sb, ss);
				builtin__string_free(&ss);
				break;
			}
			case StrIntpType__si_vp: {
				string ss = builtin__u64_hex(((u64)(data->d.d_vp)));
				strings__Builder_write_string(sb, ss);
				builtin__string_free(&ss);
				break;
			}
			case StrIntpType__si_no_str:
			case StrIntpType__si_u8:
			case StrIntpType__si_i8:
			case StrIntpType__si_u16:
			case StrIntpType__si_i16:
			case StrIntpType__si_u32:
			case StrIntpType__si_i32:
			case StrIntpType__si_u64:
			case StrIntpType__si_i64:
			case StrIntpType__si_s:
			case StrIntpType__si_p:
			case StrIntpType__si_r:
			default: {
				{
					strings__Builder_write_string(sb, _S("***ERROR!***"));
					break;
				}
			}
		}
		
	}
}
string builtin__str_intp(int data_len, StrIntpData* input_base) {
	strings__Builder res = strings__new_builder(64);
	for (int i = 0; i < data_len; i++) {
		StrIntpData* data = &input_base[i];
		if (data->str.len != 0) {
			strings__Builder_write_string(&res, data->str);
		}
		if (data->fmt != 0) {
			builtin__StrIntpData_process_str_intp_data(data, (voidptr)&res);
		}
	}
	string ret = strings__Builder_str(&res);
	strings__Builder_free(&res);
	return ret;
}
string builtin__utf32_to_str(u32 code) {
	{ // Unsafe block
		u8* buffer = builtin__malloc_noscan(5);
		string res = builtin__utf32_to_str_no_malloc(code, buffer);
		if (res.len == 0) {
			builtin___v_free(buffer);
		}
		return res;
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}
string builtin__utf32_to_str_no_malloc(u32 code, u8* buf) {
	{ // Unsafe block
		int len = builtin__utf32_decode_to_buffer(code, buf);
		if (len == 0) {
			return _S("");
		}
		buf[len] = 0;
		return builtin__tos(buf, len);
	}
	return (string){.str=(byteptr)"", .is_lit=1};
}
int builtin__utf32_decode_to_buffer(u32 code, u8* buf) {
	{ // Unsafe block
		int icode = ((int)(code));
		u8* buffer = ((u8*)(buf));
		if (icode <= 127) {
			buffer[0] = ((u8)(icode));
			return 1;
		} else if (icode <= 2047) {
			buffer[0] = (192 | ((u8)(v__rshift_int(icode, (u64)6))));
			buffer[1] = (128 | ((u8)((icode & 63))));
			return 2;
		} else if (icode <= 65535) {
			buffer[0] = (224 | ((u8)(v__rshift_int(icode, (u64)12))));
			buffer[1] = (128 | ((((u8)(v__rshift_int(icode, (u64)6))) & 63)));
			buffer[2] = (128 | ((u8)((icode & 63))));
			return 3;
		} else if (icode <= 1114111) {
			buffer[0] = (240 | ((u8)(v__rshift_int(icode, (u64)18))));
			buffer[1] = (128 | ((((u8)(v__rshift_int(icode, (u64)12))) & 63)));
			buffer[2] = (128 | ((((u8)(v__rshift_int(icode, (u64)6))) & 63)));
			buffer[3] = (128 | ((u8)((icode & 63))));
			return 4;
		}
	}
	return 0;
}
inline VV_LOC bool builtin__utf8_is_continuation(u8 b) {
	return ((b & 0xc0)) == 0x80;
}
VV_LOC multi_return_rune_int builtin__utf8_decode_rune(u8* _bytes, int available_len) {
	if (available_len <= 0) {
		return (multi_return_rune_int){.arg0=0, .arg1=0};
	}
	u8 b0 = _bytes[0];
	if (b0 < 0x80) {
		return (multi_return_rune_int){.arg0=((rune)(b0)), .arg1=1};
	}
	if (b0 < 0xc2) {
		return (multi_return_rune_int){.arg0=_const_utf8_replacement_rune, .arg1=1};
	}
	int _t4; /* if prepend */
	if (b0 < 0xe0) {
		_t4 = 2;
		goto _t5;
	};
	{
	if (b0 < 0xf0) {
		_t4 = 3;
		goto _t5;
	};
	{
	if (b0 < 0xf5) {
		_t4 = 4;
		goto _t5;
	};
	{
		return (multi_return_rune_int){.arg0=_const_utf8_replacement_rune, .arg1=1};
	}
	}
	}
	_t5: {};
		int char_len = _t4;
	if (available_len < char_len) {
		return (multi_return_rune_int){.arg0=_const_utf8_replacement_rune, .arg1=1};
	}
	u8 b1 = _bytes[1];
	if (!builtin__utf8_is_continuation(b1)) {
		return (multi_return_rune_int){.arg0=_const_utf8_replacement_rune, .arg1=1};
	}
	if (char_len == 2) {
		return (multi_return_rune_int){.arg0=((v__lshift_rune(((((rune)(b0)) & 0x1f)), (u64)6)) | ((((rune)(b1)) & 0x3f))), .arg1=2};
	}
	if (b0 == 0xe0 && b1 < 0xa0) {
		return (multi_return_rune_int){.arg0=_const_utf8_replacement_rune, .arg1=1};
	}
	if (b0 == 0xed && b1 >= 0xa0) {
		return (multi_return_rune_int){.arg0=_const_utf8_replacement_rune, .arg1=1};
	}
	u8 b2 = _bytes[2];
	if (!builtin__utf8_is_continuation(b2)) {
		return (multi_return_rune_int){.arg0=_const_utf8_replacement_rune, .arg1=1};
	}
	if (char_len == 3) {
		return (multi_return_rune_int){.arg0=(((v__lshift_rune(((((rune)(b0)) & 0x0f)), (u64)12)) | (v__lshift_rune(((((rune)(b1)) & 0x3f)), (u64)6))) | ((((rune)(b2)) & 0x3f))), .arg1=3};
	}
	if (b0 == 0xf0 && b1 < 0x90) {
		return (multi_return_rune_int){.arg0=_const_utf8_replacement_rune, .arg1=1};
	}
	if (b0 == 0xf4 && b1 > 0x8f) {
		return (multi_return_rune_int){.arg0=_const_utf8_replacement_rune, .arg1=1};
	}
	u8 b3 = _bytes[3];
	if (!builtin__utf8_is_continuation(b3)) {
		return (multi_return_rune_int){.arg0=_const_utf8_replacement_rune, .arg1=1};
	}
	return (multi_return_rune_int){.arg0=((((v__lshift_rune(((((rune)(b0)) & 0x07)), (u64)18)) | (v__lshift_rune(((((rune)(b1)) & 0x3f)), (u64)12))) | (v__lshift_rune(((((rune)(b2)) & 0x3f)), (u64)6))) | ((((rune)(b3)) & 0x3f))), .arg1=4};
}
int builtin__utf8_str_visible_length(string s) {
	return builtin__utf8_grapheme_visible_length(s);
}
inline bool builtin__ArrayFlags_has(ArrayFlags* e, ArrayFlags flag_) {
	return ((((int)(*e)) & (((int)(flag_))))) != 0;
}
inline void builtin__ArrayFlags_set(ArrayFlags* e, ArrayFlags flag_) {
	{ // Unsafe block
		*e = ((ArrayFlags)((((int)(*e)) | (((int)(flag_))))));
	}
}
inline void builtin__ArrayFlags_clear(ArrayFlags* e, ArrayFlags flag_) {
	{ // Unsafe block
		*e = ((ArrayFlags)((((int)(*e)) & ~(((int)(flag_))))));
	}
}
string os__getenv(string key) {
	_option_string _t2 = os__getenv_opt(key);
	if (_t2.state != 0) {
		*(string*) _t2.data = _S("");
	}
	
 	return (*(string*)_t2.data);
}
_option_string os__getenv_opt(string key) {
	{ // Unsafe block
		#if 0
		{
		}
		#else
		{
			char* s = getenv(((char*)(key.str)));
			if (s == ((void*)0)) {
				return (_option_string){ .state=2, .err=_const_none__, .data={E_STRUCT} };
			}
			_option_string _t3;
			builtin___option_ok(&(string[]) { builtin__cstring_to_vstring(s) }, (_option*)(&_t3), sizeof(string));
			 
			return _t3;
		}
		#endif
	}
	return (_option_string){.state=2, .err=_const_none__, .data={E_STRUCT}};
}
VV_LOC voidptr os__v_os_execute_mutex_ptr(void) {
	return ((voidptr)(&g_v_os_execute_mutex_storage[0]));
}
VV_LOC void os__init(void) {
	pthread_mutex_init(os__v_os_execute_mutex_ptr(), ((void*)0));
}
VV_LOC void os__v_os_execute_lock(void) {
	pthread_mutex_lock(os__v_os_execute_mutex_ptr());
}
VV_LOC void os__v_os_execute_unlock(void) {
	pthread_mutex_unlock(os__v_os_execute_mutex_ptr());
}
#if 1
#endif
#if 1
#endif
int os__fd_close(int fd) {
	if (fd == -1) {
		return 0;
	}
	return close(fd);
}
Array_string os__fd_slurp(int fd) {
	Array_string res = builtin____new_array_with_default(0, 0, sizeof(string), 0);
	if (fd == -1) {
		return res;
	}
	for (;;) {
		multi_return_string_int mr_929 = os__fd_read(fd, 4096);
		string s = mr_929.arg0;
		int b = mr_929.arg1;
		if (b <= 0) {
			break;
		}
		builtin__array_push((array*)&res, _MOV((string[]){ builtin__string_clone(s) }));
	}
	return res;
}
multi_return_string_int os__fd_read(int fd, int maxbytes) {
	if (fd == -1) {
		return (multi_return_string_int){.arg0=_S(""), .arg1=0};
	}
	{ // Unsafe block
		u8* buf = builtin__malloc_noscan(maxbytes + 1);
		int nbytes = 0;
		for (;;) {
			#if 1
			{
				errno = 0;
			}
			#endif
			nbytes = ((int)(read(fd, buf, maxbytes)));
			if (nbytes >= 0) {
				break;
			}
			#if 1
			{
				if (errno == EINTR) {
					continue;
				}
			}
			#endif
			break;
		}
		if (nbytes < 0) {
			builtin___v_free(buf);
			return (multi_return_string_int){.arg0=_S(""), .arg1=nbytes};
		}
		buf[nbytes] = 0;
		return (multi_return_string_int){.arg0=builtin__tos(buf, nbytes), .arg1=nbytes};
	}
	return (multi_return_string_int){0};
}
VV_LOC string os__NotExpected_msg(os__NotExpected err) {
	return err.cause;
}
VV_LOC int os__NotExpected_code(os__NotExpected err) {
	return err.code;
}
_result_os__File os__open(string path) {
	_result_FILE_ptr _t1 = os__vfopen(path, _S("rb"));
	if (_t1.is_error) {
		_result_os__File _t2 = {0};
		_t2.is_error = true;
		_t2.err = _t1.err;
		return _t2;
	}
	
 	FILE* cfile = (*(FILE**)_t1.data);
	int fd = os__fileno(cfile);
	_result_os__File _t3;
	builtin___result_ok(&(os__File[]) { ((os__File){.cfile = (voidptr)cfile,.fd = fd,.is_opened = true,}) }, (_result*)(&_t3), sizeof(os__File));
	 
	return _t3;
}
__NOINLINE _result_os__File os__create(string path) {
	_result_FILE_ptr _t1 = os__vfopen(path, _S("wb"));
	if (_t1.is_error) {
		_result_os__File _t2 = {0};
		_t2.is_error = true;
		_t2.err = _t1.err;
		return _t2;
	}
	
 	FILE* cfile = (*(FILE**)_t1.data);
	int fd = os__fileno(cfile);
	_result_os__File _t3;
	builtin___result_ok(&(os__File[]) { ((os__File){.cfile = (voidptr)cfile,.fd = fd,.is_opened = true,}) }, (_result*)(&_t3), sizeof(os__File));
	 
	return _t3;
}
_result_int os__File_read(os__File* f, Array_u8* buf) {
	if (!f->is_opened || builtin__isnil(f->cfile)) {
		return (_result_int){ .is_error=true, .err=os__error_file_not_opened(), .data={E_STRUCT} };
	}
	if (buf->len == 0) {
		return (_result_int){ .is_error=true, .err=I_os__Eof_to_Interface_IError((HEAP(os__Eof, ((os__Eof){.Error = ((Error){E_STRUCT}),})))), .data={E_STRUCT} };
	}
	int nbytes = ((int)(fread(buf->data, 1, buf->len, ((FILE*)(f->cfile)))));
	if (nbytes <= 0) {
		if (feof(((FILE*)(f->cfile))) != 0) {
			return (_result_int){ .is_error=true, .err=I_os__Eof_to_Interface_IError((HEAP(os__Eof, ((os__Eof){.Error = ((Error){E_STRUCT}),})))), .data={E_STRUCT} };
		}
		if (ferror(((FILE*)(f->cfile))) != 0) {
			return (_result_int){ .is_error=true, .err=I_os__NotExpected_to_Interface_IError((HEAP(os__NotExpected, ((os__NotExpected){.cause = _S("unexpected error from fread"),.code = -1,})))), .data={E_STRUCT} };
		}
	}
	_result_int _t5;
	builtin___result_ok(&(int[]) { nbytes }, (_result*)(&_t5), sizeof(int));
	 
	return _t5;
}
_result_void os__File_write_full_buffer(os__File* f, voidptr buffer, usize buffer_len) {
	if (buffer_len <= ((usize)(0))) {
		return (_result_void){0};
	}
	if (!f->is_opened) {
		return (_result_void){ .is_error=true, .err=os__error_file_not_opened(), .data={E_STRUCT} };
	}
	u8* ptr = ((u8*)(buffer));
	i64 remaining_bytes = ((i64)(buffer_len));
	for (;;) {
		if (!(remaining_bytes > 0)) break;
		{ // Unsafe block
			errno = 0;
			i64 x = ((i64)(fwrite(ptr, 1, remaining_bytes, f->cfile)));
			int cerror = ((int)(errno));
			ptr += x;
			remaining_bytes -= x;
			if (cerror != 0) {
				if (cerror == EINTR) {
					continue;
				}
				if (((i64)(x)) != ((i64)(buffer_len))) {
					return (_result_void){ .is_error=true, .err=builtin___v_error(os__posix_get_error_msg(cerror)), .data={E_STRUCT} };
				}
			}
			if (x <= 0) {
				return (_result_void){ .is_error=true, .err=builtin___v_error(_S("C.fwrite returned 0")), .data={E_STRUCT} };
			}
		}
	}
	return (_result_void){0};
}
VV_LOC _result_int os__fread(voidptr ptr, int item_size, int items, FILE* stream) {
	int nbytes = ((int)(fread(ptr, item_size, items, stream)));
	if (nbytes <= 0) {
		if (feof(stream) != 0) {
			return (_result_int){ .is_error=true, .err=I_os__Eof_to_Interface_IError((HEAP(os__Eof, ((os__Eof){.Error = ((Error){E_STRUCT}),})))), .data={E_STRUCT} };
		}
		if (ferror(stream) != 0) {
			return (_result_int){ .is_error=true, .err=builtin___v_error(_S("file read error")), .data={E_STRUCT} };
		}
	}
	_result_int _t3;
	builtin___result_ok(&(int[]) { nbytes }, (_result*)(&_t3), sizeof(int));
	 
	return _t3;
}
string os__FileNotOpenedError_msg(os__FileNotOpenedError err) {
	return _S("os: file not opened");
}
string os__SizeOfTypeIs0Error_msg(os__SizeOfTypeIs0Error err) {
	return _S("os: size of type is 0");
}
VV_LOC IError os__error_file_not_opened(void) {
	return I_os__FileNotOpenedError_to_Interface_IError((HEAP(os__FileNotOpenedError, ((os__FileNotOpenedError){.Error = ((Error){E_STRUCT}),}))));
}
VV_LOC IError os__error_size_of_type_0(void) {
	return I_os__SizeOfTypeIs0Error_to_Interface_IError((HEAP(os__SizeOfTypeIs0Error, ((os__SizeOfTypeIs0Error){.Error = ((Error){E_STRUCT}),}))));
}
inline VV_LOC u16 os__swap_bytes_u16(u16 x) {
	return ((((v__rshift_u16(x, (u64)8)) & 0x00FF)) | (((v__lshift_u16(x, (u64)8)) & 0xFF00)));
}
inline VV_LOC u32 os__swap_bytes_u32(u32 x) {
	return ((((((v__rshift_u32(x, (u64)24)) & 0x000000FF)) | (((v__rshift_u32(x, (u64)8)) & 0x0000FF00))) | (((v__lshift_u32(x, (u64)8)) & 0x00FF0000))) | (((v__lshift_u32(x, (u64)24)) & 0xFF000000U)));
}
inline VV_LOC u64 os__swap_bytes_u64(u64 x) {
	return ((((((((((v__rshift_u64(x, (u64)56)) & 0x00000000000000FF)) | (((v__rshift_u64(x, (u64)40)) & 0x000000000000FF00))) | (((v__rshift_u64(x, (u64)24)) & 0x0000000000FF0000))) | (((v__rshift_u64(x, (u64)8)) & 0x00000000FF000000U))) | (((v__lshift_u64(x, (u64)8)) & 0x000000FF00000000LL))) | (((v__lshift_u64(x, (u64)24)) & 0x0000FF0000000000LL))) | (((v__lshift_u64(x, (u64)40)) & 0x00FF000000000000LL))) | (((v__lshift_u64(x, (u64)56)) & 0xFF00000000000000ULL)));
}
VV_LOC _result_void os__check_cf(usize x, string label) {
	if (errno != 0) {
		return (_result_void){ .is_error=true, .err=builtin___v_error(os__posix_get_error_msg(errno)), .data={E_STRUCT} };
	}
	if (x == 0) {
		return (_result_void){ .is_error=true, .err=builtin___v_error(label), .data={E_STRUCT} };
	}
	return (_result_void){0};
}
VV_LOC _result_void os__check_fwrite(usize x) {
	_result_void _t1 = os__check_cf(x, _S("fwrite"));
	if (_t1.is_error) {
		_result_void _t2 = {0};
		_t2.is_error = true;
		_t2.err = _t1.err;
		return _t2;
	}
	
 ;
	return (_result_void){0};
}
VV_LOC _result_void os__check_fread(usize x) {
	_result_void _t1 = os__check_cf(x, _S("fread"));
	if (_t1.is_error) {
		_result_void _t2 = {0};
		_t2.is_error = true;
		_t2.err = _t1.err;
		return _t2;
	}
	
 ;
	return (_result_void){0};
}
VV_LOC _result_int os__find_cfile_size(FILE* fp) {
	i32 cseek = fseek(fp, 0, SEEK_END);
	isize raw_fsize = ftell(fp);
	if (raw_fsize != 0 && cseek != 0) {
		return (_result_int){ .is_error=true, .err=builtin___v_error(_S("fseek failed")), .data={E_STRUCT} };
	}
	if (raw_fsize < 0) {
		if (cseek != 0) {
			return (_result_int){ .is_error=true, .err=builtin___v_error(_S("ftell failed")), .data={E_STRUCT} };
		}
		rewind(fp);
		_result_int _t3;
		builtin___result_ok(&(int[]) { 0 }, (_result*)(&_t3), sizeof(int));
		 
		return _t3;
	}
	int len = ((int)(raw_fsize));
	if (((i64)(len)) < raw_fsize) {
		return (_result_int){ .is_error=true, .err=builtin___v_error(builtin__string_plus_many(4, _MOV((string[4]){_S("int("), builtin__isize_str(raw_fsize), _S(") cast results in "), builtin__int_str(len)}))), .data={E_STRUCT} };
	}
	rewind(fp);
	_result_int _t5;
	builtin___result_ok(&(int[]) { len }, (_result*)(&_t5), sizeof(int));
	 
	return _t5;
}
VV_LOC _result_strings__Builder os__slurp_file_in_builder(FILE* fp) {
	Array_fixed_u8_4096 buf = {0};
	strings__Builder sb = strings__new_builder(_const_os__buf_size);
	for (;;) {
		_result_int _t1 = os__fread(&buf[0], 1, _const_os__buf_size, fp);
		if (_t1.is_error) {
			IError _t2 = _t1.err;
			IError err = _t2;
			if ((err)._typ == _IError_os__Eof_index) {
				break;
			}
			strings__Builder_free(&sb);
			return (_result_strings__Builder){ .is_error=true, .err=err, .data={E_STRUCT} };
		}
		
 		int nbytes = (*(int*)_t1.data);
		strings__Builder_write_ptr(&sb, &buf[0], nbytes);
	}
	_result_strings__Builder _t4;
	builtin___result_ok(&(strings__Builder[]) { sb }, (_result*)(&_t4), sizeof(strings__Builder));
	 
	return _t4;
}
_result_string os__read_file(string path) {
	string mode = _S("rb");
	_result_FILE_ptr _t1 = os__vfopen(path, mode);
	if (_t1.is_error) {
		_result_string _t2 = {0};
		_t2.is_error = true;
		_t2.err = _t1.err;
		return _t2;
	}
	
 	FILE* fp = (*(FILE**)_t1.data);
	_result_int _t3 = os__find_cfile_size(fp);
	if (_t3.is_error) {
		{ // defer begin
			fclose(fp);
		} // defer end
		_result_string _t4 = {0};
		_t4.is_error = true;
		_t4.err = _t3.err;
		return _t4;
	}
	
 	int allocate = (*(int*)_t3.data);
	if (allocate == 0) {
		_result_strings__Builder _t5 = os__slurp_file_in_builder(fp);
		if (_t5.is_error) {
			{ // defer begin
				fclose(fp);
			} // defer end
			_result_string _t6 = {0};
			_t6.is_error = true;
			_t6.err = _t5.err;
			return _t6;
		}
		
 		strings__Builder sb = (*(strings__Builder*)_t5.data);
		string res = strings__Builder_str(&sb);
		strings__Builder_free(&sb);
		_result_string _t7;
		builtin___result_ok(&(string[]) { res }, (_result*)(&_t7), sizeof(string));
		 
			{ // defer begin
				fclose(fp);
			} // defer end
		return _t7;
	}
	{ // Unsafe block
		u8* str = builtin__malloc_noscan(allocate + 1);
		int nelements = ((int)(fread(str, 1, allocate, fp)));
		int is_eof = ((int)(feof(fp)));
		int is_error = ((int)(ferror(fp)));
		if (is_eof == 0 && is_error != 0) {
			builtin___v_free(str);
			_result_string _t8 = (_result_string){ .is_error=true, .err=builtin___v_error(_S("fread failed")), .data={E_STRUCT} };
				{ // defer begin
					fclose(fp);
				} // defer end
			return _t8;
		}
		str[nelements] = 0;
		if (nelements == 0) {
			_result_string _t9;
			builtin___result_ok(&(string[]) { builtin__u8_vstring(str) }, (_result*)(&_t9), sizeof(string));
			 
				{ // defer begin
					fclose(fp);
				} // defer end
			return _t9;
		}
		_result_string _t10;
		builtin___result_ok(&(string[]) { builtin__u8_vstring_with_len(str, nelements) }, (_result*)(&_t10), sizeof(string));
		 
			{ // defer begin
				fclose(fp);
			} // defer end
		return _t10;
	}
	return (_result_string){0};
}
u64 os__file_size(string path) {
	_result_os__Stat _t1 = os__stat(path);
	if (_t1.is_error) {
		builtin__eprintln(builtin__string__plus(_S("os.file_size() Cannot determine file-size: "), os__posix_get_error_msg(errno)));
		return 0;
	}
	
 	os__Stat attr = (*(os__Stat*)_t1.data);
	return attr.size;
}
_result_void os__cp(string src, string dst, os__CopyParams config) {
	#if 0
	{
	}
	#else
	{
		string w_dst = dst;
		if (os__is_dir(dst)) {
			w_dst = os__join_path_single(w_dst, os__file_name(src));
		}
		i32 fp_from = open(((char*)(src.str)), O_RDONLY, 0);
		if (fp_from < 0) {
			return (_result_void){ .is_error=true, .err=builtin__error_with_code(builtin__string_plus_many(3, _MOV((string[3]){_S("cp: failed to open "), src, _S(" for reading")})), ((int)(fp_from))), .data={E_STRUCT} };
		}
		int mode_flags = (S_IWUSR | S_IRUSR);
		int open_flags = ((O_WRONLY | O_CREAT) | O_TRUNC);
		if (config.fail_if_exists) {
			open_flags |= O_EXCL;
		}
		i32 fp_to = open(((char*)(w_dst.str)), open_flags, mode_flags);
		if (fp_to < 0) {
			close(fp_from);
			return (_result_void){ .is_error=true, .err=builtin__error_with_code(builtin__string_plus_many(3, _MOV((string[3]){_S("cp: failed to open "), w_dst, _S(" for writing")})), ((int)(fp_to))), .data={E_STRUCT} };
		}
		Array_fixed_u8_1024 buf = {0};
		int count = ((int)(0));
		for (;;) {
			count = ((int)(read(fp_from, &buf[0], sizeof(Array_fixed_u8_1024))));
			if (count == 0) {
				break;
			}
			if (write(fp_to, &buf[0], count) < 0) {
				close(fp_to);
				close(fp_from);
				return (_result_void){ .is_error=true, .err=builtin__error_with_code(builtin__string_plus_many(2, _MOV((string[2]){_S("cp: failed to write to "), w_dst})), ((int)(-1))), .data={E_STRUCT} };
			}
		}
		_result_os__Stat _t5 = os__stat(src);
		if (_t5.is_error) {
			_result_void _t6 = {0};
			_t6.is_error = true;
			_t6.err = _t5.err;
			return _t6;
		}
		
 		os__Stat from_attr = (*(os__Stat*)_t5.data);
		if (chmod(((char*)(w_dst.str)), from_attr.mode) < 0) {
			close(fp_to);
			close(fp_from);
			return (_result_void){ .is_error=true, .err=builtin__error_with_code(builtin__string_plus_many(2, _MOV((string[2]){_S("failed to set permissions for "), w_dst})), ((int)(-1))), .data={E_STRUCT} };
		}
		close(fp_to);
		close(fp_from);
	}
	#endif
	return (_result_void){0};
}
_result_FILE_ptr os__vfopen(string path, string mode) {
	if ((path).len == 0) {
		return (_result_FILE_ptr){ .is_error=true, .err=builtin___v_error(_S("vfopen called with \"\"")), .data={E_STRUCT} };
	}
	FILE* fp = ((FILE*)(((void*)0)));
	#if 0
	{
	}
	#else
	{
		fp = fopen(((char*)(path.str)), ((char*)(mode.str)));
	}
	#endif
	if (builtin__isnil(((voidptr)(fp)))) {
		return (_result_FILE_ptr){ .is_error=true, .err=os__error_posix(((os__SystemError){.msg = builtin__string_plus_many(3, _MOV((string[3]){_S("failed to open file \""), path, _S("\"")})),.code = _const_os__error_code_not_set,})), .data={E_STRUCT} };
	}
	_result_FILE_ptr _t4;
	builtin___result_ok(&(FILE*[]) { fp }, (_result*)(&_t4), sizeof(FILE*));
	 
	return _t4;
}
int os__fileno(voidptr cfile) {
	#if 0
	{
	}
	#else
	{
		return fileno(((FILE*)(cfile)));
	}
	#endif
	return 0;
}
VV_LOC bool os__posix_wait_status_exited(int status) {
	return ((status & 0x7f)) == 0;
}
VV_LOC int os__posix_wait_status_exit_code(int status) {
	return ((v__rshift_int(status, (u64)8)) & 0xff);
}
VV_LOC bool os__posix_wait_status_signaled(int status) {
	int signal = (status & 0x7f);
	return signal != 0 && signal != 0x7f;
}
VV_LOC int os__posix_wait_status_signal(int status) {
	return (status & 0x7f);
}
VV_LOC multi_return_int_bool os__posix_wait4_to_exit_status(int waitret) {
	#if 0
	{
	}
	#else
	{
		int ret = 0;
		bool is_signaled = true;
		if (os__posix_wait_status_exited(waitret)) {
			ret = os__posix_wait_status_exit_code(waitret);
			is_signaled = false;
		} else if (os__posix_wait_status_signaled(waitret)) {
			ret = os__posix_wait_status_signal(waitret);
			is_signaled = true;
		}
		return (multi_return_int_bool){.arg0=ret, .arg1=is_signaled};
	}
	#endif
	return (multi_return_int_bool){0};
}
string os__posix_get_error_msg(int code) {
	char* ptr_text = strerror(code);
	if (ptr_text == 0) {
		return _S("");
	}
	return builtin__tos3(ptr_text);
}
bool os__exists(string path) {
	#if 0
	{
	}
	#else
	{
		return access(((char*)(path.str)), _const_os__f_ok) != -1;
	}
	#endif
	return 0;
}
_result_void os__rm(string path) {
	int rc = 0;
	#if 0
	{
	}
	#else
	{
		rc = remove(((char*)(path.str)));
	}
	#endif
	if (rc == -1) {
		return (_result_void){ .is_error=true, .err=os__error_posix(((os__SystemError){.msg = builtin__string__plus(builtin__string_plus_many(3, _MOV((string[3]){_S("Failed to remove \""), path, _S("\": ")})), os__posix_get_error_msg(errno)),.code = _const_os__error_code_not_set,})), .data={E_STRUCT} };
	}
	return (_result_void){0};
}
_result_void os__rmdir(string path) {
	#if 0
	{
	}
	#else
	{
		i32 rc = rmdir(((char*)(path.str)));
		if (rc == -1) {
			return (_result_void){ .is_error=true, .err=os__error_posix(((os__SystemError){.msg = (string){.str=(byteptr)"", .is_lit=1},.code = _const_os__error_code_not_set,})), .data={E_STRUCT} };
		}
	}
	#endif
	return (_result_void){0};
}
string os__real_path(string fpath) {
	Array_fixed_u8_4096 fullpath = {0};
	string res = _S("");
	#if 0
	{
	}
	#else
	{
		char* ret = ((char*)(realpath(((char*)(fpath.str)), ((char*)(&fullpath[0])))));
		if (ret == 0) {
			builtin__string_free(&res);
			return builtin__string_clone(fpath);
		}
		builtin__string_free(&res);
		res = builtin__tos_clone(&fullpath[0]);
	}
	#endif
	os__normalize_drive_letter(res);
	return res;
}
VV_LOC void os__normalize_drive_letter(string path) {
	#if 1
	{
		return;
	}
	#endif
	if (path.len > 2 && path.str[ 0] >= 'a' && path.str[ 0] <= 'z' && path.str[ 1] == ':' && path.str[ 2] == _const_os__path_separator.str[ 0]) {
		{ // Unsafe block
			u8* x = ((u8*)(path.str));
			x[0] = (u8)(x[0] - 32);
		}
	}
}
_result_void os__chmod(string path, int mode) {
	if (chmod(((char*)(path.str)), mode) != 0) {
		return (_result_void){ .is_error=true, .err=os__error_posix(((os__SystemError){.msg = builtin__string__plus(_S("chmod failed: "), os__posix_get_error_msg(errno)),.code = _const_os__error_code_not_set,})), .data={E_STRUCT} };
	}
	return (_result_void){0};
}
inline IError os__error_posix(os__SystemError e) {
	int code = (e.code == _const_os__error_code_not_set ? (errno) : (e.code));
	string message = ((e.msg).len == 0 ? (os__posix_get_error_msg(code)) : (e.msg));
	return builtin__error_with_code(message, code);
}
void os__Result_free(os__Result* result) {
	builtin__string_free(&result->output);
}
_result_Array_string os__read_lines(string path) {
	_result_os__File _t1 = os__open(path);
	if (_t1.is_error) {
		_result_Array_string _t2 = {0};
		_t2.is_error = true;
		_t2.err = _t1.err;
		return _t2;
	}
	
 	os__File file = (*(os__File*)_t1.data);
	_result_Array_string _t3 = os__read_lines_from_open_file((voidptr)&file);
		{ // defer begin
			os__File_close(&file);
		} // defer end
	return _t3;
}
VV_LOC _result_Array_string os__read_lines_from_open_file(os__File* file) {
	Array_u8 buf = builtin____new_array_with_default(_const_os__read_lines_chunk_size, 0, sizeof(u8), 0);
	Array_string lines = builtin____new_array_with_default(0, 0, sizeof(string), 0);
	strings__Builder line = strings__new_builder(_const_os__read_lines_chunk_size);
	bool pending_cr = false;
	for (;;) {
		_result_int _t1 = os__File_read(file, &buf);
		if (_t1.is_error) {
			IError _t2 = _t1.err;
			IError err = _t2;
			if ((err)._typ == _IError_os__Eof_index) {
				break;
			}
			{ // Unsafe block
				strings__Builder_free(&line);
				Array_string_free(&lines);
			}
			return (_result_Array_string){ .is_error=true, .err=err, .data={E_STRUCT} };
		}
		
 		int nread = (*(int*)_t1.data);
		if (nread <= 0) {
			break;
		}
		int segment_start = 0;
		for (int i = 0; i < nread; i++) {
			u8 c = (*(u8*)builtin__array_get(buf, i));
			if (pending_cr) {
				pending_cr = false;
				if (c == '\n') {
					segment_start = i + 1;
					continue;
				}
			}
			if (c == '\n' || c == '\r') {
				if (i > segment_start) {
					_PUSH_MANY(&line, (builtin__array_slice(buf, segment_start, i)), _t4, strings__Builder);
				}
				builtin__array_push((array*)&lines, _MOV((string[]){ strings__Builder_str(&line) }));
				segment_start = i + 1;
				pending_cr = c == '\r';
			}
		}
		if (segment_start < nread) {
			_PUSH_MANY(&line, (builtin__array_slice(buf, segment_start, nread)), _t6, strings__Builder);
		}
	}
	if (line.len > 0) {
		builtin__array_push((array*)&lines, _MOV((string[]){ strings__Builder_str(&line) }));
	}
	strings__Builder_free(&line);
	_result_Array_string _t8;
	builtin___result_ok(&(Array_string[]) { lines }, (_result*)(&_t8), sizeof(Array_string));
	 
	return _t8;
}
_result_void os__rmdir_all(string path) {
	string err_msg = _S("");
	int err_code = -1;
	_result_Array_string _t1 = os__ls(path);
	if (_t1.is_error) {
		_result_void _t2 = {0};
		_t2.is_error = true;
		_t2.err = _t1.err;
		return _t2;
	}
	
 	Array_string items = (*(Array_string*)_t1.data);
	for (int _t3 = 0; _t3 < items.len; ++_t3) {
		string item = ((string*)items.data)[_t3];
		string fullpath = os__join_path_single(path, item);
		if (os__is_dir(fullpath) && !os__is_link(fullpath)) {
			_result_void _t4 = os__rmdir_all(fullpath);
			if (_t4.is_error) {
				IError _t5 = _t4.err;
				IError err = _t5;
				err_msg = ((struct _IError_interface_methods*)(err._methods))->_method_msg(err._object);
				err_code = ((struct _IError_interface_methods*)(err._methods))->_method_code(err._object);
			}
			
 ;
		} else {
			_result_void _t6 = os__rm(fullpath);
			if (_t6.is_error) {
				IError _t7 = _t6.err;
				IError err = _t7;
				err_msg = ((struct _IError_interface_methods*)(err._methods))->_method_msg(err._object);
				err_code = ((struct _IError_interface_methods*)(err._methods))->_method_code(err._object);
			}
			
 ;
		}
	}
	_result_void _t8 = os__rmdir(path);
	if (_t8.is_error) {
		IError _t9 = _t8.err;
		IError err = _t9;
		err_msg = ((struct _IError_interface_methods*)(err._methods))->_method_msg(err._object);
		err_code = ((struct _IError_interface_methods*)(err._methods))->_method_code(err._object);
	}
	
 ;
	if ((err_msg).len != 0) {
		return (_result_void){ .is_error=true, .err=builtin__error_with_code(err_msg, err_code), .data={E_STRUCT} };
	}
	return (_result_void){0};
}
string os__dir(string path) {
	if ((path).len == 0) {
		return _S(".");
	}
	string detected_path_separator = (builtin__string_contains(path, _S("/")) ? (_S("/")) : (_S("\\")));
	_option_int _t2 = builtin__string_last_index(path, detected_path_separator);
	if (_t2.state != 0) {
		return _S(".");
	}
	
 	int pos = (*(int*)_t2.data);
	if (pos == 0) {
		return detected_path_separator;
	}
	return builtin__string_substr(path, 0, pos);
}
string os__file_name(string path) {
	string detected_path_separator = (builtin__string_contains(path, _S("/")) ? (_S("/")) : (_S("\\")));
	return builtin__string_all_after_last(path, detected_path_separator);
}
_result_void os__write_file(string path, string text) {
	_result_os__File _t1 = os__create(path);
	if (_t1.is_error) {
		_result_void _t2 = {0};
		_t2.is_error = true;
		_t2.err = _t1.err;
		return _t2;
	}
	
 	os__File f = (*(os__File*)_t1.data);
		_result_void _t3 = os__File_write_full_buffer(&f, text.str, ((usize)(text.len)));
	if (_t3.is_error) {
		{ // defer begin
			os__File_close(&f);
		} // defer end
		_result_void _t4 = {0};
		_t4.is_error = true;
		_t4.err = _t3.err;
		return _t4;
	}
	
 ;
		{ // defer begin
			os__File_close(&f);
		} // defer end
	return (_result_void){0};
}
string os__ExecutableNotFoundError_msg(os__ExecutableNotFoundError err) {
	return _S("os: failed to find executable");
}
bool os__is_file(string path) {
	return os__exists(path) && !os__is_dir(path);
}
string os__join_path_single(string base, string elem) {
	strings__Builder sb = strings__new_builder(base.len + elem.len + 1);
	string sbase = builtin__string_trim_right(base, _S("\\/"));
	strings__Builder_write_string(&sb, sbase);
	if ((elem).len != 0) {
		strings__Builder_write_string(&sb, _const_os__path_separator);
		strings__Builder_write_string(&sb, elem);
	}
	os__normalize_path_in_builder((voidptr)&sb);
	string res = strings__Builder_str(&sb);
	if ((base).len == 0) {
		res = builtin__string_trim_left(res, _const_os__path_separator);
	}
	string _t1 = res;
		{ // defer begin
			builtin__string_free(&sbase);
		} // defer end
		{ // defer begin
			strings__Builder_free(&sb);
		} // defer end
	return _t1;
}
VV_LOC void os__normalize_path_in_builder(strings__Builder* sb) {
	rune fs = '\\';
	rune rs = '/';
	for (int idx = 0; idx < sb->len; ++idx) {
		{ // Unsafe block
			if (((u8*)sb->data)[idx] == fs) {
				((u8*)sb->data)[idx] = rs;
			}
		}
	}
	for (int idx = 0; idx < sb->len - 3; ++idx) {
		if (((u8*)sb->data)[idx] == rs && ((u8*)sb->data)[idx + 1] == '.' && ((u8*)sb->data)[idx + 2] == rs) {
			{ // Unsafe block
				for (int_literal j = idx + 1; j < sb->len - 2; j++) {
					((u8*)sb->data)[j] = ((u8*)sb->data)[(int)(j + 2)];
				}
				sb->len -= 2;
			}
		}
		if (((u8*)sb->data)[idx] == rs && ((u8*)sb->data)[idx + 1] == rs) {
			{ // Unsafe block
				for (int_literal j = idx + 1; j < sb->len - 1; j++) {
					((u8*)sb->data)[j] = ((u8*)sb->data)[(int)(j + 1)];
				}
				sb->len -= 1;
			}
		}
	}
}
_result_void os__mkdir_all(string opath, os__MkdirParams params) {
	if (os__exists(opath)) {
		if (os__is_dir(opath)) {
			return (_result_void){0};
		}
		return (_result_void){ .is_error=true, .err=builtin___v_error(builtin__string_plus_many(3, _MOV((string[3]){_S("path `"), opath, _S("` already exists, and is not a folder")}))), .data={E_STRUCT} };
	}
	string _t2;
	#if 0
	#else
		_t2 = _S("\\");
		;
	#endif
		string other_separator = _t2;
	string path = builtin__string_replace(opath, other_separator, _const_os__path_separator);
	string p = (builtin__string_starts_with(path, _const_os__path_separator) ? (_const_os__path_separator) : (_S("")));
	Array_string path_parts = builtin__string_split(builtin__string_trim_left(path, _const_os__path_separator), _const_os__path_separator);
	for (int _t3 = 0; _t3 < path_parts.len; ++_t3) {
		string subdir = ((string*)path_parts.data)[_t3];
		p = builtin__string__plus(p, builtin__string__plus(subdir, _S("/")));
		if (os__exists(p) && os__is_dir(p)) {
			continue;
		}
		_result_void _t4 = os__mkdir(p, params);
		if (_t4.is_error) {
			IError _t5 = _t4.err;
			IError err = _t5;
			return (_result_void){ .is_error=true, .err=builtin___v_error(builtin__str_intp(3, _MOV((StrIntpData[]){{_S("folder: "), 0xfe10, {.d_s = p}, 0, 0, 0}, {_S(", error: "), 0xfe10, {.d_s = builtin__IError_str(err)}, 0, 0, 0}, {_SLIT0, 0, { .d_c = 0 }, 0, 0, 0}}))), .data={E_STRUCT} };
		}
		
 ;
	}
	return (_result_void){0};
}
_result_Array_string os__ls(string path) {
	if ((path).len == 0) {
		return (_result_Array_string){ .is_error=true, .err=builtin___v_error(_S("ls() expects a folder, not an empty string")), .data={E_STRUCT} };
	}
	Array_string res = builtin____new_array_with_default(0, 50, sizeof(string), 0);
	DIR* dir_ptr = opendir(((char*)(path.str)));
	if (builtin__isnil(dir_ptr)) {
		return (_result_Array_string){ .is_error=true, .err=os__error_posix(((os__SystemError){.msg = builtin__string_plus_many(3, _MOV((string[3]){_S("ls() couldnt open dir \""), path, _S("\"")})),.code = _const_os__error_code_not_set,})), .data={E_STRUCT} };
	}
	struct dirent* ent = ((struct dirent*)(((void*)0)));
	for (;;) {
		ent = readdir(dir_ptr);
		if (builtin__isnil(ent)) {
			break;
		}
		{ // Unsafe block
			u8* bptr = ((u8*)(&ent->d_name[0]));
			if (bptr[0] == 0 || (bptr[0] == '.' && bptr[1] == 0) || (bptr[0] == '.' && bptr[1] == '.' && bptr[2] == 0)) {
				continue;
			}
			builtin__array_push((array*)&res, _MOV((string[]){ builtin__tos_clone(bptr) }));
		}
	}
	closedir(dir_ptr);
	_result_Array_string _t4;
	builtin___result_ok(&(Array_string[]) { res }, (_result*)(&_t4), sizeof(Array_string));
	 
	return _t4;
}
_result_void os__mkdir(string path, os__MkdirParams params) {
	if (_SLIT_EQ(path.str, path.len, ".")) {
		return (_result_void){0};
	}
	string apath = os__real_path(path);
	i32 r = mkdir(((char*)(apath.str)), params.mode);
	if (r == -1) {
		return (_result_void){ .is_error=true, .err=builtin___v_error(os__posix_get_error_msg(errno)), .data={E_STRUCT} };
	}
	return (_result_void){0};
}
os__Result os__execute(string cmd) {
	int pid = 0;
	int read_fd = -1;
	os__v_os_execute_lock();
	int rc = v_os_execute_capture_start(((char*)(cmd.str)), &pid, &read_fd);
	os__v_os_execute_unlock();
	if (rc != 0) {
		return ((os__Result){.exit_code = -1,.output = builtin__string_plus_many(3, _MOV((string[3]){_S("exec(\""), cmd, _S("\") failed")})),});
	}
	string soutput = Array_string_join(os__fd_slurp(read_fd), _S(""));
	os__fd_close(read_fd);
	int status = 0;
	for (;;) {
		errno = 0;
		if (waitpid(pid, &status, 0) != -1) {
			break;
		}
		if (errno == EINTR) {
			continue;
		}
		return ((os__Result){.exit_code = -1,.output = soutput,});
	}
	multi_return_int_bool mr_9462 = os__posix_wait4_to_exit_status(status);
	int exit_code = mr_9462.arg0;
	return ((os__Result){.exit_code = exit_code,.output = soutput,});
}
_result_void os__symlink(string target, string link_name) {
	i32 res = symlink(((char*)(target.str)), ((char*)(link_name.str)));
	if (res == 0) {
		return (_result_void){0};
	}
	return (_result_void){ .is_error=true, .err=builtin___v_error(os__posix_get_error_msg(errno)), .data={E_STRUCT} };
}
void os__File_close(os__File* f) {
	if (!f->is_opened) {
		return;
	}
	f->is_opened = false;
	voidptr cfile = f->cfile;
	f->cfile = ((void*)0);
	fflush(cfile);
	fclose(cfile);
}
_result_os__Stat os__stat(string path) {
	struct stat s;
	{ // Unsafe block
		i32 res = stat(((char*)(path.str)), &s);
		if (res != 0) {
			return (_result_os__Stat){ .is_error=true, .err=os__error_posix(((os__SystemError){.msg = (string){.str=(byteptr)"", .is_lit=1},.code = _const_os__error_code_not_set,})), .data={E_STRUCT} };
		}
		_result_os__Stat _t2;
		builtin___result_ok(&(os__Stat[]) { ((os__Stat){
			.dev = ((u64)(s.st_dev)),
			.inode = s.st_ino,
			.mode = s.st_mode,
			.nlink = s.st_nlink,
			.uid = s.st_uid,
			.gid = s.st_gid,
			.rdev = ((u64)(s.st_rdev)),
			.size = ((u64)(s.st_size)),
			.atime = s.st_atime,
			.mtime = s.st_mtime,
			.ctime = s.st_ctime,
		}) }, (_result*)(&_t2), sizeof(os__Stat));
		 
		return _t2;
	}
	return (_result_os__Stat){0};
}
_result_os__Stat os__lstat(string path) {
	struct stat s;
	{ // Unsafe block
		i32 res = lstat(((char*)(path.str)), &s);
		if (res != 0) {
			return (_result_os__Stat){ .is_error=true, .err=os__error_posix(((os__SystemError){.msg = (string){.str=(byteptr)"", .is_lit=1},.code = _const_os__error_code_not_set,})), .data={E_STRUCT} };
		}
		_result_os__Stat _t2;
		builtin___result_ok(&(os__Stat[]) { ((os__Stat){
			.dev = ((u64)(s.st_dev)),
			.inode = s.st_ino,
			.mode = s.st_mode,
			.nlink = s.st_nlink,
			.uid = s.st_uid,
			.gid = s.st_gid,
			.rdev = ((u64)(s.st_rdev)),
			.size = ((u64)(s.st_size)),
			.atime = s.st_atime,
			.mtime = s.st_mtime,
			.ctime = s.st_ctime,
		}) }, (_result*)(&_t2), sizeof(os__Stat));
		 
		return _t2;
	}
	return (_result_os__Stat){0};
}
os__FileType os__Stat_get_filetype(os__Stat st) {
	u32 _t1 = (st.mode & ((u32)(S_IFMT)));
	
	if (_t1 == (((u32)(S_IFREG)))) {
		return os__FileType__regular;
	}
	else if (_t1 == (((u32)(S_IFDIR)))) {
		return os__FileType__directory;
	}
	else if (_t1 == (((u32)(S_IFCHR)))) {
		return os__FileType__character_device;
	}
	else if (_t1 == (((u32)(S_IFBLK)))) {
		return os__FileType__block_device;
	}
	else if (_t1 == (((u32)(S_IFIFO)))) {
		return os__FileType__fifo;
	}
	else if (_t1 == (((u32)(S_IFLNK)))) {
		return os__FileType__symbolic_link;
	}
	else if (_t1 == (((u32)(S_IFSOCK)))) {
		return os__FileType__socket;
	}
	else {
		return os__FileType__unknown;
	}
	return 0;
}
bool os__is_dir(string path) {
	_result_os__Stat _t1 = os__stat(path);
	if (_t1.is_error) {
		return false;
	}
	
 	os__Stat attr = (*(os__Stat*)_t1.data);
	return os__Stat_get_filetype(attr) == os__FileType__directory;
}
bool os__is_link(string path) {
	_result_os__Stat _t1 = os__lstat(path);
	if (_t1.is_error) {
		return false;
	}
	
 	os__Stat attr = (*(os__Stat*)_t1.data);
	return os__Stat_get_filetype(attr) == os__FileType__symbolic_link;
}
VV_LOC string main__pad_right(string s, int width) {
	if (s.len >= width) {
		return s;
	}
	return builtin__string__plus(s, strings__repeat(' ', width - s.len));
}
VV_LOC string main__format_bytes(u64 bytes) {
	if (bytes >= 1048576) {
		f64 mb = ((f64)(bytes)) / ((f64)(1.048576e+06));
		return builtin__str_intp(2, _MOV((StrIntpData[]){{_SLIT0, 0x20d, {.d_f64 = mb}, 0, 0, 0}, {_S("MB"), 0, { .d_c = 0 }, 0, 0, 0}}));
	} else if (bytes >= 1024) {
		f64 kb = ((f64)(bytes)) / ((f64)(1024.0));
		return builtin__str_intp(2, _MOV((StrIntpData[]){{_SLIT0, 0xd, {.d_f64 = kb}, 0, 0, 0}, {_S("KB"), 0, { .d_c = 0 }, 0, 0, 0}}));
	}
	return builtin__string_plus_many(2, _MOV((string[2]){builtin__u64_str(bytes), _S("B")}));
}
VV_LOC string main__json_escape(string s) {
	strings__Builder res = strings__new_builder(s.len + 8);
	for (int i = 0; i < s.len; i++) {
		u8 ch = builtin__string_at(s, i);

		if (ch == ('"')) {
			strings__Builder_write_string(&res, _S("\\\""));
		}
		else if (ch == ('\\')) {
			strings__Builder_write_string(&res, _S("\\\\"));
		}
		else if (ch == ('\n')) {
			strings__Builder_write_string(&res, _S("\\n"));
		}
		else if (ch == ('\r')) {
			strings__Builder_write_string(&res, _S("\\r"));
		}
		else if (ch == ('\t')) {
			strings__Builder_write_string(&res, _S("\\t"));
		}
		else {
			strings__Builder_write_u8(&res, ch);
		}
	}
	return strings__Builder_str(&res);
}
VV_LOC string main__parse_json_value(string json_str, string key) {
	string search_key = builtin__string_plus_many(3, _MOV((string[3]){_S("\""), key, _S("\"")}));
	if (!builtin__string_contains(json_str, search_key)) {
		return _S("");
	}
	string after_key = builtin__string_trim_space(builtin__string_all_after(json_str, search_key));
	if (!builtin__string_starts_with(after_key, _S(":"))) {
		return _S("");
	}
	string val_part = builtin__string_trim_space(builtin__string_all_after(after_key, _S(":")));
	if (builtin__string_starts_with(val_part, _S("\""))) {
		return builtin__string_all_before(builtin__string_all_after(val_part, _S("\"")), _S("\""));
	}
	string val = builtin__string_trim_space(builtin__string_all_before(builtin__string_all_before(builtin__string_all_before(builtin__string_all_before(val_part, _S(",")), _S("}")), _S("\n")), _S("]")));
	return val;
}
VV_LOC void main__print_banner(void) {
	builtin__println(builtin__string_plus_many(3, _MOV((string[3]){_const_main__c_cyan, _S("\342\225\255\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\225\256"), _const_main__c_reset})));
	builtin__println(builtin__string_plus_many(16, _MOV((string[16]){_const_main__c_cyan, _S("\342\224\202"), _const_main__c_reset, _S("  "), _const_main__c_bold, _S("OpenNGFW Serverless Package Manager"), _const_main__c_reset, _S(" ("), _const_main__c_green, _S("ngpkg v"), _const_main__version, _const_main__c_reset, _S(")      "), _const_main__c_cyan, _S("\342\224\202"), _const_main__c_reset})));
	builtin__println(builtin__string_plus_many(11, _MOV((string[11]){_const_main__c_cyan, _S("\342\224\202"), _const_main__c_reset, _S("  "), _const_main__c_gray, _S("Serverless Git Architecture \342\200\242 Prefix: /mnt/usb/opt"), _const_main__c_reset, _S("          "), _const_main__c_cyan, _S("\342\224\202"), _const_main__c_reset})));
	builtin__println(builtin__string_plus_many(3, _MOV((string[3]){_const_main__c_cyan, _S("\342\225\260\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\225\257"), _const_main__c_reset})));
}
VV_LOC string main__normalize_repo_url(string url) {
	string u = builtin__string_trim_right(builtin__string_trim_space(url), _S("/"));
	if (builtin__string_ends_with(u, _S(".git"))) {
		u = builtin__string_all_before_last(u, _S(".git"));
	}
	if (builtin__string_starts_with(u, _S("https://github.com/")) || builtin__string_starts_with(u, _S("http://github.com/"))) {
		string after_gh = (builtin__string_starts_with(u, _S("https://github.com/")) ? (builtin__string_all_after(u, _S("https://github.com/"))) : (builtin__string_all_after(u, _S("http://github.com/"))));
		Array_string parts = builtin__string_split(after_gh, _S("/"));
		if (parts.len >= 2) {
			string user = (*(string*)builtin__array_get(parts, 0));
			string repo = (*(string*)builtin__array_get(parts, 1));
			string branch = _S("main");
			if (parts.len >= 4 && builtin__string__eq((*(string*)builtin__array_get(parts, 2)), _S("tree"))) {
				branch = (*(string*)builtin__array_get(parts, 3));
			}
			return builtin__string_plus_many(6, _MOV((string[6]){_S("https://raw.githubusercontent.com/"), user, _S("/"), repo, _S("/"), branch}));
		}
	} else if (builtin__string_starts_with(u, _S("https://gitlab.com/")) || builtin__string_starts_with(u, _S("http://gitlab.com/"))) {
		string after_gl = (builtin__string_starts_with(u, _S("https://gitlab.com/")) ? (builtin__string_all_after(u, _S("https://gitlab.com/"))) : (builtin__string_all_after(u, _S("http://gitlab.com/"))));
		Array_string parts = builtin__string_split(after_gl, _S("/"));
		if (parts.len >= 2) {
			string user = (*(string*)builtin__array_get(parts, 0));
			string repo = (*(string*)builtin__array_get(parts, 1));
			return builtin__string_plus_many(5, _MOV((string[5]){_S("https://gitlab.com/"), user, _S("/"), repo, _S("/-/raw/main")}));
		}
	} else if (builtin__string_starts_with(u, _S("https://codeberg.org/")) || builtin__string_starts_with(u, _S("http://codeberg.org/"))) {
		string after_cb = (builtin__string_starts_with(u, _S("https://codeberg.org/")) ? (builtin__string_all_after(u, _S("https://codeberg.org/"))) : (builtin__string_all_after(u, _S("http://codeberg.org/"))));
		Array_string parts = builtin__string_split(after_cb, _S("/"));
		if (parts.len >= 2) {
			string user = (*(string*)builtin__array_get(parts, 0));
			string repo = (*(string*)builtin__array_get(parts, 1));
			return builtin__string_plus_many(5, _MOV((string[5]){_S("https://codeberg.org/"), user, _S("/"), repo, _S("/raw/branch/main")}));
		}
	}
	return u;
}
VV_LOC Array_string main__get_repo_file_urls(main__Repo repo, string rel_path) {
	Array_string urls = builtin____new_array_with_default(0, 0, sizeof(string), 0);
	string clean_rel = builtin__string_trim_left(rel_path, _S("/"));
	if (builtin__string_contains(repo.url, _S("code.weexnes.dev"))) {
		string base = builtin__string_trim_right(repo.url, _S("/"));
		if (builtin__string_ends_with(base, _S(".git"))) {
			base = builtin__string_all_before_last(base, _S(".git"));
		}
		builtin__array_push((array*)&urls, _MOV((string[]){ builtin__string_plus_many(3, _MOV((string[3]){base, _S("/~raw?revision=main&file="), clean_rel})) }));
		builtin__array_push((array*)&urls, _MOV((string[]){ builtin__string_plus_many(3, _MOV((string[3]){base, _S("/~raw?revision=master&file="), clean_rel})) }));
		return urls;
	}
	if (builtin__string_starts_with(repo.url, _S("https://github.com/")) || builtin__string_starts_with(repo.url, _S("http://github.com/"))) {
		string after = (builtin__string_starts_with(repo.url, _S("https://github.com/")) ? (builtin__string_all_after(repo.url, _S("https://github.com/"))) : (builtin__string_all_after(repo.url, _S("http://github.com/"))));
		string clean = builtin__string_trim_right(after, _S("/"));
		if (builtin__string_ends_with(clean, _S(".git"))) {
			clean = builtin__string_all_before_last(clean, _S(".git"));
		}
		Array_string parts = builtin__string_split(clean, _S("/"));
		if (parts.len >= 2) {
			string user = (*(string*)builtin__array_get(parts, 0));
			string rname = (*(string*)builtin__array_get(parts, 1));
			builtin__array_push((array*)&urls, _MOV((string[]){ builtin__string_plus_many(6, _MOV((string[6]){_S("https://raw.githubusercontent.com/"), user, _S("/"), rname, _S("/main/"), clean_rel})) }));
			builtin__array_push((array*)&urls, _MOV((string[]){ builtin__string_plus_many(6, _MOV((string[6]){_S("https://raw.githubusercontent.com/"), user, _S("/"), rname, _S("/master/"), clean_rel})) }));
			return urls;
		}
	}
	if (builtin__string_starts_with(repo.url, _S("https://gitlab.com/")) || builtin__string_starts_with(repo.url, _S("http://gitlab.com/"))) {
		string clean = builtin__string_trim_right(repo.url, _S("/"));
		if (builtin__string_ends_with(clean, _S(".git"))) {
			clean = builtin__string_all_before_last(clean, _S(".git"));
		}
		builtin__array_push((array*)&urls, _MOV((string[]){ builtin__string_plus_many(3, _MOV((string[3]){clean, _S("/-/raw/main/"), clean_rel})) }));
		builtin__array_push((array*)&urls, _MOV((string[]){ builtin__string_plus_many(3, _MOV((string[3]){clean, _S("/-/raw/master/"), clean_rel})) }));
		return urls;
	}
	if (builtin__string_starts_with(repo.url, _S("https://codeberg.org/")) || builtin__string_starts_with(repo.url, _S("http://codeberg.org/"))) {
		string clean = builtin__string_trim_right(repo.url, _S("/"));
		if (builtin__string_ends_with(clean, _S(".git"))) {
			clean = builtin__string_all_before_last(clean, _S(".git"));
		}
		builtin__array_push((array*)&urls, _MOV((string[]){ builtin__string_plus_many(3, _MOV((string[3]){clean, _S("/raw/branch/main/"), clean_rel})) }));
		builtin__array_push((array*)&urls, _MOV((string[]){ builtin__string_plus_many(3, _MOV((string[3]){clean, _S("/raw/branch/master/"), clean_rel})) }));
		return urls;
	}
	string base_raw = builtin__string_trim_right(repo.raw_url, _S("/"));
	builtin__array_push((array*)&urls, _MOV((string[]){ builtin__string_plus_many(3, _MOV((string[3]){base_raw, _S("/"), clean_rel})) }));
	if (builtin__string_contains(base_raw, _S("/main"))) {
		builtin__array_push((array*)&urls, _MOV((string[]){ builtin__string__plus(builtin__string_replace(base_raw, _S("/main"), _S("/master")), builtin__string_plus_many(2, _MOV((string[2]){_S("/"), clean_rel}))) }));
	}
	return urls;
}
VV_LOC Array_string main__get_repos_conf_paths(string prefix) {
	return builtin__new_array_from_c_array(6, 6, sizeof(string), _MOV((string[6]){builtin__string_plus_many(2, _MOV((string[2]){prefix, _S("/etc/ngpkg/repos.conf")})), _S("/etc/ngpkg/repos.conf"), _S("/etc/ngpkg.repos"), builtin__string_plus_many(2, _MOV((string[2]){prefix, _S("/etc/ngpkg.conf")})), _S("/etc/ngpkg.conf"), _S("/etc/pkg.conf")}));
}
VV_LOC main__Config main__load_config(void) {
	string prefix = os__getenv(_S("INSTALL_PREFIX"));
	string db_dir = os__getenv(_S("PKG_DB"));
	if ((prefix).len == 0) {
		prefix = _const_main__default_install_prefix;
	}
	if ((db_dir).len == 0) {
		db_dir = _const_main__default_db_dir;
	}
	Array_main__Repo repos = builtin____new_array_with_default(0, 0, sizeof(main__Repo), 0);
	Array_string conf_paths = main__get_repos_conf_paths(prefix);
	for (int _t1 = 0; _t1 < conf_paths.len; ++_t1) {
		string p = ((string*)conf_paths.data)[_t1];
		if ((p).len != 0 && os__exists(p)) {
			_result_Array_string _t2 = os__read_lines(p);
			if (_t2.is_error) {
				*(Array_string*) _t2.data = builtin____new_array_with_default(0, 0, sizeof(string), 0);
			}
			
 			Array_string lines = (*(Array_string*)_t2.data);
			for (int _t3 = 0; _t3 < lines.len; ++_t3) {
				string line = ((string*)lines.data)[_t3];
				string trimmed = builtin__string_trim_space(line);
				if (builtin__string_starts_with(trimmed, _S("#")) || (trimmed).len == 0) {
					continue;
				}
				if (builtin__string_starts_with(trimmed, _S("REPO_URL="))) {
					string u = builtin__string_trim(builtin__string_all_after(trimmed, _S("REPO_URL=")), _S(" \"'"));
					if ((u).len != 0) {
						string raw = main__normalize_repo_url(u);
						builtin__array_push((array*)&repos, _MOV((main__Repo[]){ ((main__Repo){.name = _S("default"),.url = u,.raw_url = raw,.package_count = 0,}) }));
					}
				} else if (builtin__string_contains(trimmed, _S(" ")) || builtin__string_contains(trimmed, _S("\t"))) {
					Array_string parts = builtin__string_fields(trimmed);
					if (parts.len >= 2) {
						string r_name = builtin__string_trim_space((*(string*)builtin__array_get(parts, 0)));
						string r_url = builtin__string_trim_space((*(string*)builtin__array_get(parts, 1)));
						string raw = main__normalize_repo_url(r_url);
						bool exists = false;
						for (int _t5 = 0; _t5 < repos.len; ++_t5) {
							main__Repo r = ((main__Repo*)repos.data)[_t5];
							if (builtin__string__eq(r.name, r_name)) {
								exists = true;
								break;
							}
						}
						if (!exists) {
							builtin__array_push((array*)&repos, _MOV((main__Repo[]){ ((main__Repo){.name = r_name,.url = r_url,.raw_url = raw,.package_count = 0,}) }));
						}
					}
				}
			}
			if (repos.len > 0) {
				break;
			}
		}
	}
	string env_repo = os__getenv(_S("REPO_URL"));
	if ((env_repo).len != 0) {
		string raw = main__normalize_repo_url(env_repo);
		repos = builtin__new_array_from_c_array(1, 1, sizeof(main__Repo), _MOV((main__Repo[1]){((main__Repo){.name = _S("env"),.url = env_repo,.raw_url = raw,.package_count = 0,})}));
	}
	if (repos.len == 0) {
		builtin__array_push((array*)&repos, _MOV((main__Repo[]){ ((main__Repo){.name = _const_main__default_repo_name,.url = _const_main__default_repo_url,.raw_url = _const_main__default_repo_url,.package_count = 0,}) }));
	}
	return ((main__Config){.repos = repos,.prefix = builtin__string_trim_right(prefix, _S("/")),.db_dir = builtin__string_trim_right(db_dir, _S("/")),});
}
VV_LOC bool main__save_repos_config(main__Config cfg) {
	strings__Builder content = strings__new_builder(256);
	strings__Builder_write_string(&content, _S("# OpenNGFW Serverless Package Repositories\n"));
	strings__Builder_write_string(&content, _S("# Format: <name> <git-url-or-raw-url>\n\n"));
	for (int _t1 = 0; _t1 < cfg.repos.len; ++_t1) {
		main__Repo r = ((main__Repo*)cfg.repos.data)[_t1];
		{
			strings__Builder_write_string(&content, r.name);
			strings__Builder_write_string(&content, _S(" "));
			strings__Builder_write_string(&content, r.url);
			strings__Builder_write_string(&content, _S("\n"));
		}
	}
	Array_string target_paths = builtin__new_array_from_c_array(2, 2, sizeof(string), _MOV((string[2]){builtin__string_plus_many(2, _MOV((string[2]){cfg.prefix, _S("/etc/ngpkg/repos.conf")})), _S("/etc/ngpkg/repos.conf")}));
	bool ok = false;
	for (int _t2 = 0; _t2 < target_paths.len; ++_t2) {
		string p = ((string*)target_paths.data)[_t2];
		string dir = os__dir(p);
		_result_void _t3 = os__mkdir_all(dir, ((os__MkdirParams){.mode = 0777,}));
		(void)_t3;
 ;
		_result_void _t4 = os__write_file(p, strings__Builder_str(&content));
		if (_t4.is_error) {
			continue;
		}
		
 ;
		ok = true;
	}
	return ok;
}
VV_LOC Array_string main__get_installed_db_dirs(main__Config cfg) {
	return builtin__new_array_from_c_array(3, 3, sizeof(string), _MOV((string[3]){builtin__string_plus_many(2, _MOV((string[2]){cfg.prefix, _S("/var/lib/ngpkg/installed")})), builtin__string_plus_many(2, _MOV((string[2]){cfg.db_dir, _S("/installed")})), _S("/var/lib/ngpkg/installed")}));
}
VV_LOC bool main__is_installed(main__Config cfg, string pkg_name) {
	Array_string _t1 = main__get_installed_db_dirs(cfg);
	for (int _t2 = 0; _t2 < _t1.len; ++_t2) {
		string d = ((string*)_t1.data)[_t2];
		if (os__exists(builtin__string_plus_many(4, _MOV((string[4]){d, _S("/"), pkg_name, _S(".json")}))) || os__exists(builtin__string_plus_many(4, _MOV((string[4]){d, _S("/"), pkg_name, _S(".list")}))) || os__exists(builtin__string_plus_many(4, _MOV((string[4]){d, _S("/"), pkg_name, _S(".meta")})))) {
			return true;
		}
	}
	if (os__exists(builtin__string_plus_many(3, _MOV((string[3]){cfg.prefix, _S("/bin/"), pkg_name}))) || os__exists(builtin__string_plus_many(3, _MOV((string[3]){cfg.prefix, _S("/sbin/"), pkg_name})))) {
		return true;
	}
	return false;
}
VV_LOC Array_string main__get_installed_packages(main__Config cfg) {
	Array_string pkgs = builtin____new_array_with_default(0, 0, sizeof(string), 0);
	Array_string dirs = main__get_installed_db_dirs(cfg);
	for (int _t1 = 0; _t1 < dirs.len; ++_t1) {
		string d = ((string*)dirs.data)[_t1];
		if (os__is_dir(d)) {
			_result_Array_string _t2 = os__ls(d);
			if (_t2.is_error) {
				*(Array_string*) _t2.data = builtin____new_array_with_default(0, 0, sizeof(string), 0);
			}
			
 			Array_string files = (*(Array_string*)_t2.data);
			for (int _t3 = 0; _t3 < files.len; ++_t3) {
				string f = ((string*)files.data)[_t3];
				if (builtin__string_ends_with(f, _S(".json"))) {
					string name = builtin__string_trim_string_right(f, _S(".json"));
					if (!Array_string_contains(pkgs, name)) {
						builtin__array_push((array*)&pkgs, _MOV((string[]){ builtin__string_clone(name) }));
					}
				} else if (builtin__string_ends_with(f, _S(".list"))) {
					string name = builtin__string_trim_string_right(f, _S(".list"));
					if (!Array_string_contains(pkgs, name)) {
						builtin__array_push((array*)&pkgs, _MOV((string[]){ builtin__string_clone(name) }));
					}
				}
			}
		}
	}
	return pkgs;
}
VV_LOC _option_main__Package main__get_installed_meta(main__Config cfg, string pkg_name) {
	Array_string _t1 = main__get_installed_db_dirs(cfg);
	for (int _t2 = 0; _t2 < _t1.len; ++_t2) {
		string d = ((string*)_t1.data)[_t2];
		string json_file = builtin__string_plus_many(4, _MOV((string[4]){d, _S("/"), pkg_name, _S(".json")}));
		if (os__exists(json_file)) {
			_result_string _t3 = os__read_file(json_file);
			if (_t3.is_error) {
				*(string*) _t3.data = _S("");
			}
			
 			string content = (*(string*)_t3.data);
			if ((content).len != 0) {
				string name = main__parse_json_value(content, _S("name"));
				string ver = main__parse_json_value(content, _S("version"));
				string desc = main__parse_json_value(content, _S("description"));
				string cat = main__parse_json_value(content, _S("category"));
				string repo = main__parse_json_value(content, _S("repo"));
				_option_main__Package _t4;
				builtin___option_ok(&(main__Package[]) { ((main__Package){
					.name = ((name).len != 0 ? (name) : (pkg_name)),
					.version = ((ver).len != 0 ? (ver) : (_S("installed"))),
					.arch = _S("armv7l"),
					.size = _S("installed"),
					.size_bytes = 0,
					.description = ((desc).len != 0 ? (desc) : (_S("Installed application"))),
					.category = ((cat).len != 0 ? (cat) : (_S("utilities"))),
					.bin = (string){.str=(byteptr)"", .is_lit=1},
					.src = (string){.str=(byteptr)"", .is_lit=1},
					.pkg_type = _S("installed"),
					.repo_name = ((repo).len != 0 ? (repo) : (_S("local"))),
				}) }, (_option*)(&_t4), sizeof(main__Package));
				 
				return _t4;
			}
		}
	}
	Array_string _t5 = main__get_installed_db_dirs(cfg);
	for (int _t6 = 0; _t6 < _t5.len; ++_t6) {
		string d = ((string*)_t5.data)[_t6];
		string meta_file = builtin__string_plus_many(4, _MOV((string[4]){d, _S("/"), pkg_name, _S(".meta")}));
		if (os__exists(meta_file)) {
			_result_Array_string _t7 = os__read_lines(meta_file);
			if (_t7.is_error) {
				*(Array_string*) _t7.data = builtin____new_array_with_default(0, 0, sizeof(string), 0);
			}
			
 			Array_string lines = (*(Array_string*)_t7.data);
			string name = pkg_name;
			string ver = _S("unknown");
			string desc = _S("Installed package");
			string cat = _S("custom");
			for (int _t8 = 0; _t8 < lines.len; ++_t8) {
				string line = ((string*)lines.data)[_t8];
				string trimmed = builtin__string_trim_space(line);
				if (builtin__string_starts_with(trimmed, _S("NAME="))) {
					name = builtin__string_trim_space(builtin__string_all_after(trimmed, _S("NAME=")));
				} else if (builtin__string_starts_with(trimmed, _S("VERSION="))) {
					ver = builtin__string_trim_space(builtin__string_all_after(trimmed, _S("VERSION=")));
				} else if (builtin__string_starts_with(trimmed, _S("DESCRIPTION="))) {
					desc = builtin__string_trim_space(builtin__string_all_after(trimmed, _S("DESCRIPTION=")));
				} else if (builtin__string_starts_with(trimmed, _S("CATEGORY="))) {
					cat = builtin__string_trim_space(builtin__string_all_after(trimmed, _S("CATEGORY=")));
				}
			}
			_option_main__Package _t9;
			builtin___option_ok(&(main__Package[]) { ((main__Package){
				.name = name,
				.version = ver,
				.arch = _S("armv7l"),
				.size = _S("installed"),
				.size_bytes = 0,
				.description = desc,
				.category = cat,
				.bin = (string){.str=(byteptr)"", .is_lit=1},
				.src = (string){.str=(byteptr)"", .is_lit=1},
				.pkg_type = _S("installed"),
				.repo_name = _S("local"),
			}) }, (_option*)(&_t9), sizeof(main__Package));
			 
			return _t9;
		}
	}
	return (_option_main__Package){ .state=2, .err=_const_none__, .data={E_STRUCT} };
}
VV_LOC Array_main__Package main__parse_index_json(string content, string repo_name) {
	Array_main__Package pkgs = builtin____new_array_with_default(0, 0, sizeof(main__Package), 0);
	if (!builtin__string_contains(content, _S("\"packages\""))) {
		return pkgs;
	}
	string after_pkgs = builtin__string_trim_space(builtin__string_all_after(content, _S("\"packages\"")));
	if (!builtin__string_starts_with(after_pkgs, _S(":"))) {
		return pkgs;
	}
	string array_part = builtin__string_trim_space(builtin__string_all_after(after_pkgs, _S(":")));
	if (!builtin__string_starts_with(array_part, _S("["))) {
		return pkgs;
	}
	string raw_array = builtin__string_all_before_last(builtin__string_all_after(array_part, _S("[")), _S("]"));
	bool in_obj = false;
	int brace_depth = 0;
	int start_idx = 0;
	for (int i = 0; i < raw_array.len; i++) {
		u8 ch = builtin__string_at(raw_array, i);
		if (ch == '{') {
			if (brace_depth == 0) {
				start_idx = i;
				in_obj = true;
			}
			brace_depth++;
		} else if (ch == '}') {
			brace_depth--;
			if (brace_depth == 0 && in_obj) {
				in_obj = false;
				string obj_str = builtin__string_substr(raw_array, start_idx, i + 1);
				string name = main__parse_json_value(obj_str, _S("name"));
				if ((name).len != 0) {
					string ver = main__parse_json_value(obj_str, _S("version"));
					string arch = main__parse_json_value(obj_str, _S("arch"));
					string desc = main__parse_json_value(obj_str, _S("description"));
					string cat = main__parse_json_value(obj_str, _S("category"));
					string sz = main__parse_json_value(obj_str, _S("size"));
					string bin = main__parse_json_value(obj_str, _S("bin"));
					string src = main__parse_json_value(obj_str, _S("src"));
					string ptype = main__parse_json_value(obj_str, _S("type"));
					string final_type = ptype;
					if ((final_type).len == 0) {
						if (builtin__string_ends_with(bin, _S(".tar.gz")) || builtin__string_ends_with(bin, _S(".tgz")) || builtin__string_ends_with(bin, _S(".ngpkg")) || builtin__string_ends_with(bin, _S(".tar")) || builtin__string_ends_with(bin, _S(".tar.xz"))) {
							final_type = _S("archive");
						} else {
							final_type = _S("binary");
						}
					}
					builtin__array_push((array*)&pkgs, _MOV((main__Package[]){ ((main__Package){
						.name = name,
						.version = ((ver).len != 0 ? (ver) : (_S("1.0.0"))),
						.arch = ((arch).len != 0 ? (arch) : (_S("armv7l"))),
						.size = ((sz).len != 0 ? (sz) : (_S("unknown"))),
						.size_bytes = 0,
						.description = ((desc).len != 0 ? (desc) : (builtin__string_plus_many(2, _MOV((string[2]){_S("Package "), name})))),
						.category = ((cat).len != 0 ? (cat) : (_S("utilities"))),
						.bin = bin,
						.src = src,
						.pkg_type = final_type,
						.repo_name = repo_name,
					}) }));
				}
			}
		}
	}
	return pkgs;
}
VV_LOC Array_main__Package main__fetch_all_repo_packages(main__Config cfg) {
	Array_main__Package all_pkgs = builtin____new_array_with_default(0, 0, sizeof(main__Package), 0);
	Map_string_bool seen = builtin__new_map(sizeof(string), sizeof(bool), &builtin__map_hash_string, &builtin__map_eq_string, &builtin__map_clone_string, &builtin__map_free_string)
	;
	for (int _t1 = 0; _t1 < cfg.repos.len; ++_t1) {
		main__Repo repo = ((main__Repo*)cfg.repos.data)[_t1];
		Array_string repo_cache_candidates = builtin__new_array_from_c_array(3, 3, sizeof(string), _MOV((string[3]){builtin__string_plus_many(4, _MOV((string[4]){cfg.prefix, _S("/var/lib/ngpkg/repos/"), repo.name, _S("/index.json")})), builtin__string_plus_many(4, _MOV((string[4]){cfg.db_dir, _S("/repos/"), repo.name, _S("/index.json")})), builtin__string_plus_many(3, _MOV((string[3]){_S("/var/lib/ngpkg/repos/"), repo.name, _S("/index.json")}))}));
		for (int _t2 = 0; _t2 < repo_cache_candidates.len; ++_t2) {
			string cand = ((string*)repo_cache_candidates.data)[_t2];
			if (os__exists(cand)) {
				_result_string _t3 = os__read_file(cand);
				if (_t3.is_error) {
					*(string*) _t3.data = _S("");
				}
				
 				string content = (*(string*)_t3.data);
				if ((content).len != 0) {
					Array_main__Package pkgs = main__parse_index_json(content, repo.name);
					for (int _t4 = 0; _t4 < pkgs.len; ++_t4) {
						main__Package p = ((main__Package*)pkgs.data)[_t4];
						if (!(*(bool*)builtin__map_get(ADDR(map, seen), &(string[]){p.name}, &(bool[]){ 0 }))) {
							builtin__map_set(&seen, &(string[]){p.name}, &(bool[]) { true });
							builtin__array_push((array*)&all_pkgs, _MOV((main__Package[]){ p }));
						}
					}
					break;
				}
			}
		}
	}
	Array_string consolidated_candidates = builtin__new_array_from_c_array(3, 3, sizeof(string), _MOV((string[3]){builtin__string_plus_many(2, _MOV((string[2]){cfg.prefix, _S("/var/lib/ngpkg/cache/index.json")})), builtin__string_plus_many(2, _MOV((string[2]){cfg.db_dir, _S("/cache/index.json")})), _S("/var/lib/ngpkg/cache/index.json")}));
	for (int _t6 = 0; _t6 < consolidated_candidates.len; ++_t6) {
		string cand = ((string*)consolidated_candidates.data)[_t6];
		if (os__exists(cand)) {
			_result_string _t7 = os__read_file(cand);
			if (_t7.is_error) {
				*(string*) _t7.data = _S("");
			}
			
 			string content = (*(string*)_t7.data);
			if ((content).len != 0) {
				Array_main__Package pkgs = main__parse_index_json(content, _S("core"));
				for (int _t8 = 0; _t8 < pkgs.len; ++_t8) {
					main__Package p = ((main__Package*)pkgs.data)[_t8];
					if (!(*(bool*)builtin__map_get(ADDR(map, seen), &(string[]){p.name}, &(bool[]){ 0 }))) {
						builtin__map_set(&seen, &(string[]){p.name}, &(bool[]) { true });
						builtin__array_push((array*)&all_pkgs, _MOV((main__Package[]){ p }));
					}
				}
				break;
			}
		}
	}
	return all_pkgs;
}
VV_LOC bool main__download_url(string url, string dest) {
	string dir = os__dir(dest);
	_result_void _t1 = os__mkdir_all(dir, ((os__MkdirParams){.mode = 0777,}));
	(void)_t1;
 ;
	string cmd = builtin__string_plus_many(13, _MOV((string[13]){_S("curl -fsSL --connect-timeout 10 -m 60 --cacert /etc/ssl/certs/ca-certificates.crt -o \""), dest, _S("\" \""), url, _S("\" 2>/dev/null || curl -fsSL -k --connect-timeout 10 -m 60 -o \""), dest, _S("\" \""), url, _S("\" 2>/dev/null || wget -q -T 15 -O \""), dest, _S("\" \""), url, _S("\" 2>/dev/null")}));
	os__Result res = os__execute(cmd);
	return res.exit_code == 0 && os__exists(dest) && os__file_size(dest) > 0;
}
VV_LOC int main__cmd_update(main__Config cfg) {
	builtin__println(builtin__string_plus_many(4, _MOV((string[4]){_const_main__c_cyan, _S("\342\227\210"), _const_main__c_reset, _S(" Synchronizing serverless package repositories...\n")})));
	int total_available = 0;
	int success_count = 0;
	for (int _t1 = 0; _t1 < cfg.repos.len; ++_t1) {
		main__Repo repo = ((main__Repo*)cfg.repos.data)[_t1];
		builtin__print(builtin__string_plus_many(13, _MOV((string[13]){_S("  "), _const_main__c_blue, _S("\342\200\242"), _const_main__c_reset, _S(" Fetching "), _const_main__c_bold, repo.name, _const_main__c_reset, _S(" ("), _const_main__c_gray, repo.url, _const_main__c_reset, _S(")... ")})));
		string target_file = builtin__string_plus_many(4, _MOV((string[4]){cfg.db_dir, _S("/repos/"), repo.name, _S("/index.json")}));
		_result_void _t2 = os__mkdir_all(os__dir(target_file), ((os__MkdirParams){.mode = 0777,}));
		(void)_t2;
 ;
		Array_string urls_to_try = main__get_repo_file_urls(repo, _S("index.json"));
		bool fetched = false;
		for (int _t3 = 0; _t3 < urls_to_try.len; ++_t3) {
			string u = ((string*)urls_to_try.data)[_t3];
			if (main__download_url(u, target_file)) {
				fetched = true;
				break;
			}
		}
		if (fetched) {
			_result_string _t4 = os__read_file(target_file);
			if (_t4.is_error) {
				*(string*) _t4.data = _S("");
			}
			
 			string content = (*(string*)_t4.data);
			Array_main__Package pkgs = main__parse_index_json(content, repo.name);
			builtin__println(builtin__string_plus_many(8, _MOV((string[8]){_const_main__c_green, _S("\342\234\223 OK"), _const_main__c_reset, _S(" ("), _const_main__c_bold, builtin__int_str(pkgs.len), _const_main__c_reset, _S(" packages)")})));
			total_available += pkgs.len;
			success_count++;
			if (os__is_dir(cfg.prefix)) {
				string usb_dest = builtin__string_plus_many(4, _MOV((string[4]){cfg.prefix, _S("/var/lib/ngpkg/repos/"), repo.name, _S("/index.json")}));
				_result_void _t5 = os__mkdir_all(os__dir(usb_dest), ((os__MkdirParams){.mode = 0777,}));
				(void)_t5;
 ;
				_result_void _t6 = os__cp(target_file, usb_dest, ((os__CopyParams){.fail_if_exists = 0,}));
				(void)_t6;
 ;
			}
		} else {
			builtin__println(builtin__string_plus_many(3, _MOV((string[3]){_const_main__c_red, _S("\342\234\227 Failed"), _const_main__c_reset})));
			builtin__eprintln(builtin__string_plus_many(5, _MOV((string[5]){_S("    "), _const_main__c_yellow, _S("Could not fetch index.json from "), repo.raw_url, _const_main__c_reset})));
		}
	}
	Array_main__Package all_pkgs = main__fetch_all_repo_packages(cfg);
	_result_void _t7 = os__mkdir_all(builtin__string_plus_many(2, _MOV((string[2]){cfg.db_dir, _S("/cache")})), ((os__MkdirParams){.mode = 0777,}));
	(void)_t7;
 ;
	strings__Builder consolidated_json = strings__new_builder(2048);
	strings__Builder_write_string(&consolidated_json, _S("{\n  \"version\": \"2.0\",\n  \"packages\": [\n"));
	for (int idx = 0; idx < all_pkgs.len; ++idx) {
		main__Package p = ((main__Package*)all_pkgs.data)[idx];
		string comma = (idx < all_pkgs.len - 1 ? (_S(",")) : (_S("")));
		{
			strings__Builder_write_string(&consolidated_json, _S("    {\"name\":\""));
			strings__Builder_write_string(&consolidated_json, p.name);
			strings__Builder_write_string(&consolidated_json, _S("\",\"version\":\""));
			strings__Builder_write_string(&consolidated_json, p.version);
			strings__Builder_write_string(&consolidated_json, _S("\",\"size\":\""));
			strings__Builder_write_string(&consolidated_json, p.size);
			strings__Builder_write_string(&consolidated_json, _S("\",\"description\":\""));
			strings__Builder_write_string(&consolidated_json, main__json_escape(p.description));
			strings__Builder_write_string(&consolidated_json, _S("\",\"category\":\""));
			strings__Builder_write_string(&consolidated_json, p.category);
			strings__Builder_write_string(&consolidated_json, _S("\",\"bin\":\""));
			strings__Builder_write_string(&consolidated_json, p.bin);
			strings__Builder_write_string(&consolidated_json, _S("\",\"src\":\""));
			strings__Builder_write_string(&consolidated_json, p.src);
			strings__Builder_write_string(&consolidated_json, _S("\",\"type\":\""));
			strings__Builder_write_string(&consolidated_json, p.pkg_type);
			strings__Builder_write_string(&consolidated_json, _S("\",\"repo\":\""));
			strings__Builder_write_string(&consolidated_json, p.repo_name);
			strings__Builder_write_string(&consolidated_json, _S("\"}"));
			strings__Builder_write_string(&consolidated_json, comma);
			strings__Builder_write_string(&consolidated_json, _S("\n"));
		}
	}
	strings__Builder_write_string(&consolidated_json, _S("  ]\n}\n"));
	_result_void _t8 = os__write_file(builtin__string_plus_many(2, _MOV((string[2]){cfg.db_dir, _S("/cache/index.json")})), strings__Builder_str(&consolidated_json));
	(void)_t8;
 ;
	if (os__is_dir(cfg.prefix)) {
		_result_void _t9 = os__mkdir_all(builtin__string_plus_many(2, _MOV((string[2]){cfg.prefix, _S("/var/lib/ngpkg/cache")})), ((os__MkdirParams){.mode = 0777,}));
		(void)_t9;
 ;
		_result_void _t10 = os__write_file(builtin__string_plus_many(2, _MOV((string[2]){cfg.prefix, _S("/var/lib/ngpkg/cache/index.json")})), strings__Builder_str(&consolidated_json));
		(void)_t10;
 ;
	}
	builtin__println(builtin__string_plus_many(15, _MOV((string[15]){_S("\n"), _const_main__c_green, _S("\342\234\223 Update complete:"), _const_main__c_reset, _S(" "), _const_main__c_bold, builtin__int_str(total_available), _const_main__c_reset, _S(" packages across "), _const_main__c_bold, builtin__int_str(success_count), _S("/"), builtin__int_str(cfg.repos.len), _const_main__c_reset, _S(" repositories.\n")})));
	return (success_count > 0 ? (0) : (1));
}
VV_LOC int main__cmd_list(main__Config cfg, bool json_mode) {
	Array_main__Package pkgs = main__fetch_all_repo_packages(cfg);
	if (pkgs.len == 0 && !json_mode) {
		builtin__println(builtin__string_plus_many(4, _MOV((string[4]){_const_main__c_yellow, _S("[! No index found]"), _const_main__c_reset, _S(" Updating repository index first...\n")})));
		main__cmd_update(cfg);
	}
	Array_main__Package fresh_pkgs = main__fetch_all_repo_packages(cfg);
	Array_string installed = main__get_installed_packages(cfg);
	if (json_mode) {
		Array_string items = builtin____new_array_with_default(0, 0, sizeof(string), 0);
		for (int _t1 = 0; _t1 < fresh_pkgs.len; ++_t1) {
			main__Package p = ((main__Package*)fresh_pkgs.data)[_t1];
			bool is_inst = main__is_installed(cfg, p.name);
			builtin__array_push((array*)&items, _MOV((string[]){ builtin__string_plus_many(19, _MOV((string[19]){_S("{\"name\":\""), p.name, _S("\",\"version\":\""), p.version, _S("\",\"size\":\""), p.size, _S("\",\"description\":\""), main__json_escape(p.description), _S("\",\"category\":\""), p.category, _S("\",\"repo\":\""), p.repo_name, _S("\",\"installed\":"), (is_inst ? _S("true") : _S("false")), _S(",\"bin\":\""), p.bin, _S("\",\"src\":\""), p.src, _S("\"}")})) }));
		}
		for (int _t3 = 0; _t3 < installed.len; ++_t3) {
			string inst_name = ((string*)installed.data)[_t3];
			bool in_repo = false;
			for (int _t4 = 0; _t4 < fresh_pkgs.len; ++_t4) {
				main__Package p = ((main__Package*)fresh_pkgs.data)[_t4];
				if (builtin__string__eq(p.name, inst_name)) {
					in_repo = true;
					;
					break;
				}
			}
			if (!in_repo) {
				_option_main__Package _t5 = main__get_installed_meta(cfg, inst_name);
				if (_t5.state != 0) {
					*(main__Package*) _t5.data = ((main__Package){.name = inst_name,.version = _S("custom"),.arch = (string){.str=(byteptr)"", .is_lit=1},.size = (string){.str=(byteptr)"", .is_lit=1},.size_bytes = 0,.description = _S("Local package"),.category = _S("custom"),.bin = (string){.str=(byteptr)"", .is_lit=1},.src = (string){.str=(byteptr)"", .is_lit=1},.pkg_type = (string){.str=(byteptr)"", .is_lit=1},.repo_name = (string){.str=(byteptr)"", .is_lit=1},});
				}
				
 				main__Package m = (*(main__Package*)_t5.data);
				builtin__array_push((array*)&items, _MOV((string[]){ builtin__string_plus_many(11, _MOV((string[11]){_S("{\"name\":\""), m.name, _S("\",\"version\":\""), m.version, _S("\",\"size\":\""), m.size, _S("\",\"description\":\""), main__json_escape(m.description), _S("\",\"category\":\""), m.category, _S("\",\"repo\":\"local\",\"installed\":true,\"bin\":\"\",\"src\":\"\"}")})) }));
			}
		}
		builtin__println(builtin__string_plus_many(3, _MOV((string[3]){_S("["), Array_string_join(items, _S(",")), _S("]")})));
		return 0;
	}
	builtin__println(builtin__string_plus_many(3, _MOV((string[3]){_const_main__c_bold, _S("OpenNGFW Serverless Package Repositories:"), _const_main__c_reset})));
	builtin__println(builtin__string_plus_many(3, _MOV((string[3]){_const_main__c_gray, _S("\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200"), _const_main__c_reset})));
	string h_name = main__pad_right(_S("NAME"), 14);
	string h_ver = main__pad_right(_S("VERSION"), 9);
	string h_repo = main__pad_right(_S("REPO"), 10);
	string h_size = main__pad_right(_S("SIZE"), 8);
	string h_status = main__pad_right(_S("STATUS"), 14);
	builtin__println(builtin__string_plus_many(13, _MOV((string[13]){_S("  "), _const_main__c_bold, h_name, _S(" "), h_ver, _S(" "), h_repo, _S(" "), h_size, _S(" "), h_status, _S(" DESCRIPTION"), _const_main__c_reset})));
	builtin__println(builtin__string_plus_many(3, _MOV((string[3]){_const_main__c_gray, _S("\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200"), _const_main__c_reset})));
	int inst_count = 0;
	Array_string listed_installed = builtin____new_array_with_default(0, 0, sizeof(string), 0);
	for (int _t8 = 0; _t8 < fresh_pkgs.len; ++_t8) {
		main__Package p = ((main__Package*)fresh_pkgs.data)[_t8];
		bool is_inst = main__is_installed(cfg, p.name);
		if (is_inst) {
			inst_count++;
			builtin__array_push((array*)&listed_installed, _MOV((string[]){ builtin__string_clone(p.name) }));
		}
		string status_badge = (is_inst ? (builtin__string_plus_many(3, _MOV((string[3]){_const_main__c_green, _S("\342\227\217 installed"), _const_main__c_reset}))) : (builtin__string_plus_many(3, _MOV((string[3]){_const_main__c_cyan, _S("\342\227\213 available"), _const_main__c_reset}))));
		string name_fmt = (is_inst ? (builtin__string_plus_many(4, _MOV((string[4]){_const_main__c_green, _const_main__c_bold, main__pad_right(p.name, 14), _const_main__c_reset}))) : (builtin__string_plus_many(3, _MOV((string[3]){_const_main__c_bold, main__pad_right(p.name, 14), _const_main__c_reset}))));
		string ver_fmt = builtin__string_plus_many(3, _MOV((string[3]){_const_main__c_yellow, main__pad_right(p.version, 9), _const_main__c_reset}));
		string repo_fmt = builtin__string_plus_many(3, _MOV((string[3]){_const_main__c_purple, main__pad_right(p.repo_name, 10), _const_main__c_reset}));
		string size_fmt = builtin__string_plus_many(3, _MOV((string[3]){_const_main__c_gray, main__pad_right(p.size, 8), _const_main__c_reset}));
		string status_fmt = main__pad_right(status_badge, 23);
		builtin__println(builtin__string_plus_many(12, _MOV((string[12]){_S("  "), name_fmt, _S(" "), ver_fmt, _S(" "), repo_fmt, _S(" "), size_fmt, _S(" "), status_fmt, _S(" "), p.description})));
	}
	for (int _t10 = 0; _t10 < installed.len; ++_t10) {
		string inst_name = ((string*)installed.data)[_t10];
		if (!Array_string_contains(listed_installed, inst_name)) {
			inst_count++;
			_option_main__Package _t11 = main__get_installed_meta(cfg, inst_name);
			if (_t11.state != 0) {
				*(main__Package*) _t11.data = ((main__Package){.name = inst_name,.version = _S("custom"),.arch = (string){.str=(byteptr)"", .is_lit=1},.size = (string){.str=(byteptr)"", .is_lit=1},.size_bytes = 0,.description = _S("Local package"),.category = _S("custom"),.bin = (string){.str=(byteptr)"", .is_lit=1},.src = (string){.str=(byteptr)"", .is_lit=1},.pkg_type = (string){.str=(byteptr)"", .is_lit=1},.repo_name = (string){.str=(byteptr)"", .is_lit=1},});
			}
			
 			main__Package m = (*(main__Package*)_t11.data);
			string status_badge = builtin__string_plus_many(3, _MOV((string[3]){_const_main__c_green, _S("\342\227\217 installed (local)"), _const_main__c_reset}));
			string name_fmt = builtin__string_plus_many(4, _MOV((string[4]){_const_main__c_green, _const_main__c_bold, main__pad_right(m.name, 14), _const_main__c_reset}));
			string ver_fmt = builtin__string_plus_many(3, _MOV((string[3]){_const_main__c_yellow, main__pad_right(m.version, 9), _const_main__c_reset}));
			string repo_fmt = builtin__string_plus_many(3, _MOV((string[3]){_const_main__c_gray, main__pad_right(_S("local"), 10), _const_main__c_reset}));
			string size_fmt = builtin__string_plus_many(3, _MOV((string[3]){_const_main__c_gray, main__pad_right(_S("installed"), 8), _const_main__c_reset}));
			string status_fmt = main__pad_right(status_badge, 31);
			builtin__println(builtin__string_plus_many(12, _MOV((string[12]){_S("  "), name_fmt, _S(" "), ver_fmt, _S(" "), repo_fmt, _S(" "), size_fmt, _S(" "), status_fmt, _S(" "), m.description})));
		}
	}
	builtin__println(builtin__string_plus_many(3, _MOV((string[3]){_const_main__c_gray, _S("\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200"), _const_main__c_reset})));
	builtin__println(builtin__string_plus_many(17, _MOV((string[17]){_S("  "), _const_main__c_gray, _S("Total:"), _const_main__c_reset, _S(" "), builtin__int_str(fresh_pkgs.len), _S(" repository packages ("), _const_main__c_green, builtin__int_str(inst_count), _S(" installed"), _const_main__c_reset, _S(", "), _const_main__c_cyan, builtin__int_str(fresh_pkgs.len - listed_installed.len), _S(" available"), _const_main__c_reset, _S(")\n")})));
	return 0;
}
VV_LOC int main__cmd_search(main__Config cfg, string query) {
	Array_main__Package pkgs = main__fetch_all_repo_packages(cfg);
	if (pkgs.len == 0) {
		main__cmd_update(cfg);
	}
	Array_main__Package fresh_pkgs = main__fetch_all_repo_packages(cfg);
	string q = builtin__string_to_lower(query);
	builtin__println(builtin__string_plus_many(8, _MOV((string[8]){_const_main__c_cyan, _S("\342\227\210"), _const_main__c_reset, _S(" Search results for \""), _const_main__c_bold, query, _const_main__c_reset, _S("\":")})));
	builtin__println(builtin__string_plus_many(3, _MOV((string[3]){_const_main__c_gray, _S("\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200"), _const_main__c_reset})));
	int matches = 0;
	for (int _t1 = 0; _t1 < fresh_pkgs.len; ++_t1) {
		main__Package p = ((main__Package*)fresh_pkgs.data)[_t1];
		if (builtin__string_contains(builtin__string_to_lower(p.name), q) || builtin__string_contains(builtin__string_to_lower(p.description), q) || builtin__string_contains(builtin__string_to_lower(p.category), q) || builtin__string_contains(builtin__string_to_lower(p.repo_name), q)) {
			matches++;
			bool is_inst = main__is_installed(cfg, p.name);
			string status_badge = (is_inst ? (builtin__string_plus_many(3, _MOV((string[3]){_const_main__c_green, _S("[installed]"), _const_main__c_reset}))) : (builtin__string_plus_many(3, _MOV((string[3]){_const_main__c_cyan, _S("[available]"), _const_main__c_reset}))));
			string name_fmt = main__pad_right(p.name, 14);
			string ver_fmt = main__pad_right(p.version, 8);
			string repo_fmt = main__pad_right(p.repo_name, 10);
			string status_fmt = main__pad_right(status_badge, 21);
			builtin__println(builtin__string_plus_many(16, _MOV((string[16]){_S("  "), _const_main__c_bold, name_fmt, _const_main__c_reset, _S(" "), _const_main__c_yellow, ver_fmt, _const_main__c_reset, _S(" "), _const_main__c_purple, repo_fmt, _const_main__c_reset, _S(" "), status_fmt, _S(" "), p.description})));
		}
	}
	if (matches == 0) {
		builtin__println(builtin__string_plus_many(4, _MOV((string[4]){_S("  "), _const_main__c_gray, _S("No matching packages found."), _const_main__c_reset})));
	}
	builtin__println(builtin__string_plus_many(4, _MOV((string[4]){_const_main__c_gray, _S("\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200"), _const_main__c_reset, _S("\n")})));
	return 0;
}
VV_LOC int main__cmd_info(main__Config cfg, string pkg_name) {
	Array_main__Package pkgs = main__fetch_all_repo_packages(cfg);
	if (pkgs.len == 0) {
		main__cmd_update(cfg);
	}
	Array_main__Package fresh_pkgs = main__fetch_all_repo_packages(cfg);
	main__Package _t1 = ((main__Package){.name = (string){.str=(byteptr)"", .is_lit=1},.version = (string){.str=(byteptr)"", .is_lit=1},.arch = (string){.str=(byteptr)"", .is_lit=1},.size = (string){.str=(byteptr)"", .is_lit=1},.size_bytes = 0,.description = (string){.str=(byteptr)"", .is_lit=1},.category = (string){.str=(byteptr)"", .is_lit=1},.bin = (string){.str=(byteptr)"", .is_lit=1},.src = (string){.str=(byteptr)"", .is_lit=1},.pkg_type = (string){.str=(byteptr)"", .is_lit=1},.repo_name = (string){.str=(byteptr)"", .is_lit=1},});
	main__Package target = _t1;
	bool found = false;
	for (int _t2 = 0; _t2 < fresh_pkgs.len; ++_t2) {
		main__Package p = ((main__Package*)fresh_pkgs.data)[_t2];
		if (builtin__string__eq(p.name, pkg_name)) {
			target = p;
			found = true;
			break;
		}
	}
	if (!found && main__is_installed(cfg, pkg_name)) {
		_option_main__Package meta_opt = main__get_installed_meta(cfg, pkg_name);
		_option_main__Package _t3 = {0};
		if (_t3 = meta_opt, _t3.state == 0) {
			main__Package m = *(main__Package*)_t3.data;
			target = m;
			found = true;
		}
	}
	if (!found) {
		builtin__eprintln(builtin__string_plus_many(5, _MOV((string[5]){_const_main__c_red, _S("\342\234\227 Package \""), pkg_name, _S("\" not found in repository index or installed database."), _const_main__c_reset})));
		return 1;
	}
	string repo_url = _S("");
	for (int _t5 = 0; _t5 < cfg.repos.len; ++_t5) {
		main__Repo r = ((main__Repo*)cfg.repos.data)[_t5];
		if (builtin__string__eq(r.name, target.repo_name)) {
			repo_url = r.url;
			break;
		}
	}
	bool is_inst = main__is_installed(cfg, target.name);
	string homedir = ((os__getenv(_S("HOME"))).len != 0 ? (os__getenv(_S("HOME"))) : (_S("/root")));
	string ngpkg_bin = builtin__string_plus_many(2, _MOV((string[2]){homedir, _S("/.ngpkg-bin")}));
	builtin__println(builtin__string_plus_many(9, _MOV((string[9]){_const_main__c_cyan, _S("\342\225\255\342\224\200 Package Information: "), _const_main__c_bold, target.name, _const_main__c_reset, _S(" "), _const_main__c_cyan, _S("\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\225\256"), _const_main__c_reset})));
	builtin__println(builtin__string_plus_many(11, _MOV((string[11]){_const_main__c_cyan, _S("\342\224\202"), _const_main__c_reset, _S("  "), _const_main__c_gray, _S("Name:"), _const_main__c_reset, _S("         "), _const_main__c_bold, target.name, _const_main__c_reset})));
	builtin__println(builtin__string_plus_many(11, _MOV((string[11]){_const_main__c_cyan, _S("\342\224\202"), _const_main__c_reset, _S("  "), _const_main__c_gray, _S("Version:"), _const_main__c_reset, _S("      "), _const_main__c_yellow, target.version, _const_main__c_reset})));
	builtin__println(builtin__string_plus_many(14, _MOV((string[14]){_const_main__c_cyan, _S("\342\224\202"), _const_main__c_reset, _S("  "), _const_main__c_gray, _S("Repository:"), _const_main__c_reset, _S("   "), _const_main__c_purple, target.repo_name, _const_main__c_reset, _S(" ("), repo_url, _S(")")})));
	builtin__println(builtin__string_plus_many(11, _MOV((string[11]){_const_main__c_cyan, _S("\342\224\202"), _const_main__c_reset, _S("  "), _const_main__c_gray, _S("Category:"), _const_main__c_reset, _S("     "), _const_main__c_purple, target.category, _const_main__c_reset})));
	builtin__println(builtin__string_plus_many(9, _MOV((string[9]){_const_main__c_cyan, _S("\342\224\202"), _const_main__c_reset, _S("  "), _const_main__c_gray, _S("Payload Size:"), _const_main__c_reset, _S(" "), target.size})));
	builtin__println(builtin__string_plus_many(9, _MOV((string[9]){_const_main__c_cyan, _S("\342\224\202"), _const_main__c_reset, _S("  "), _const_main__c_gray, _S("Type:"), _const_main__c_reset, _S("         "), target.pkg_type})));
	builtin__println(builtin__string_plus_many(9, _MOV((string[9]){_const_main__c_cyan, _S("\342\224\202"), _const_main__c_reset, _S("  "), _const_main__c_gray, _S("Binary Path:"), _const_main__c_reset, _S("  "), target.bin})));
	builtin__println(builtin__string_plus_many(9, _MOV((string[9]){_const_main__c_cyan, _S("\342\224\202"), _const_main__c_reset, _S("  "), _const_main__c_gray, _S("Source Path:"), _const_main__c_reset, _S("  "), target.src})));
	builtin__println(builtin__string__plus(builtin__string_plus_many(8, _MOV((string[8]){_const_main__c_cyan, _S("\342\224\202"), _const_main__c_reset, _S("  "), _const_main__c_gray, _S("Status:"), _const_main__c_reset, _S("       ")})), (is_inst ? (builtin__string_plus_many(3, _MOV((string[3]){_const_main__c_green, _S("\342\227\217 Installed"), _const_main__c_reset}))) : (builtin__string_plus_many(3, _MOV((string[3]){_const_main__c_cyan, _S("\342\227\213 Available for installation"), _const_main__c_reset}))))));
	builtin__println(builtin__string_plus_many(11, _MOV((string[11]){_const_main__c_cyan, _S("\342\224\202"), _const_main__c_reset, _S("  "), _const_main__c_gray, _S("Exec Link:"), _const_main__c_reset, _S("    "), ngpkg_bin, _S("/"), target.name})));
	builtin__println(builtin__string_plus_many(9, _MOV((string[9]){_const_main__c_cyan, _S("\342\224\202"), _const_main__c_reset, _S("  "), _const_main__c_gray, _S("Description:"), _const_main__c_reset, _S("  "), target.description})));
	if (is_inst) {
		Array_string _t6 = main__get_installed_db_dirs(cfg);
		for (int _t7 = 0; _t7 < _t6.len; ++_t7) {
			string d = ((string*)_t6.data)[_t7];
			string list_file = builtin__string_plus_many(4, _MOV((string[4]){d, _S("/"), target.name, _S(".list")}));
			if (os__exists(list_file)) {
				_result_Array_string _t8 = os__read_lines(list_file);
				if (_t8.is_error) {
					*(Array_string*) _t8.data = builtin____new_array_with_default(0, 0, sizeof(string), 0);
				}
				
 				Array_string lines = (*(Array_string*)_t8.data);
				builtin__println(builtin__string_plus_many(3, _MOV((string[3]){_const_main__c_cyan, _S("\342\224\202"), _const_main__c_reset})));
				builtin__println(builtin__string_plus_many(10, _MOV((string[10]){_const_main__c_cyan, _S("\342\224\202"), _const_main__c_reset, _S("  "), _const_main__c_bold, _S("Installed Files:"), _const_main__c_reset, _S(" ("), builtin__int_str(lines.len), _S(" files)")})));
				int count = 0;
				for (int _t9 = 0; _t9 < lines.len; ++_t9) {
					string l = ((string*)lines.data)[_t9];
					if ((builtin__string_trim_space(l)).len != 0 && count < 8) {
						builtin__println(builtin__string_plus_many(11, _MOV((string[11]){_const_main__c_cyan, _S("\342\224\202"), _const_main__c_reset, _S("    "), _const_main__c_gray, _S("\342\200\242"), _const_main__c_reset, _S(" "), cfg.prefix, _S("/"), builtin__string_trim_space(l)})));
						count++;
					}
				}
				if (lines.len > 8) {
					builtin__println(builtin__string_plus_many(9, _MOV((string[9]){_const_main__c_cyan, _S("\342\224\202"), _const_main__c_reset, _S("    "), _const_main__c_dim, _S("... and "), builtin__int_str(lines.len - 8), _S(" more files"), _const_main__c_reset})));
				}
				break;
			}
		}
	}
	builtin__println(builtin__string_plus_many(2, _MOV((string[2]){_const_main__c_cyan, _S("\342\225\260\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\225\257\n")})));
	return 0;
}
VV_LOC int main__cmd_install(main__Config cfg, string pkg_name) {
	Array_main__Package pkgs = main__fetch_all_repo_packages(cfg);
	if (pkgs.len == 0) {
		main__cmd_update(cfg);
	}
	Array_main__Package fresh_pkgs = main__fetch_all_repo_packages(cfg);
	main__Package _t1 = ((main__Package){.name = (string){.str=(byteptr)"", .is_lit=1},.version = (string){.str=(byteptr)"", .is_lit=1},.arch = (string){.str=(byteptr)"", .is_lit=1},.size = (string){.str=(byteptr)"", .is_lit=1},.size_bytes = 0,.description = (string){.str=(byteptr)"", .is_lit=1},.category = (string){.str=(byteptr)"", .is_lit=1},.bin = (string){.str=(byteptr)"", .is_lit=1},.src = (string){.str=(byteptr)"", .is_lit=1},.pkg_type = (string){.str=(byteptr)"", .is_lit=1},.repo_name = (string){.str=(byteptr)"", .is_lit=1},});
	main__Package target_pkg = _t1;
	bool found = false;
	for (int _t2 = 0; _t2 < fresh_pkgs.len; ++_t2) {
		main__Package p = ((main__Package*)fresh_pkgs.data)[_t2];
		if (builtin__string__eq(p.name, pkg_name)) {
			target_pkg = p;
			found = true;
			break;
		}
	}
	if (!found) {
		if (builtin__string_ends_with(pkg_name, _S(".ngpkg")) || builtin__string_ends_with(pkg_name, _S(".tar.gz")) || os__exists(pkg_name)) {
			return main__cmd_install_local_file(cfg, pkg_name);
		}
		builtin__eprintln(builtin__string_plus_many(5, _MOV((string[5]){_const_main__c_red, _S("\342\234\227 Package \""), pkg_name, _S("\" not found in any repository index."), _const_main__c_reset})));
		builtin__eprintln(builtin__string_plus_many(5, _MOV((string[5]){_S("  Run "), _const_main__c_bold, _S("pkg list"), _const_main__c_reset, _S(" to view all available applications.")})));
		return 1;
	}
	main__Repo target_repo = ((main__Repo){.name = _const_main__default_repo_name,.url = _const_main__default_repo_url,.raw_url = _const_main__default_repo_url,.package_count = 0,});
	for (int _t5 = 0; _t5 < cfg.repos.len; ++_t5) {
		main__Repo r = ((main__Repo*)cfg.repos.data)[_t5];
		if (builtin__string__eq(r.name, target_pkg.repo_name)) {
			target_repo = r;
			break;
		}
	}
	string bin_path = builtin__string_trim_left(target_pkg.bin, _S("/"));
	if ((bin_path).len == 0) {
		bin_path = builtin__string_plus_many(2, _MOV((string[2]){_S("bin/"), target_pkg.name}));
	}
	Array_string candidate_urls = main__get_repo_file_urls(target_repo, bin_path);
	builtin__println(builtin__string_plus_many(19, _MOV((string[19]){_const_main__c_cyan, _S("\342\227\210"), _const_main__c_reset, _S(" Installing "), _const_main__c_bold, target_pkg.name, _const_main__c_reset, _S(" ("), _const_main__c_yellow, _S("v"), target_pkg.version, _const_main__c_reset, _S(", "), target_pkg.size, _S(") from repo ["), _const_main__c_purple, target_pkg.repo_name, _const_main__c_reset, _S("]...")})));
	string cache_dir = builtin__string_plus_many(2, _MOV((string[2]){cfg.prefix, _S("/cache")}));
	_result_void _t6 = os__mkdir_all(cache_dir, ((os__MkdirParams){.mode = 0777,}));
	(void)_t6;
 ;
	string archive_filename = os__file_name(bin_path);
	string dest_file = builtin__string_plus_many(3, _MOV((string[3]){cache_dir, _S("/"), archive_filename}));
	builtin__print(builtin__string_plus_many(9, _MOV((string[9]){_S("  "), _const_main__c_blue, _S("[1/2]"), _const_main__c_reset, _S(" \342\254\207 Downloading from "), _const_main__c_gray, target_repo.name, _const_main__c_reset, _S("...")})));
	bool downloaded = false;
	for (int _t7 = 0; _t7 < candidate_urls.len; ++_t7) {
		string u = ((string*)candidate_urls.data)[_t7];
		if (main__download_url(u, dest_file)) {
			downloaded = true;
			break;
		}
	}
	if (!downloaded) {
		builtin__println(builtin__string_plus_many(4, _MOV((string[4]){_S(" "), _const_main__c_red, _S("FAILED"), _const_main__c_reset})));
		builtin__eprintln(builtin__string_plus_many(7, _MOV((string[7]){_const_main__c_red, _S("\342\234\227 Failed to download "), target_pkg.name, _S(" from repository "), target_repo.name, _S("."), _const_main__c_reset})));
		return 1;
	}
	builtin__println(builtin__string_plus_many(4, _MOV((string[4]){_S(" "), _const_main__c_green, _S("DONE"), _const_main__c_reset})));
	int res = main__deploy_package_payload(cfg, dest_file, target_pkg);
	_result_void _t9 = os__rm(dest_file);
	(void)_t9;
 ;
	return res;
}
VV_LOC int main__cmd_install_local_file(main__Config cfg, string file_path) {
	if (!os__exists(file_path)) {
		builtin__eprintln(builtin__string_plus_many(4, _MOV((string[4]){_const_main__c_red, _S("\342\234\227 File not found: "), file_path, _const_main__c_reset})));
		return 1;
	}
	string base = builtin__string_trim_string_right(builtin__string_trim_string_right(os__file_name(file_path), _S(".ngpkg")), _S(".tar.gz"));
	main__Package _t2 = ((main__Package){
		.name = base,
		.version = _S("local"),
		.arch = _S("armv7l"),
		.size = main__format_bytes(((u64)(os__file_size(file_path)))),
		.size_bytes = 0,
		.description = _S("Custom local package"),
		.category = _S("custom"),
		.bin = (string){.str=(byteptr)"", .is_lit=1},
		.src = (string){.str=(byteptr)"", .is_lit=1},
		.pkg_type = _S("archive"),
		.repo_name = _S("local"),
	});
	main__Package pkg = _t2;
	builtin__println(builtin__string_plus_many(8, _MOV((string[8]){_const_main__c_cyan, _S("\342\227\210"), _const_main__c_reset, _S(" Installing local package file: "), _const_main__c_bold, file_path, _const_main__c_reset, _S("...")})));
	return main__deploy_package_payload(cfg, file_path, pkg);
}
VV_LOC int main__deploy_package_payload(main__Config cfg, string payload_file, main__Package pkg) {
	builtin__print(builtin__string_plus_many(9, _MOV((string[9]){_S("  "), _const_main__c_blue, _S("[2/2]"), _const_main__c_reset, _S(" \360\237\223\246 Deploying to "), _const_main__c_bold, cfg.prefix, _const_main__c_reset, _S(" & establishing links...")})));
	_result_void _t1 = os__mkdir_all(cfg.prefix, ((os__MkdirParams){.mode = 0777,}));
	(void)_t1;
 ;
	_result_void _t2 = os__mkdir_all(builtin__string_plus_many(2, _MOV((string[2]){cfg.prefix, _S("/bin")})), ((os__MkdirParams){.mode = 0777,}));
	(void)_t2;
 ;
	_result_void _t3 = os__mkdir_all(builtin__string_plus_many(2, _MOV((string[2]){cfg.prefix, _S("/sbin")})), ((os__MkdirParams){.mode = 0777,}));
	(void)_t3;
 ;
	_result_void _t4 = os__mkdir_all(builtin__string_plus_many(2, _MOV((string[2]){cfg.prefix, _S("/lib")})), ((os__MkdirParams){.mode = 0777,}));
	(void)_t4;
 ;
	_result_void _t5 = os__mkdir_all(builtin__string_plus_many(2, _MOV((string[2]){cfg.prefix, _S("/etc")})), ((os__MkdirParams){.mode = 0777,}));
	(void)_t5;
 ;
	_result_void _t6 = os__mkdir_all(builtin__string_plus_many(2, _MOV((string[2]){cfg.prefix, _S("/share")})), ((os__MkdirParams){.mode = 0777,}));
	(void)_t6;
 ;
	_result_void _t7 = os__mkdir_all(builtin__string_plus_many(2, _MOV((string[2]){cfg.prefix, _S("/var/lib/ngpkg/installed")})), ((os__MkdirParams){.mode = 0777,}));
	(void)_t7;
 ;
	_result_void _t8 = os__mkdir_all(builtin__string_plus_many(2, _MOV((string[2]){cfg.db_dir, _S("/installed")})), ((os__MkdirParams){.mode = 0777,}));
	(void)_t8;
 ;
	Array_string installed_files = builtin____new_array_with_default(0, 0, sizeof(string), 0);
	bool is_archive = builtin__string_ends_with(payload_file, _S(".tar.gz")) || builtin__string_ends_with(payload_file, _S(".tgz")) || builtin__string_ends_with(payload_file, _S(".ngpkg")) || builtin__string_ends_with(payload_file, _S(".tar")) || builtin__string_ends_with(payload_file, _S(".tar.xz"));
	if (is_archive) {
		string list_cmd = builtin__string_plus_many(9, _MOV((string[9]){_S("(gzip -dc \""), payload_file, _S("\" 2>/dev/null || gunzip -c \""), payload_file, _S("\" 2>/dev/null || cat \""), payload_file, _S("\") | tar -tf - 2>/dev/null || tar -tf \""), payload_file, _S("\" 2>/dev/null")}));
		os__Result res_list = os__execute(list_cmd);
		if (res_list.exit_code == 0) {
			Array_string _t9 = builtin__string_split_into_lines(res_list.output);
			for (int _t10 = 0; _t10 < _t9.len; ++_t10) {
				string f = ((string*)_t9.data)[_t10];
				string trimmed = builtin__string_trim_left(builtin__string_trim_space(f), _S("./"));
				if ((trimmed).len != 0 && !builtin__string_ends_with(trimmed, _S("/"))) {
					builtin__array_push((array*)&installed_files, _MOV((string[]){ builtin__string_clone(trimmed) }));
				}
			}
		}
		string unpack_cmd = builtin__string_plus_many(13, _MOV((string[13]){_S("(gzip -dc \""), payload_file, _S("\" 2>/dev/null || gunzip -c \""), payload_file, _S("\" 2>/dev/null || cat \""), payload_file, _S("\") | tar -xf - -C \""), cfg.prefix, _S("\" 2>/dev/null || tar -xf \""), payload_file, _S("\" -C \""), cfg.prefix, _S("\" 2>/dev/null")}));
		os__Result unpack_res = os__execute(unpack_cmd);
		if (unpack_res.exit_code != 0) {
			builtin__println(builtin__string_plus_many(4, _MOV((string[4]){_S(" "), _const_main__c_red, _S("FAILED"), _const_main__c_reset})));
			builtin__eprintln(builtin__string_plus_many(5, _MOV((string[5]){_const_main__c_red, _S("\342\234\227 Failed to unpack payload archive to "), cfg.prefix, _S("."), _const_main__c_reset})));
			return 1;
		}
	} else {
		string bin_dest = builtin__string_plus_many(3, _MOV((string[3]){cfg.prefix, _S("/bin/"), pkg.name}));
		_result_void _t13 = os__cp(payload_file, bin_dest, ((os__CopyParams){.fail_if_exists = 0,}));
		if (_t13.is_error) {
			builtin__println(builtin__string_plus_many(4, _MOV((string[4]){_S(" "), _const_main__c_red, _S("FAILED"), _const_main__c_reset})));
			builtin__eprintln(builtin__string_plus_many(5, _MOV((string[5]){_const_main__c_red, _S("\342\234\227 Failed to copy binary to "), bin_dest, _S("."), _const_main__c_reset})));
			return 1;
		}
		
 ;
		_result_void _t15 = os__chmod(bin_dest, 0755);
		(void)_t15;
 ;
		builtin__array_push((array*)&installed_files, _MOV((string[]){ builtin__string_plus_many(2, _MOV((string[2]){_S("bin/"), pkg.name})) }));
	}
	string homedir = ((os__getenv(_S("HOME"))).len != 0 ? (os__getenv(_S("HOME"))) : (_S("/root")));
	string ngpkg_bin = builtin__string_plus_many(2, _MOV((string[2]){homedir, _S("/.ngpkg-bin")}));
	_result_void _t17 = os__mkdir_all(ngpkg_bin, ((os__MkdirParams){.mode = 0777,}));
	(void)_t17;
 ;
	if (_SLIT_NE(homedir.str, homedir.len, "/root")) {
		_result_void _t18 = os__mkdir_all(_S("/root/.ngpkg-bin"), ((os__MkdirParams){.mode = 0777,}));
		(void)_t18;
 ;
	}
	Array_string service_units = builtin____new_array_with_default(0, 0, sizeof(string), 0);
	for (int _t19 = 0; _t19 < installed_files.len; ++_t19) {
		string f = ((string*)installed_files.data)[_t19];
		string full = builtin__string_plus_many(3, _MOV((string[3]){cfg.prefix, _S("/"), f}));
		if (builtin__string_starts_with(f, _S("bin/"))) {
			string b_name = builtin__string_all_after(f, _S("bin/"));
			if (!builtin__string_contains(b_name, _S("/"))) {
				_result_void _t20 = os__chmod(full, 0755);
				(void)_t20;
 ;
				string sym = builtin__string_plus_many(3, _MOV((string[3]){ngpkg_bin, _S("/"), b_name}));
				if (!os__exists(sym) && !os__is_link(sym)) {
					_result_void _t21 = os__symlink(full, sym);
					(void)_t21;
 ;
				}
				if (_SLIT_NE(homedir.str, homedir.len, "/root") && !os__exists(builtin__string_plus_many(2, _MOV((string[2]){_S("/root/.ngpkg-bin/"), b_name}))) && !os__is_link(builtin__string_plus_many(2, _MOV((string[2]){_S("/root/.ngpkg-bin/"), b_name})))) {
					_result_void _t22 = os__symlink(full, builtin__string_plus_many(2, _MOV((string[2]){_S("/root/.ngpkg-bin/"), b_name})));
					(void)_t22;
 ;
				}
			}
		} else if (builtin__string_starts_with(f, _S("sbin/"))) {
			string b_name = builtin__string_all_after(f, _S("sbin/"));
			if (!builtin__string_contains(b_name, _S("/"))) {
				_result_void _t23 = os__chmod(full, 0755);
				(void)_t23;
 ;
				string sym = builtin__string_plus_many(3, _MOV((string[3]){ngpkg_bin, _S("/"), b_name}));
				if (!os__exists(sym) && !os__is_link(sym)) {
					_result_void _t24 = os__symlink(full, sym);
					(void)_t24;
 ;
				}
				if (_SLIT_NE(homedir.str, homedir.len, "/root") && !os__exists(builtin__string_plus_many(2, _MOV((string[2]){_S("/root/.ngpkg-bin/"), b_name}))) && !os__is_link(builtin__string_plus_many(2, _MOV((string[2]){_S("/root/.ngpkg-bin/"), b_name})))) {
					_result_void _t25 = os__symlink(full, builtin__string_plus_many(2, _MOV((string[2]){_S("/root/.ngpkg-bin/"), b_name})));
					(void)_t25;
 ;
				}
			}
		} else if (builtin__string_starts_with(f, _S("etc/systemd/system/")) && builtin__string_ends_with(f, _S(".service"))) {
			string svc_name = builtin__string_trim_string_right(builtin__string_all_after(f, _S("etc/systemd/system/")), _S(".service"));
			_result_void _t26 = os__mkdir_all(_S("/etc/systemd/system"), ((os__MkdirParams){.mode = 0777,}));
			(void)_t26;
 ;
			string dst = builtin__string_plus_many(3, _MOV((string[3]){_S("/etc/systemd/system/"), svc_name, _S(".service")}));
			if (!os__exists(dst) && !os__is_link(dst)) {
				_result_void _t27 = os__symlink(full, dst);
				(void)_t27;
 ;
			}
			builtin__array_push((array*)&service_units, _MOV((string[]){ builtin__string_clone(svc_name) }));
		}
	}
	if (os__exists(builtin__string_plus_many(3, _MOV((string[3]){cfg.prefix, _S("/bin/"), pkg.name})))) {
		string p_target = builtin__string_plus_many(3, _MOV((string[3]){cfg.prefix, _S("/bin/"), pkg.name}));
		_result_void _t29 = os__chmod(p_target, 0755);
		(void)_t29;
 ;
		if (!os__exists(builtin__string_plus_many(3, _MOV((string[3]){ngpkg_bin, _S("/"), pkg.name}))) && !os__is_link(builtin__string_plus_many(3, _MOV((string[3]){ngpkg_bin, _S("/"), pkg.name})))) {
			_result_void _t30 = os__symlink(p_target, builtin__string_plus_many(3, _MOV((string[3]){ngpkg_bin, _S("/"), pkg.name})));
			(void)_t30;
 ;
		}
		if (_SLIT_NE(homedir.str, homedir.len, "/root") && !os__exists(builtin__string_plus_many(2, _MOV((string[2]){_S("/root/.ngpkg-bin/"), pkg.name}))) && !os__is_link(builtin__string_plus_many(2, _MOV((string[2]){_S("/root/.ngpkg-bin/"), pkg.name})))) {
			_result_void _t31 = os__symlink(p_target, builtin__string_plus_many(2, _MOV((string[2]){_S("/root/.ngpkg-bin/"), pkg.name})));
			(void)_t31;
 ;
		}
	}
	if (os__exists(builtin__string_plus_many(3, _MOV((string[3]){_S("/etc/systemd/system/"), pkg.name, _S(".service")}))) && !Array_string_contains(service_units, pkg.name)) {
		builtin__array_push((array*)&service_units, _MOV((string[]){ builtin__string_clone(pkg.name) }));
	}
	if (service_units.len > 0) {
		os__execute(_S("systemctl daemon-reload 2>/dev/null || true"));
		for (int _t33 = 0; _t33 < service_units.len; ++_t33) {
			string svc = ((string*)service_units.data)[_t33];
			os__execute(builtin__string_plus_many(3, _MOV((string[3]){_S("systemctl enable "), svc, _S(" 2>/dev/null || true")})));
			os__execute(builtin__string_plus_many(3, _MOV((string[3]){_S("systemctl start "), svc, _S(" 2>/dev/null || true")})));
		}
	}
	strings__Builder receipt_content = strings__new_builder(512);
	strings__Builder_write_string(&receipt_content, _S("{\n"));
	{
		strings__Builder_write_string(&receipt_content, _S("  \"name\": \""));
		strings__Builder_write_string(&receipt_content, pkg.name);
		strings__Builder_write_string(&receipt_content, _S("\",\n"));
	}
	{
		strings__Builder_write_string(&receipt_content, _S("  \"version\": \""));
		strings__Builder_write_string(&receipt_content, pkg.version);
		strings__Builder_write_string(&receipt_content, _S("\",\n"));
	}
	{
		strings__Builder_write_string(&receipt_content, _S("  \"repo\": \""));
		strings__Builder_write_string(&receipt_content, pkg.repo_name);
		strings__Builder_write_string(&receipt_content, _S("\",\n"));
	}
	{
		strings__Builder_write_string(&receipt_content, _S("  \"description\": \""));
		strings__Builder_write_string(&receipt_content, main__json_escape(pkg.description));
		strings__Builder_write_string(&receipt_content, _S("\",\n"));
	}
	{
		strings__Builder_write_string(&receipt_content, _S("  \"category\": \""));
		strings__Builder_write_string(&receipt_content, pkg.category);
		strings__Builder_write_string(&receipt_content, _S("\",\n"));
	}
	strings__Builder_write_string(&receipt_content, _S("  \"files\": [\n"));
	for (int idx = 0; idx < installed_files.len; ++idx) {
		string f = ((string*)installed_files.data)[idx];
		string comma = (idx < installed_files.len - 1 ? (_S(",")) : (_S("")));
		{
			strings__Builder_write_string(&receipt_content, _S("    \""));
			strings__Builder_write_string(&receipt_content, f);
			strings__Builder_write_string(&receipt_content, _S("\""));
			strings__Builder_write_string(&receipt_content, comma);
			strings__Builder_write_string(&receipt_content, _S("\n"));
		}
	}
	strings__Builder_write_string(&receipt_content, _S("  ]\n}\n"));
	Array_string receipt_dests = builtin__new_array_from_c_array(2, 2, sizeof(string), _MOV((string[2]){builtin__string_plus_many(4, _MOV((string[4]){cfg.prefix, _S("/var/lib/ngpkg/installed/"), pkg.name, _S(".json")})), builtin__string_plus_many(4, _MOV((string[4]){cfg.db_dir, _S("/installed/"), pkg.name, _S(".json")}))}));
	for (int _t34 = 0; _t34 < receipt_dests.len; ++_t34) {
		string d = ((string*)receipt_dests.data)[_t34];
		_result_void _t35 = os__mkdir_all(os__dir(d), ((os__MkdirParams){.mode = 0777,}));
		(void)_t35;
 ;
		_result_void _t36 = os__write_file(d, strings__Builder_str(&receipt_content));
		(void)_t36;
 ;
	}
	string list_content = builtin__string__plus(Array_string_join(installed_files, _S("\n")), _S("\n"));
	_result_void _t37 = os__write_file(builtin__string_plus_many(4, _MOV((string[4]){cfg.prefix, _S("/var/lib/ngpkg/installed/"), pkg.name, _S(".list")})), list_content);
	(void)_t37;
 ;
	_result_void _t38 = os__write_file(builtin__string_plus_many(4, _MOV((string[4]){cfg.db_dir, _S("/installed/"), pkg.name, _S(".list")})), list_content);
	(void)_t38;
 ;
	builtin__println(builtin__string_plus_many(4, _MOV((string[4]){_S(" "), _const_main__c_green, _S("DONE"), _const_main__c_reset})));
	builtin__println(builtin__string_plus_many(10, _MOV((string[10]){_S("\n"), _const_main__c_green, _S("\342\234\223 Successfully installed "), _const_main__c_bold, pkg.name, _const_main__c_reset, _S(" ("), pkg.version, _S(")!"), _const_main__c_reset})));
	builtin__println(builtin__string_plus_many(11, _MOV((string[11]){_S("  "), _const_main__c_gray, _S("Executables:"), _const_main__c_reset, _S(" "), _const_main__c_cyan, ngpkg_bin, _S("/"), pkg.name, _const_main__c_reset, _S(" (ready to run)\n")})));
	return 0;
}
VV_LOC int main__cmd_remove(main__Config cfg, string pkg_name) {
	if (!main__is_installed(cfg, pkg_name)) {
		builtin__eprintln(builtin__string_plus_many(5, _MOV((string[5]){_const_main__c_red, _S("\342\234\227 Package \""), pkg_name, _S("\" is not installed."), _const_main__c_reset})));
		return 1;
	}
	builtin__println(builtin__string_plus_many(8, _MOV((string[8]){_const_main__c_cyan, _S("\342\227\210"), _const_main__c_reset, _S(" Removing package "), _const_main__c_bold, pkg_name, _const_main__c_reset, _S("...")})));
	os__execute(builtin__string_plus_many(3, _MOV((string[3]){_S("systemctl stop "), pkg_name, _S(" 2>/dev/null || true")})));
	os__execute(builtin__string_plus_many(3, _MOV((string[3]){_S("systemctl disable "), pkg_name, _S(" 2>/dev/null || true")})));
	string homedir = ((os__getenv(_S("HOME"))).len != 0 ? (os__getenv(_S("HOME"))) : (_S("/root")));
	string ngpkg_bin = builtin__string_plus_many(2, _MOV((string[2]){homedir, _S("/.ngpkg-bin")}));
	Array_string files_to_remove = builtin____new_array_with_default(0, 0, sizeof(string), 0);
	Array_string _t2 = main__get_installed_db_dirs(cfg);
	for (int _t3 = 0; _t3 < _t2.len; ++_t3) {
		string d = ((string*)_t2.data)[_t3];
		string json_file = builtin__string_plus_many(4, _MOV((string[4]){d, _S("/"), pkg_name, _S(".json")}));
		if (os__exists(json_file)) {
			_result_string _t4 = os__read_file(json_file);
			if (_t4.is_error) {
				*(string*) _t4.data = _S("");
			}
			
 			string content = (*(string*)_t4.data);
			if (builtin__string_contains(content, _S("\"files\""))) {
				string files_part = builtin__string_all_before(builtin__string_all_after(builtin__string_all_after(content, _S("\"files\"")), _S("[")), _S("]"));
				Array_string _t5 = builtin__string_split_into_lines(files_part);
				for (int _t6 = 0; _t6 < _t5.len; ++_t6) {
					string line = ((string*)_t5.data)[_t6];
					string trimmed = builtin__string_trim(builtin__string_trim_space(line), _S("\","));
					if ((trimmed).len != 0) {
						builtin__array_push((array*)&files_to_remove, _MOV((string[]){ builtin__string_clone(trimmed) }));
					}
				}
			}
			break;
		}
		string list_file = builtin__string_plus_many(4, _MOV((string[4]){d, _S("/"), pkg_name, _S(".list")}));
		if (os__exists(list_file)) {
			_result_Array_string _t8 = os__read_lines(list_file);
			if (_t8.is_error) {
				*(Array_string*) _t8.data = builtin____new_array_with_default(0, 0, sizeof(string), 0);
			}
			
 			Array_string lines = (*(Array_string*)_t8.data);
			for (int _t9 = 0; _t9 < lines.len; ++_t9) {
				string l = ((string*)lines.data)[_t9];
				string trimmed = builtin__string_trim_space(l);
				if ((trimmed).len != 0) {
					builtin__array_push((array*)&files_to_remove, _MOV((string[]){ builtin__string_clone(trimmed) }));
				}
			}
			break;
		}
	}
	if (files_to_remove.len == 0) {
		builtin__array_push((array*)&files_to_remove, _MOV((string[]){ builtin__string_plus_many(2, _MOV((string[2]){_S("bin/"), pkg_name})) }));
	}
	for (int _t12 = 0; _t12 < files_to_remove.len; ++_t12) {
		string f = ((string*)files_to_remove.data)[_t12];
		string full = builtin__string_plus_many(3, _MOV((string[3]){cfg.prefix, _S("/"), f}));
		if (os__is_file(full) || os__is_link(full)) {
			_result_void _t13 = os__rm(full);
			(void)_t13;
 ;
		}
		if (builtin__string_starts_with(f, _S("bin/"))) {
			string b_name = builtin__string_all_after(f, _S("bin/"));
			_result_void _t14 = os__rm(builtin__string_plus_many(3, _MOV((string[3]){ngpkg_bin, _S("/"), b_name})));
			(void)_t14;
 ;
			if (_SLIT_NE(homedir.str, homedir.len, "/root")) {
				_result_void _t15 = os__rm(builtin__string_plus_many(2, _MOV((string[2]){_S("/root/.ngpkg-bin/"), b_name})));
				(void)_t15;
 ;
			}
		} else if (builtin__string_starts_with(f, _S("sbin/"))) {
			string b_name = builtin__string_all_after(f, _S("sbin/"));
			_result_void _t16 = os__rm(builtin__string_plus_many(3, _MOV((string[3]){ngpkg_bin, _S("/"), b_name})));
			(void)_t16;
 ;
			if (_SLIT_NE(homedir.str, homedir.len, "/root")) {
				_result_void _t17 = os__rm(builtin__string_plus_many(2, _MOV((string[2]){_S("/root/.ngpkg-bin/"), b_name})));
				(void)_t17;
 ;
			}
		} else if (builtin__string_starts_with(f, _S("etc/systemd/system/"))) {
			string svc_file = builtin__string_all_after(f, _S("etc/systemd/system/"));
			_result_void _t18 = os__rm(builtin__string_plus_many(2, _MOV((string[2]){_S("/etc/systemd/system/"), svc_file})));
			(void)_t18;
 ;
		}
	}
	_result_void _t19 = os__rm(builtin__string_plus_many(3, _MOV((string[3]){ngpkg_bin, _S("/"), pkg_name})));
	(void)_t19;
 ;
	if (_SLIT_NE(homedir.str, homedir.len, "/root")) {
		_result_void _t20 = os__rm(builtin__string_plus_many(2, _MOV((string[2]){_S("/root/.ngpkg-bin/"), pkg_name})));
		(void)_t20;
 ;
	}
	Array_string _t21 = main__get_installed_db_dirs(cfg);
	for (int _t22 = 0; _t22 < _t21.len; ++_t22) {
		string d = ((string*)_t21.data)[_t22];
		_result_void _t23 = os__rm(builtin__string_plus_many(4, _MOV((string[4]){d, _S("/"), pkg_name, _S(".json")})));
		(void)_t23;
 ;
		_result_void _t24 = os__rm(builtin__string_plus_many(4, _MOV((string[4]){d, _S("/"), pkg_name, _S(".list")})));
		(void)_t24;
 ;
		_result_void _t25 = os__rm(builtin__string_plus_many(4, _MOV((string[4]){d, _S("/"), pkg_name, _S(".meta")})));
		(void)_t25;
 ;
	}
	os__execute(_S("systemctl daemon-reload 2>/dev/null || true"));
	builtin__println(builtin__string_plus_many(6, _MOV((string[6]){_const_main__c_green, _S("\342\234\223 Package \""), pkg_name, _S("\" removed successfully."), _const_main__c_reset, _S("\n")})));
	return 0;
}
VV_LOC int main__cmd_repo_list(main__Config cfg, bool json_mode) {
	if (json_mode) {
		Array_string items = builtin____new_array_with_default(0, 0, sizeof(string), 0);
		for (int _t1 = 0; _t1 < cfg.repos.len; ++_t1) {
			main__Repo r = ((main__Repo*)cfg.repos.data)[_t1];
			string cache_file = builtin__string_plus_many(4, _MOV((string[4]){cfg.db_dir, _S("/repos/"), r.name, _S("/index.json")}));
			int count = 0;
			if (os__exists(cache_file)) {
				_result_string _t2 = os__read_file(cache_file);
				if (_t2.is_error) {
					*(string*) _t2.data = _S("");
				}
				
 				string c = (*(string*)_t2.data);
				Array_main__Package pkgs = main__parse_index_json(c, r.name);
				count = pkgs.len;
			}
			builtin__array_push((array*)&items, _MOV((string[]){ builtin__string_plus_many(9, _MOV((string[9]){_S("{\"name\":\""), r.name, _S("\",\"url\":\""), r.url, _S("\",\"raw_url\":\""), r.raw_url, _S("\",\"packages\":"), builtin__int_str(count), _S("}")})) }));
		}
		builtin__println(builtin__string_plus_many(3, _MOV((string[3]){_S("["), Array_string_join(items, _S(",")), _S("]")})));
		return 0;
	}
	builtin__println(builtin__string_plus_many(3, _MOV((string[3]){_const_main__c_bold, _S("Configured OpenNGFW Repositories:"), _const_main__c_reset})));
	builtin__println(builtin__string_plus_many(3, _MOV((string[3]){_const_main__c_gray, _S("\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200"), _const_main__c_reset})));
	string h_name = main__pad_right(_S("NAME"), 14);
	string h_pkgs = main__pad_right(_S("PACKAGES"), 10);
	builtin__println(builtin__string_plus_many(7, _MOV((string[7]){_S("  "), _const_main__c_bold, h_name, _S(" "), h_pkgs, _S(" URL"), _const_main__c_reset})));
	builtin__println(builtin__string_plus_many(3, _MOV((string[3]){_const_main__c_gray, _S("\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200"), _const_main__c_reset})));
	for (int _t5 = 0; _t5 < cfg.repos.len; ++_t5) {
		main__Repo r = ((main__Repo*)cfg.repos.data)[_t5];
		string cache_file = builtin__string_plus_many(4, _MOV((string[4]){cfg.db_dir, _S("/repos/"), r.name, _S("/index.json")}));
		int count = 0;
		if (os__exists(cache_file)) {
			_result_string _t6 = os__read_file(cache_file);
			if (_t6.is_error) {
				*(string*) _t6.data = _S("");
			}
			
 			string c = (*(string*)_t6.data);
			Array_main__Package pkgs = main__parse_index_json(c, r.name);
			count = pkgs.len;
		}
		string name_fmt = builtin__string_plus_many(4, _MOV((string[4]){_const_main__c_purple, _const_main__c_bold, main__pad_right(r.name, 14), _const_main__c_reset}));
		string pkgs_fmt = builtin__string_plus_many(3, _MOV((string[3]){_const_main__c_cyan, main__pad_right(builtin__int_str(count), 10), _const_main__c_reset}));
		builtin__println(builtin__string_plus_many(6, _MOV((string[6]){_S("  "), name_fmt, _S(" "), pkgs_fmt, _S(" "), r.url})));
	}
	builtin__println(builtin__string_plus_many(4, _MOV((string[4]){_const_main__c_gray, _S("\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200"), _const_main__c_reset, _S("\n")})));
	return 0;
}
VV_LOC int main__cmd_repo_add(main__Config* cfg, string name, string url) {
	if ((name).len == 0 || (url).len == 0) {
		builtin__eprintln(builtin__string_plus_many(3, _MOV((string[3]){_const_main__c_red, _S("Usage: pkg repo add <name> <git-or-raw-url>"), _const_main__c_reset})));
		return 1;
	}
	for (int _t2 = 0; _t2 < cfg->repos.len; ++_t2) {
		main__Repo* r = ((main__Repo*)cfg->repos.data) + _t2;
		if (builtin__string__eq(r->name, name)) {
			builtin__println(builtin__string_plus_many(5, _MOV((string[5]){_const_main__c_yellow, _S("[*] Updating existing repository \""), name, _S("\"..."), _const_main__c_reset})));
			r->url = url;
			r->raw_url = main__normalize_repo_url(url);
			main__save_repos_config(*cfg);
			return main__cmd_update(*cfg);
		}
	}
	string raw = main__normalize_repo_url(url);
	builtin__array_push((array*)&cfg->repos, _MOV((main__Repo[]){ ((main__Repo){.name = name,.url = url,.raw_url = raw,.package_count = 0,}) }));
	main__save_repos_config(*cfg);
	builtin__println(builtin__string_plus_many(6, _MOV((string[6]){_const_main__c_green, _S("\342\234\223 Added repository \""), name, _S("\": "), url, _const_main__c_reset})));
	builtin__println(builtin__string_plus_many(7, _MOV((string[7]){_S("  "), _const_main__c_gray, _S("Raw URL:"), _const_main__c_reset, _S(" "), raw, _S("\n")})));
	return main__cmd_update(*cfg);
}
VV_LOC int main__cmd_repo_remove(main__Config* cfg, string name) {
	if ((name).len == 0) {
		builtin__eprintln(builtin__string_plus_many(3, _MOV((string[3]){_const_main__c_red, _S("Usage: pkg repo remove <name>"), _const_main__c_reset})));
		return 1;
	}
	int idx = -1;
	for (int i = 0; i < cfg->repos.len; ++i) {
		main__Repo r = ((main__Repo*)cfg->repos.data)[i];
		if (builtin__string__eq(r.name, name)) {
			idx = i;
			break;
		}
	}
	if (idx == -1) {
		builtin__eprintln(builtin__string_plus_many(5, _MOV((string[5]){_const_main__c_red, _S("\342\234\227 Repository \""), name, _S("\" not found in configuration."), _const_main__c_reset})));
		return 1;
	}
	builtin__array_delete(&cfg->repos, idx);
	main__save_repos_config(*cfg);
	_result_void _t3 = os__rmdir_all(builtin__string_plus_many(3, _MOV((string[3]){cfg->db_dir, _S("/repos/"), name})));
	(void)_t3;
 ;
	_result_void _t4 = os__rmdir_all(builtin__string_plus_many(3, _MOV((string[3]){cfg->prefix, _S("/var/lib/ngpkg/repos/"), name})));
	(void)_t4;
 ;
	builtin__println(builtin__string_plus_many(6, _MOV((string[6]){_const_main__c_green, _S("\342\234\223 Removed repository \""), name, _S("\"."), _const_main__c_reset, _S("\n")})));
	return 0;
}
VV_LOC int main__cmd_status(main__Config cfg) {
	Array_string installed = main__get_installed_packages(cfg);
	string homedir = ((os__getenv(_S("HOME"))).len != 0 ? (os__getenv(_S("HOME"))) : (_S("/root")));
	builtin__println(builtin__string_plus_many(3, _MOV((string[3]){_const_main__c_cyan, _S("\342\225\255\342\224\200 System & Storage Status \342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\225\256"), _const_main__c_reset})));
	builtin__println(builtin__string_plus_many(13, _MOV((string[13]){_const_main__c_cyan, _S("\342\224\202"), _const_main__c_reset, _S("  "), _const_main__c_gray, _S("Package Manager:"), _const_main__c_reset, _S(" "), _const_main__c_bold, _S("ngpkg v"), _const_main__version, _const_main__c_reset, _S(" (Serverless Edition)")})));
	builtin__println(builtin__string_plus_many(10, _MOV((string[10]){_const_main__c_cyan, _S("\342\224\202"), _const_main__c_reset, _S("  "), _const_main__c_gray, _S("Repositories:"), _const_main__c_reset, _S("    "), builtin__int_str(cfg.repos.len), _S(" configured")})));
	for (int _t1 = 0; _t1 < cfg.repos.len; ++_t1) {
		main__Repo r = ((main__Repo*)cfg.repos.data)[_t1];
		builtin__println(builtin__string_plus_many(11, _MOV((string[11]){_const_main__c_cyan, _S("\342\224\202"), _const_main__c_reset, _S("    "), _const_main__c_purple, _S("\342\200\242 "), r.name, _S(":"), _const_main__c_reset, _S(" "), r.url})));
	}
	builtin__println(builtin__string_plus_many(9, _MOV((string[9]){_const_main__c_cyan, _S("\342\224\202"), _const_main__c_reset, _S("  "), _const_main__c_gray, _S("Install Root:"), _const_main__c_reset, _S("    "), cfg.prefix})));
	builtin__println(builtin__string_plus_many(10, _MOV((string[10]){_const_main__c_cyan, _S("\342\224\202"), _const_main__c_reset, _S("  "), _const_main__c_gray, _S("User Binaries:"), _const_main__c_reset, _S("   "), homedir, _S("/.ngpkg-bin")})));
	builtin__println(builtin__string_plus_many(12, _MOV((string[12]){_const_main__c_cyan, _S("\342\224\202"), _const_main__c_reset, _S("  "), _const_main__c_gray, _S("Installed:"), _const_main__c_reset, _S("       "), _const_main__c_green, builtin__int_str(installed.len), _S(" packages"), _const_main__c_reset})));
	os__Result df_res = os__execute(builtin__string_plus_many(3, _MOV((string[3]){_S("df -h \""), cfg.prefix, _S("\" 2>/dev/null | tail -n 1")})));
	if (df_res.exit_code == 0 && (builtin__string_trim_space(df_res.output)).len != 0) {
		Array_string fields = builtin__string_fields(df_res.output);
		if (fields.len >= 5) {
			string total = (*(string*)builtin__array_get(fields, 1));
			string used = (*(string*)builtin__array_get(fields, 2));
			string avail = (*(string*)builtin__array_get(fields, 3));
			string percent = (*(string*)builtin__array_get(fields, 4));
			builtin__println(builtin__string_plus_many(3, _MOV((string[3]){_const_main__c_cyan, _S("\342\224\202"), _const_main__c_reset})));
			builtin__println(builtin__string_plus_many(9, _MOV((string[9]){_const_main__c_cyan, _S("\342\224\202"), _const_main__c_reset, _S("  "), _const_main__c_bold, _S("USB Storage ("), cfg.prefix, _S("):"), _const_main__c_reset})));
			builtin__println(builtin__string_plus_many(11, _MOV((string[11]){_const_main__c_cyan, _S("\342\224\202"), _const_main__c_reset, _S("    Total: "), total, _S("  \342\200\242  Used: "), used, _S(" ("), percent, _S(")  \342\200\242  Free: "), avail})));
		}
	}
	builtin__println(builtin__string_plus_many(2, _MOV((string[2]){_const_main__c_cyan, _S("\342\225\260\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\225\257\n")})));
	return 0;
}
VV_LOC void main__print_help(void) {
	main__print_banner();
	builtin__println(builtin__string_plus_many(3, _MOV((string[3]){_const_main__c_bold, _S("USAGE:"), _const_main__c_reset})));
	builtin__println(_S("  pkg <command> [arguments]\n"));
	builtin__println(builtin__string_plus_many(3, _MOV((string[3]){_const_main__c_bold, _S("COMMANDS:"), _const_main__c_reset})));
	builtin__println(builtin__string_plus_many(5, _MOV((string[5]){_S("  "), _const_main__c_cyan, _S("update"), _const_main__c_reset, _S("                      Sync latest package indexes from all git repos")})));
	builtin__println(builtin__string_plus_many(5, _MOV((string[5]){_S("  "), _const_main__c_cyan, _S("list"), _const_main__c_reset, _S(" [--json]               List all available & installed packages")})));
	builtin__println(builtin__string_plus_many(5, _MOV((string[5]){_S("  "), _const_main__c_cyan, _S("search"), _const_main__c_reset, _S(" <query>              Search packages by name, description, or category")})));
	builtin__println(builtin__string_plus_many(5, _MOV((string[5]){_S("  "), _const_main__c_cyan, _S("info"), _const_main__c_reset, _S(" <package>              Inspect package details, source & binary paths")})));
	builtin__println(builtin__string_plus_many(5, _MOV((string[5]){_S("  "), _const_main__c_cyan, _S("install"), _const_main__c_reset, _S(" <pkg|file>          Install package from repo or local archive")})));
	builtin__println(builtin__string_plus_many(5, _MOV((string[5]){_S("  "), _const_main__c_cyan, _S("remove"), _const_main__c_reset, _S(" <package>            Uninstall an application and clean symlinks/services")})));
	builtin__println(builtin__string_plus_many(5, _MOV((string[5]){_S("  "), _const_main__c_cyan, _S("repo list"), _const_main__c_reset, _S(" [--json]          List configured serverless repositories")})));
	builtin__println(builtin__string_plus_many(5, _MOV((string[5]){_S("  "), _const_main__c_cyan, _S("repo add"), _const_main__c_reset, _S(" <name> <url>       Add a new Git repository (GitHub/GitLab/etc.)")})));
	builtin__println(builtin__string_plus_many(5, _MOV((string[5]){_S("  "), _const_main__c_cyan, _S("repo remove"), _const_main__c_reset, _S(" <name>          Remove a configured repository")})));
	builtin__println(builtin__string_plus_many(5, _MOV((string[5]){_S("  "), _const_main__c_cyan, _S("status"), _const_main__c_reset, _S("                      Display repositories, installed count & storage")})));
	builtin__println(builtin__string_plus_many(5, _MOV((string[5]){_S("  "), _const_main__c_cyan, _S("help"), _const_main__c_reset, _S("                        Show this reference manual\n")})));
	builtin__println(builtin__string_plus_many(3, _MOV((string[3]){_const_main__c_bold, _S("EXAMPLES:"), _const_main__c_reset})));
	builtin__println(_S("  pkg update"));
	builtin__println(_S("  pkg repo add custom https://github.com/myuser/my-openngfw-packages"));
	builtin__println(_S("  pkg list"));
	builtin__println(_S("  pkg install nano"));
	builtin__println(_S("  pkg remove nano\n"));
}
VV_LOC void main__main(void) {
	Array_string args = builtin__array_slice(_const_os__args, 1, 2147483647);
	if (args.len == 0) {
		main__print_help();
		return;
	}
	string cmd = (*(string*)builtin__array_get(args, 0));
	main__Config cfg = main__load_config();

	if (_SLIT_EQ(cmd.str, cmd.len, "update") || _SLIT_EQ(cmd.str, cmd.len, "sync") || _SLIT_EQ(cmd.str, cmd.len, "refresh")) {
		builtin___v_exit(main__cmd_update(cfg));
		VUNREACHABLE();
	}
	else if (_SLIT_EQ(cmd.str, cmd.len, "list") || _SLIT_EQ(cmd.str, cmd.len, "ls")) {
		bool json_mode = Array_string_contains(args, _S("--json")) || Array_string_contains(args, _S("-j"));
		builtin___v_exit(main__cmd_list(cfg, json_mode));
		VUNREACHABLE();
	}
	else if (_SLIT_EQ(cmd.str, cmd.len, "search") || _SLIT_EQ(cmd.str, cmd.len, "find")) {
		if (args.len < 2) {
			builtin__eprintln(builtin__string_plus_many(3, _MOV((string[3]){_const_main__c_red, _S("Usage: pkg search <query>"), _const_main__c_reset})));
			builtin___v_exit(1);
			VUNREACHABLE();
		}
		builtin___v_exit(main__cmd_search(cfg, (*(string*)builtin__array_get(args, 1))));
		VUNREACHABLE();
	}
	else if (_SLIT_EQ(cmd.str, cmd.len, "info") || _SLIT_EQ(cmd.str, cmd.len, "show")) {
		if (args.len < 2) {
			builtin__eprintln(builtin__string_plus_many(3, _MOV((string[3]){_const_main__c_red, _S("Usage: pkg info <package>"), _const_main__c_reset})));
			builtin___v_exit(1);
			VUNREACHABLE();
		}
		builtin___v_exit(main__cmd_info(cfg, (*(string*)builtin__array_get(args, 1))));
		VUNREACHABLE();
	}
	else if (_SLIT_EQ(cmd.str, cmd.len, "install") || _SLIT_EQ(cmd.str, cmd.len, "i") || _SLIT_EQ(cmd.str, cmd.len, "add") || _SLIT_EQ(cmd.str, cmd.len, "get")) {
		if (args.len < 2) {
			builtin__eprintln(builtin__string_plus_many(3, _MOV((string[3]){_const_main__c_red, _S("Usage: pkg install <package|path/to/package>"), _const_main__c_reset})));
			builtin___v_exit(1);
			VUNREACHABLE();
		}
		builtin___v_exit(main__cmd_install(cfg, (*(string*)builtin__array_get(args, 1))));
		VUNREACHABLE();
	}
	else if (_SLIT_EQ(cmd.str, cmd.len, "remove") || _SLIT_EQ(cmd.str, cmd.len, "uninstall") || _SLIT_EQ(cmd.str, cmd.len, "rm") || _SLIT_EQ(cmd.str, cmd.len, "delete")) {
		if (args.len < 2) {
			builtin__eprintln(builtin__string_plus_many(3, _MOV((string[3]){_const_main__c_red, _S("Usage: pkg remove <package>"), _const_main__c_reset})));
			builtin___v_exit(1);
			VUNREACHABLE();
		}
		builtin___v_exit(main__cmd_remove(cfg, (*(string*)builtin__array_get(args, 1))));
		VUNREACHABLE();
	}
	else if (_SLIT_EQ(cmd.str, cmd.len, "repo") || _SLIT_EQ(cmd.str, cmd.len, "repos")) {
		if (args.len < 2 || builtin__string__eq((*(string*)builtin__array_get(args, 1)), _S("list")) || builtin__string__eq((*(string*)builtin__array_get(args, 1)), _S("ls"))) {
			bool json_mode = Array_string_contains(args, _S("--json")) || Array_string_contains(args, _S("-j"));
			builtin___v_exit(main__cmd_repo_list(cfg, json_mode));
			VUNREACHABLE();
		}
		string sub = (*(string*)builtin__array_get(args, 1));
		if (_SLIT_EQ(sub.str, sub.len, "add")) {
			if (args.len < 4) {
				builtin__eprintln(builtin__string_plus_many(3, _MOV((string[3]){_const_main__c_red, _S("Usage: pkg repo add <name> <git-or-raw-url>"), _const_main__c_reset})));
				builtin___v_exit(1);
				VUNREACHABLE();
			}
			builtin___v_exit(main__cmd_repo_add((voidptr)&cfg, (*(string*)builtin__array_get(args, 2)), (*(string*)builtin__array_get(args, 3))));
			VUNREACHABLE();
		} else if (_SLIT_EQ(sub.str, sub.len, "remove") || _SLIT_EQ(sub.str, sub.len, "rm") || _SLIT_EQ(sub.str, sub.len, "del") || _SLIT_EQ(sub.str, sub.len, "delete")) {
			if (args.len < 3) {
				builtin__eprintln(builtin__string_plus_many(3, _MOV((string[3]){_const_main__c_red, _S("Usage: pkg repo remove <name>"), _const_main__c_reset})));
				builtin___v_exit(1);
				VUNREACHABLE();
			}
			builtin___v_exit(main__cmd_repo_remove((voidptr)&cfg, (*(string*)builtin__array_get(args, 2))));
			VUNREACHABLE();
		} else {
			builtin__eprintln(builtin__string_plus_many(5, _MOV((string[5]){_const_main__c_red, _S("Unknown repo command: "), sub, _S(". Available: list, add, remove"), _const_main__c_reset})));
			builtin___v_exit(1);
			VUNREACHABLE();
		}
	}
	else if (_SLIT_EQ(cmd.str, cmd.len, "status") || _SLIT_EQ(cmd.str, cmd.len, "stat") || _SLIT_EQ(cmd.str, cmd.len, "df")) {
		builtin___v_exit(main__cmd_status(cfg));
		VUNREACHABLE();
	}
	else if (_SLIT_EQ(cmd.str, cmd.len, "help") || _SLIT_EQ(cmd.str, cmd.len, "--help") || _SLIT_EQ(cmd.str, cmd.len, "-h")) {
		main__print_help();
		builtin___v_exit(0);
		VUNREACHABLE();
	}
	else if (_SLIT_EQ(cmd.str, cmd.len, "version") || _SLIT_EQ(cmd.str, cmd.len, "--version") || _SLIT_EQ(cmd.str, cmd.len, "-v")) {
		builtin__println(builtin__string_plus_many(3, _MOV((string[3]){_S("ngpkg version "), _const_main__version, _S(" (Serverless Edition)")})));
		builtin___v_exit(0);
		VUNREACHABLE();
	}
	else {
		builtin__eprintln(builtin__string_plus_many(5, _MOV((string[5]){_const_main__c_red, _S("Unknown command: \""), cmd, _S("\""), _const_main__c_reset})));
		builtin__eprintln(builtin__string_plus_many(5, _MOV((string[5]){_S("Run "), _const_main__c_bold, _S("pkg help"), _const_main__c_reset, _S(" for available commands.")})));
		builtin___v_exit(1);
		VUNREACHABLE();
	}
}
void _vinit(int ___argc, voidptr ___argv) {
	static bool once = false; if (once) {return;} once = true;
#if __STDC_HOSTED__ == 1
	signal(11, builtin__v_segmentation_fault_handler);
#endif
	builtin__builtin_init();
	// Initializations of consts for module strconv
	_const_strconv__digit_pairs = _S("00102030405060708090011121314151617181910212223242526272829203132333435363738393041424344454647484940515253545556575859506162636465666768696071727374757677787970818283848586878889809192939495969798999");
	_const_strconv__base_digits = _S("0123456789abcdefghijklmnopqrstuvwxyz");
	// Initializations of consts for module builtin
	_const_grapheme_control_ranges = _S("00000000090000000b0000000c0000000e0000001f0000007f0000009f000000ad000000ad0000001c0600001c0600000e1800000e1800000b2000000b2000000e2000000f200000282000002820000029200000292000002a2000002e20000060200000642000006520000065200000662000006f200000fffe0000fffe0000f0ff0000f8ff0000f9ff0000fbff00003034010038340100a0bc0100a3bc010073d101007ad1010000000e0000000e0001000e0001000e0002000e001f000e0080000e00ff000e00f0010e00ff0f0e00");
	_const_grapheme_extend_ranges = _S("000300006f0300008304000087040000880400008904000091050000bd050000bf050000bf050000c1050000c2050000c4050000c5050000c7050000c7050000100600001a0600004b0600005f0600007006000070060000d6060000dc060000df060000e4060000e7060000e8060000ea060000ed0600001107000011070000300700004a070000a6070000b0070000eb070000f3070000fd070000fd07000016080000190800001b080000230800002508000027080000290800002d080000590800005b080000d3080000e1080000e3080000020900003a0900003a0900003c0900003c09000041090000480900004d0900004d090000510900005709000062090000630900008109000081090000bc090000bc090000be090000be090000c1090000c4090000cd090000cd090000d7090000d7090000e2090000e3090000fe090000fe090000010a0000020a00003c0a00003c0a0000410a0000420a0000470a0000480a00004b0a00004d0a0000510a0000510a0000700a0000710a0000750a0000750a0000810a0000820a0000bc0a0000bc0a0000c10a0000c50a0000c70a0000c80a0000cd0a0000cd0a0000e20a0000e30a0000fa0a0000ff0a0000010b0000010b00003c0b00003c0b00003e0b00003e0b00003f0b00003f0b0000410b0000440b00004d0b00004d0b0000550b0000560b0000570b0000570b0000620b0000630b0000820b0000820b0000be0b0000be0b0000c00b0000c00b0000cd0b0000cd0b0000d70b0000d70b0000000c0000000c0000040c0000040c00003e0c0000400c0000460c0000480c00004a0c00004d0c0000550c0000560c0000620c0000630c0000810c0000810c0000bc0c0000bc0c0000bf0c0000bf0c0000c20c0000c20c0000c60c0000c60c0000cc0c0000cd0c0000d50c0000d60c0000e20c0000e30c0000000d0000010d00003b0d00003c0d00003e0d00003e0d0000410d0000440d00004d0d00004d0d0000570d0000570d0000620d0000630d0000810d0000810d0000ca0d0000ca0d0000cf0d0000cf0d0000d20d0000d40d0000d60d0000d60d0000df0d0000df0d0000310e0000310e0000340e00003a0e0000470e00004e0e0000b10e0000b10e0000b40e0000bc0e0000c80e0000cd0e0000180f0000190f0000350f0000350f0000370f0000370f0000390f0000390f0000710f00007e0f0000800f0000840f0000860f0000870f00008d0f0000970f0000990f0000bc0f0000c60f0000c60f00002d100000301000003210000037100000391000003a1000003d1000003e10000058100000591000005e100000601000007110000074100000821000008210000085100000861000008d1000008d1000009d1000009d1000005d1300005f1300001217000014170000321700003417000052170000531700007217000073170000b4170000b5170000b7170000bd170000c6170000c6170000c9170000d3170000dd170000dd1700000b1800000d1800008518000086180000a9180000a9180000201900002219000027190000281900003219000032190000391900003b190000171a0000181a00001b1a00001b1a0000561a0000561a0000581a00005e1a0000601a0000601a0000621a0000621a0000651a00006c1a0000731a00007c1a00007f1a00007f1a0000b01a0000bd1a0000be1a0000be1a0000bf1a0000c01a0000001b0000031b0000341b0000341b0000351b0000351b0000361b00003a1b00003c1b00003c1b0000421b0000421b00006b1b0000731b0000801b0000811b0000a21b0000a51b0000a81b0000a91b0000ab1b0000ad1b0000e61b0000e61b0000e81b0000e91b0000ed1b0000ed1b0000ef1b0000f11b00002c1c0000331c0000361c0000371c0000d01c0000d21c0000d41c0000e01c0000e21c0000e81c0000ed1c0000ed1c0000f41c0000f41c0000f81c0000f91c0000c01d0000f91d0000fb1d0000ff1d00000c2000000c200000d0200000dc200000dd200000e0200000e1200000e1200000e2200000e4200000e5200000f0200000ef2c0000f12c00007f2d00007f2d0000e02d0000ff2d00002a3000002d3000002e3000002f300000993000009a3000006fa600006fa6000070a6000072a6000074a600007da600009ea600009fa60000f0a60000f1a6000002a8000002a8000006a8000006a800000ba800000ba8000025a8000026a800002ca800002ca80000c4a80000c5a80000e0a80000f1a80000ffa80000ffa8000026a900002da9000047a9000051a9000080a9000082a90000b3a90000b3a90000b6a90000b9a90000bca90000bda90000e5a90000e5a9000029aa00002eaa000031aa000032aa000035aa000036aa000043aa000043aa00004caa00004caa00007caa00007caa0000b0aa0000b0aa0000b2aa0000b4aa0000b7aa0000b8aa0000beaa0000bfaa0000c1aa0000c1aa0000ecaa0000edaa0000f6aa0000f6aa0000e5ab0000e5ab0000e8ab0000e8ab0000edab0000edab00001efb00001efb000000fe00000ffe000020fe00002ffe00009eff00009fff0000fd010100fd010100e0020100e0020100760301007a030100010a0100030a0100050a0100060a01000c0a01000f0a0100380a01003a0a01003f0a01003f0a0100e50a0100e60a0100240d0100270d0100ab0e0100ac0e0100460f0100500f0100011001000110010038100100461001007f10010081100100b3100100b6100100b9100100ba1001000011010002110100271101002b1101002d1101003411010073110100731101008011010081110100b6110100be110100c9110100cc110100cf110100cf1101002f12010031120100341201003412010036120100371201003e1201003e120100df120100df120100e3120100ea12010000130100011301003b1301003c1301003e1301003e13010040130100401301005713010057130100661301006c1301007013010074130100381401003f140100421401004414010046140100461401005e1401005e140100b0140100b0140100b3140100b8140100ba140100ba140100bd140100bd140100bf140100c0140100c2140100c3140100af150100af150100b2150100b5150100bc150100bd150100bf150100c0150100dc150100dd150100331601003a1601003d1601003d1601003f16010040160100ab160100ab160100ad160100ad160100b0160100b5160100b7160100b71601001d1701001f1701002217010025170100271701002b1701002f18010037180100391801003a18010030190100301901003b1901003c1901003e1901003e1901004319010043190100d4190100d7190100da190100db190100e0190100e0190100011a01000a1a0100331a0100381a01003b1a01003e1a0100471a0100471a0100511a0100561a0100591a01005b1a01008a1a0100961a0100981a0100991a0100301c0100361c0100381c01003d1c01003f1c01003f1c0100921c0100a71c0100aa1c0100b01c0100b21c0100b31c0100b51c0100b61c0100311d0100361d01003a1d01003a1d01003c1d01003d1d01003f1d0100451d0100471d0100471d0100901d0100911d0100951d0100951d0100971d0100971d0100f31e0100f41e0100f06a0100f46a0100306b0100366b01004f6f01004f6f01008f6f0100926f0100e46f0100e46f01009dbc01009ebc010065d1010065d1010067d1010069d101006ed1010072d101007bd1010082d1010085d101008bd10100aad10100add1010042d2010044d2010000da010036da01003bda01006cda010075da010075da010084da010084da01009bda01009fda0100a1da0100afda010000e0010006e0010008e0010018e001001be0010021e0010023e0010024e0010026e001002ae0010030e1010036e10100ece20100efe20100d0e80100d6e8010044e901004ae90100fbf30100fff3010020000e007f000e0000010e00ef010e00");
	_const_grapheme_spacing_mark_ranges = _S("03090000030900003b0900003b0900003e09000040090000490900004c0900004e0900004f0900008209000083090000bf090000c0090000c7090000c8090000cb090000cc090000030a0000030a00003e0a0000400a0000830a0000830a0000be0a0000c00a0000c90a0000c90a0000cb0a0000cc0a0000020b0000030b0000400b0000400b0000470b0000480b00004b0b00004c0b0000bf0b0000bf0b0000c10b0000c20b0000c60b0000c80b0000ca0b0000cc0b0000010c0000030c0000410c0000440c0000820c0000830c0000be0c0000be0c0000c00c0000c10c0000c30c0000c40c0000c70c0000c80c0000ca0c0000cb0c0000020d0000030d00003f0d0000400d0000460d0000480d00004a0d00004c0d0000820d0000830d0000d00d0000d10d0000d80d0000de0d0000f20d0000f30d0000330e0000330e0000b30e0000b30e00003e0f00003f0f00007f0f00007f0f000031100000311000003b1000003c10000056100000571000008410000084100000b6170000b6170000be170000c5170000c7170000c81700002319000026190000291900002b19000030190000311900003319000038190000191a00001a1a0000551a0000551a0000571a0000571a00006d1a0000721a0000041b0000041b00003b1b00003b1b00003d1b0000411b0000431b0000441b0000821b0000821b0000a11b0000a11b0000a61b0000a71b0000aa1b0000aa1b0000e71b0000e71b0000ea1b0000ec1b0000ee1b0000ee1b0000f21b0000f31b0000241c00002b1c0000341c0000351c0000e11c0000e11c0000f71c0000f71c000023a8000024a8000027a8000027a8000080a8000081a80000b4a80000c3a8000052a9000053a9000083a9000083a90000b4a90000b5a90000baa90000bba90000bea90000c0a900002faa000030aa000033aa000034aa00004daa00004daa0000ebaa0000ebaa0000eeaa0000efaa0000f5aa0000f5aa0000e3ab0000e4ab0000e6ab0000e7ab0000e9ab0000eaab0000ecab0000ecab0000001001000010010002100100021001008210010082100100b0100100b2100100b7100100b81001002c1101002c11010045110100461101008211010082110100b3110100b5110100bf110100c0110100ce110100ce1101002c1201002e12010032120100331201003512010035120100e0120100e212010002130100031301003f1301003f130100411301004413010047130100481301004b1301004d1301006213010063130100351401003714010040140100411401004514010045140100b1140100b2140100b9140100b9140100bb140100bc140100be140100be140100c1140100c1140100b0150100b1150100b8150100bb150100be150100be15010030160100321601003b1601003c1601003e1601003e160100ac160100ac160100ae160100af160100b6160100b6160100201701002117010026170100261701002c1801002e1801003818010038180100311901003519010037190100381901003d1901003d19010040190100401901004219010042190100d1190100d3190100dc190100df190100e4190100e4190100391a0100391a0100571a0100581a0100971a0100971a01002f1c01002f1c01003e1c01003e1c0100a91c0100a91c0100b11c0100b11c0100b41c0100b41c01008a1d01008e1d0100931d0100941d0100961d0100961d0100f51e0100f61e0100516f0100876f0100f06f0100f16f010066d1010066d101006dd101006dd10100");
	_const_grapheme_prepend_ranges = _S("0006000005060000dd060000dd0600000f0700000f070000e2080000e20800004e0d00004e0d0000bd100100bd100100cd100100cd100100c2110100c31101003f1901003f19010041190100411901003a1a01003a1a0100841a0100891a0100461d0100461d0100");
	_const_grapheme_extended_pictographic_ranges = _S("a9000000a9000000ae000000ae0000003c2000003c2000004920000049200000222100002221000039210000392100009421000099210000a9210000aa2100001a2300001b23000028230000282300008823000088230000cf230000cf230000e9230000ec230000ed230000ee230000ef230000ef230000f0230000f0230000f1230000f2230000f3230000f3230000f8230000fa230000c2240000c2240000aa250000ab250000b6250000b6250000c0250000c0250000fb250000fe2500000026000001260000022600000326000004260000042600000526000005260000072600000d2600000e2600000e2600000f2600001026000011260000112600001226000012260000142600001526000016260000172600001826000018260000192600001c2600001d2600001d2600001e2600001f2600002026000020260000212600002126000022260000232600002426000025260000262600002626000027260000292600002a2600002a2600002b2600002d2600002e2600002e2600002f2600002f260000302600003726000038260000392600003a2600003a2600003b2600003f26000040260000402600004126000041260000422600004226000043260000472600004826000053260000542600005e2600005f2600005f2600006026000060260000612600006226000063260000632600006426000064260000652600006626000067260000672600006826000068260000692600007a2600007b2600007b2600007c2600007d2600007e2600007e2600007f2600007f2600008026000085260000902600009126000092260000922600009326000093260000942600009426000095260000952600009626000097260000982600009826000099260000992600009a2600009a2600009b2600009c2600009d2600009f260000a0260000a1260000a2260000a6260000a7260000a7260000a8260000a9260000aa260000ab260000ac260000af260000b0260000b1260000b2260000bc260000bd260000be260000bf260000c3260000c4260000c5260000c6260000c7260000c8260000c8260000c9260000cd260000ce260000ce260000cf260000cf260000d0260000d0260000d1260000d1260000d2260000d2260000d3260000d3260000d4260000d4260000d5260000e8260000e9260000e9260000ea260000ea260000eb260000ef260000f0260000f1260000f2260000f3260000f4260000f4260000f5260000f5260000f6260000f6260000f7260000f9260000fa260000fa260000fb260000fc260000fd260000fd260000fe26000001270000022700000227000003270000042700000527000005270000082700000c2700000d2700000d2700000e2700000e2700000f2700000f27000010270000112700001227000012270000142700001427000016270000162700001d2700001d270000212700002127000028270000282700003327000034270000442700004427000047270000472700004c2700004c2700004e2700004e270000532700005527000057270000572700006327000063270000642700006427000065270000672700009527000097270000a1270000a1270000b0270000b0270000bf270000bf2700003429000035290000052b0000072b00001b2b00001c2b0000502b0000502b0000552b0000552b000030300000303000003d3000003d3000009732000097320000993200009932000000f0010003f0010004f0010004f0010005f00100cef00100cff00100cff00100d0f00100fff001000df101000ff101002ff101002ff101006cf101006ff1010070f1010071f101007ef101007ff101008ef101008ef1010091f101009af10100adf10100e5f1010001f2010002f2010003f201000ff201001af201001af201002ff201002ff2010032f201003af201003cf201003ff2010049f201004ff2010050f2010051f2010052f20100fff2010000f301000cf301000df301000ef301000ff301000ff3010010f3010010f3010011f3010011f3010012f3010012f3010013f3010015f3010016f3010018f3010019f3010019f301001af301001af301001bf301001bf301001cf301001cf301001df301001ef301001ff3010020f3010021f3010021f3010022f3010023f3010024f301002cf301002df301002ff3010030f3010031f3010032f3010033f3010034f3010035f3010036f3010036f3010037f301004af301004bf301004bf301004cf301004ff3010050f3010050f3010051f301007bf301007cf301007cf301007df301007df301007ef301007ff3010080f3010093f3010094f3010095f3010096f3010097f3010098f3010098f3010099f301009bf301009cf301009df301009ef301009ff30100a0f30100c4f30100c5f30100c5f30100c6f30100c6f30100c7f30100c7f30100c8f30100c8f30100c9f30100c9f30100caf30100caf30100cbf30100cef30100cff30100d3f30100d4f30100dff30100e0f30100e3f30100e4f30100e4f30100e5f30100f0f30100f1f30100f2f30100f3f30100f3f30100f4f30100f4f30100f5f30100f5f30100f6f30100f6f30100f7f30100f7f30100f8f30100faf3010000f4010007f4010008f4010008f4010009f401000bf401000cf401000ef401000ff4010010f4010011f4010012f4010013f4010013f4010014f4010014f4010015f4010015f4010016f4010016f4010017f4010029f401002af401002af401002bf401003ef401003ff401003ff4010040f4010040f4010041f4010041f4010042f4010064f4010065f4010065f4010066f401006bf401006cf401006df401006ef40100acf40100adf40100adf40100aef40100b5f40100b6f40100b7f40100b8f40100ebf40100ecf40100edf40100eef40100eef40100eff40100eff40100f0f40100f4f40100f5f40100f5f40100f6f40100f7f40100f8f40100f8f40100f9f40100fcf40100fdf40100fdf40100fef40100fef40100fff4010002f5010003f5010003f5010004f5010007f5010008f5010008f5010009f5010009f501000af5010014f5010015f5010015f5010016f501002bf501002cf501002df501002ef501003df5010046f5010048f5010049f501004af501004bf501004ef501004ff501004ff5010050f501005bf501005cf5010067f5010068f501006ef501006ff5010070f5010071f5010072f5010073f5010079f501007af501007af501007bf5010086f5010087f5010087f5010088f5010089f501008af501008df501008ef501008ff5010090f5010090f5010091f5010094f5010095f5010096f5010097f50100a3f50100a4f50100a4f50100a5f50100a5f50100a6f50100a7f50100a8f50100a8f50100a9f50100b0f50100b1f50100b2f50100b3f50100bbf50100bcf50100bcf50100bdf50100c1f50100c2f50100c4f50100c5f50100d0f50100d1f50100d3f50100d4f50100dbf50100dcf50100def50100dff50100e0f50100e1f50100e1f50100e2f50100e2f50100e3f50100e3f50100e4f50100e7f50100e8f50100e8f50100e9f50100eef50100eff50100eff50100f0f50100f2f50100f3f50100f3f50100f4f50100f9f50100faf50100faf50100fbf50100fff5010000f6010000f6010001f6010006f6010007f6010008f6010009f601000df601000ef601000ef601000ff601000ff6010010f6010010f6010011f6010011f6010012f6010014f6010015f6010015f6010016f6010016f6010017f6010017f6010018f6010018f6010019f6010019f601001af601001af601001bf601001bf601001cf601001ef601001ff601001ff6010020f6010025f6010026f6010027f6010028f601002bf601002cf601002cf601002df601002df601002ef601002ff6010030f6010033f6010034f6010034f6010035f6010035f6010036f6010036f6010037f6010040f6010041f6010044f6010045f601004ff6010080f6010080f6010081f6010082f6010083f6010085f6010086f6010086f6010087f6010087f6010088f6010088f6010089f6010089f601008af601008bf601008cf601008cf601008df601008df601008ef601008ef601008ff601008ff6010090f6010090f6010091f6010093f6010094f6010094f6010095f6010095f6010096f6010096f6010097f6010097f6010098f6010098f6010099f601009af601009bf60100a1f60100a2f60100a2f60100a3f60100a3f60100a4f60100a5f60100a6f60100a6f60100a7f60100adf60100aef60100b1f60100b2f60100b2f60100b3f60100b5f60100b6f60100b6f60100b7f60100b8f60100b9f60100bef60100bff60100bff60100c0f60100c0f60100c1f60100c5f60100c6f60100caf60100cbf60100cbf60100ccf60100ccf60100cdf60100cff60100d0f60100d0f60100d1f60100d2f60100d3f60100d4f60100d5f60100d5f60100d6f60100d7f60100d8f60100dff60100e0f60100e5f60100e6f60100e8f60100e9f60100e9f60100eaf60100eaf60100ebf60100ecf60100edf60100eff60100f0f60100f0f60100f1f60100f2f60100f3f60100f3f60100f4f60100f6f60100f7f60100f8f60100f9f60100f9f60100faf60100faf60100fbf60100fcf60100fdf60100fff6010074f701007ff70100d5f70100dff70100e0f70100ebf70100ecf70100fff701000cf801000ff8010048f801004ff801005af801005ff8010088f801008ff80100aef80100fff801000cf901000cf901000df901000ff9010010f9010018f9010019f901001ef901001ff901001ff9010020f9010027f9010028f901002ff9010030f9010030f9010031f9010032f9010033f901003af901003cf901003ef901003ff901003ff9010040f9010045f9010047f901004bf901004cf901004cf901004df901004ff9010050f901005ef901005ff901006bf901006cf9010070f9010071f9010071f9010072f9010072f9010073f9010076f9010077f9010078f9010079f9010079f901007af901007af901007bf901007bf901007cf901007ff9010080f9010084f9010085f9010091f9010092f9010097f9010098f90100a2f90100a3f90100a4f90100a5f90100aaf90100abf90100adf90100aef90100aff90100b0f90100b9f90100baf90100bff90100c0f90100c0f90100c1f90100c2f90100c3f90100caf90100cbf90100cbf90100ccf90100ccf90100cdf90100cff90100d0f90100e6f90100e7f90100fff9010000fa01006ffa010070fa010073fa010074fa010074fa010075fa010077fa010078fa01007afa01007bfa01007ffa010080fa010082fa010083fa010086fa010087fa01008ffa010090fa010095fa010096fa0100a8fa0100a9fa0100affa0100b0fa0100b6fa0100b7fa0100bffa0100c0fa0100c2fa0100c3fa0100cffa0100d0fa0100d6fa0100d7fa0100fffa010000fc0100fdff0100");
	_const_digit_pairs = _S("00102030405060708090011121314151617181910212223242526272829203132333435363738393041424344454647484940515253545556575859506162636465666768696071727374757677787970818283848586878889809192939495969798999");
	g_live_reload_info = *(voidptr*)&((voidptr[]){0}[0]); // global 5
	_const_error_sentinel = I_MessageError_to_Interface_IError((HEAP(MessageError, ((MessageError){.msg = _S("error"),.code = 0,}))));
	_const_none__ = I_None___to_Interface_IError((HEAP(None__, ((None__){.Error = ((Error){E_STRUCT}),}))));
	_const_min_i64 = ((i64)(-9223372036854775807LL - 1));
	_const_max_i64 = ((i64)(9223372036854775807LL));
	_const_utf8_replacement_rune = ((rune)(0xfffd));
	// Initializations of consts for module os
	_const_os__path_separator = _S("/");
	_const_os__args = builtin__arguments();
	// Calling fn init() for module os
	os__init();
	// Initializations of consts for module main
	_const_main__version = _S("2.0.0");
	_const_main__default_repo_name = _S("core");
	_const_main__default_repo_url = _S("https://code.weexnes.dev/NGPKG-PKG-REPO.git");
	_const_main__default_install_prefix = _S("/mnt/usb/opt");
	_const_main__default_db_dir = _S("/var/lib/ngpkg");
	_const_main__c_reset = _S("\033[0m");
	_const_main__c_bold = _S("\033[1m");
	_const_main__c_dim = _S("\033[2m");
	_const_main__c_cyan = _S("\033[1;36m");
	_const_main__c_blue = _S("\033[1;34m");
	_const_main__c_green = _S("\033[1;32m");
	_const_main__c_yellow = _S("\033[1;33m");
	_const_main__c_red = _S("\033[1;31m");
	_const_main__c_purple = _S("\033[1;35m");
	_const_main__c_gray = _S("\033[38;5;244m");
}
void _vcleanup(void) {
	static bool once = false; if (once) {return;} once = true;
}

int main(int ___argc, char** ___argv){
	g_main_argc = ___argc;
	g_main_argv = ___argv;
	_vinit(___argc, (voidptr)___argv);
	main__main();
	_vcleanup();
	return 0;
}
// THE END.
