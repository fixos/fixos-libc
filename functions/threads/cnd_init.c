#ifndef REGTEST
#include <threads.h>

int cnd_init(cnd_t *cond)
{
	/* does nothing */
	return thrd_success;
}
#endif

#ifdef TEST
#include <pdclib/test.h>

int main( void )
{
    return TEST_RESULTS;
}

#endif
