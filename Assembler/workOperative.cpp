#include "workOperative.h"

bool parsingOperative(const char* line, double* arg, double num_arg, double* index_operative);
bool pushOrPopWithRegistr(std::vector<double >& code, const char* line, std::vector<std::string> &names_registers, int push_or_pop);

bool pushOperative (std::vector<double >& code, const char* line) {
  double arg;
  double index_operative;
  double num_arg = 1;
  parsingOperative(line, &arg, num_arg, &index_operative);
  code.push_back(13);
  code.push_back(arg);
  code.push_back(index_operative);
  return true;
}

bool pushOperativeFromStack(std::vector<double >& code, const char* line) {
  double arg = 0;
  double index_operative;

  parsingOperative(line, &arg, 0, &index_operative);
  code.push_back(23);
  code.push_back(index_operative);
  return true;
}

bool pushOperativeFromRegistr(std::vector<double >& code, const char* line, std::vector<std::string> &names_registers) {
  pushOrPopWithRegistr(code, line, names_registers, 33);
}

bool popOperativeToStack(std::vector<double >& code, const char* line) {
  double value;
  double arg = 0;
  double index_operative;

  parsingOperative(line, &arg, 0, &index_operative);
  castToDouble(line, &value);
  code.push_back(43);
  code.push_back(value);
  return true;
}

bool popOperativeToRegistr(std::vector<double >& code, const char* line, std::vector<std::string> &names_registers) {
  pushOrPopWithRegistr(code, line, names_registers, 53);
}

bool pushOrPopWithRegistr(std::vector<double >& code, const char* line, std::vector<std::string> &names_registers, int push_or_pop) {
  std::string name_registr = nullptr;
  while (line[0] != ',') {
    name_registr += line[0];
    line++;
  }
  line++;

  double index_registr = nameRegistr(&name_registr, names_registers);

  double arg = 0;
  double index_operative;
  parsingOperative(line, &arg, 0, &index_operative);

  code.push_back(push_or_pop);
  code.push_back(index_registr);
  code.push_back(index_operative);
  return true;
}

bool parsingOperative(const char* line, double* arg, double num_arg, double* index_operative) {
  auto number = new char[35];
  int j = 0;
  double value = 0;

  if (num_arg > 0) {
    while (line[0] != ',') {
      number[j] = line[0];
      j++;
      line++;
    }
    number[j] = '\0';
    castToDouble(number, &value);

    *arg = value;

    line++;
  }
  j = 0;
  while (line[0] != ']') {
    number[j] = line[0];
    j++;
    line++;
  }
  while (line[0] != '\n') {
    line++;
  }

  number[j] = '\0';
  castToDouble(number, &value);

  *index_operative = value;

  return true;
}

