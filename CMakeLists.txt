cmake_minimum_required(VERSION 3.10)
project(curs_work)

set(CMAKE_CXX_STANDARD 17)
include_directories(Headers)
include_directories(Sources)
find_package(Threads REQUIRED)
find_package(OpenCV REQUIRED)
find_package(Eigen3 3.3 REQUIRED NO_MODULE)

include_directories(Headers)
include_directories(Sources)
add_executable(curs_work main.cpp Sources/functions.cpp Headers/functions.h Sources/my_matrix.cpp Headers/my_matrix.h Sources/read_functions.cpp Headers/read_functions.h Headers/time_count.h)
target_link_libraries(curs_work Threads::Threads ${OpenCV_LIBS} Eigen3::Eigen)