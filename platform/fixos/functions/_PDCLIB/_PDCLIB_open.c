/* $Id$ */

/* _PDCLIB_open( char const * const, int )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

/* This is a stub implementation of open.
*/

#include <stdio.h>
#include <errno.h>

#ifndef REGTEST
#include <pdclib/glue.h>
#include <fixos/fcntl.h>
#include <syscall_entry.h>

extern const _PDCLIB_fileops_t _PDCLIB_fileops;

int sys_open(const char *file, int mode);

_SYSCALL_DECL(sys_open, SYSCALL_OPEN);


bool _PDCLIB_open( _PDCLIB_fd_t * pFd, const _PDCLIB_fileops_t ** pOps,
                   char const * const filename, unsigned int mode )
{
	int needCreate = 0;
	int realMode;

	// FIXME needCreate is not always good
    switch(mode & ( _PDCLIB_FREAD | _PDCLIB_FWRITE | _PDCLIB_FAPPEND 
                    | _PDCLIB_FRW ))
    {
    case _PDCLIB_FREAD: /* "r" */
        realMode = O_RDONLY;
        break;
    case _PDCLIB_FWRITE: /* "w" */
        realMode = O_WRONLY;
		needCreate = 1;
        break;
    case _PDCLIB_FAPPEND: /* "a" */
        realMode = O_WRONLY;
		needCreate = 1;
        break;
    case _PDCLIB_FREAD | _PDCLIB_FRW: /* "r+" */
        realMode = O_RDWR;
        break;
    case _PDCLIB_FWRITE | _PDCLIB_FRW: /* "w+" */
        realMode = O_RDWR;
		needCreate = 1;
        break;
    case _PDCLIB_FAPPEND | _PDCLIB_FRW: /* "a+" */
        realMode = O_RDWR;
		needCreate = 0;
        break;
    default: /* Invalid mode */
        errno = EINVAL;
        return false;
    }

	int fd = sys_open(filename, realMode);

    if(fd < 0) {
		errno = -fd;
        return false;
    }

    if(mode & _PDCLIB_FAPPEND) {
		// TODO fseek()
    }

    pFd->sval = fd;
    *pOps = &_PDCLIB_fileops;
    return true;
}

#endif

#ifdef TEST
#include <pdclib/test.h>

#include <stdlib.h>
#include <string.h>

int main( void )
{
    return TEST_RESULTS;
}

#endif

