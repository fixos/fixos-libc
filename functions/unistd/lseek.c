#include <unistd.h>
#include <bits/inline_syscalls.h>

off_t lseek(int fildes, off_t offset, int whence) {
	return _IN_lseek(fildes, offset, whence);
}
