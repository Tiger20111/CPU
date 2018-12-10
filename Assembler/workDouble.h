
#ifndef CPU_WORKDOUBLE_H
#define CPU_WORKDOUBLE_H

#include <vector>
#include <cstring>
#include <iostream>

#include "commonFunc.h"

bool pushDouble (std::vector<double >& code, const char* line);
bool popDouble (std::vector<double >& code);
bool addDouble (std::vector<double >& code, const char* line);
bool mulDouble (std::vector<double >& code, const char* line);
bool minusDouble (std::vector<double >& code, const char* line);
bool devideDouble (std::vector<double >& code, const char* line);
bool sqrtDouble(std::vector<double> &code);

#endif
