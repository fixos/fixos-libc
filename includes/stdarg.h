/* $Id$ */

/* 7.15 Variable arguments <stdarg.h> 

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#ifndef _PDCLIB_STDARG_H
#define _PDCLIB_STDARG_H _PDCLIB_STDARG_H
#include <pdclib/aux.h>
_PDCLIB_BEGIN_EXTERN_C

/**
 * As the FiXos libc is intended to be used with GCC, we are using its
 * builtins.
 */

typedef __builtin_va_list va_list;

#define va_arg( ap, type )    __builtin_va_arg( ap, type )
#define va_copy( dest, src )  __builtin_va_copy( dest, src )
#define va_end( ap )          __builtin_va_end( ap )
#define va_start( ap, parmN ) __builtin_va_start( ap, parmN )

_PDCLIB_END_EXTERN_C
#endif

