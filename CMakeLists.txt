cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(fixos-libc C)


#set(PDCLIB_TARGET "" CACHE STRING "Target environment name for PDCLib")

# FiXos Kernel Headers path
set(KERNEL_HEADERS "" CACHE STRING "Path to the FiXos kernel headers (interface/ directory)")

if(NOT EXISTS "${KERNEL_HEADERS}")
	message(FATAL_ERROR "KERNEL_HEADERS is not a valid directory (should be the path to kernel header files)")
endif(NOT EXISTS "${KERNEL_HEADERS}")


# prepare target directory (now only FiXos, PDCLIB_TARGET is not more used)
#add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/fixos")



# prepare main source files
set(PUBLIC_INCLUDE_DIR "includes/")
set(KERNEL_INCLUDE_DIR "${KERNEL_HEADERS}")
set(ALL_INCLUDE_DIRS ${PUBLIC_INCLUDE_DIR} ${KERNEL_INCLUDE_DIR})

file(GLOB_RECURSE ALL_LIB_SOURCES "functions/*.c")


include_directories(BEFORE ${ALL_INCLUDE_DIRS})
include_directories(BEFORE SYSTEM ${ALL_INCLUDE_DIRS})


# no linker for the library itself
#set(CMAKE_EXE_LINKER_FLAGS "-nostdlib ${CMAKE_EXE_LINKER_FLAGS}")

# not used flags, which was used in the Jamrules file  "-ffunction-sections -fdata-sections"
set(C_WARNING "-Wall -Wextra -Wno-unused-parameter -Wshadow -Wpointer-arith -Wwrite-strings -Wmissing-declarations -Wno-long-long -Wuninitialized -pedantic -Wnested-externs -Wstrict-prototypes -Wmissing-prototypes")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${C_WARNING} -std=c11 -Os -ffreestanding -nostdinc")
message("CFLAGS: ${CMAKE_C_FLAGS}")


add_library(libc STATIC ${ALL_LIB_SOURCES}) 


#set_target_properties(libc PROPERTIES PUBLIC_HEADER ${PUBLIC_INCLUDE_DIR})



#
# Install directives : library and public headers
# 

install(TARGETS libc
		RUNTIME DESTINATION bin
		PUBLIC_HEADER DESTINATION include
		ARCHIVE DESTINATION lib)

install(DIRECTORY ${PUBLIC_INCLUDE_DIR} DESTINATION include PATTERN "${PUBLIC_INCLUDE_DIR}/*.h" )
install(DIRECTORY ${KERNEL_INCLUDE_DIR} DESTINATION include PATTERN "${KERNEL_INCLUDE_DIR}/*.h" )


# create the include tree in build directory
#foreach(DIR ${ALL_INCLUDE_DIRS})
#endforeach(DIR)

# copy include dir
#install(DIRECTORY "${CMAKE_BINARY_DIR}/include" DESTINATION . )
