cmake_minimum_required(VERSION 2.8)

project(weak_this)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...
set(CMAKE_CXX_EXTENSIONS OFF) #...without compiler extensions like gnu++11

add_executable(${PROJECT_NAME} "main.cpp")

target_link_libraries(${PROJECT_NAME} pthread)
