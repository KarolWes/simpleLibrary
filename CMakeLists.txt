cmake_minimum_required(VERSION 3.25)
project(biblioteka)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(biblioteka
        magazyn_lib.cpp
        magazyn_lib.h
        main.cpp)
