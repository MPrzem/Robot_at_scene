cmake_minimum_required(VERSION 3.10)
project(IntroSort)
set(CMAKE_CXX_STANDARD 14)

include_directories(inc)
FILE(GLOB SRCS_F "src/*.cpp")
add_executable(Robot_at_scene ${SRCS_F} )
