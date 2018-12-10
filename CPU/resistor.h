#ifndef CPU_RISISTOR_H
#define CPU_RISISTOR_H

#include "Stack.h"

#include <string>

template<typename T>
class Resistor {
 public:
  template<typename T>
  Resistor<T>::Resistor();
  inline void pushResistor(Stack <double> & stack, const int& name_resistor, T element, int *error = nullptr);
  T popResistor(Stack <double> & stack, const int &name_resistor, int *error = nullptr);
  T addResistor(Stack <double> & stack, const int &name_resistor1, const int &name_resistor2, int *error = nullptr);
  T mulResistor(Stack <double> & stack, const int &name_resistor1, const int &name_resistor2, int *error = nullptr);
  T minusResistor(Stack <double> & stack, const int &name_resistor1, const int &name_resistor2, int *error = nullptr);
  T devideResistor(Stack <double> & stack, const int &name_resistor1, const int &name_resistor2, int *error = nullptr);

  private:
  T ax;
  T bx;
  T cx;
  T dx;
  T ex;
  T fx;
  T gx;
  T hx;
  T jx;
};

template class Resistor <double>;

#endif //CPU_RISISTOR_H
