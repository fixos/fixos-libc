#ifndef _LIBC_SYS_IOCTL_H
#define _LIBC_SYS_IOCTL_H

/**
 * Not in POSIX standard, but sys/ioctl.h seems to be widespread on modern
 * UNIX.
 * Define ioctl() call, and common ioctls.
 */

#include <pdclib/aux.h>

_PDCLIB_BEGIN_EXTERN_C


#include <bits/ioctl.h>

int ioctl(int fd, int req, ...);


_PDCLIB_END_EXTERN_C

#endif //_LIBC_SYS_IOCTL_H
