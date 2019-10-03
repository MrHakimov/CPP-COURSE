cmake_minimum_required(VERSION 3.13)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(randomized_queue_n_deque
        main.cpp
        deque.hpp
        randomized_queue.hpp
        subset.cpp)
