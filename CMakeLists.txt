cmake_minimum_required(VERSION 3.10)
project(lab_vectors LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(benchmark REQUIRED)
add_subdirectory(task_01)

add_subdirectory(task_02)
