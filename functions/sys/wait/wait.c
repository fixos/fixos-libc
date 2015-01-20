#include <sys/wait.h>
#include <bits/inline_syscalls.h>

pid_t wait(int *status) {
	return _IN_wait(status);
}

