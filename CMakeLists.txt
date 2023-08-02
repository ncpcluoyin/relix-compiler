cmake_minimum_required(VERSION 3.0)
project(relix-compiler)

include_directories(
	includes/rcc/
)

set(CMAKE_C_FLAGS "-O0 -g -pipe -fomit-frame-pointer")#this is for debugging

add_subdirectory(rcc)
