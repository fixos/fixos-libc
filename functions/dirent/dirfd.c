#include <dirent.h>
#include "dir.h"


int dirfd(DIR *dirp) {
	return dirp->fd;
}
