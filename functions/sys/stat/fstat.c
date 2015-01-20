#include <sys/stat.h>
#include <bits/inline_syscalls.h>


int fstat(int fd, struct stat *buf) {
	return _IN_fstat(fd, buf);
}
