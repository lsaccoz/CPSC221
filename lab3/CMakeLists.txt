cmake_minimum_required(VERSION 3.6)
project(lab3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    CDate.cc
    CDate.h
    dates.cc
    linked_list.cc
    linked_list.h
    lists.cc
    Makefile)

add_executable(lab3 ${SOURCE_FILES})