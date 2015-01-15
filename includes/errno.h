/* 7.5 Errors <errno.h>

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#ifndef _PDCLIB_ERRNO_H
#define _PDCLIB_ERRNO_H _PDCLIB_ERRNO_H
#include <pdclib/int.h>

_PDCLIB_BEGIN_EXTERN_C

extern int * _PDCLIB_errno_func( void );
#define errno (*_PDCLIB_errno_func())

// errno values
#include <bits/errno.h>

_PDCLIB_END_EXTERN_C
#endif

