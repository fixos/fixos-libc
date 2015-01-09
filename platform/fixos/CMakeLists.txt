message("Building PDCLib for FiXos/sh3 target!")

# build POSIX functions
pdclib_set_posix(YES)

file(GLOB_RECURSE TMP_SOURCES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}/functions" "functions/*.c")
add_base_sources("${TMP_SOURCES}")
add_source_topdir("${CMAKE_CURRENT_SOURCE_DIR}/functions")
add_header_topdir("${CMAKE_CURRENT_SOURCE_DIR}/includes")

add_pdclib_option("nothread;notime;dlmalloc;tss_errno;basecodecs;c_locale")
