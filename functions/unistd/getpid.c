#include <unistd.h>
#include <bits/inline_syscalls.h>

pid_t getpid(void) {
	return _IN_getpid();
}

