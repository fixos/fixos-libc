#include <sys/stat.h>
#include <bits/inline_syscalls.h>


int stat(const char *pathname, struct stat *buf) {
	return _IN_stat(pathname, buf);
}
