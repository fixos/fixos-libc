#include <time.h>
#include <bits/inline_syscalls.h>


int nanosleep(const struct timespec *expect, struct timespec *rest) {
	return _IN_nanosleep(expect, rest);
}
