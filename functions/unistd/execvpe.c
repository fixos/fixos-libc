#include <unistd.h>
#include <bits/inline_syscalls.h>
#include <string.h>
#include <stdlib.h>

// FIXME: PATH is not used for now, and default is FiXos-specific

#define EXECVPE_MAX_PREFIX		16
static const char *const prefix_paths[] = {
	"/mnt/smem/",
	"/mnt/smem/bin/",
	NULL
};


/**
 * This is an extension to the POSIX standard, and it's also the base used
 * internaly for all the exec*e functions.
 * FIXME should check if a '/' is present, and then call execve with file
 * as path
 */
int execvpe(const char *file, char *const argv[], char *const envp[]) {
	// this implementation is dirty, and should be replaced with calls to fexecve
	char *buf;
	const char *const *current = prefix_paths;
	int ret = 0;

	// freed by execve() in success case
	buf = malloc(EXECVPE_MAX_PREFIX + strlen(file));
	while(*current != NULL) {
		size_t curs = strlen(*current);
		memcpy(buf, *current, curs);
		strcpy(buf + curs, file);

		// try to exec, and iterate if fail
		ret = execve(buf, argv, envp);

		current++;
	}

	free(buf);
	return ret;
}
