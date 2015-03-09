/* $Id$ */

/* signal( int sig, void (*func)( int ) )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#include <signal.h>

#ifndef REGTEST

void (*signal( int sig, void (*func)( int ) ) )( int )
{
	struct sigaction act;
	struct sigaction oldact;

	act.sa_handler = func;
	sigemptyset(& act.sa_mask);
	act.sa_flags = 0;

	if(sigaction(sig, &act, &oldact) == 0) {
		return oldact.sa_handler;
	}
	return (void (*)(int))SIG_ERR;
}

#endif

#ifdef TEST
#include <pdclib/test.h>

int main( void )
{
    /* Testing covered by raise.c */
    return TEST_RESULTS;
}
#endif
