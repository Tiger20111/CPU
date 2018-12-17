#include "workRegistr.h"

#define TRANSLATE_TO_NUMBER(num_arg)                      \
  do {                                                    \
    int z = 0;                                            \
    while (z < (num_arg)) {                                 \
      for (int i = 0; i < names_registers.size(); i++) {  \
        if (arg[z] == names_registers[i])                 \
          com_arg[z] = i;                                 \
      }                                                   \
      z++;                                                \
    }                                                     \
  } while (false)




#define WORK_REGISTR(operation, num_arg)                \
  do {                                                  \
    int k = 0;                                          \
                                                        \
    code.push_back(operation);                          \
    while (k < (num_arg)) {                               \
      code.push_back(com_arg[k]);                       \
      k++;                                              \
    }                                                   \
    return true;                                        \
  } while (false)


#define OPERATIONS_WITH_REGISTRS(operation, num_arg, type_operation)   \
  do {                                                  \
    auto *arg = new std::string[num_arg];               \
    auto *com_arg = new double[num_arg];                \
                                                        \
    bool success = ParsingRegistr(arg, num_arg, line);  \
    if (!success) return false;                         \
    TRANSLATE_TO_NUMBER(num_arg);                       \
    if ((type_operation) == 1) {                          \
      castToDouble(arg[1], &com_arg[1]);                \
    }                                                   \
    WORK_REGISTR(operation, num_arg);                         \
                                                        \
    delete[] arg;                                       \
    delete[] com_arg;                                   \
} while (false)


bool ParsingRegistr(std::string *arg, int num_arg, const char *line);
bool castToDouble(std::string s, double *value);

bool pushRegistr(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers) {
  OPERATIONS_WITH_REGISTRS(12, 2,

                           1);
}

bool popRegistrToStack(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers) {
  OPERATIONS_WITH_REGISTRS(62, 1, 0);
}

bool addRegistrToStack(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers) {
  OPERATIONS_WITH_REGISTRS(22, 2, 0);
}

bool mulRegistrToStack(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers) {
  OPERATIONS_WITH_REGISTRS(32, 2, 0);
}

bool minusRegistrToStack(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers) {
  OPERATIONS_WITH_REGISTRS(42, 2, 0);
}

bool devideRegistrToStack(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers) {
  OPERATIONS_WITH_REGISTRS(52, 2, 0);
}

bool pushRegistrFromStack(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers) {
  OPERATIONS_WITH_REGISTRS(72, 1, 0);
}

bool sqrtRegistrToStack(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers) {
  OPERATIONS_WITH_REGISTRS(82, 1, 0);
}

bool scanfRegistr(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers) {
  OPERATIONS_WITH_REGISTRS(92, 1, 0);
}

bool printfRegistr(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers) {
  OPERATIONS_WITH_REGISTRS(102, 1, 0);
}

bool ParsingRegistr(std::string *arg, int num_arg, const char *line) {
  int k = 0;
  int number_arg = 0;

  while (line[k] != '\n' && line[k] != '\0') {
    if (line[k] == ' ') {
      number_arg++;
      k++;
      continue;
    }
    if (number_arg >= num_arg) {
      return false;
    }
    arg[number_arg] += line[k];
    k++;
  }

  return true;
}

//!!
bool castToDouble(std::string s, double *value) {
  char *ptrEnd = nullptr;
  *value = atof(s.c_str());
  return true;
}



///не тестировано
///не безопасно
///не доделано