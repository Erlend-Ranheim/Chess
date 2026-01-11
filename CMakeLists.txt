cmake_minimum_required(VERSION 4.1)
project(Chess)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.2
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(Chess main.cpp
        Board.cpp
        Board.h
        Game.cpp
        Move.h
        Renderer.cpp
        Renderer.h
)

target_compile_features(Chess PRIVATE cxx_std_17)
target_link_libraries(Chess PRIVATE SFML::Graphics)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Chess)