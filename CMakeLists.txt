cmake_minimum_required(VERSION 3.16)
project(network)

set (CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++17 -Wall -Wextra")

add_executable(network src/main.cpp src/graph.cpp src/utils.cpp src/csv_row.cpp)