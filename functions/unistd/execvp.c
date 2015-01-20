#include <unistd.h>
#include <stddef.h>

int execvp(const char *file, char *const argv[]) {
	// TODO environ variable
	return execvpe(file, argv, NULL);
}

