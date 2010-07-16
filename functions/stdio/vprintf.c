/* $Id$ */

/* vprintf( const char *, va_list arg )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#include <stdio.h>
#include <stdarg.h>

#ifndef REGTEST

int vprintf( const char * _PDCLIB_restrict format, _PDCLIB_va_list arg )
{
    return vfprintf( stdout, format, arg );
}

#endif

#ifdef TEST
#include <limits.h>
#include <string.h>
#include <_PDCLIB_test.h>

static int testprintf( FILE * stream, size_t n, const char * format, ... )
{
    int i;
    va_list arg;
    va_start( arg, format );
    i = vprintf( format, arg );
    va_end( arg );
    return i;
}

int main( void )
{
    FILE * buffer;
    TESTCASE( ( buffer = freopen( "testfile", "wb", stdout ) ) != NULL );
#include "printf_testcases.incl"
    TESTCASE( fclose( buffer ) == 0 );
    char readbuffer[1000];
    TESTCASE( ( buffer = fopen( "testfile", "rb" ) ) != NULL );
    TESTCASE( fread( readbuffer, 1, 1000, buffer ) == 985 );
    TESTCASE( fclose( buffer ) == 0 );
    TESTCASE( remove( "testfile" ) == 0 );
    TESTCASE( memcmp( readbuffer, "-1281270-32768327670-214748364821474836470-214748364821474836470-922337203685477580892233720368547758070255255655356553542949672954294967295429496729542949672951844674407370955161518446744073709551615FFFFFFFF0XFFFFFFFFffffffff0xffffffff37777777777037777777777%.0#o-2147483648+2147483647+042949672954294967295-2147483648 2147483647 042949672954294967295-21474836482147483647-21474836482147483647-2147483648 2147483647 -2147483648  2147483647-21474836482147483647-21474836482147483647-21474836482147483647 -2147483648 2147483647  -21474836482147483647-21474836482147483647-214748364802147483647-02147483648002147483647-21474836482147483647-21474836482147483647-21474836482147483647 -2147483648 2147483647            00000000002147483647ffffffff0xffffffff0xffffffff-2147483648-2147483648-21474836480xffffffff0xffffffff0xffffffff214748364721474836472147483647+2147483647+2147483647+2147483647+2147483647+2147483647+2147483647- 2147483647- 2147483647 % -2147483648xabcdef0xdeadbeef123456789", 985 ) == 0 );
    return TEST_RESULTS;
}

#endif
