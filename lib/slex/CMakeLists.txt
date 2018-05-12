cmake_minimum_required(VERSION 3.1.0)
project(slex C)

file(GLOB HEADERS *.h)
file(GLOB SOURCES *.c)

add_library(slex ${HEADERS} ${SOURCES})
set_property(TARGET slex PROPERTY C_STANDARD 99)
