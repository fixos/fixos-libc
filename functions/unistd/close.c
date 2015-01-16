#include <unistd.h>
#include <bits/inline_syscalls.h>

int close(int fd) {
	return _IN_close(fd);
}
