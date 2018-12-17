#ifndef ASSEMBLER_WORKOPERATIVE_H
#define ASSEMBLER_WORKOPERATIVE_H

#include <vector>
#include <iostream>

#include "commonFunc.h"

bool pushOperative (std::vector<double >& code, const char* line);
bool pushOperativeFromStack(std::vector<double >& code, const char* line);
bool pushOperativeFromRegistr(std::vector<double >& code, const char* line, std::vector<std::string> &names_registers);
bool popOperativeToStack(std::vector<double >& code, const char* line);
bool popOperativeToRegistr(std::vector<double >& code, const char* line, std::vector<std::string> &names_registers);

#endif //ASSEMBLER_WORKOPERATIVE_H
