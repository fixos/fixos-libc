cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(pdclib C)


set(PDCLIB_TARGET "" CACHE STRING "Target environment name for PDCLib")

# functions used to manipulate sources files
function(add_base_sources FILES) 
	message("Added files : ${FILES}")
	set_property(GLOBAL APPEND PROPERTY BaseSourceFiles ${FILES})
endfunction(add_base_sources)

function(add_source_topdir DIR) 
	message("Added union top directory : ${DIR}")
	set_property(GLOBAL APPEND PROPERTY SourceTopdirs ${DIR})
endfunction(add_source_topdir)


function(add_public_headers FILES) 
	message("Added public headers : ${FILES}")
	set_property(GLOBAL APPEND PROPERTY BaseHeaderFiles ${FILES})
endfunction(add_public_headers)

function(add_header_topdir FILES) 
	message("Added header top directory : ${FILES}")
	set_property(GLOBAL APPEND PROPERTY HeaderTopdirs ${FILES})
endfunction(add_header_topdir)


function(add_pdclib_option OPT)
	message("Added PDCLib options : ${OPT}")
	set_property(GLOBAL APPEND PROPERTY LibOptions ${OPT})
endfunction(add_pdclib_option)

function(pdclib_set_posix ENABLE)
	set_property(GLOBAL PROPERTY PDCLibPosixEnable ${ENABLE})
endfunction(pdclib_set_posix)


# prepare target directory (now only FiXos, PDCLIB_TARGET is not more used)
#if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/platform/${PDCLIB_TARGET}")
	add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/fixos")
#else()
#	message(FATAL_ERROR "Not found target platform '${PDCLIB_TARGET}'.")
#endif()


# prepare each option directory
get_property(ALL_OPTIONS GLOBAL PROPERTY LibOptions)
foreach(OPT ${ALL_OPTIONS})
	# FIXME more or less that :
	#add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/opt/${OPT}")

	file(GLOB TMP_SOURCES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}/opt/${OPT}" "opt/${OPT}/*.c")
	add_base_sources("${TMP_SOURCES}")
	add_source_topdir("${CMAKE_CURRENT_SOURCE_DIR}/opt/${OPT}")
	add_header_topdir("${CMAKE_CURRENT_SOURCE_DIR}/opt/${OPT}")
endforeach(OPT)


# prepare POSIX source and header tree if needed
get_property(POSIX_ENABLE GLOBAL PROPERTY PDCLibPosixEnable)
if(${POSIX_ENABLE})
	file(GLOB_RECURSE TMP_SOURCES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}/posix/functions" "posix/functions/*.c")
	add_base_sources("${TMP_SOURCES}")
	add_source_topdir("${CMAKE_CURRENT_SOURCE_DIR}/posix/functions")
	add_header_topdir("${CMAKE_CURRENT_SOURCE_DIR}/posix/includes")
endif()



# prepare main source files
file(GLOB_RECURSE TMP_SOURCES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}/functions" "functions/*.c")
add_base_sources("${TMP_SOURCES}")
add_source_topdir("${CMAKE_CURRENT_SOURCE_DIR}/functions")
add_header_topdir("${CMAKE_CURRENT_SOURCE_DIR}/includes")



# glue everything...
get_property(ALL_SOURCE_DIRS GLOBAL PROPERTY SourceTopdirs)
get_property(ALL_BASE_SOURCES GLOBAL PROPERTY BaseSourceFiles)
#message("> ${ALL_SOURCE_DIRS}")
#message("> ${ALL_BASE_SOURCES}")
foreach(SRCFILE ${ALL_BASE_SOURCES})
	foreach(CDIR ${ALL_SOURCE_DIRS})
#message("Testing ${CDIR}/${SRCFILE}")
		if(EXISTS ${CDIR}/${SRCFILE})
			set(PDCLIB_SOURCES ${PDCLIB_SOURCES} "${CDIR}/${SRCFILE}")
			break()
		endif()
	endforeach(CDIR)
endforeach(SRCFILE)

get_property(ALL_INCLUDE_DIRS GLOBAL PROPERTY HeaderTopdirs)
include_directories(BEFORE ${ALL_INCLUDE_DIRS})
include_directories(BEFORE SYSTEM ${ALL_INCLUDE_DIRS})




#set(CMAKE_EXE_LINKER_FLAGS "-nostdlib ${CMAKE_EXE_LINKER_FLAGS}")

# not used flags, which was used in the Jamrules file  "-ffunction-sections -fdata-sections"
set(C_WARNING "-Wall -Wextra -Wno-unused-parameter -Wshadow -Wpointer-arith -Wwrite-strings -Wmissing-declarations -Wno-long-long -Wuninitialized -pedantic -Wnested-externs -Wstrict-prototypes -Wmissing-prototypes")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${C_WARNING} -std=c11 -Os -ffreestanding -nostdinc")
message("CFLAGS: ${CMAKE_C_FLAGS}")


add_library(pdclib STATIC ${PDCLIB_SOURCES}) 
#set_target_properties(pdclib PROPERTIES PUBLIC_HEADER ${PDCLIB_HEADER})



#
# Install directives : library and public headers
# 

install(TARGETS pdclib
		RUNTIME DESTINATION bin
		PUBLIC_HEADER DESTINATION include
		ARCHIVE DESTINATION lib)


# create the include tree in build directory
foreach(DIR ${ALL_INCLUDE_DIRS})
	# for now, get all the files, no priority...
	file(GLOB_RECURSE TMP_HEADERS RELATIVE "${DIR}" "${DIR}/*.h")
	foreach(HEADER ${TMP_HEADERS})
		get_filename_component(HEADER_DIR ${HEADER} PATH)
		file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/include/${HEADER_DIR}") 
		file(COPY "${DIR}/${HEADER}" DESTINATION "${CMAKE_BINARY_DIR}/include/${HEADER_DIR}")
	endforeach(HEADER)
endforeach(DIR)

# copy include dir
install(DIRECTORY "${CMAKE_BINARY_DIR}/include" DESTINATION . )
