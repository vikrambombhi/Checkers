cmake_minimum_required(VERSION 3.3)
project(Checkers)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    include/CheckersBoard.h
    include/SDL_util.h
    src/AI.cpp
    src/CheckersBoard.cpp
    src/main.cpp
    src/SDL_util.cpp)

add_executable(Checkers ${SOURCE_FILES})