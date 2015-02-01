#include <sys/sysctl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


/**
 * Minimalist top-like program, using sysctl() calls.
 */


// helper to read a sysctl value by name, as a string
static void read_sysctl_str(const char *name, char *buf, int len) {
	size_t size;

	size = len-1;
	if(!sysctlbyname(name, buf, &size, NULL, 0))
		buf[size] = '\0';
	else
		buf[0] = '\0';

}

static void test_print_sysinfo() {
	char ostype[32];
	char osrelease[32];
	char osbuilddate[32];
	char machine[32];

	read_sysctl_str("kern.ostype", ostype, sizeof(ostype));
	read_sysctl_str("kern.osrelease", osrelease, sizeof(osrelease));
	read_sysctl_str("kern.osbuilddate", osbuilddate, sizeof(osbuilddate));
	read_sysctl_str("hw.machine", machine, sizeof(machine));

	printf(	"Kernel informations (sysctl) :\n"
			"%s %s (%s), hw: %s\n", ostype, osrelease, osbuilddate, machine);
}


int main(int argc, char **argv) {
	test_print_sysinfo();
	exit(0);
}
