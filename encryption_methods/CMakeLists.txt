cmake_minimum_required(VERSION 3.0)

project(encryption_methods)

add_library(encryption_methods
            STATIC
            src/encryption_methods.cpp)

find_library(character_utilities_lib
             NAMES character_utilities
             HINTS ${CMAKE_SOURCE_DIR}/utilities
             NO_DEFAULT_PATH)

target_link_libraries(encryption_methods
                      character_utilities_lib)

target_include_directories(encryption_methods
                           PUBLIC include
                           INTERFACE ${CMAKE_SOURCE_DIR}/utilities/include)