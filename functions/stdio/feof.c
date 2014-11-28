/* $Id$ */

/* feof( FILE * )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#include <stdio.h>

#ifndef REGTEST
#include <pdclib/io.h>

int _PDCLIB_feof_unlocked( FILE * stream )
{
    return stream->status & _PDCLIB_EOFFLAG;
}

int feof( FILE * stream )
{
    _PDCLIB_flockfile( stream );
    int eof = _PDCLIB_feof_unlocked( stream );
    _PDCLIB_funlockfile( stream );
    return eof;
}

#endif

#ifdef TEST
#include <pdclib/test.h>

int main( void )
{
    /* Testing covered by clearerr(). */
    return TEST_RESULTS;
}

#endif

