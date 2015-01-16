#include <fcntl.h>

#include <bits/inline_syscalls.h>

int open(const char *pathname, int flags, ...) {
	//FIXME additionnal parameter if O_CREAT is used
	return _IN_open(pathname, flags);
}
