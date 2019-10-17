cmake_minimum_required(VERSION 3.0)

project(encryption_methods)

add_library(
    encryption_methods
    STATIC src/encryption_methods.cpp
)

target_include_directories(
    encryption_methods
    PUBLIC include
    PUBLIC ${CMAKE_SOURCE_DIR}/utilities/include
)

target_link_libraries(
    encryption_methods
    character_utilities
)