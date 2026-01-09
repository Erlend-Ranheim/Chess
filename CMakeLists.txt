cmake_minimum_required(VERSION 4.1)
project(Chess)

set(CMAKE_CXX_STANDARD 20)

add_executable(Chess main.cpp
        Board.cpp
        Board.h
        Game.cpp
        Move.h
)
