/* Encoding support <_PDCLIB_encoding.h>

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#ifndef _PDCLIB_ENCODING_H
#define _PDCLIB_ENCODING_H _PDCLIB_ENCODING_H
#include "_PDCLIB_int.h"

#ifndef __cplusplus
typedef _PDCLIB_int_least16_t   _PDCLIB_char16_t;
typedef _PDCLIB_int_least32_t   _PDCLIB_char32_t;
#else
typedef char16_t                _PDCLIB_char16_t;
typedef char32_t                _PDCLIB_char32_t;
#endif

#ifdef _PDCLIB_WCHAR_IS_UCS2
/* Must be cauued with bufsize >= 1, in != NULL, out != NULL, ps != NULL
 *
 * Converts a wchar to a UCS4 (char32_t) value. Returns
 *   1, 2   : Valid character (converted to UCS-4)
 *   -1     : Encoding error
 *   -2     : Partial character (only lead surrogate in buffer)
 */
static inline int _PDCLIB_wcrtoc32(
            _PDCLIB_char32_t    *_PDCLIB_restrict   out, 
    const   _PDCLIB_wchar_t     *_PDCLIB_restrict   in,
            _PDCLIB__PDCLIB_size_t                          bufsize,
            _PDCLIB_mbstate_t   *_PDCLIB_restrict   ps  
)
{
    if(ps->_Surrogate) {
        // We already have a lead surrogate
        if(*in & ~0x3FF != 0xDC00) {
            // Encoding error
            return -1;
        } else {
            // Decode and reset state
            *out = (ps->_Surrogate & 0x3FF) << 10 | (*in & 0x3FF);
            ps->_Surrogate = 0;
            return 1;
        }
    } if(*in & ~0x3FF == 0xD800) {
        // Lead surrogate
        if(bufsize >= 2) {
            // Buffer big enough
            if(in[1] & ~0x3FF != 0xDC00) {
                // Encoding error
                return -1;
            } else {
                *out = (in[0] & 0x3FF) << 10 | (in[1] & 0x3FF);
                return 2;
            }
        } else {
            // Buffer too small - update state
            ps->_Surrogate = *in;
            return -2;
        }
    } else {
        // BMP character
        *out = *in;
        return 1;
    }
}

static inline _PDCLIB_size_t _PDCLIB_c32rtowc(
            _PDCLIB_wchar_t     *_PDCLIB_restrict   out,
    const   _PDCLIB_char32_t    *_PDCLIB_restrict   in,
            _PDCLIB__PDCLIB_size_t                          bufsize,
            _PDCLIB_mbstate_t   *_PDCLIB_restrict   ps
)
{
    if(ps->_Surrogate) {
        *out = ps->_Surrogate;
        ps->_Surrogate = 0;
        return 0;
    }

    if(*in <= 0xFFFF) {
        // BMP character
        *out = *in;
        return 1;
    } else {
        // Supplementary plane character
        *out = 0xD800 | (*in & 0x3FF);
        if(bufsize >= 2) {
            out[1] = 0xDC00 | (*in >> 10);
            return 2;
        } else {
            ps->_Surrogate = 0xDC00 | (*in >> 10);
            return 1;
        }
    }
}
#else
/* Dummy implementation for when wc == c32 */
static inline _PDCLIB_size_t _PDCLIB_wcrtoc32(
            _PDCLIB_char32_t    *_PDCLIB_restrict   out, 
    const   _PDCLIB_wchar_t     *_PDCLIB_restrict   in,
            _PDCLIB__PDCLIB_size_t                          bufsize,
            _PDCLIB_mbstate_t   *_PDCLIB_restrict   ps  
)
{
    *out = *in;
    return 1;
}

static inline _PDCLIB_size_t _PDCLIB_c32rtowc(
            _PDCLIB_wchar_t     *_PDCLIB_restrict   out,
    const   _PDCLIB_char32_t    *_PDCLIB_restrict   in,
            _PDCLIB__PDCLIB_size_t                          bufsize,
            _PDCLIB_mbstate_t   *_PDCLIB_restrict   ps
)
{
    *out = *in;
    return 1;
}
#endif

typedef struct {
    _PDCLIB_bool_t (*__mbtoc32)(
        _PDCLIB_char32_t       **_PDCLIB_restrict   _P_outbuf,
        _PDCLIB_size_t          *_PDCLIB_restrict   _P_outsz,
        const char             **_PDCLIB_restrict   _P_inbuf,
        _PDCLIB_size_t          *_PDCLIB_restrict   _P_insz,
        _PDCLIB_mbstate_t       *_PDCLIB_restrict   _P_ps
    );

    _PDCLIB_bool_t (*__c32tomb)(
        char                   **_PDCLIB_restrict  _P_outbuf,
        _PDCLIB_size_t          *_PDCLIB_restrict  _P_outsz,
        const _PDCLIB_char32_t **_PDCLIB_restrict  _P_inbuf,
        _PDCLIB_size_t          *_PDCLIB_restrict  _P_insz,
        _PDCLIB_mbstate_t       *_PDCLIB_restrict  _P_ps
    );
} _PDCLIB_charcodec;

#endif
