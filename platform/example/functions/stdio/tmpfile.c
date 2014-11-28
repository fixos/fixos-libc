/* $Id$ */

/* tmpfile( void )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#include <stdio.h>

#ifndef REGTEST

#include <errno.h>
#include <pdclib/glue.h>

/* This is a stub implementation of tmpfile
*/
FILE* tmpfile( void )
{
    errno = ENOTSUP;
    return NULL;
}

#endif

#ifdef TEST
#include <pdclib/test.h>
#include <string.h>

int main( void )
{
    return TEST_RESULTS;
}

#endif

