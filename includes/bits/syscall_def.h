#ifndef _SYSCALL_ARCH_SYSCALL_H
#define _SYSCALL_ARCH_SYSCALL_H

#include <errno.h>

/**
 * _SYSCALL_INLINEDEF_n() macros are used to define inline syscall functions.
 * As syscalls should use a very specific convention (which is not exactly the
 * same than GCC one) for passing arguments, it's mandatory to use a such
 * wrapper.
 * The inline function for syscall named "name" will be "_IN_name".
 * Types used as return values and arguments are given by rettype, type1,
 * type2...
 * Finally a last thing is done in these wrapper : the return value is checked
 * to set errno if needed (error is expected if return value, as a signed int,
 * is between -1023 and -1).
 *
 * Syscall convention for fixos/sh3 is :
 * 	- r0 for return value
 *  - r4 for argument 1
 *  - r5 for argument 2
 *  - r6 for argument 3
 *  - r7 for argument 4
 */

#define _SYSCALL_INLINEDEF_0(name, sysno, rettype) \
	static inline rettype _IN_##name (void) { \
		register int retval __asm__("r0"); \
		__asm__ volatile ("trapa %1;" : "=r"(retval) : "n"(sysno)); \
		_SYSCALL_CHECK_ERROR(retval); \
		return (rettype)(retval); \
	}


#define _SYSCALL_INLINEDEF_1(name, sysno, rettype, type1) \
	static inline rettype _IN_##name (type1 _arg1) { \
		register int retval __asm__("r0"); \
		register int arg1 __asm__("r4") = (int)_arg1; \
		__asm__ volatile ("trapa %1;" : "=r"(retval) : "n"(sysno), "r"(arg1)); \
		_SYSCALL_CHECK_ERROR(retval); \
		return (rettype)(retval); \
	}

#define _SYSCALL_INLINEDEF_2(name, sysno, rettype, type1, type2) \
	static inline rettype _IN_##name (type1 _arg1, type2 _arg2) { \
		register int retval __asm__("r0"); \
		register int arg1 __asm__("r4") = (int)_arg1; \
		register int arg2 __asm__("r5") = (int)_arg2; \
		__asm__ volatile ("trapa %1;" : "=r"(retval) : "n"(sysno), "r"(arg1), "r"(arg2)); \
		_SYSCALL_CHECK_ERROR(retval); \
		return (rettype)(retval); \
	}


#define _SYSCALL_INLINEDEF_3(name, sysno, rettype, type1, type2, type3) \
	static inline rettype _IN_##name (type1 _arg1, type2 _arg2, type3 _arg3) { \
		register int retval __asm__("r0"); \
		register int arg1 __asm__("r4") = (int)_arg1; \
		register int arg2 __asm__("r5") = (int)_arg2; \
		register int arg3 __asm__("r6") = (int)_arg3; \
		__asm__ volatile ("trapa %1;" : "=r"(retval) : "n"(sysno), "r"(arg1), "r"(arg2), "r"(arg3)); \
		_SYSCALL_CHECK_ERROR(retval); \
		return (rettype)(retval); \
	}


#define _SYSCALL_INLINEDEF_4(name, sysno, rettype, type1, type2, type3, type4) \
	static inline rettype _IN_##name (type1 _arg1, type2 _arg2, type3 _arg3, type4 _arg4) { \
		register int retval __asm__("r0"); \
		register int arg1 __asm__("r4") = (int)_arg1; \
		register int arg2 __asm__("r5") = (int)_arg2; \
		register int arg3 __asm__("r6") = (int)_arg3; \
		register int arg4 __asm__("r7") = (int)_arg4; \
		__asm__ volatile ("" : : "r"(arg4)); /* GCC bug workaround... */ \
		__asm__ volatile ("trapa %1;" : "=r"(retval) : "n"(sysno), "r"(arg1), "r"(arg2), "r"(arg3), "r"(arg4)); \
		_SYSCALL_CHECK_ERROR(retval); \
		return (rettype)(retval); \
	}


/**
 * used to check for error in syscall return value
 */
#define _SYSCALL_CHECK_ERROR(ret) \
	if((unsigned int)ret >= (unsigned int)-1023) { \
		errno = -(int)(ret); \
		ret = -1; \
	}

#endif //_SYSCALL_ARCH_SYSCALL_H
