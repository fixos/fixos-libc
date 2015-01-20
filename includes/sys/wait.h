#ifndef _LIBC_SYS_WAIT_H
#define _LIBC_SYS_WAIT_H

#include <pdclib/aux.h>
#include <signal.h>

_PDCLIB_BEGIN_EXTERN_C

//#define __need_id_t
#define __need_pid_t
#include <bits/types.h>

#include <bits/wait.h>


pid_t wait(int *status);

_PDCLIB_END_EXTERN_C

#endif //_LIBC_SYS_WAIT_H
