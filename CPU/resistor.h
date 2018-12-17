#ifndef MYCPU_RESISTOR_H
#define MYCPU_RESISTOR_H

#include "stack.h"

#include <string>
#include <cmath>


template<typename T>
class Resistor {
 public:
  Resistor();
  bool pushResistor(const int& name_resistor, T element, int *error = nullptr);
  T popResistor(const int &name_resistor, int *error = nullptr);
  bool pushResistorFromStack(Stack <double> & stack, const int &name_resistor, int *error);
  bool addResistorToStack(Stack <double> & stack, const int &name_resistor1, const int &name_resistor2, int *error = nullptr);
  bool mulResistorToStack(Stack <double> & stack, const int &name_resistor1, const int &name_resistor2, int *error = nullptr);
  bool minusResistorToStack(Stack <double> & stack, const int &name_resistor1, const int &name_resistor2, int *error = nullptr);
  bool devideResistorToStack(Stack <double> & stack, const int &name_resistor1, const int &name_resistor2, int *error = nullptr);
  bool popResistorToStack(Stack <double> & stack, const int &name_resistor, int *error);
  bool sqrtResistorToStack(Stack <double> & stack, const int &name_resistor, int *error);
  bool scanfResistor(Stack <double> & stack, const int &name_resistor, int *error);
  bool printfResistor(Stack <double> & stack, const int &name_resistor, int *error);

 private:
  T& captureRegistr(const int &name_resistor, int *error = nullptr);
  T ax;
  T bx;
  T cx;
  T dx;
  T ex;
  T fx;
  T gx;
  T hx;
  T ix;
  T jx;
};

template class Resistor <double>;

#endif //MYCPU_RESISTOR_H