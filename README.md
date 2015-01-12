FiXos userland C library (libc)
===============

What is the libc
----------------
Basically, all UNIX-like OSes and some other provide their low-level interface
as a C library.
This library contains the C standard library functions (ISO C standard), and
depending OSes, other standards such as POSIX, or OS-specific interfaces.


FiXos libc interfaces
--------------------
For FiXos, the libc is designed to be relatively close to the POSIX standard,
but doesn't try to follow it exactly (POSIX is huge!). The idea is to keep a
small and compact library, but to be enough POSIX-like to allow porting of
basic UNIX applications.

It is possible that some FiXos-specific APIs will be added to this library,
but for now the goal is to have functions and headers from the standards
implemented.


ISO C implementation - PDCLib
===================

The ISO C standard implementation comes from the [PDCLib project](http://pdclib.e43.eu),
which is a C Standard library in public domain (CC0 license).

In a first time, PDCLib was chosen to be a small ISO C library instead of Newlib,
because easier to understand fully and to extend. Finally, it appears difficult
to extend a multiplatform C standard library to transform it in a POSIX, system
specific library.
So I decided to change the way PDCLib is used, and now this library will diverge
a lot from PDCLib original project. Multiplatform support is dropped, some
functions will maybe be optimized for FiXos kernel, and the project hierarchy
will change.

It's why the name PDCLib will not be conserved in the name of the library,
but I would like to thank the authors and contributors of PDCLib for their work.


