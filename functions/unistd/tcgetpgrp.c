#include <unistd.h>
#include <sys/ioctl.h>


pid_t tcgetpgrp(int fd) {
	pid_t ret;
	int ioret;

	ioret = ioctl(fd, TIOCGPGRP, &ret);
	return ioret < 0 ? (pid_t)-1 : ret;
}
