#ifndef _LIBC_DIRENT_H
#define _LIBC_DIRENT_H

/**
 * POSIX directory manipulation header.
 * FiXos implements a BSD-like way to read entries from a directory (getdents
 * syscall), and differ a bit from POSIX way to handle that.
 * The functions in this header are easier to use than the FiXos specific
 * syscall, but need more memory and computation.
 */

#include <pdclib/aux.h>

_PDCLIB_BEGIN_EXTERN_C


#define __need_ino_t
#include <bits/types.h>


/**
 * Public dirent structure, may differ from the internal fixos_dirent struct.
 */
struct dirent {
	ino_t d_ino;	// XSI extension, not really needed?
	char d_type;	// common extension to POSIX, not standard
	char d_name[256];	// d_name real size is the dynamic size of d_name string
};


// incomplete type for DIR
typedef struct DIR_s DIR;


int closedir(DIR *dirp);

int dirfd(DIR *dirp);

DIR *fdopendir(int fd);

DIR *opendir(const char *name);

struct dirent *readdir(DIR *dirp);

void rewinddir(DIR *dirp);


_PDCLIB_END_EXTERN_C

#endif //_LIBC_DIRENT_H
