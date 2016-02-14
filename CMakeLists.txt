cmake_minimum_required(VERSION 3.3)
project(Checkers)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES AI.cpp)
add_executable(Checkers ${SOURCE_FILES})