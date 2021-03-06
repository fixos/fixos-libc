/* _PDCLIB_initclocale( locale_t )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#ifndef REGTEST
#include <pdclib/clocale.h>
#include <pdclib/locale.h>

void _PDCLIB_initclocale( _PDCLIB_locale_t l )
{
    // TODO: There will be more added here...

    l->_WCType     = _PDCLIB_wcinfo;
    l->_WCTypeSize = _PDCLIB_wcinfo_size;
}

#endif

#ifdef TEST
#include <pdclib/test.h>

int main()
{
    return TEST_RESULTS;
}

#endif
