cmake_minimum_required(VERSION 3.5.0)
project(network VERSION 0.1.0 LANGUAGES C CXX)

add_executable(network graph_fcn.cpp network.cpp)

include(CTest)
enable_testing()

