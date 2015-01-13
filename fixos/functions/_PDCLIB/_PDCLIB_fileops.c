/* _PDCLIB_fileops

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#ifndef REGTEST
#include <stdio.h>
#include <stdint.h>
#include <pdclib/glue.h>
#include <errno.h>
#include <bits/inline_syscalls.h>


static bool readf( _PDCLIB_fd_t self, void * buf, size_t length, 
                   size_t * numBytesRead )
{
	int ret;
	ret = _IN_read(self.sval, buf, length);
	if(ret<0) {
		*numBytesRead = 0;
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
	ret = _IN_write(self.sval, buf, length);
	if(ret<0) {
		*numBytesWritten = 0;
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
	ret = _IN_lseek(self.sval, offset, whence);
	if(ret<0) {
		// FIXME not 0 ?
		*newPos = 0;
		return false;
	}
	else {
		*newPos = ret;
		return true;
	}
}

static void closef( _PDCLIB_fd_t self )
{
	_IN_close(self.sval);
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
