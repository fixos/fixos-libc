#ifndef _LIBC_BITS_TYPES_H
/**
 * Type definition for sys/types.h from the kernel.
 * This header is a bit special because the header guard do not cover the
 * entire content. Instead it uses a design like the glibc one.
 * Some types are protected by a __need_xxx macro that allow to include
 * only several types (to avoid pollution of some POSIX and ISO C headers).
 * If included without any __need_xxx macro, everything is defined (for
 * sys/types.h).
 * If included with a definition of some implemented __need_xxx, instead
 * nothing else the explicitly needed types will be included.
 */

#include <fixos/types.h>

#if !defined(__need_time_t) && !defined(__need_clock_t) && !defined(__need_size_t) \
	&& !defined(__need_mode_t) && !defined(__need_off_t) && !defined(__need_pid_t)
// no valid __need_xxx macro, include all the content including all types
// protected by __need_xxx
#define _LIBC_BITS_TYPES_H

#define __need_time_t
#define __need_clock_t
#define __need_size_t
#define __need_mode_t
#define __need_off_t
#define __need_pid_t


// content here is protected by _LIBC_BITS_TYPES_H header guard :
typedef __kernel_ssize_t	ssize_t;

// FiXos specific definition, should be protected by an appropriate feature test
/*typedef __kernel_uint32		uint32;
typedef __kernel_int32		int32;
typedef __kernel_uint16 	uint16;
typedef __kernel_int16		int16;
typedef __kernel_uint8		uint8;
typedef __kernel_int8		int8;
*/

typedef __kernel_dev_t		dev_t;

// should be protected, BSD style
#define major(x)			__kernel_major(x)
#define minor(x)			__kernel_minor(x)
#define makedev(maj, min)	__kernel_makedev(maj, min)

typedef __kernel_ino_t		ino_t;

#endif // no __need_xxx macro defined


// independant types, each one have its own guard and is enable by __need_xxx
#if !defined(_LIBC_TIME_T_DEFINED) && defined(__need_time_t)
#define _LIBC_TIME_T_DEFINED
typedef __kernel_time_t time_t;
#undef __need_time_t
#endif //!defined(_LIBC_TIME_T_DEFINED) && defined(__need_time_t)


#if !defined(_LIBC_CLOCK_T_DEFINED) && defined(__need_clock_t)
#define _LIBC_CLOCK_T_DEFINED
typedef __kernel_clock_t clock_t;
#undef __need_clock_t
#endif //!defined(_LIBC_CLOCK_T_DEFINED) && defined(__need_clock_t)


#if !defined(_LIBC_SIZE_T_DEFINED) && defined(__need_size_t)
#define _LIBC_SIZE_T_DEFINED
typedef __kernel_size_t size_t;
#undef __need_size_t
#endif //!defined(_LIBC_SIZE_T_DEFINED) && defined(__need_size_t)


#if !defined(_LIBC_OFF_T_DEFINED) && defined(__need_off_t)
#define _LIBC_OFF_T_DEFINED
typedef __kernel_off_t		off_t;
#endif //!defined(_LIBC_OFF_T_DEFINED) && defined(__need_off_t)


#if !defined(_LIBC_PID_T_DEFINED) && defined(__need_pid_t)
#define _LIBC_PID_T_DEFINED
typedef __kernel_pid_t		pid_t;
#endif //!defined(_LIBC_PID_T_DEFINED) && defined(__need_pid_t)


#if !defined(_LIBC_MODE_T_DEFINED) && defined(__need_mode_t)
#define _LIBC_MODE_T_DEFINED
typedef __kernel_mode_t		mode_t;
#endif //!defined(_LIBC_MODE_T_DEFINED) && defined(__need_mode_t)



#endif //_LIBC_BITS_TYPES_H
