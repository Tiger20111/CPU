#ifndef MYCPU_COMMANDDOUBLE_H
#define MYCPU_COMMANDDOUBLE_H

#include "stack.h"


bool pushDoubl(Stack <double> & stack, double element, int* error);
bool popDoubl(Stack <double> & stack, int* error);
bool mulDoubl(Stack <double> & stack, double element, int* error);
bool addDoubl(Stack <double> & stack, double element, int* error);
bool minusDoubl(Stack <double> & stack, double element, int* error);
bool devideDoubl(Stack <double> & stack, double element, int* error);
bool sqrtDoubl(Stack <double> & stack, int* error);
bool inDouble(Stack <double> & stack, int* error);
bool outDouble(Stack <double> & stack, int* error);

#endif //MYCPU_COMMANDDOUBLE_H
