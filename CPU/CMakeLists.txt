cmake_minimum_required(VERSION 3.10)
project(MyCPU)

set(CMAKE_CXX_STANDARD 11)

add_executable(MyCPU main.cpp cpu.cpp cpu.h stack.cpp stack.h resistor.cpp resistor.h commandDouble.cpp commandDouble.h operative.cpp operative.h)