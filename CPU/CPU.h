#ifndef CPU_CPU_H
#define CPU_CPU_H

#include <vector>
#include <cstring>
#include <iostream>
#include <limits>
#include <cmath>

#include "CommandDouble.h"
#include "Assembler.h"
#include "Stack.h"
#include "resistor.h"

#define DefoltHard 0

#define CRASH_NORMAL 10013

class CPU {
  public:
    bool DisAssembler(const char* file = nullptr, int hard = DefoltHard); //Assembler //program1
    bool Compiler();                                                                  //program2

    CPU();
    explicit CPU(int size);                       // constructor
    ~CPU();
  private:
    int error;
    char* line_;
    std::vector<double> code_;
};

#endif //CPU_CPU_H
