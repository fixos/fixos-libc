#ifndef REGTEST
#include <threads.h>
#include <windows.h>

void mtx_destroy(mtx_t *mtx)
{
    CloseHandle(mtx->_WaitEvHandle);
}
#endif

#ifdef TEST
#include <pdclib/test.h>

int main( void )
{
    return TEST_RESULTS;
}

#endif