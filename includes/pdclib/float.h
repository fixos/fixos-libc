#ifndef __PDCLIB_PDCLIB_FLOAT_H
#define __PDCLIB_PDCLIB_FLOAT_H __PDCLIB_PDCLIB_FLOAT_H

/* PDCLib internal floating point logic <_PDCLIB_float.h>

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

/* IEEE 754 single precision */
#define _PDCLIB_FP_SINGLE_MIN 1.17549435082228750797e-38
#define _PDCLIB_FP_SINGLE_EPSILON 1.19209289550781250000e-7
#define _PDCLIB_FP_SINGLE_HAS_DENORM 1
#define _PDCLIB_FP_SINGLE_MIN_EXP -125
#define _PDCLIB_FP_SINGLE_MANT_DIG 24
#define _PDCLIB_FP_SINGLE_RADIX 2
#define _PDCLIB_FP_SINGLE_HAS_QUIET_NAN 1
#define _PDCLIB_FP_SINGLE_MAX_10_EXP 38
#define _PDCLIB_FP_SINGLE_HAS_INFINITY 1
#define _PDCLIB_FP_SINGLE_DIG 6
#define _PDCLIB_FP_SINGLE_MAX_EXP 128
#define _PDCLIB_FP_SINGLE_DENORM_MIN 1.40129846432481707092e-45
#define _PDCLIB_FP_SINGLE_MAX 3.40282346638528859812e+38
#define _PDCLIB_FP_SINGLE_MIN_10_EXP -37

/* IEEE 754 double precision */
#define _PDCLIB_FP_DOUBLE_MIN_EXP -1021
#define _PDCLIB_FP_DOUBLE_DENORM_MIN 4.94065645841246544177e-324
#define _PDCLIB_FP_DOUBLE_MIN_10_EXP -307
#define _PDCLIB_FP_DOUBLE_DIG 15
#define _PDCLIB_FP_DOUBLE_MAX 1.79769313486231570815e+308
#define _PDCLIB_FP_DOUBLE_HAS_INFINITY 1
#define _PDCLIB_FP_DOUBLE_MAX_EXP 1024
#define _PDCLIB_FP_DOUBLE_MIN 2.22507385850720138309e-308
#define _PDCLIB_FP_DOUBLE_HAS_DENORM 1
#define _PDCLIB_FP_DOUBLE_HAS_QUIET_NAN 1
#define _PDCLIB_FP_DOUBLE_MANT_DIG 53
#define _PDCLIB_FP_DOUBLE_EPSILON 2.22044604925031308085e-16
#define _PDCLIB_FP_DOUBLE_MAX_10_EXP 308

/* IEEE 754 80-bit extended precision */
#define _PDCLIB_FP_EXTENDED_MAX 1.18973149535723176502e+4932
#define _PDCLIB_FP_EXTENDED_MAX_EXP 16384
#define _PDCLIB_FP_EXTENDED_HAS_INFINITY 1
#define _PDCLIB_FP_EXTENDED_MIN 3.36210314311209350626e-4932
#define _PDCLIB_FP_EXTENDED_HAS_QUIET_NAN 1
#define _PDCLIB_FP_EXTENDED_HAS_DENORM 1
#define _PDCLIB_FP_EXTENDED_EPSILON 1.08420217248550443401e-19
#define _PDCLIB_FP_EXTENDED_MANT_DIG 64
#define _PDCLIB_FP_EXTENDED_MIN_EXP (-16381)
#define _PDCLIB_FP_EXTENDED_MAX_10_EXP 4932
#define _PDCLIB_FP_EXTENDED_DENORM_MIN 3.64519953188247460253e-4951
#define _PDCLIB_FP_EXTENDED_MIN_10_EXP (-4931)
#define _PDCLIB_FP_EXTENDED_DIG 18

/* TODO: IEEE754 quadruple precision (_PDCLIB_FP_QUADRUPLE_*) and
         "double-double" math
 */

#define _PDCLIB_FLT_RADIX       ((float) _PDCLIB_concat3( _PDCLIB_FP_, _PDCLIB_FLOAT_TYPE, _RADIX ))
#define _PDCLIB_FLT_MANT_DIG    _PDCLIB_concat3( _PDCLIB_FP_, _PDCLIB_FLOAT_TYPE, _MANT_DIG )
#define _PDCLIB_FLT_DIG         _PDCLIB_concat3( _PDCLIB_FP_, _PDCLIB_FLOAT_TYPE, _DIG )
#define _PDCLIB_FLT_EPSILON     ((float) _PDCLIB_concat3( _PDCLIB_FP_, _PDCLIB_FLOAT_TYPE, _EPSILON ))
#define _PDCLIB_FLT_MIN_EXP     _PDCLIB_concat3( _PDCLIB_FP_, _PDCLIB_FLOAT_TYPE, _MIN_EXP )
#define _PDCLIB_FLT_MIN         ((float) _PDCLIB_concat3( _PDCLIB_FP_, _PDCLIB_FLOAT_TYPE, _MIN ))
#define _PDCLIB_FLT_MIN_10_EXP  _PDCLIB_concat3( _PDCLIB_FP_, _PDCLIB_FLOAT_TYPE, _MIN_10_EXP )
#define _PDCLIB_FLT_MAX_EXP     _PDCLIB_concat3( _PDCLIB_FP_, _PDCLIB_FLOAT_TYPE, _MAX_EXP )
#define _PDCLIB_FLT_MAX         ((float) _PDCLIB_concat3( _PDCLIB_FP_, _PDCLIB_FLOAT_TYPE, _MAX ))
#define _PDCLIB_FLT_MAX_10_EXP  _PDCLIB_concat3( _PDCLIB_FP_, _PDCLIB_FLOAT_TYPE, _MAX_10_EXP )

#define _PDCLIB_DBL_RADIX       ((double) _PDCLIB_concat3( _PDCLIB_FP_, _PDCLIB_DOUBLE_TYPE, _RADIX ))
#define _PDCLIB_DBL_MANT_DIG    _PDCLIB_concat3( _PDCLIB_FP_, _PDCLIB_DOUBLE_TYPE, _MANT_DIG )
#define _PDCLIB_DBL_DIG         _PDCLIB_concat3( _PDCLIB_FP_, _PDCLIB_DOUBLE_TYPE, _DIG )
#define _PDCLIB_DBL_EPSILON     ((double) _PDCLIB_concat3( _PDCLIB_FP_, _PDCLIB_DOUBLE_TYPE, _EPSILON ))
#define _PDCLIB_DBL_MIN_EXP     _PDCLIB_concat3( _PDCLIB_FP_, _PDCLIB_DOUBLE_TYPE, _MIN_EXP )
#define _PDCLIB_DBL_MIN         ((double) _PDCLIB_concat3( _PDCLIB_FP_, _PDCLIB_DOUBLE_TYPE, _MIN ))
#define _PDCLIB_DBL_MIN_10_EXP  _PDCLIB_concat3( _PDCLIB_FP_, _PDCLIB_DOUBLE_TYPE, _MIN_10_EXP )
#define _PDCLIB_DBL_MAX_EXP     _PDCLIB_concat3( _PDCLIB_FP_, _PDCLIB_DOUBLE_TYPE, _MAX_EXP )
#define _PDCLIB_DBL_MAX         ((double) _PDCLIB_concat3( _PDCLIB_FP_, _PDCLIB_DOUBLE_TYPE, _MAX ))
#define _PDCLIB_DBL_MAX_10_EXP  _PDCLIB_concat3( _PDCLIB_FP_, _PDCLIB_DOUBLE_TYPE, _MAX_10_EXP )

#define _PDCLIB_LDBL_RADIX       ((long double) _PDCLIB_concat3( _PDCLIB_FP_, _PDCLIB_LDOUBLE_TYPE, _RADIX ))
#define _PDCLIB_LDBL_MANT_DIG    _PDCLIB_concat3( _PDCLIB_FP_, _PDCLIB_LDOUBLE_TYPE, _MANT_DIG )
#define _PDCLIB_LDBL_DIG         _PDCLIB_concat3( _PDCLIB_FP_, _PDCLIB_LDOUBLE_TYPE, _DIG )
#define _PDCLIB_LDBL_EPSILON     ((long double) _PDCLIB_concat3( _PDCLIB_FP_, _PDCLIB_LDOUBLE_TYPE, _EPSILON ))
#define _PDCLIB_LDBL_MIN_EXP     _PDCLIB_concat3( _PDCLIB_FP_, _PDCLIB_LDOUBLE_TYPE, _MIN_EXP )
#define _PDCLIB_LDBL_MIN         ((long double) _PDCLIB_concat3( _PDCLIB_FP_, _PDCLIB_LDOUBLE_TYPE, _MIN ))
#define _PDCLIB_LDBL_MIN_10_EXP  _PDCLIB_concat3( _PDCLIB_FP_, _PDCLIB_LDOUBLE_TYPE, _MIN_10_EXP )
#define _PDCLIB_LDBL_MAX_EXP     _PDCLIB_concat3( _PDCLIB_FP_, _PDCLIB_LDOUBLE_TYPE, _MAX_EXP )
#define _PDCLIB_LDBL_MAX         ((long double) _PDCLIB_concat3( _PDCLIB_FP_, _PDCLIB_LDOUBLE_TYPE, _MAX ))
#define _PDCLIB_LDBL_MAX_10_EXP  _PDCLIB_concat3( _PDCLIB_FP_, _PDCLIB_LDOUBLE_TYPE, _MAX_10_EXP )

#endif
