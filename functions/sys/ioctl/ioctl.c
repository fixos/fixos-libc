#include <sys/ioctl.h>

#include <stdarg.h>
#include <bits/inline_syscalls.h>


int ioctl(int fd, int req, ...) {
	va_list vl;
	void *realarg;
	int res;

	va_start(vl, req);
	realarg = va_arg(vl, void*);

	res = _IN_ioctl(fd, req, realarg);

	va_end(vl);
	return res;
}
