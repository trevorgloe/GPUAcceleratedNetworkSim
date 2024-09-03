cmake_minimum_required(VERSION 3.5.0)
project(gans_fnc VERSION 0.1.0 LANGUAGES C CXX)

add_library(gans_fnc SHARED gans_fnc.cpp)

include(CTest)
enable_testing()

