// ----------------------------------------------------------------------------
// $Id$
// ----------------------------------------------------------------------------
// Public Domain C Library - http://pdclib.sourceforge.net
// This code is Public Domain. Use, modify, and redistribute at will.
// ----------------------------------------------------------------------------
// Errors
// ----------------------------------------------------------------------------

#ifndef __ERRNO_H
#define __ERRNO_H __ERRNO_H

// TODO: Documentation

// ----------------------------------------------------------------------------
// DECLARATIONS

extern int errno;

// ----------------------------------------------------------------------------
// DEFINES

#define EDOM      1 // domain error
#define EILSEQ    2 // illegal (multibyte) sequence
#define ERANGE    3 // range error

#endif // __ERRNO_H
