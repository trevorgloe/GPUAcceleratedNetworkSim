cmake_minimum_required(VERSION 3.5.0)
project(gans_fnc VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# add_library(gans_fnc SHARED gans_fnc.cpp)
add_library(graph SHARED graph.cpp gans_fnc.cpp)

include(CTest)
enable_testing()

