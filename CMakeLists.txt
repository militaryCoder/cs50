cmake_minimum_required(VERSION 3.10)

project(cs50)

add_subdirectory(utilities)
add_subdirectory(encryption_methods)

add_executable(
    vigener_cypher
    cyphers/vigener_cypher.cpp
)
target_link_libraries(
    vigener_cypher
    encryption_methods
)
target_include_directories(
    vigener_cypher
    PUBLIC encryption_methods/include
)
                           

add_executable(
    caesar_cypher
    cyphers/caesar_cypher.cpp
)
target_link_libraries(
    caesar_cypher
    encryption_methods
    character_utilities
)
target_include_directories(
    caesar_cypher
    PUBLIC encrytion_methods/include
)


add_executable(
    bottles
    quests/bottles.cpp
)

add_executable(
    greedy
    quests/greedy.cpp
)
set_target_properties(
    greedy PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED TRUE
)


add_executable(
    initials
    quests/initials.cpp
)

add_executable(
    mario_pyramide
    quests/mario_pyramide.cpp
)
set_target_properties(
    mario_pyramide PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED TRUE
)
