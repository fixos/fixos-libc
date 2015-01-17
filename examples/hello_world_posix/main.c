#include <unistd.h>
#include <fcntl.h>

/**
 * Simple test for FiXos, assuming no stdout.
 */

#define write_const(fd, str) write((fd), (str), sizeof(str)-1)

int main(int argc, char **argv) {
	int fd;

	fd = open("/dev/console", O_RDWR);
	if(fd != -1) {
		write_const(fd, "Hello world from POSIX libc!\n");
		while(1);
	}

	return -1;
}
