
#ifndef CPU_ASSEMBLER_H
#define CPU_ASSEMBLER_H

#include <vector>
#include <cstring>

#include <iostream>
#include <map>

#include "workDouble.h"
#include "workRegistr.h"
#include "workOperative.h"

bool pushChoose (std::vector<double>& code, const char* line, std::vector<std::string> &names_registers);
bool popChoose(std::vector<double>& code, const char* line, std::vector<std::string> &names_registers);
bool mulChoose(std::vector<double>& code, const char* line, std::vector<std::string> &names_registers);
bool addChoose(std::vector<double>& code, const char* line, std::vector<std::string> &names_registers);
bool jmpChoose(std::vector<double> &code, int command, const char *line,
               std::map <std::string, std::pair<int, std::vector<int>>> &tags, int enter);
bool minusChoose(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers);
bool divideChoose(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers);
bool sqrtChoose(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers);
bool scanfChoose(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers);
bool printfChoose(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers);
bool enterTitle(std::vector<double> &code,
                std::map <std::string, std::pair<int, std::vector<int>>> &tags);

#endif
