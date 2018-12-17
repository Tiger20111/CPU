#include "workDouble.h"

#define WORK_DOUBLE(operation, num_arg)           \
  do {                                            \
    double value = 0;                             \
    bool success = true;                          \
    if (num_arg)                                    \
      success = castToDouble(line, &value);       \
                                                  \
    if (!success) {                               \
      return false;                               \
    } else {                                      \
       code.push_back(operation);                 \
       if (num_arg)                               \
         code.push_back(value);                   \
       return true;                               \
    }                                             \
  } while (false)

bool pushDouble(std::vector<double> &code, const char *line) {
  WORK_DOUBLE(11, 1);
}
bool popDouble(std::vector<double> &code) {
  const char *line = nullptr;
  WORK_DOUBLE(21, 0);
}

bool addDouble(std::vector<double> &code, const char *line) {
  WORK_DOUBLE(31, 1);
}

bool mulDouble(std::vector<double> &code, const char *line) {
  WORK_DOUBLE(41, 1);
}

bool minusDouble(std::vector<double> &code, const char *line) {
  WORK_DOUBLE(51, 1);
}

bool devideDouble(std::vector<double> &code, const char *line) {
  WORK_DOUBLE(61, 1);
}

bool sqrtDouble(std::vector<double> &code) {
  const char *line = nullptr;
  WORK_DOUBLE(71, 0);
}

