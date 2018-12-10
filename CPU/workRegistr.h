#ifndef CPU_WORKREGISTR_H
#define CPU_WORKREGISTR_H

#include <vector>
#include <cstring>
#include <iostream>

bool pushRegistr(std::vector<double >& code, const char* line);
bool popRegistr(std::vector<double> &code, const char *line);
bool addRegistr(std::vector<double> &code, const char *line);
bool mulRegistr(std::vector<double> &code, const char *line);
bool minusRegistr(std::vector<double> &code, const char *line);
bool devideRegistr(std::vector<double> &code, const char *line);
bool sqrtDouble(std::vector<double> &code, const char *line);

#endif //CPU_WORKREGISTR_H
