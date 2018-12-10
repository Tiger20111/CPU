#ifndef CPU_WORKREGISTR_H
#define CPU_WORKREGISTR_H

#include <vector>
#include <cstring>
#include <iostream>

bool pushRegistr(std::vector<double >& code, const char* line, std::vector<std::string> &names_registers);
bool popRegistr(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers);
bool addRegistr(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers);
bool mulRegistr(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers);
bool minusRegistr(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers);
bool devideRegistr(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers);
bool sqrtRegistr(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers);

#endif //CPU_WORKREGISTR_H
