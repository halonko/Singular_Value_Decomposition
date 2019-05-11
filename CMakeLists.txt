cmake_minimum_required(VERSION 3.10)
project(curs_work)

set(CMAKE_CXX_STANDARD 11)
find_package(Threads REQUIRED)
find_package(OpenCV REQUIRED)

include_directories(Headers)
include_directories(Sources)
add_executable(curs_work main.cpp Sources/functions.cpp Headers/functions.h Sources/Matrix.cpp Headers/Matrix.h Sources/read_image.cpp Headers/read_image.h)
target_link_libraries(curs_work Threads::Threads ${OpenCV_LIBS} )