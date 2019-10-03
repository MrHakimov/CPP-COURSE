cmake_minimum_required(VERSION 3.13)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(8-puzzle main.cpp
        board.cpp board.hpp
        solver.cpp solver.hpp)
