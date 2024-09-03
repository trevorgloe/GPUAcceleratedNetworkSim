cmake_minimum_required(VERSION 3.5.0)
project(graph_fcn VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_library(graph_fcn SHARED graph_fcn.cpp)

include(CTest)
enable_testing()

