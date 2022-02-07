cmake_minimum_required(VERSION 3.16)
project(ld64)

enable_language(CXX)

message(STATUS "Checking if the compiler is clang")
if (NOT CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    message(FATAL_ERROR "Compiler is not Clang, please install clang before continuing")
endif()
message(STATUS "Checking if the compiler is clang - done")

message(STATUS "Checking if pkg-config is availible...")
include(FindPkgConfig)
message(STATUS "Checking if pkg-config is availible... - done")


# Check for BSD libraries on Linux, Utopia already has them
# We dont use IF LINUX and NOT UTOPIAOS as that is deprecated... https://discourse.cmake.org/t/platform-id-vs-win32-vs-cmake-system-name/1226
if(CMAKE_SYSTEM_NAME STREQUAL "Linux" AND NOT CMAKE_SYSTEM_NAME STREQUAL "UtopiaOS")
    message(STATUS "Checking if libbsd overlay is availible...")
    pkg_check_modules(BSD_OVERLAY REQUIRED libbsd-overlay)
endif()


add_subdirectory(src)

