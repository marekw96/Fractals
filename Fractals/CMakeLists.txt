cmake_minimum_required(VERSION 3.7)

project(Fractals)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

file(GLOB FRACTALS_SOURCES "*.cpp")
file(GLOB FRACTALS_HEADERS "*.hpp")

add_executable(Fractals ${FRACTALS_SOURCES})
target_link_libraries(Fractals ${SDL2_LIBRARIES})
