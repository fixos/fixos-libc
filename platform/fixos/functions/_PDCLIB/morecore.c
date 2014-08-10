/* $Id$ */

/* _PDCLIB_morecore( size_t const )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#include <stdint.h>
#include <stddef.h>
#include <_PDCLIB_glue.h>
#include <errno.h>
#include <syscall_entry.h>

void *sys_sbrk(int size);

_SYSCALL_DECL(sys_sbrk, SYSCALL_SBRK);


void * _PDCLIB_morecore( long size )
{
	void *ret;
	ret = sys_sbrk((int)size);
	if(ret == NULL)
		errno = ENOMEM;
	return ret;
}

#ifdef TEST
#include <_PDCLIB_test.h>

int main( void )
{
    return TEST_RESULTS;
}

#endif
