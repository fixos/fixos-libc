#include <unistd.h>
#include <bits/inline_syscalls.h>

int execve(const char *path, char *const argv[], char *const envp[]) {
	return _IN_execve(path, argv, envp);
}
