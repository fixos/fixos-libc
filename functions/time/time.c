#include <time.h>

#ifndef REGTEST
time_t time(time_t* t)
{
	if(t) *t = -1;
	return -1;
}
#endif

#ifdef TEST
#include <pdclib/test.h>

int main( void )
{
    return TEST_RESULTS;
}

#endif
