#include <unistd.h>
#include <bits/inline_syscalls.h>

ssize_t write(int fildes, const void *buf, size_t nbyte) {
	return _IN_write(fildes, buf, nbyte);
}
