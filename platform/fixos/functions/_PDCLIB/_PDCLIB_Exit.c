/* $Id$ */

/* _PDCLIB_exit( int )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

/* This is a stub implementation of _PDCLIB_Exit
*/

#include <stdlib.h>

#ifndef REGTEST
#include <_PDCLIB_glue.h>
#include <syscall_entry.h>
#include <errno.h>
#include <stdnoreturn.h>


noreturn void sys__exit(int status);

_SYSCALL_DECL(sys__exit, SYSCALL_EXIT);


void _PDCLIB_Exit( int status )
{
	sys__exit(status);
}

#endif

#ifdef TEST
#include <_PDCLIB_test.h>

int main( void )
{
    int UNEXPECTED_RETURN = 0;
    _PDCLIB_Exit( 0 );
    TESTCASE( UNEXPECTED_RETURN );
    return TEST_RESULTS;
}

#endif
