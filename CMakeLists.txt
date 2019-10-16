cmake_minimum_required(VERSION 3.0)

project(cs50)

include_directories("encryption_methods/include"
                    "character_utilities/include")

add_subdirectory(encryption_methods)
add_subdirectory(utilities)

add_executable(vigener_cypher "cyphers/vigener_cypher.cpp")
target_link_libraries(vigener_cypher encryption_methods)

add_executable(caesar_cypher "cyphers/caesar_cypher.cpp")
target_link_libraries(caesar_cypher encryption_methods)

add_executable(bottles "quests/bottles.cpp")

add_executable(greedy "quests/greedy.cpp")
target_compile_features(greedy PUBLIC cxx_std_17)

add_executable(initials "quests/initials.cpp")

add_executable(mario_pyramide "quests/mario_pyramide.cpp")
target_compile_features(mario_pyramide PUBLIC cxx_std_17)
