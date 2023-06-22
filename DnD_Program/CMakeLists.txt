cmake_minimum_required(VERSION 3.25)
project(DnD_Program)

set(CMAKE_CXX_STANDARD 17)

add_executable(DnD_Program main.cpp stats.h stats.cpp combat.h enemy_stats.h enemy_stats.cpp)
