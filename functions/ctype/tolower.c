/* $Id$ */

/* tolower( int )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#include <ctype.h>

#ifndef REGTEST
#include <pdclib/locale.h>

int tolower( int c )
{
    return _PDCLIB_threadlocale()->_CType[c].lower;
}

#endif

#ifdef TEST
#include <pdclib/test.h>

int main( void )
{
    TESTCASE( tolower( 'A' ) == 'a' );
    TESTCASE( tolower( 'Z' ) == 'z' );
    TESTCASE( tolower( 'a' ) == 'a' );
    TESTCASE( tolower( 'z' ) == 'z' );
    TESTCASE( tolower( '@' ) == '@' );
    TESTCASE( tolower( '[' ) == '[' );
    return TEST_RESULTS;
}
#endif
