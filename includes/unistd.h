#ifndef _LIBC_FCNTL_H
#define _LIBC_FCNTL_H


#include <pdclib/aux.h>

_PDCLIB_BEGIN_EXTERN_C

#define __need_size_t
#define __need_ssize_t
#define __need_uid_t
#define __need_gid_t
#define __need_off_t
#define __need_pid_t
#include <bits/types.h>

/**
 * Standard streams file numbers
 */
#define STDERR_FILENO			2
#define STDIN_FILENO			0
#define STDOUT_FILENO			1


// TODO define NULL

int chdir(const char *path);

int close(int fd);

off_t lseek(int fildes, off_t offset, int whence);

ssize_t read(int fildes, void *buf, size_t nbyte);

ssize_t write(int fildes, const void *buf, size_t nbyte);

_PDCLIB_END_EXTERN_C

#endif //_LIBC_FCNTL_H
