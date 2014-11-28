/* iswspace( wint_t )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#include <wctype.h>
#ifndef REGTEST
#include <pdclib/locale.h>

int iswspace( wint_t wc )
{
    return iswctype( wc,  _PDCLIB_CTYPE_SPACE );
}

#endif

#ifdef TEST
#include <pdclib/test.h>

int main( void )
{
    TESTCASE(iswspace(L' '));
    TESTCASE(iswspace(L'\t'));
    TESTCASE(!iswspace(L'a'));
    return TEST_RESULTS;
}
#endif
