
#ifndef MYCPU_CPU_H
#define MYCPU_CPU_H

#include <vector>
#include <cstring>
#include <iostream>
#include <limits>
#include <cmath>

#include "commandDouble.h"
#include "stack.h"
#include "resistor.h"
#include "operative.h";
#include "jump.h"

#define DEFOULT_HARD 0
#define SIZE_FILE 100

#define CRASH_NORMAL 10013

class CPU {
 public:
  bool Compiler(const char* fread);                                                                  //program2

  CPU();
  explicit CPU(int size);                       // constructor
  ~CPU();
 private:
  bool isEqual(double x, double y);
  bool Scanf(const char* input);

  int error;
  char* line_;
  std::vector<double> code_;
};

#endif //MYCPU_CPU_H
