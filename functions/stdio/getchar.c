/* $Id$ */

/* getchar( void )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#include <stdio.h>

#ifndef REGTEST
#include <pdclib/io.h>

int _PDCLIB_getchar_unlocked( void )
{
    return _PDCLIB_fgetc_unlocked( stdin );
}


int getchar( void )
{
    return fgetc( stdin );
}

#endif

#ifdef TEST
#include <pdclib/test.h>

int main( void )
{
    /* Testing covered by ftell.c */
    return TEST_RESULTS;
}

#endif
