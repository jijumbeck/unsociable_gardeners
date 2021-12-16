cmake_minimum_required(VERSION 3.20)
project(unsociable_gardeners)

set(CMAKE_CXX_STANDARD 14)

add_executable(unsociable_gardeners main.cpp gardener.cpp gardener.h garden.cpp garden.h gardenCell.cpp gardenCell.h)
