cmake_minimum_required(VERSION 3.10)

enable_testing()

add_executable(tests
    Addition-Test.cpp
    Number-Test.cpp
)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

target_link_libraries(tests gtest gtest_main pthread)

add_test(NAME unit_tests COMMAND tests)
