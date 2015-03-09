#include <signal.h>
#include <bits/inline_syscalls.h>


int kill(pid_t pid, int sig) {
	return _IN_kill(pid, sig);
}
