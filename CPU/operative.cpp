#include "operative.h"

#define WORK_OPERATIVE                                         \
do {                                                           \
  if (index_operative < 0 || index_operative > operative_size) \
return false;                                                  \
  } while (false)

template<typename T>
Operative<T>::Operative(T element) {
  operative_buffer = new T[STANDART_SIZE];
  for (int i = 0; i < STANDART_SIZE; i++) {
    operative_buffer[0] = element;
  }
  operative_size = STANDART_SIZE;
}

template<typename T>
Operative<T>::Operative(int max_size, T element) {
  operative_buffer = new T[max_size];
  for (int i = 0; i < max_size; i++) {
    operative_buffer[0] = element;
  }
  operative_size = max_size;
}

template<typename T>
bool Operative<T>::pushOperative (T element, int index_operative, int *error) {
  WORK_OPERATIVE;
  operative_buffer[index_operative] = element;
  return true;
}


template<typename T>
bool Operative<T>::pushOperativeFromStack (int index_operative,   Stack<double>& stack, int *error) {
  WORK_OPERATIVE;
  operative_buffer[index_operative] = *stack.pop();
  return true;
}


template<typename T>
bool Operative<T>::popOperativeToStack (int index_operative, Stack<double>& stack, int *error) {
  WORK_OPERATIVE;
  stack.push(std::move(operative_buffer[index_operative]));
  return true;
}


template<typename T>
bool Operative<T>::pushOperativeFromRegistr (int index_registr, int index_operative, Resistor<double>& set1_resistors, int *error) {
  WORK_OPERATIVE;
  operative_buffer[index_operative] = set1_resistors.popResistor(index_registr);
  return true;
}

template<typename T>
bool Operative<T>::popOperativeToRegistr(int index_registr, int index_operative, Resistor<double>& set1_resistors, int *error) {
  WORK_OPERATIVE;
  set1_resistors.pushResistor(index_registr, operative_buffer[index_operative]);
  return true;
}