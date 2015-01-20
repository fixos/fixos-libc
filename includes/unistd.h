#ifndef _LIBC_UNISTD_H
#define _LIBC_UNISTD_H


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

// exec-like functions :
int execl(const char *path, const char *arg0, ...);
//int execle(const char *path, const char *arg0, ...);
int execlp(const char *file, const char *arg0, ...);
int execv(const char *path, char *const argv[]);
int execve(const char *path, char *const argv[], char *const envp[]);
int execvp(const char *file, char *const argv[]);
// FIXME FiXos extension
int execvpe(const char *file, char *const argv[], char *const envp[]);

pid_t fork(void);

pid_t getpgid(pid_t pid);

pid_t getpid(void);

pid_t getppid(void);

off_t lseek(int fildes, off_t offset, int whence);

ssize_t read(int fildes, void *buf, size_t nbyte);

int setpgid(pid_t pid, pid_t pgid);

pid_t tcgetpgrp(int fd);

int tcsetpgrp(int fd, pid_t pgrp);

ssize_t write(int fildes, const void *buf, size_t nbyte);

_PDCLIB_END_EXTERN_C

#endif //_LIBC_UNISTD_H
