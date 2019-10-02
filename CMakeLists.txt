cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_FLAGS -Wall -std=c++17 -Werrors -O2)

add_executable(bottles bottles.cpp)
add_executable(caesar_cypher caesar_cypher.cpp)
add_executable(greedy greedy.cpp)
add_executable(initials initials.cpp)
add_executable(mario_pyramide mario_pyramide.cpp)