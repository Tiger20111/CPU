#ifndef ASSEMBLER_ASSEMBLER_H
#define ASSEMBLER_ASSEMBLER_H

#include <vector>
#include <cstring>
#include <iostream>
#include <limits>
#include <cmath>

#include "parsingCommand.h"

#define DefoltHard 0

#define CRASH_NORMAL 10013

class Assembler {
 public:
  bool Assemble(const char* output = nullptr, const char* input = nullptr, int hard = DefoltHard); //Assembler //program1


  Assembler();
  explicit Assembler(int size);                       // constructor
  ~Assembler();
 private:
  bool endAssembler(const char *output, std::vector<double> &code);
  bool Scanf(char *line, FILE* input);
  bool InputNamesRegisters();

  int error;
  char* line_;
  std::vector<double> code_;
  std::vector<std::string> names_registers;
};

#endif //ASSEMBLER_ASSEMBLER_H
