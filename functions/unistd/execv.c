#include <unistd.h>
#include <stddef.h>

int execv(const char *path, char *const argv[]) {
	// TODO environ variable
	return execve(path, argv, NULL);
}
