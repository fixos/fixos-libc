#
# Build examples, using a very simple design for now : add an executable
# for each subdirectory with all their source files...
#


file(GLOB EXAMPLES_CONTENT "./*")

message("Examples content : ${EXAMPLES_CONTENT}")

set(GENERIC_C_FLAGS  "-std=c11 -Os -nostdinc") 
set(GENERIC_LD_FLAGS "-T${CMAKE_SOURCE_DIR}/fixos/userland.ld -nostdlib -lgcc")

foreach(SUBDIR ${EXAMPLES_CONTENT})
	if(IS_DIRECTORY ${SUBDIR})
		# add its content as a new executable
		get_filename_component(SUBNAME ${SUBDIR} NAME)
		file(GLOB SUBDIR_SRC "${SUBDIR}/*.c")

		add_executable(${SUBNAME} ${SUBDIR_SRC})
		message("New example target : ${SUBNAME}, sources : ${SUBDIR_SRC}")
		
		set_target_properties(${SUBNAME} PROPERTIES COMPILE_FLAGS ${GENERIC_C_FLAGS})
		target_include_directories(${SUBNAME} SYSTEM BEFORE INTERFACE ${ALL_INCLUDE_DIRS})
		target_link_libraries(${SUBNAME} libc ${GENERIC_LD_FLAGS})

		
		# strip almost everything
		add_custom_command(TARGET ${SUBNAME} POST_BUILD
				COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${SUBNAME}> ${CMAKE_BINARY_DIR}/${SUBNAME}.big
				COMMAND ${CMAKE_STRIP} -s $<TARGET_FILE:${SUBNAME}>)

		install(TARGETS ${SUBNAME} RUNTIME DESTINATION bin/examples)
	endif(IS_DIRECTORY ${SUBDIR})
endforeach(SUBDIR)
