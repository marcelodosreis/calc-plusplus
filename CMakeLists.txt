cmake_minimum_required(VERSION 3.10)


project(calc-plusplus VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(calc-plusplus 
    src/main.cpp
)

enable_testing()
add_subdirectory(tests)
