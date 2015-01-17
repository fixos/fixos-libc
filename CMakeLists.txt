cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(fixos-libc C)


#set(PDCLIB_TARGET "" CACHE STRING "Target environment name for PDCLib")

# FiXos Kernel Headers path
set(KERNEL_HEADERS "" CACHE STRING "Path to the FiXos kernel headers (interface/ directory)")
# toggle generation of html documentation
option(HTML_DOC "Toggle the creation of HTML man pages (need mdocml tool)")


# check mandatory parameters
if(NOT EXISTS "${KERNEL_HEADERS}")
	message(FATAL_ERROR "KERNEL_HEADERS is not a valid directory (should be the path to kernel header files)")
endif(NOT EXISTS "${KERNEL_HEADERS}")



# prepare main source files
set(PUBLIC_INCLUDE_DIR "includes/")
set(KERNEL_INCLUDE_DIR "${KERNEL_HEADERS}")
set(ALL_INCLUDE_DIRS ${PUBLIC_INCLUDE_DIR} ${KERNEL_INCLUDE_DIR})

file(GLOB_RECURSE ALL_LIB_SOURCES "functions/*.c")



# no linker for the library itself
#set(CMAKE_EXE_LINKER_FLAGS "-nostdlib ${CMAKE_EXE_LINKER_FLAGS}")

# not used flags, which was used in the Jamrules file  "-ffunction-sections -fdata-sections"
set(C_WARNING "-Wall -Wextra -Wno-unused-parameter -Wshadow -Wpointer-arith -Wwrite-strings -Wmissing-declarations -Wno-long-long -Wuninitialized -pedantic -Wnested-externs -Wstrict-prototypes -Wmissing-prototypes")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${C_WARNING} ")

# only for libc (not for examples)
set(LIBC_C_FLAGS "-std=c11 -Os -ffreestanding -nostdinc")

message("LIBC CFLAGS: ${CMAKE_C_FLAGS} ${LIBC_C_FLAGS}")

#include_directories(BEFORE ${ALL_INCLUDE_DIRS})
#include_directories(BEFORE SYSTEM ${ALL_INCLUDE_DIRS})



#
# Build targets definitions
#

add_library(libc STATIC ${ALL_LIB_SOURCES}) 
set_target_properties(libc PROPERTIES COMPILE_FLAGS ${LIBC_C_FLAGS})
target_include_directories(libc SYSTEM BEFORE PUBLIC ${ALL_INCLUDE_DIRS})


if(${HTML_DOC})
	# add each file in man/ directory
	file(GLOB_RECURSE ALL_MAN_PAGE "man3/*.3")

	foreach(MAN_FILE ${ALL_MAN_PAGE})
		get_filename_component(FILENAME ${MAN_FILE} NAME)
		string(REGEX REPLACE "^.*\\.([0-9]*)$" "\\1" SECTION ${FILENAME})
		string(REGEX REPLACE "^(.*)\\.[0-9]*$" "\\1" PAGENAME ${FILENAME})
		set(HTML_OUTPUT "${CMAKE_BINARY_DIR}/doc/${SECTION}/${PAGENAME}.html")


		#message(WARNING "for file '${MAN_FILE} : section ${SECTION} and output ${HTML_OUTPUT}")

		file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/doc/${SECTION})
		
		add_custom_command(OUTPUT ${HTML_OUTPUT}
				COMMAND mandoc -Thtml -Ostyle=../style.css -Oincludes=../3/%I.html -Oman=../%S/%N.html ${MAN_FILE} > ${HTML_OUTPUT}
				DEPENDS ${MAN_FILE}
				WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
				VERBATIM)

		# add this command as a dependency for documantation target
		list(APPEND HTML_DOC_DEPENDENCIES ${HTML_OUTPUT})
	endforeach(MAN_FILE)

	# copy the style.css file in doc/
	add_custom_command(OUTPUT doc/style.css
			COMMAND cp ${CMAKE_SOURCE_DIR}/html/style.css doc/style.css
			DEPENDS ${CMAKE_SOURCE_DIR}/html/style.css
			VERBATIM)

	add_custom_target(documentation DEPENDS doc/style.css ${HTML_DOC_DEPENDENCIES})

	install(DIRECTORY ${CMAKE_BINARY_DIR}/doc DESTINATION ./)
endif(${HTML_DOC})



#
# Example directory
#

add_subdirectory(examples)


#
# Install directives : library and public headers
# 

install(TARGETS libc
		RUNTIME DESTINATION bin
		PUBLIC_HEADER DESTINATION include
		ARCHIVE DESTINATION lib)

install(DIRECTORY ${PUBLIC_INCLUDE_DIR}/ ${KERNEL_INCLUDE_DIR}/ DESTINATION include 
		FILES_MATCHING PATTERN "*.h")

install(DIRECTORY man3/ DESTINATION usr/man/man3 
		FILES_MATCHING PATTERN "*.3")


# create the include tree in build directory
#foreach(DIR ${ALL_INCLUDE_DIRS})
#endforeach(DIR)

# copy include dir
#install(DIRECTORY "${CMAKE_BINARY_DIR}/include" DESTINATION . )
