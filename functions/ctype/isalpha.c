/* $Id$ */

/* isalpha( int )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#include <ctype.h>

#ifndef REGTEST
#include <pdclib/locale.h>

int isalpha( int c )
{
    return ( _PDCLIB_threadlocale()->_CType[c].flags & _PDCLIB_CTYPE_ALPHA );
}

#endif

#ifdef TEST
#include <pdclib/test.h>

int main( void )
{
    TESTCASE( isalpha( 'a' ) );
    TESTCASE( isalpha( 'z' ) );
    TESTCASE( ! isalpha( ' ' ) );
    TESTCASE( ! isalpha( '1' ) );
    TESTCASE( ! isalpha( '@' ) );
    return TEST_RESULTS;
}

#endif
