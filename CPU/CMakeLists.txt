cmake_minimum_required(VERSION 3.10)
project(CPU)

set(CMAKE_CXX_STANDARD 11)

add_executable(CPU main.cpp CPU.h CPU.cpp Assembler.cpp Assembler.h workDouble.h workDouble.cpp CommandDouble.h CommandDouble.cpp Stack.h Stack.cpp resistor.h resistor.cpp workRegistr.h workRegistr.cpp workOperative.h workOperative.cpp Operative.cpp Operative.h)