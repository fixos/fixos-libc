#include <unistd.h>
#include <sys/ioctl.h>


int tcsetpgrp(int fd, pid_t pgrp);
	int ret;

	return ioctl(fd, TIOCSPGRP, &pgrp);
}
