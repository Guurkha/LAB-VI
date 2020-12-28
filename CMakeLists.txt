cmake_minimum_required(VERSION 3.0.0)

project(laboratorium3extension)

include_directories(./include ./src)

add_executable(output ./src/main.cpp ./src/HRMS.cpp ./src/employee.cpp)