cmake_minimum_required(VERSION 3.28)
project(VK_1stage)

set(CMAKE_CXX_STANDARD 20)

add_library(graph graph.cpp graph.h)

add_executable(main main.cpp)

target_link_libraries(main graph)
