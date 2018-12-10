
#ifndef CPU_COMMANDDOUBLE_H
#define CPU_COMMANDDOUBLE_H
#include "Stack.h"


bool pushDoubl(Stack <double> & stack, double element, int* error);
bool popDoubl(Stack <double> & stack, int* error);
bool mulDoubl(Stack <double> & stack, double element, int* error);
bool addDoubl(Stack <double> & stack, double element, int* error);
bool minusDoubl(Stack <double> & stack, double element, int* error);
bool devideDoubl(Stack <double> & stack, double element, int* error);
bool sqrtDoubl(Stack <double> & stack, int* error);
bool pushResistor(std::string name_resistor, int element);

#endif //CPU_COMMANDDOUBLE_H
