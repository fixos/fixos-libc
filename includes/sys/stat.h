#ifndef _LIBC_SYS_STAT_H
#define _LIBC_SYS_STAT_H

#include <pdclib/aux.h>

_PDCLIB_BEGIN_EXTERN_C


#include <bits/stat.h>

#define __need_dev_t
#define __need_ino_t
#define __need_mode_t
#define __need_uid_t
#define __need_gid_t
#define __need_off_t
#define __need_time_t
//FIXME #define __need_nlink_t
#include <bits/types.h>


int fstat(int fd, struct stat *buf);

int stat(const char *pathname, struct stat *buf);


_PDCLIB_END_EXTERN_C

#endif //_LIBC_SYS_STAT_H
