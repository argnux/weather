cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)

project(Weather)

include_directories(src/headers)

file(GLOB SOURCES
    src/headers/*.hpp
    src/sources/*.cpp
)

find_package(Boost COMPONENTS system filesystem program_options REQUIRED)
find_package(Threads REQUIRED)

add_executable(Weather ${SOURCES})

target_link_libraries(Weather
                        dl
                        Threads::Threads
                        Boost::system
                        Boost::filesystem
                        Boost::program_options)
