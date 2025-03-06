cmake_minimum_required(VERSION 3.28)
project(OptimalQuickSort)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(OptimalQuickSort
        OptimalQuickSort.cpp
        OptimalQuickSort.h)
