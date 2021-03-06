/* $Id$ */

/* getc( FILE * )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#include <stdio.h>

#ifndef REGTEST
#include <pdclib/io.h>
   
int _PDCLIB_getc_unlocked( FILE * stream )
{
    return _PDCLIB_fgetc_unlocked( stream );
}

int getc( FILE * stream )
{
    return fgetc( stream );
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
