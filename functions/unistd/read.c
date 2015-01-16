#include <unistd.h>
#include <bits/inline_syscalls.h>

ssize_t read(int fildes, void *buf, size_t nbyte) {
	return _IN_read(fildes, buf, nbyte);
}
