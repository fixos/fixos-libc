#include <unistd.h>
#include <bits/inline_syscalls.h>

pid_t getppid(void) {
	return _IN_getppid();
}

