#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>

int execv(const char *path, char *const argv[]) {
	return execve(path, argv, environ);
}
