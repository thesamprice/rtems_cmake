cmake_minimum_required (VERSION 2.8.12)
project (CMakeHelloWorld C ASM)

#
# Start of things that should be in a toolchain
#
#Set the pkg config path to where rtems packages are
SET(ENV{RTEMS_PATH} /home/sprice5/opt/rtems/6)
SET(ENV{RTEMS_BSP_NAME} kcu105_cpu0)
SET(CMAKE_SYSTEM_PROCESSOR microblaze)
SET(CMAKE_SYSTEM_VERSION 6)
SET(CMAKE_SYSTEM_NAME rtems)
# Change the pkg config path so cmake can find the rtems bsp .pc file
SET(ENV{PKG_CONFIG_PATH} $ENV{RTEMS_PATH}/lib/pkgconfig)

find_package(PkgConfig REQUIRED)
pkg_search_module(PKG_RTEMS REQUIRED IMPORTED_TARGET ${CMAKE_SYSTEM_PROCESSOR}-${CMAKE_SYSTEM_NAME}${CMAKE_SYSTEM_VERSION}-$ENV{RTEMS_BSP_NAME})

# TODO Should sysroot be set?
#set(CMAKE_SYSROOT "/opt/rtems/6/lib/pkgconfig")

# Set the rtems tool names
SET(TARGETPREFIX $ENV{RTEMS_PATH}/bin/${CMAKE_SYSTEM_PROCESSOR}-${CMAKE_SYSTEM_NAME}${CMAKE_SYSTEM_VERSION}-)
SET(CMAKE_C_COMPILER            ${TARGETPREFIX}gcc)
SET(CMAKE_CXX_COMPILER          ${TARGETPREFIX}g++)
SET(CMAKE_LINKER                ${TARGETPREFIX}ld)
SET(CMAKE_ASM_COMPILER          ${TARGETPREFIX}as)
SET(CMAKE_STRIP                 ${TARGETPREFIX}strip)
SET(CMAKE_NM                    ${TARGETPREFIX}nm)
SET(CMAKE_AR                    ${TARGETPREFIX}ar)
SET(CMAKE_OBJDUMP               ${TARGETPREFIX}objdump)
SET(CMAKE_OBJCOPY               ${TARGETPREFIX}objcopy)

# Seems like package config uses ; in flags, replace with spaces
string( REPLACE  ";" " " PKG_RTEMS_LDFLAGS "${PKG_RTEMS_LDFLAGS}")
string( REPLACE  ";" " " PKG_RTEMS_CFLAGS "${PKG_RTEMS_CFLAGS}")
string( REPLACE  ";" " " PKG_RTEMS_STATIC_LDFLAGS "${PKG_RTEMS_STATIC_LDFLAGS}")
# -B/opt/rtems/6/microblaze-rtems6/kcu105_cpu0/lib -qrtems -Wall  -L/opt/rtems/6/microblaze-rtems6/kcu105_cpu0/lib
set(PKG_RTEMS_CFLAGS "${PKG_RTEMS_CFLAGS} -qrtems -B$ENV{RTEMS_PATH}/${CMAKE_SYSTEM_PROCESSOR}-${CMAKE_SYSTEM_NAME}${CMAKE_SYSTEM_VERSION}/$ENV{RTEMS_BSP_NAME}/lib")

# Update flags, best practicie is to use _INIT, settings may need to be set
set(CMAKE_C_FLAGS   ${PKG_RTEMS_CFLAGS} )
set(CMAKE_CXX_FLAGS ${PKG_RTEMS_CFLAGS})
set(CMAKE_ASM_FLAGS "-mlittle-endian" )
string(REPLACE "-mno-xl-soft-div" "" CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS}")
string(REPLACE "-mno-xl-soft-mul" "" CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS}")

set(CMAKE_EXE_LINKER_FLAGS_INIT ${PKG_RTEMS_LDFLAGS})
set(CMAKE_SHARED_LINKER_FLAGS_INIT ${PKG_RTEMS_STATIC_LDFLAGS})
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS ${PKG_RTEMS_STATIC_LDFLAGS})
#set( CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "" )
set( CMAKE_C_FLAGS_INIT PKG_RTEMS_CFLAGS)

# Include the linker script
set(LINKER_SCRIPT "$ENV{RTEMS_PATH}/${CMAKE_SYSTEM_PROCESSOR}-${CMAKE_SYSTEM_NAME}${CMAKE_SYSTEM_VERSION}/$ENV{RTEMS_BSP_NAME}/lib/linkcmds")
message( ${LINKER_SCRIPT})
# search for programs in the build host directories
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM   NEVER)

# for libraries and headers in the target directories
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY   ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE   ONLY)

SET(CMAKE_PREFIX_PATH                   /)
#
# End of things that should be moved to a toolchain file
#
#version number
set (CMakeHelloWorld_VERSION_MAJOR 1)
set (CMakeHelloWorld_VERSION_MINOR 0)


## DEBUG print out all variables 
# get_cmake_property(_variableNames VARIABLES)
# list (SORT _variableNames)
# foreach (_variableName ${_variableNames})
#     message(STATUS "${_variableName}=${${_variableName}}")
# endforeach()

#include the subdirectory containing our libs


# execute_process(COMMAND tar -cf ${CMAKE_BINARY_DIR}/config.tar -C ${CMAKE_SOURCE_DIR}/rootfs . )
# execute_process(COMMAND $ENV{RTEMS_PATH}/bin/rtems-bin2c ${CMAKE_BINARY_DIR}/config.tar ${CMAKE_BINARY_DIR}/rootfs)
# SET(CMAKE_ASM_FLAGS "${CFLAGS} -x assembler-with-cpp")

add_executable (fseek_stress_test 
	# microblaze_disable_icache.s
	# microblaze_disable_dcache.s
#	src/divi3.S
	# src/modsi3.S
	# src/umodsi3.S
	init.c
	hello.c
	# rootfs.c
)
# set_property(SOURCE microblaze_disable_icache.s APPEND PROPERTY COMPILE_OPTIONS "-x" "assembler-with-cpp")
# set_property(SOURCE microblaze_disable_dcache.s APPEND PROPERTY COMPILE_OPTIONS "-x" "assembler-with-cpp")

target_link_libraries(fseek_stress_test PUBLIC
        bsd
      rtemsbsp
   rtemscpu
    rtemsdefaultconfig
)
# Indicate which libraries to include during the link process.
install (TARGETS fseek_stress_test DESTINATION bin)
