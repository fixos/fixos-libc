#ifndef _LIBC_FCNTL_H
#define _LIBC_FCNTL_H


#include <pdclib/aux.h>

_PDCLIB_BEGIN_EXTERN_C

#define __need_mode_t
#define __need_off_t
#define __need_pid_t
#include <bits/types.h>

#include <bits/fcntl.h>


//int creat(const char *pathname, mode_t mode);

//int fcntl(int fildes, int cmd, ...);

int open(const char *pathname, int flags, ...);

//int openat(int dirfd, const char *pathname, int flags, ...);


_PDCLIB_END_EXTERN_C

#endif //_LIBC_FCNTL_H
