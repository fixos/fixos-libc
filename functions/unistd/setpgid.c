#include <unistd.h>
#include <bits/inline_syscalls.h>

int setpgid(pid_t pid, pid_t pgid) {
	return _IN_setpgid(pid, pgid);
}
