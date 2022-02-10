cmake_minimum_required(VERSION 3.21)
project(OS)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

find_package (Threads)

add_executable(OS main.cpp CriticalSection.cpp CriticalSection.h)

target_link_libraries (OS ${CMAKE_THREAD_LIBS_INIT})