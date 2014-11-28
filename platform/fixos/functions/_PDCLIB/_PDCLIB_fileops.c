/* _PDCLIB_fileops

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#ifndef REGTEST
#include <stdio.h>
#include <stdint.h>
#include <pdclib/glue.h>
#include <errno.h>
#include <syscall_entry.h>

typedef int ssize_t;
typedef int off_t;

ssize_t sys_read(int fd, char *dest, size_t nb);
ssize_t sys_write(int fd, const char *source, size_t nb);
int sys_lseek(int fd, off_t offset, int whence);
int sys_close(int fd);

_SYSCALL_DECL(sys_read, SYSCALL_READ);
_SYSCALL_DECL(sys_write, SYSCALL_WRITE);
_SYSCALL_DECL(sys_lseek, SYSCALL_LSEEK);
_SYSCALL_DECL(sys_close, SYSCALL_CLOSE);

static bool readf( _PDCLIB_fd_t self, void * buf, size_t length, 
                   size_t * numBytesRead )
{
	int ret;
	ret = sys_read(self.sval, buf, length);
	if(ret<0) {
		*numBytesRead = 0;
		errno = -ret;
		return false;
	}
	else {
		*numBytesRead = ret;
		return true;
	}
}

static bool writef( _PDCLIB_fd_t self, const void * buf, size_t length, 
                   size_t * numBytesWritten )
{
	int ret;
	ret = sys_write(self.sval, buf, length);
	if(ret<0) {
		*numBytesWritten = 0;
		errno = -ret;
		return false;
	}
	else {
		*numBytesWritten = ret;
		return true;
	}
}
static bool seekf( _PDCLIB_fd_t self, int_fast64_t offset, int whence,
    int_fast64_t* newPos )
{
	int ret;
	ret = sys_lseek(self.sval, offset, whence);
	if(ret<0) {
		*newPos = 0;
		errno = -ret;
		return false;
	}
	else {
		*newPos = ret;
		return true;
	}
}

static void closef( _PDCLIB_fd_t self )
{
	int ret;
	ret = sys_close(self.sval);
	if(ret < 0) {
		errno = -ret;
	}
}

const _PDCLIB_fileops_t _PDCLIB_fileops = {
    .read  = readf,
    .write = writef,
    .seek  = seekf,
    .close = closef,
};

#endif

#ifdef TEST
#include <pdclib/test.h>

int main( void )
{
    // Tested by stdio test cases
    return TEST_RESULTS;
}

#endif
