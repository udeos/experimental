cmake_minimum_required(VERSION 3.3)
project(Experimental)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")

set(SOURCE_FILES main.c bloomfilter/bitmap.c bloomfilter/bitmap.h bloomfilter/bloomfilter.c bloomfilter/bloomfilter.h bloomfilter/hashes.c bloomfilter/hashes.h bloomfilter/utils.c bloomfilter/utils.h)
add_executable(Experimental ${SOURCE_FILES})