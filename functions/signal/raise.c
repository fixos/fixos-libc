/* $Id$ */

/* raise( int )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#include <signal.h>

#ifndef REGTEST

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int raise( int sig )
{
	return kill(getpid(), sig);
}

#endif

#ifdef TEST
#include <pdclib/test.h>

#include <stdlib.h>

static volatile sig_atomic_t flag = 0;

static int expected_signal = 0;

static void test_handler( int sig )
{
    TESTCASE( sig == expected_signal );
    flag = 1;
}

int main( void )
{
    /* Could be other than SIG_DFL if you changed the implementation. */
    TESTCASE( signal( SIGABRT, SIG_IGN ) == SIG_DFL );
    /* Should be ignored. */
    TESTCASE( raise( SIGABRT ) == 0 );
    /* Installing test handler, old handler should be returned */
    TESTCASE( signal( SIGABRT, test_handler ) == SIG_IGN );
    /* Raising and checking SIGABRT */
    expected_signal = SIGABRT;
    TESTCASE( raise( SIGABRT ) == 0 );
    TESTCASE( flag == 1 );
    /* Re-installing test handler, should have been reset to default */
    /* Could be other than SIG_DFL if you changed the implementation. */
    TESTCASE( signal( SIGABRT, test_handler ) == SIG_DFL );
    /* Raising and checking SIGABRT */
    flag = 0;
    TESTCASE( raise( SIGABRT ) == 0 );
    TESTCASE( flag == 1 );
    /* Installing test handler for different signal... */
    TESTCASE( signal( SIGTERM, test_handler ) == SIG_DFL );
    /* Raising and checking SIGTERM */
    expected_signal = SIGTERM;
    TESTCASE( raise( SIGTERM ) == 0 );
    TESTCASE( flag == 1 );
    return TEST_RESULTS;
}
#endif
