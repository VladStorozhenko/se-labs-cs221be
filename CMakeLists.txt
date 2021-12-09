cmake_minimum_required(VERSION 3.20)
project(Lab5)

set(CMAKE_CXX_STANDARD 17)

#set(SOURCE_FILES main.cpp checks.cpp calculate.cpp)
set(SOURCE_FILES tests.cpp)

#set(SOURCE_FILES main.cpp checks.cpp calculate.cpp tests.cpp)


add_executable(Lab5 ${SOURCE_FILES})

enable_testing()
add_subdirectory(googletest)
include_directories(googletest/googletest/include)
target_link_libraries(Lab5 gtest gtest_main)
