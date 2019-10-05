cmake_minimum_required(VERSION 2.6)

add_library(encryption_methods STATIC
            "include/encryption_methods.hpp"
            "src/encryption_methods.cpp")

add_executable(bottles bottles.cpp)
target_compile_options(bottles PUBLIC cxx_std_17)

add_executable(caesar_cypher caesar_cypher.cpp)
target_link_libraries(caesar_cypher encryption_methods)
target_compile_options(caesar_cypher PUBLIC cxx_std_17)

add_executable(greedy greedy.cpp)
target_compile_options(greedy PUBLIC cxx_std_17)

add_executable(initials initials.cpp)
target_compile_options(initials PUBLIC cxx_std_17)

add_executable(mario_pyramide mario_pyramide.cpp)
target_compile_options(mario_pyramide PUBLIC cxx_std_17)