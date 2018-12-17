#ifndef CPU_WORKREGISTR_H
#define CPU_WORKREGISTR_H

#include <vector>
#include <cstring>
#include <iostream>

bool pushRegistr(std::vector<double >& code, const char* line, std::vector<std::string> &names_registers);
bool popRegistrToStack(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers);
bool addRegistrToStack(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers);
bool mulRegistrToStack(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers);
bool minusRegistrToStack(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers);
bool devideRegistrToStack(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers);
bool pushRegistrFromStack(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers);
bool sqrtRegistrToStack(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers);
bool scanfRegistr(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers);
bool printfRegistr(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers);

#endif //CPU_WORKREGISTR_H
