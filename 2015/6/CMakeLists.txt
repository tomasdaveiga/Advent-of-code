cmake_minimum_required(VERSION 3.25)
project(6)

set(CMAKE_CXX_STANDARD 17)

add_library(lightGrid lightGrid.cpp)

add_executable(6 main.cpp)

target_link_libraries(6 lightGrid)