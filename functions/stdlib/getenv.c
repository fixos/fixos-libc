/* $Id$ */

/* getenv( const char * )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

/* This is a stub implementation of getenv
*/

#include <string.h>
#include <stdlib.h>

#ifndef REGTEST

char * getenv( const char * name )
{
	size_t name_length = strlen(name);
	if( environ == NULL || name_length == NULL )
		return NULL;
    int i = 0;
    while ( environ[i] != NULL )
    {
    	if( memcmp(name, environ[i], name_length) == 0 ) {
            char *ptr = environ[i];
            while(*ptr != '=') ptr++;
    		return ptr + 1; // let out the prefix and the = character.
        }
    	++i;
    }
    return NULL;
}

#endif

#ifdef TEST
#include <pdclib/test.h>

int main( void )
{
    return TEST_RESULTS;
}

#endif
