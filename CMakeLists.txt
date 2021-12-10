cmake_minimum_required(VERSION 3.0.0)
project(lab VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/054a986a8513149e8374fc669a5fe40117ca6b41.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

if (MSVC)
	add_compile_options(/Wall)
else()
	add_compile_options(
		-Wall
		-Wextra
		-pedantic-errors
		-Wconversion
	)
endif()

file (GLOB SOURCES input.cpp calculation.cpp print.cpp)

add_executable(code code.cpp ${SOURCES})

enable_testing()

add_executable(tests tests.cpp ${SOURCES})

target_link_libraries(
  tests
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)

