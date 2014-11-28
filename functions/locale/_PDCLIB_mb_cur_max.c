/* _PDCLIB_mb_cur_max( void ) 

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#include <locale.h>
#ifndef REGTEST
#include <pdclib/locale.h>
#include <pdclib/encoding.h>

size_t _PDCLIB_mb_cur_max( void )
{
    return _PDCLIB_threadlocale()->_Codec->__mb_max;
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
