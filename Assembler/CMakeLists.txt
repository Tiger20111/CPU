cmake_minimum_required(VERSION 3.10)
project(Assembler)

set(CMAKE_CXX_STANDARD 11)

add_executable(assembler main.cpp assembler.h assembler.cpp parsingCommand.h parsingCommand.cpp workDouble.h workRegistr.h workRegistr.cpp workDouble.cpp workOperative.cpp workOperative.h commonFunc.cpp commonFunc.h)