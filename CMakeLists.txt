cmake_minimum_required(VERSION 3.15)
project(breakout)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5.1 COMPONENTS graphics window system REQUIRED)

add_executable(breakout main.cpp)

target_link_libraries(breakout sfml-graphics sfml-window sfml-system)
