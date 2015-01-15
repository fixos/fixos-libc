#ifndef _LIBC_BITS_ERRNO_H
#define _LIBC_BITS_ERRNO_H

/**
 * Possible errno values are the same as FiXos kernel.
 * FIXME by doing so, it is not possible to restrict ISO C errno list
 */

#include <fixos/errno.h>


// temporary definition of missing errno
/* C errno values */
#define ERANGE 1001
#define EDOM   1002
#define EILSEQ 1003

/* C++11/POSIX errno values */
#define E2BIG 1004
#define ECONNRESET 1005
#define EISCONN 1006
#define ENOTRECOVERABLE 1008
#define EDEADLK 1011
#define ENOEXEC 1013
#define ENOTSOCK 1014
#define ESPIPE 1015
#define EADDRINUSE 1016
#define EDESTADDRREQ 1017
#define ELOOP 1018
#define ENOLCK 1019
#define ENOTSUP 1020
#define EADDRNOTAVAIL 1022
#define ENOLINK 1024
#define ENOTTY 1025
#define ETIME 1026
#define EAFNOSUPPORT 1027
#define EEXIST 1028
#define EMLINK 1029
#define ENOMEM 1030
#define ETIMEDOUT 1032
#define EMSGSIZE 1035
#define ENOMSG 1036
#define EOPNOTSUPP 1037
#define ETXTBSY 1038
#define EALREADY 1039
#define EFBIG 1040
#define ENOPROTOOPT 1042
#define EOVERFLOW 1043
#define EWOULDBLOCK _PDCLIB_EAGAIN
#define EBADF EBADF
#define EHOSTUNREACH 1045
#define ENETDOWN 1046
#define ENOSPC 1047
#define EOWNERDEAD 1048
#define EXDEV 1049
#define EBADMSG 1050
#define EIDRM 1051
#define ENETRESET 1052
#define ENOSR 1053
#define EBUSY 1055
#define ENETUNREACH 1056
#define ENOSTR 1057
#define EPIPE 1058
#define ECANCELED 1059
#define EINPROGRESS 1060
#define ENOSYS 1062
#define EPROTO 1063
#define ECHILD 1064
#define ENOBUFS 1066
#define ENOTCONN 1067
#define EPROTONOSUPPORT 1068
#define ECONNABORTED 1069
#define ENODATA 1071
#define EPROTOTYPE 1073


#endif //_LIBC_BITS_ERRNO_H
