cmake_minimum_required(VERSION 3.25)
project(samolot)

set(CMAKE_CXX_STANDARD 23)

set(PROJECT_HEADERS
        samolot.h
        pasazerowie.h
        )
set(PROJECT_SOURCES
        main.cpp
        samolot.cpp
        pasazerowie.cpp
        )

add_executable(samolot ${PROJECT_SOURCES} ${PROJECT_HEADERS})
