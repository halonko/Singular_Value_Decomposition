cmake_minimum_required(VERSION 3.10)
project(curs_work)

set(CMAKE_CXX_STANDARD 11)
find_package(Threads REQUIRED)

SET(Boost_USE_STATIC_LIBS OFF)
SET(Boost_USE_MULTITHREAD ON)
FIND_PACKAGE(Boost REQUIRED COMPONENTS
        )
IF(Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
    LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
ENDIF(Boost_FOUND)

include_directories(Headers)
include_directories(Sources)
add_executable(curs_work main.cpp Sources/functions.cpp Headers/functions.h Sources/Matrix.cpp Headers/Matrix.h)
target_link_libraries(curs_work Threads::Threads)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")