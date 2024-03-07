cmake_minimum_required(VERSION 3.27)
project(Project2_cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(Project2_cpp main.cpp
        RoadSection.h
        RoadSection.cpp
        RoadSpeed.h
        RoadSpeed.cpp
        RoadVolume.h
        RoadVolume.cpp
        FileHandler.h
        FileHandler.cpp)
