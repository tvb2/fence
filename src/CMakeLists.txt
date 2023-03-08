cmake_minimum_required(VERSION 3.0.0)
project(fence VERSION 0.1.0)

add_executable(fence main.cpp)

target_include_directories(fence PUBLIC {INCLUDE_DIR})