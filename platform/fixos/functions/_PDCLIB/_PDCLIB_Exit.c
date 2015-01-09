/* $Id$ */

/* _PDCLIB_exit( int )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

/* This is a stub implementation of _PDCLIB_Exit
*/

#include <stdlib.h>

#ifndef REGTEST
#include <pdclib/glue.h>
#include <bits/inline_syscalls.h>
#include <stdnoreturn.h>


void _PDCLIB_Exit( int status )
{
	_IN_exit(status);
}

#endif

#ifdef TEST
#include <pdclib/test.h>

int main( void )
{
    int UNEXPECTED_RETURN = 0;
    _PDCLIB_Exit( 0 );
    TESTCASE( UNEXPECTED_RETURN );
    return TEST_RESULTS;
}

#endif
