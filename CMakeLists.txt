cmake_minimum_required(VERSION 2.8.4)
project(first)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp geometry.h)
add_executable(first ${SOURCE_FILES})