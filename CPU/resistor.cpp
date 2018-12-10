#include "resistor.h"

template<typename T>
Resistor<double>::Resistor() {
  ax = 0;
  bx = 0;
  cx = 0;
  dx = 0;
  ex = 0;
  fx = 0;
  gx = 0;
  hx = 0;
  jx = 0;
}

template<typename T>
inline void Resistor<T>::pushResistor(Stack <double> & stack, const int &name_resistor, T element, int *error) {
  switch (name_resistor) {
    case 1:
      ax = element;
      break;
    case 2:
      bx = element;
      break;
    case 3:
      cx = element;
      break;
    case 4:
      dx = element;
      break;
    case 5:
      ex = element;
      break;
    case 6:
      fx = element;
      break;
    case 7:
      gx = element;
      break;
    case 8:
      hx = element;
      break;
    case 9:
      jx = element;
      break;
    default:
      break;
  }
}

template<typename T>
T Resistor<T>::popResistor(Stack <double> & stack, const int &name_resistor, int *error) {
  switch (name_resistor) {
    case 1:
      return ax;
    case 2:
      return bx;
    case 3:
      return cx;
    case 4:
      return dx;
    case 5:
      return ex;
    case 6:
      return fx;
    case 7:
      return gx;
    case 8:
      return hx;
    case 9:
      return jx;
    default:
      perror("Something was happen");
      return -1;
  }
}

template<typename T>
T Resistor<T>::addResistor(Stack <double> & stack, const int &name_resistor1, const int &name_resistor2, int *error) {
  auto element = popResistor(stack, name_resistor1) + popResistor(stack, name_resistor2);
  stack.push(element);
  return element;
}

template<typename T>
T Resistor<T>::mulResistor(Stack <double> & stack, const int &name_resistor1, const int &name_resistor2, int *error) {
  auto element = popResistor(stack, name_resistor1) * popResistor(stack, name_resistor2);
  stack.push(element);
  return element;
}

template<typename T>
T Resistor<T>::minusResistor(Stack <double> & stack, const int &name_resistor1, const int &name_resistor2, int *error) {
  auto element = popResistor(stack, name_resistor1) - popResistor(stack, name_resistor2);
  stack.push(element);
  return element;
}

template<typename T>
T Resistor<T>::devideResistor(Stack <double> & stack, const int &name_resistor1, const int &name_resistor2, int *error) {
  auto element = popResistor(stack, name_resistor1) / popResistor(stack, name_resistor2);
  stack.push(element);
  return element;
}





























