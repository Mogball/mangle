cmake_minimum_required(VERSION 3.1.0)
project(mangle C)

add_subdirectory(lib/slex)

file(GLOB_RECURSE HEADERS src/*.h)
file(GLOB_RECURSE SOURCES src/*.c)

add_executable(mangle ${HEADERS} ${SOURCES})
set_property(TARGET mangle PROPERTY C_STANDARD 99)
