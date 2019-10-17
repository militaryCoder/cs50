cmake_minimum_required(VERSION 3.0)

project(character_utilities)

add_library(
    character_utilities
    STATIC
    src/character_utilities.cpp
)

target_include_directories(
    character_utilities
    PUBLIC include
)