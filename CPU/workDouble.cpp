#include "workDouble.h"

#define WORK_DOUBLE(operation)                  \
  do {                                          \
    double value = 0;                           \
    bool success = castToDouble(line, &value);  \
                                                \
    if (!success) {                             \
      return false;                             \
    } else {                                    \
       code.push_back(operation);                       \
       code.push_back(value);                  \
       return true;                            \
    }                                         \
  } while (false)

bool castToDouble(char const *line, double *value);

bool pushDouble(std::vector<double> &code, const char *line) {
  WORK_DOUBLE(11);
}
bool popDouble(std::vector<double> &code) {
  code.push_back(21);
}

bool addDouble(std::vector<double> &code, const char *line) {
  WORK_DOUBLE(31);
}

bool mulDouble(std::vector<double> &code, const char *line) {
  WORK_DOUBLE(41);
}

bool minusDouble(std::vector<double> &code, const char *line) {
  WORK_DOUBLE(51);
}

bool devideDouble(std::vector<double> &code, const char *line) {
  WORK_DOUBLE(61);
}

bool sqrtDouble(std::vector<double> &code, const char *line) {
  WORK_DOUBLE(71);
}

bool castToDouble(char const *line, double *value) {
  char *ptrEnd = nullptr;
  double b = strtod(line, &ptrEnd);
  if (*ptrEnd == '\n') {
    *value = b;
    return true;
  } else {
    perror("There is no such function push with such arguments");
    return false;
  }
}