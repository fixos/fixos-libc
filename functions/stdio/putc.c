/* $Id$ */

/* putc( int, FILE * )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#include <stdio.h>

#ifndef REGTEST
#include <pdclib/io.h>

int _PDCLIB_putc_unlocked( int c, FILE * stream )
{
    return _PDCLIB_fputc_unlocked( c, stream );
}


int putc( int c, FILE * stream )
{
    return fputc( c, stream );
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
