#include "resistor.h"

template<typename T>
Resistor<T>::Resistor() {
  ax = 0;
  bx = 0;
  cx = 0;
  dx = 0;
  ex = 0;
  fx = 0;
  gx = 0;
  hx = 0;
  ix = 0;
  jx = 0;
}


//#define hhs(a, op, b) \
//  a op b              \
//
//hhs(5, +, 7);

template<typename T>
T& Resistor<T>::captureRegistr(const int &name_resistor, int *error) {
  switch (name_resistor) {
    case 0:
      return ax;
    case 1:
      return bx;
    case 2:
      return cx;
    case 3:
      return dx;
    case 4:
      return ex;
    case 5:
      return fx;
    case 6:
      return gx;
    case 7:
      return hx;
    case 8:
      return ix;
    case 9:
      return jx;
    default:
      break;
  }
}

template<typename T>
bool Resistor<T>::pushResistor(const int &name_resistor, T element, int *error) {
  captureRegistr(name_resistor) = element;
}

template<typename T>
T Resistor<T>::popResistor(const int &name_resistor, int *error) {
  T a = captureRegistr(name_resistor);
  return captureRegistr(name_resistor);
}

template<typename T>
bool Resistor<T>::pushResistorFromStack(Stack <double> & stack, const int &name_resistor, int *error) {
  pushResistor(name_resistor, *stack.pop());
  return true;
}
template<typename T>
bool Resistor<T>::popResistorToStack(Stack <double> & stack, const int &name_resistor, int *error) {
  stack.push(popResistor(name_resistor));
  return true;
}

template<typename T>
bool Resistor<T>::addResistorToStack(Stack <double> & stack, const int &name_resistor1, const int &name_resistor2, int *error) {
  auto element = popResistor(name_resistor1) + popResistor(name_resistor2);
  stack.push(element);
  return true;
}

template<typename T>
bool Resistor<T>::mulResistorToStack(Stack <double> & stack, const int &name_resistor1, const int &name_resistor2, int *error) {
  auto element = popResistor(name_resistor1) * popResistor(name_resistor2);
  stack.push(element);
  return true;
}

template<typename T>
bool Resistor<T>::minusResistorToStack(Stack <double> & stack, const int &name_resistor1, const int &name_resistor2, int *error) {
  auto element = popResistor(name_resistor1) - popResistor(name_resistor2);
  stack.push(element);
  return true;
}

template<typename T>
bool Resistor<T>::devideResistorToStack(Stack <double> & stack, const int &name_resistor1, const int &name_resistor2, int *error) {
  auto element = popResistor(name_resistor1) / popResistor(name_resistor2);
  stack.push(element);
  return true;
}

template<typename T>
bool Resistor<T>::sqrtResistorToStack(Stack <double> & stack, const int &name_resistor, int *error) {
  stack.push(sqrt(popResistor(name_resistor)));
  return true;
}

template<typename T>
bool Resistor<T>::scanfResistor(Stack <double> & stack, const int &name_resistor, int *error) {
  scanf("%lf", &captureRegistr(name_resistor));
  return true;
}

template<typename T>
bool Resistor<T>::printfResistor(Stack <double> & stack, const int &name_resistor, int *error) {
  printf("%.2lf\n", popResistor(name_resistor));
  return true;
}








