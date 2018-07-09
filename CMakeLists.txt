cmake_minimum_required(VERSION 2.8.9)
project (running_median)
add_subdirectory (gtest)

set(CMAKE_CXX_STANDARD 11)
include_directories(include)

file(GLOB SOURCES src/heap.cpp src/running_median.cpp )

add_executable(running_median ${SOURCES} src/main.cpp)


file(GLOB_RECURSE TEST_SOURCES  tests/*.cpp)
add_executable(run_tests ${TEST_SOURCES} ${SOURCES})
target_link_libraries(run_tests ${GTEST_LIBRARIES} pthread gtest)