#include <dirent.h>
#include "dir.h"

#include <string.h>
#include <stddef.h>
#include <bits/inline_syscalls.h>


// static struct for non-reentrant version of readdir (POSIX is dirty...)
static struct dirent static_dirent;

struct dirent *readdir(DIR *dirp) {
	// check if next entry is included in the current buffer
	if(dirp->bufpos >= dirp->bufsize) {
		// fill the buffer
		int nbread;
		
		nbread = _IN_getdents(dirp->fd, dirp->buf, sizeof(dirp->buf));
		if(nbread < 0) {
			return NULL;
		}

		dirp->bufsize = nbread;
		dirp->bufpos = 0;

		// check again, if not present in the buffer, this is the end of entries	
		if(dirp->bufpos >= dirp->bufsize) {
			return NULL;
		}
	}

	struct fixos_dirent *realdir = (struct fixos_dirent*)(((char*)dirp->buf) + dirp->bufpos);
	// fill the static dirent with the content of the buffered fixos_dirent
	static_dirent.d_type = realdir->d_type;
	static_dirent.d_ino = realdir->d_ino;
	strncpy(static_dirent.d_name, realdir->d_name, sizeof(static_dirent.d_name));

	dirp->bufpos += realdir->d_off;

	return &static_dirent;
}
