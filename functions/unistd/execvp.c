#include <unistd.h>
#include <stddef.h>

int execvp(const char *file, char *const argv[]) {
	return execvpe(file, argv, environ);
}

