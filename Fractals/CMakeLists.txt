cmake_minimum_required(VERSION 3.7)

project(Fractals)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

file(GLOB FRACTALS_MAIN "Source.cpp")
file(GLOB FRACTALS_SAVE_TO_IMG_MAIN "SaveFractalsToImg.cpp")

file(GLOB FRACTALS_SOURCES_ALL "*.cpp")
file(GLOB FRACTALS_HEADERS "*.hpp")

set(FRACTALS_SOURCES ${FRACTALS_SOURCES_ALL})
list(REMOVE_ITEM FRACTALS_SOURCES ${FRACTALS_MAIN})
list(REMOVE_ITEM FRACTALS_SOURCES ${FRACTALS_SAVE_TO_IMG_MAIN})

add_executable(Fractals ${FRACTALS_MAIN} ${FRACTALS_SOURCES})
target_link_libraries(Fractals ${SDL2_LIBRARIES})

message(${FRACTALS_SOURCES})

add_executable(SaveFractalsToImg ${FRACTALS_SAVE_TO_IMG_MAIN} ${FRACTALS_SOURCES})
target_link_libraries(SaveFractalsToImg ${SDL2_LIBRARIES})
