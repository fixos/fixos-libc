#include <unistd.h>
#include <bits/inline_syscalls.h>

pid_t fork(void) {
	return _IN_fork();
}
