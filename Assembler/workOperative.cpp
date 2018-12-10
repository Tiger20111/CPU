#include "workOperative.h"

bool parsingOperative(const char* line, double* arg, double num_arg, double* index_operative);

bool pushOperative (std::vector<double >& code, const char* line) {
  auto arg = new double[2];
  double index_operative;
  double num_arg = 1;
  parsingOperative(line, arg, num_arg, &index_operative);
  code.push_back(13);
  code.push_back(arg[0]);
  code.push_back(index_operative);
}

bool pushOperativeFromStack(std::vector<double >& code, const char* line) {
  auto arg = new double[0];
  double index_operative;
  double num_arg = 0;
  parsingOperative(line, arg, num_arg, &index_operative);
  code.push_back(23);
  code.push_back(index_operative);
  delete arg;
}

bool pushOperativeFromRegistr(std::vector<double >& code, const char* line) {

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

    arg[0] = value;
  }
  j = 0;
  while (line[0] != ']') {
    number[j] = line[0];
    j++;
    line++;
  }
  number[j] = '\0';
  castToDouble(number, &value);

  *index_operative = value;

  return true;
}
