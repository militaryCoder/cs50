cmake_minimum_required(VERSION 2.6)

project(cs50)

add_library(encryption_methods STATIC
            "include/encryption_methods.hpp"
            "src/encryption_methods.cpp")

add_executable(bottles "src/quests/bottles.cpp")

add_executable(caesar_cypher "src/cyphers/caesar_cypher.cpp")
target_link_libraries(caesar_cypher encryption_methods)

add_executable(greedy "src/quests/greedy.cpp")

add_executable(initials "src/quests/initials.cpp")

add_executable(mario_pyramide "src/quests/mario_pyramide.cpp")