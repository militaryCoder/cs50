cmake_minimum_required(VERSION 3.0)

project(encryption_methods)

include_directories(include)

add_library(encryption_methods
            STATIC
            "src/encryption_methods.cpp"
            )
