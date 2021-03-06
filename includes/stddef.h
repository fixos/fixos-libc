/* $Id$ */

/* 7.17 Common definitions <stddef.h>

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#ifndef _PDCLIB_STDDEF_H
#define _PDCLIB_STDDEF_H _PDCLIB_STDDEF_H
#include <pdclib/config.h>
#include <pdclib/int.h>
_PDCLIB_BEGIN_EXTERN_C

typedef _PDCLIB_ptrdiff_t ptrdiff_t;

#define __need_size_t
#include <bits/types.h>

#ifndef __cplusplus
#ifndef _PDCLIB_WCHAR_T_DEFINED
#define _PDCLIB_WCHAR_T_DEFINED _PDCLIB_WCHAR_T_DEFINED
typedef _PDCLIB_wchar_t   wchar_t;
#endif
#endif

#ifndef _PDCLIB_NULL_DEFINED
#define _PDCLIB_NULL_DEFINED _PDCLIB_NULL_DEFINED
#define NULL _PDCLIB_NULL
#endif

#define offsetof( type, member ) _PDCLIB_offsetof( type, member )

_PDCLIB_END_EXTERN_C
#endif

