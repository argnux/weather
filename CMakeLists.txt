cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)

project(Weather)

include_directories(src/headers)

file(GLOB SOURCES
    src/headers/*.hpp
    src/sources/*.cpp
)

file(
  DOWNLOAD
  https://github.com/cpm-cmake/CPM.cmake/releases/download/v0.42.0/CPM.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake
  EXPECTED_HASH SHA256=66639bcac9dd2907b2918de466783554c1334446b9874e90d38e3778d404c2ef
)
include(${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake)
include(FetchContent)
include(ExternalProject)

CPMAddPackage(
        NAME Boost
        GITHUB_REPOSITORY boostorg/boost
        GIT_TAG boost-1.88.0
)
find_package(Boost COMPONENTS system filesystem program_options beast property_tree dll REQUIRED)
find_package(Threads REQUIRED)

add_executable(Weather ${SOURCES})

target_link_libraries(Weather
                        dl
                        Threads::Threads
                        Boost::system
                        Boost::filesystem
                        Boost::program_options
                        Boost::property_tree
                        Boost::beast
                        Boost::dll)
