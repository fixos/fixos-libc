This directory is the base of the generic part of POSIX implementation and
header files.

As POSIX extends ISO C, some POSIX definitions are directly added with
appropriate guards in ISO C header files, but every header which is not
mandatory in ISO C standard should be placed here, and every function
which is ony defined by POSIX stadard should be implemented here.
Of course, POSIX function can use ISO C definitions and functions to be
implemented, and the opposite is not allowed.

It seems maybe a bit tricky to separate everything this way, but it's not so
easy to try to have both standard, with a clean way to use only the ISO C
subset if needed.

As a lot of POSIX defintions are far more platform-dependant than ISO C
standard is, many primitives and types should be defined to port posix
part of this library, and this work will probaby cause this fork of
original PDCLib to move away from their primary idea.
