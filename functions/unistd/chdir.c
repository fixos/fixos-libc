#include <unistd.h>
#include <bits/inline_syscalls.h>

int chdir(const char *path) {
	return _IN_chdir(path);
}
