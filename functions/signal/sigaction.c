#include <signal.h>
#include <bits/inline_syscalls.h>


int sigaction(int sig, const struct sigaction *restrict act, 
		struct sigaction *restrict oact)
{
	return _IN_sigaction(sig, act, oact);
}
