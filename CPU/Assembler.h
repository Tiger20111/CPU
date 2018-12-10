
#ifndef CPU_ASSEMBLER_H
#define CPU_ASSEMBLER_H

#include <vector>
#include <cstring>
#include <iostream>

#include "workDouble.h"
#include "workRegistr.h"

bool pushChoose (std::vector<double>& code, const char* line);
bool popChoose(std::vector<double>& code, const char* line);
bool mulChoose(std::vector<double>& code, const char* line);
bool addChoose(std::vector<double>& code, const char* line);
void jmpChoose(std::vector<double>& code, const char* line);
bool minusChoose(std::vector<double> &code, const char *line);
bool divideChoose(std::vector<double> &code, const char *line);
bool Scanf (char* line, const char* file);


#endif
