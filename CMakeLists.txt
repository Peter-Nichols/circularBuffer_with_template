#[[

]]#

cmake_minimum_required(VERSION 3.31.3)

project(CircularBuffer
    VERSION 1.0.0
    DESCRIPTION "A simple circular buffer (ring buffer) implemented using C++"
    LANGUAGES C CXX)

include(CTest)
enable_testing()

include(FetchContent)
FetchContent_Declare(
   googletest
   GIT_REPOSITORY https://github.com/google/googletest.git
   GIT_TAG        v1.15.2
)

FetchContent_MakeAvailable(googletest)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(circularBuffer)
target_link_libraries(${PROJECT_NAME} PUBLIC circularBuffer)

target_link_libraries(${PROJECT_NAME} PUBLIC gtest)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
include(CTest)
