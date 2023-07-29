cmake_minimum_required(VERSION 3.0)
project(relix-compiler)

include_directories(
    ${PROJECT_SOURCE_DIR}/includes/rcc/
)

set(CMAKE_C_FLAGS "-O0 -g -fomit-frame-pointer")

add_subdirectory(rcc)