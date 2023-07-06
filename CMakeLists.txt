cmake_minimum_required(VERSION 3.17)
project(algorithm)

set(CMAKE_CXX_STANDARD 17)

add_executable(algorithm Source/main.cpp Source/SimpleTimer.cpp Header/SimpleTimer.h Header/Search.h Header/Sorting.h Header/Testing.h)