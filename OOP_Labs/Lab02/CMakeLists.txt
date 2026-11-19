cmake_minimum_required(VERSION 3.20)
project(lab_02_string LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -Wpedantic)

if(NOT MSVC)
  add_compile_options(-fsanitize=address)
  add_link_options(-fsanitize=address)
endif()

include_directories(include)

add_library(lab_02_lib src/string.cpp)

add_executable(lab_02_exe src/main.cpp)
target_link_libraries(lab_02_exe PRIVATE lab_02_lib)

find_package(GTest QUIET)
if(NOT GTest_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.2
  )
  FetchContent_MakeAvailable(googletest)
endif()

enable_testing()
add_executable(lab_02_tests test/string_test.cpp)
target_link_libraries(lab_02_tests PRIVATE lab_02_lib GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(lab_02_tests)
