cmake_minimum_required(VERSION 3.16)
project(dining_philosophers LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(dining_philosophers
    src/main.cpp
)

target_include_directories(dining_philosophers PRIVATE src)