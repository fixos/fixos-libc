#ifndef _LIBC_SYS_SYSCTL_H
#define _LIBC_SYS_SYSCTL_H

/**
 * BSD-like sysctl interface.
 */

#include <pdclib/aux.h>

_PDCLIB_BEGIN_EXTERN_C


#include <bits/sysctl.h>

#define __need_size_t
#include <sys/types.h>

int sysctl(const int *name, size_t namelen, void *oldp, size_t *oldlenp,
		const void *newp, size_t newlen);

int sysctlbyname(const char *name, void *oldp, size_t *oldlenp,
		const void *newp, size_t newlen);

int sysctlnametomib(const char *name, int *mibp, size_t *sizep);


_PDCLIB_END_EXTERN_C

#endif //_LIBC_SYS_SYSCTL_H
