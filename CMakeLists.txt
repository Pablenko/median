cmake_minimum_required (VERSION 2.6)
project (median)

file(GLOB median_srcs ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_subdirectory("src/")
add_subdirectory("test/")
