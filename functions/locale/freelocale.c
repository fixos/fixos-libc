/* freelocale( locale_t )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#include <locale.h>
#ifndef REGTEST
#include <pdclib/locale.h>
#include <assert.h>

void freelocale( _PDCLIB_locale_t newloc )
{
    if( newloc != NULL ) {
        assert( ! "Not implemented" );
    }
}

#endif

#ifdef TEST
#include <pdclib/test.h>

int main( void )
{
    TESTCASE( NO_TESTDRIVER );
    return TEST_RESULTS;
}
#endif
