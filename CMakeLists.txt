cmake_minimum_required(VERSION 3.0)

project(cs50)

add_subdirectory(encryption_methods)

include_directories("encryption_methods/include")

add_executable(vigener_cypher "cyphers/vigener_cypher.cpp")
target_link_libraries(vigener_cypher encryption_methods)

add_executable(caesar_cypher "cyphers/caesar_cypher.cpp")
target_link_libraries(caesar_cypher encryption_methods)

add_executable(bottles "quests/bottles.cpp")
add_executable(greedy "quests/greedy.cpp")
add_executable(initials "quests/initials.cpp")
add_executable(mario_pyramide "quests/mario_pyramide.cpp")
