#include <dirent.h>
#include "dir.h"

#include <unistd.h>


/**
 * On FiXos, it is possible to call lseek() syscall to set the position in
 * a directory stream.
 */
void rewinddir(DIR *dirp) {
	
	// FIXME check this call
	// lseek(dirp->fd, 0, SEEK_SET);
	
	dirp->bufsize = 0;
	dirp->bufpos = 0;
}

