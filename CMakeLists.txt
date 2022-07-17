cmake_minimum_required(VERSION 3.8)

project(Weather)

include_directories(src/headers)

file(GLOB SOURCES
    src/headers/*.hpp
    src/sources/*.cpp
)

add_executable(Weather ${SOURCES})
