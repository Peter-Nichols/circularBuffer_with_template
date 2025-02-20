#cmake_minimum_required(VERSION 3.31.3)
project(CircularBuffer_Simple VERSION 0.1.0 LANGUAGES C CXX)

add_library(circularBuffer STATIC)
target_sources(circularBuffer PRIVATE CircularBuffer.cpp)
target_include_directories(circularBuffer PUBLIC "include")

#add_subdirectory(test)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
