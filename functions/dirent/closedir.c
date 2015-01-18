#include <dirent.h>
#include "dir.h"

#include <unistd.h>
#include <stdlib.h>

int closedir(DIR *dirp) {
	// simply close the file descriptor and free allocated memory
	close(dirp->fd);
	free(dirp);

	return 0;
}
