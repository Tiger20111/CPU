#include "commandDouble.h"

#define MAX_ERROR()  \
  do {                        \
    if (error1 > error2) {    \
      *error = error1;         \
    } else {                  \
      *error = error2;         \
    }                         \
} while (false)

bool pushDoubl(Stack <double> & stack, double element, int* error) {
  stack.push(element, error);
  return (*error == 0);
}

bool popDoubl(Stack <double> & stack, int* error) {
  stack.pop(error);
  return (*error == 0);
}

bool addDoubl(Stack <double> & stack, double element, int* error) {
  if (stack.isEmpty()) return false;

  int error1 = 0;
  int error2 = 0;
  double *swap;

  swap = stack.pop(&error1);
  *swap = *swap + element;
  stack.push(*swap, &error2);

  MAX_ERROR();
  return (*error == 0);
}

bool mulDoubl(Stack <double> & stack, double element, int* error) {
  if (stack.isEmpty()) return false;

  int error1 = 0;
  int error2 = 0;
  double *swap;

  swap = stack.pop(&error1);
  *swap = *swap * element;
  stack.push(*swap, &error2);

  MAX_ERROR();
  return (*error == 0);
}

bool minusDoubl(Stack <double> & stack, double element, int* error) {
  if (stack.isEmpty()) return false;

  int error1 = 0;
  int error2 = 0;
  double *swap;

  swap = stack.pop(&error1);
  *swap = *swap - element;
  stack.push(*swap, &error2);

  MAX_ERROR();
}

bool devideDoubl(Stack <double> & stack, double element, int* error) {
  if (stack.isEmpty()) return false;

  int error1 = 0;
  int error2 = 0;
  double *swap;

  swap = stack.pop(&error1);
  *swap = *swap / element;
  stack.push(*swap, &error2);

  MAX_ERROR();
  return (*error == 0);
}

bool sqrtDoubl(Stack <double> & stack, int* error) {
  double* element = stack.pop(error);
  stack.push(*element, error);

  return (*error == 0);
}

bool inDouble(Stack <double> & stack, int* error) {
  double element;
  scanf("%lf", &element);
  stack.push(element, error);

  return (*error == 0);
}

bool outDouble(Stack <double> & stack, int* error) {
  double element = *stack.showTop(error);
  printf("%.2lf\n", element);

  return (*error == 0);
}