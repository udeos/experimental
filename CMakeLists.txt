cmake_minimum_required(VERSION 3.3)
project(Experimental)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")

set(SOURCE_FILES main.c bloomfilter/bitmap.c bloomfilter/bitmap.h)
add_executable(Experimental ${SOURCE_FILES})