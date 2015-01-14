How to compile and install FiXos libc?
=================

Prerequisite
------------
In order to be able to build this library, you should already have :   
- a working cross GCC C compiler and binutils (libgcc may be needed, and you
 should have it by default, but no other libraries are required)   
- the FiXos kernel public headers (from FiXos kernel sources, or from an already
 compiled kernel)   
- CMake on the host machine

Let's build it!
-----------
As CMake is used, build may (and should) be done in an other directory than the
sources. You need to create a directory outside the source tree, and to run a
shell at this place.   
If you don't already have a place for FiXos toolchain includes and libraries,
you should also create a directory to install the compiled libc.   

Then, you have to prepare the CMake build system in this directory, by replacing
{path/to/something} by appropriate path :   
>    $ cmake -DCMAKE\_INSTALL\_PREFIX:PATH={path/to/install} -DCMAKE\_TOOLCHAIN\_FILE={path/to/source}fixos/fixos-sh3.cmake -DKERNEL\_HEADERS={path/to/fixos/kernel}/interface {path/to/sources}   

If you have no error, you can build FiXos with the backend used by CMake
(should be "make" on most UNIX platforms) :   
>    $ make all   

And finally to install compiled library and public headers, install it :   
>    $ make install   
