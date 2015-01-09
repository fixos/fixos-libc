/* $Id$ */

/* _PDCLIB_morecore( size_t const )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#include <stdint.h>
#include <stddef.h>
#include <pdclib/glue.h>
#include <errno.h>
#include <bits/inline_syscalls.h>

void * _PDCLIB_morecore( long size )
{
	void *ret;
	ret = _IN_sbrk((int)size);

	// FIXME sbrk syscall will change!
	if(ret == NULL)
		errno = ENOMEM;
	return ret;
}

#ifdef TEST
#include <pdclib/test.h>

int main( void )
{
    return TEST_RESULTS;
}

#endif
