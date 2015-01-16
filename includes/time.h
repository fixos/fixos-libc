#ifndef _PDCLIB_TIME_H
#define _PDCLIB_TIME_H
#include <pdclib/aux.h>
#include <pdclib/int.h>

_PDCLIB_BEGIN_EXTERN_C

#define __need_size_t
#define __need_time_t
#define __need_clock_t
#include <bits/types.h>

// for timespec struct
#include <bits/time.h>


#ifndef _PDCLIB_NULL_DEFINED
#define _PDCLIB_NULL_DEFINED _PDCLIB_NULL_DEFINED
#define NULL _PDCLIB_NULL
#endif

#define TIME_UTC _PDCLIB_TIME_UTC


struct tm {
	int tm_sec;
		int tm_min;
		int tm_hour;
		int tm_mday;
		int tm_mon;
		int tm_year;
		int tm_wday;
		int tm_yday;
		int tm_isdst;
};

time_t time( time_t* t ) _PDCLIB_nothrow;
int timespec_get( struct timespec *ts, int base ) _PDCLIB_nothrow;

// FIXME other time.h definitions!

_PDCLIB_END_EXTERN_C
#endif
