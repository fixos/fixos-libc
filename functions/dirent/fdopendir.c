#include <dirent.h>
#include "dir.h"

#include <errno.h>
#include <stdlib.h>


DIR *fdopendir(int fd) {
	DIR *ret = NULL;

	// FIXME check if fd is a directory
	
	ret = malloc(sizeof(DIR));
	if(ret != NULL) {
		ret->fd = fd;
		ret->bufpos = 0;
		ret->bufsize = 0;
	}
	return ret;
}
