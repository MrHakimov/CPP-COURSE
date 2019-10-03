cmake_minimum_required(VERSION 3.13)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(autocomplete-template main.cpp autocomplete.cpp autocomplete.hpp
        term.cpp term.hpp binary_search_deluxe.cpp binary_search_deluxe.hpp)
