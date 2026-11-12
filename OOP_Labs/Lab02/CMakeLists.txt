cmake_minimum_required(VERSION 3.20)
project(lab_02_string LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -Wpedantic -fsanitize=address)
add_link_options(-fsanitize=address)

include_directories(include)

add_library(lab_02_lib src/string.cpp)

add_executable(lab_02_exe src/main.cpp)
target_link_libraries(lab_02_exe PRIVATE lab_02_lib)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com
)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(lab_02_tests test/string_test.cpp)
target_link_libraries(lab_02_tests PRIVATE lab_02_lib gtest_main)

include(GoogleTest)
gtest_discover_tests(lab_02_tests)
