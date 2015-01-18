#ifndef _DIRENT_DIR_H
#define _DIRENT_DIR_H

/**
 * Internals for dirent.h functions.
 */

#include <fixos/dirent.h>
#include <sys/types.h>

struct DIR_s {
	// internal file descriptor
	int fd;

	// buffer data, using maximum size of fixos_dirent (used as an abstract
	// byte buffer, but this syntax ensure its properly aligned)
	struct fixos_dirent buf[1];
	// current position inside the buffer
	size_t bufpos;
	// current usefull size of the buffer
	size_t bufsize;
};

#endif //_DIRENT_DIR_H
