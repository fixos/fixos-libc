#include <unistd.h>
#include <bits/inline_syscalls.h>

pid_t getpgid(pid_t pid) {
	return _IN_getpgid(pid);
}
