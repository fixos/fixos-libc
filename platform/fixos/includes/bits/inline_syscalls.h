#ifndef _BITS_INLINE_SYSCALL_H
#define _BITS_INLINE_SYSCALL_H

#include <fixos/types.h>
#include <fixos/syscalls.h>
#include <bits/syscall_def.h>
#include <stdnoreturn.h>


/**
 * Definition of all FiXos syscalls as inline functions (centralized to avoid multiple
 * definitions).
 */



_SYSCALL_INLINEDEF_2(open, SYSCALL_OPEN, int, const char *, int)

_SYSCALL_INLINEDEF_3(read, SYSCALL_READ, __kernel_ssize_t, int, char *, __kernel_size_t)

_SYSCALL_INLINEDEF_3(write, SYSCALL_WRITE, __kernel_ssize_t, int, const char *, __kernel_size_t)

_SYSCALL_INLINEDEF_3(lseek, SYSCALL_LSEEK, __kernel_off_t, int, __kernel_off_t, int)

_SYSCALL_INLINEDEF_1(close, SYSCALL_CLOSE, int, int)


// TODO fix sbrk syscall implementation to return an integer (and take 2 arguments)
_SYSCALL_INLINEDEF_1(sbrk, SYSCALL_SBRK, void *, int)


noreturn _SYSCALL_INLINEDEF_1(exit, SYSCALL_EXIT, void, int)


#endif // _BITS_INLINE_SYSCALL_H
