cmake_minimum_required(VERSION 3.27)
project(Bug_Life_C__)

set(CMAKE_CXX_STANDARD 17)

add_executable(Bug_Life_C__ main.cpp
        cmake-build-debug/cppFiles/Bug.cpp
        cmake-build-debug/headerFiles/Bug.h
        cmake-build-debug/cppFiles/Crawler.cpp
        cmake-build-debug/headerFiles/Crawler.h
        cmake-build-debug/cppFiles/Hopper.cpp
        cmake-build-debug/headerFiles/Hopper.h
        cmake-build-debug/cppFiles/Board.cpp
        cmake-build-debug/headerFiles/Board.h)
