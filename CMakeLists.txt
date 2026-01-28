cmake_minimum_required(VERSION 3.10)
project(dining_philosophers LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(philosophers
    src/main.cpp
    src/table.cpp
    src/philosopher.cpp
    src/logger.cpp
)

target_include_directories(philosophers PRIVATE include)
