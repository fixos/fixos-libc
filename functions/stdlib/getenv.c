/* $Id$ */

/* getenv( const char * )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#include <string.h>
#include <stdlib.h>

#ifndef REGTEST

char * getenv( const char * name )
{
	size_t name_length = strlen(name);
	if( environ == NULL || name_length == 0 )
		return NULL;
    int i;
    for(i=0; environ[i] != NULL; i++) {
    	if( memcmp(name, environ[i], name_length) == 0 ) {
            char *ptr = environ[i] + name_length;
			// name should be directly followed by an '=' char
			if(*ptr == '=')
				return ptr + 1; // let out the prefix and the = character.
        }
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
