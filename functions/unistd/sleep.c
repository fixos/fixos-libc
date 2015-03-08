#include <unistd.h>
#include <time.h>

unsigned int sleep(unsigned int seconds) {
	struct timespec expected, rest;

	expected.tv_nsec = 0;
	expected.tv_sec = seconds;
	if(nanosleep(&expected, &rest) != 0) {
		return rest.tv_sec;
	}
	return 0;
}
