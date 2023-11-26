cmake_minimum_required(VERSION 3.27)
project(MazeGame)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
set(CMAKE_CXX_STANDARD 17)

add_executable(MazeGame main.cpp
        input_parser.cpp
        input_parser.h
        playerdata.cpp
        playerdata.h
        MazeGenerator.cpp
        MazeGenerator.h
        MazeSolver.cpp
        MazeSolver.h
        RandomNumberGenerator.cpp
        RandomNumberGenerator.h)
