#ifndef MYCPU_OPERATIVE_H
#define MYCPU_OPERATIVE_H

#define STANDART_SIZE 32

#include "stack.h"
#include "resistor.h"

template<typename T>
class Operative {
 public:
  Operative(T element);
  Operative(int max_size, T element);

  bool pushOperative (T element, int index_operative, int *error = nullptr);
  bool pushOperativeFromStack (int index_operative, Stack<double>& stack, int *error = nullptr);
  bool pushOperativeFromRegistr (int index_registr, int index_operative, Resistor<double>& set1_resistors, int *error = nullptr);
  bool popOperativeToStack (int index_operative, Stack<double>& stack, int *error = nullptr);
  bool popOperativeToRegistr(int index_registr, int index_operative, Resistor<double>& set1_resistors, int *error = nullptr);
 private:
  T* operative_buffer;
  int operative_size;

};

template class Operative <double>;

#endif //MYCPU_OPERATIVE_H
