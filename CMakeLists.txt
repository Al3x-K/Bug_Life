cmake_minimum_required(VERSION 3.27)
project(Bug_Life_C__)

set(CMAKE_CXX_STANDARD 17)

add_executable(Bug_Life_C__ cmake-build-debug/cppFiles/main.cpp
        cmake-build-debug/cppFiles/Bug.cpp
        cmake-build-debug/headerFiles/Bug.h
        cmake-build-debug/cppFiles/Crawler.cpp
        cmake-build-debug/headerFiles/Crawler.h
        cmake-build-debug/cppFiles/Hopper.cpp
        cmake-build-debug/headerFiles/Hopper.h
        cmake-build-debug/cppFiles/Board.cpp
        cmake-build-debug/headerFiles/Board.h
        cmake-build-debug/cppFiles/Dizzler.cpp
        cmake-build-debug/headerFiles/Dizzler.h
        cmake-build-debug/cppFiles/SuperBug.cpp
        cmake-build-debug/headerFiles/SuperBug.h
)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/Users/Asus/CLionProjects/SFML-2.6.1-windows-gcc-13.1.0-mingw-64-bit/SFML-2.6.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/Users/Asus/CLionProjects/SFML-2.6.1-windows-gcc-13.1.0-mingw-64-bit/SFML-2.6.1/include)
target_link_libraries(Bug_Life_C__ sfml-system sfml-window sfml-graphics sfml-audio)