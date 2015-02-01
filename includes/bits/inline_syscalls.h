#ifndef _BITS_INLINE_SYSCALL_H
#define _BITS_INLINE_SYSCALL_H

#include <fixos/types.h>
#include <fixos/syscalls.h>
#include <bits/syscall_def.h>
#include <stdnoreturn.h>


/**
 * Definition of all FiXos syscalls as inline functions (centralized to avoid
 * multiple definitions).
 * Maybe not the best design ever, but it allow also user of libc to use any
 * FiXos syscall easily.
 */


// forward declaration needed
struct timespec;
struct timezone;
struct tms;
struct sigaction;
struct stat;
struct fixos_dirent;

// will maybe not work
typedef struct sigset_s sigset_t;


_SYSCALL_INLINEDEF_2(open, SYSCALL_OPEN, int, const char *, int)

_SYSCALL_INLINEDEF_3(read, SYSCALL_READ, __kernel_ssize_t, int, char *, __kernel_size_t)

_SYSCALL_INLINEDEF_3(write, SYSCALL_WRITE, __kernel_ssize_t, int, const char *, __kernel_size_t)

_SYSCALL_INLINEDEF_0(fork, SYSCALL_FORK, __kernel_pid_t)

// little trick to avoid GCC warning : we say it's returning an int (instead
// of noreturn)
_SYSCALL_INLINEDEF_1(exit, SYSCALL_EXIT, int, int)

_SYSCALL_INLINEDEF_0(getpid, SYSCALL_GETPID, __kernel_pid_t)

_SYSCALL_INLINEDEF_0(getppid, SYSCALL_GETPPID, __kernel_pid_t)

_SYSCALL_INLINEDEF_1(wait, SYSCALL_WAIT, __kernel_pid_t, int*)

_SYSCALL_INLINEDEF_3(execve, SYSCALL_EXECVE, int, const char*, char * const*, char *const *)

// FiXos-specific gettimeofday : use a struct timespec instead of struct timeval
_SYSCALL_INLINEDEF_2(gettimeofday, SYSCALL_GETTIMEOFDAY, int, struct timespec *,
		struct timezone *)

_SYSCALL_INLINEDEF_1(times, SYSCALL_TIMES, __kernel_clock_t, struct tms *)

_SYSCALL_INLINEDEF_3(sigaction, SYSCALL_SIGACTION, int, int,
		const struct sigaction*, struct sigaction*)

_SYSCALL_INLINEDEF_2(kill, SYSCALL_KILL, int, __kernel_pid_t, int)

_SYSCALL_INLINEDEF_3(sigprocmask, SYSCALL_SIGPROCMASK, int, int,
		const sigset_t *, sigset_t *)

// not implemented sigreturn (not design to be used by the libc or user)

_SYSCALL_INLINEDEF_2(pipe2, SYSCALL_PIPE2, int, int*, int)

_SYSCALL_INLINEDEF_3(ioctl, SYSCALL_IOCTL, int, int, int, void*)

_SYSCALL_INLINEDEF_2(dynbind, SYSCALL_DYNBIND, int, const char*, void**)

// TODO fix sbrk syscall implementation to return an integer (and take 2 arguments)
_SYSCALL_INLINEDEF_1(sbrk, SYSCALL_SBRK, void *, int)


_SYSCALL_INLINEDEF_4(sysctl_read, SYSCALL_SYSCTL_READ, int, const int*,
		__kernel_size_t, void*, __kernel_size_t*)

_SYSCALL_INLINEDEF_4(sysctl_write, SYSCALL_SYSCTL_WRITE, int, const int*,
		__kernel_size_t, const void*, __kernel_size_t)

_SYSCALL_INLINEDEF_2(nanosleep, SYSCALL_NANOSLEEP, int,
		const struct timespec *, struct timespec *)

_SYSCALL_INLINEDEF_3(sysctl_mibname, SYSCALL_SYSCTL_MIBNAME, int, const char *,
		int *, int *)

_SYSCALL_INLINEDEF_3(lseek, SYSCALL_LSEEK, __kernel_off_t, int, __kernel_off_t, int)

_SYSCALL_INLINEDEF_2(fstat, SYSCALL_FSTAT, int, int, struct stat*)

_SYSCALL_INLINEDEF_2(stat, SYSCALL_STAT, int, const char*, struct stat*)

_SYSCALL_INLINEDEF_3(getdents, SYSCALL_GETDENTS, int, int,
		struct fixos_dirent *, __kernel_size_t)

_SYSCALL_INLINEDEF_1(close, SYSCALL_CLOSE, int, int)

_SYSCALL_INLINEDEF_1(chdir, SYSCALL_CHDIR, int, const char *)

_SYSCALL_INLINEDEF_1(fchdir, SYSCALL_FCHDIR, int, int)

_SYSCALL_INLINEDEF_2(setpgid, SYSCALL_SETPGID, int, __kernel_pid_t,
		__kernel_pid_t)

_SYSCALL_INLINEDEF_1(getpgid, SYSCALL_GETPGID, __kernel_pid_t, __kernel_pid_t)

_SYSCALL_INLINEDEF_1(dup, SYSCALL_DUP, int, int)

_SYSCALL_INLINEDEF_2(dup2, SYSCALL_DUP2, int, int, int)



#endif // _BITS_INLINE_SYSCALL_H
