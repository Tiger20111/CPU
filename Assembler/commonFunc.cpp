#include "commonFunc.h"


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