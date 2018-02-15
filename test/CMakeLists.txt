set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++17 -Wall")

find_package(GTest REQUIRED)
find_package (Threads)

include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/src)

file(GLOB median_tests_src "*.hpp" "*.cpp")
list(REMOVE_ITEM median_tests_src ${CMAKE_SOURCE_DIR}/src/main.cpp)

add_executable(median_tests ${median_tests_src})
target_link_libraries(median_tests ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
