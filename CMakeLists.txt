cmake_minimum_required(VERSION 3.13)
project(curs_work)

set(CMAKE_CXX_STANDARD 11)
find_package(Threads REQUIRED)

include_directories(Headers)
include_directories(Sources)
add_executable(curs_work main.cpp Sources/functions.cpp Headers/functions.h Headers/Matrix.cpp Headers/Matrix.h)
target_link_libraries(curs_work Threads::Threads)