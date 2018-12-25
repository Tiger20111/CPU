
#include "jump.h"

bool je(Stack<double> &stack, bool &logic) {
  double element = *stack.pop();
  if (element == *stack.showTop()) {
    logic = true;
  } else {
    logic = false;
  }

  stack.push(element);
  return true;
}

bool jne(Stack<double> &stack, bool& logic) {
  double element = *stack.pop();
  if (element != *stack.showTop()) {
    logic = true;
  } else {
    logic = false;
  }

  stack.push(element);
  return true;
}

bool jae(Stack<double> &stack, bool& logic) {
  double element = *stack.pop();
  if (element >= *stack.showTop()) {
    logic = true;
  } else {
    logic = false;
  }

  stack.push(element);
  return true;
}

bool jb(Stack<double> &stack, bool& logic) {
  double element = *stack.pop();
  if (element < *stack.showTop()) {
    logic = true;
  } else {
    logic = false;
  }

  stack.push(element);
  return true;
}

bool jbe(Stack<double> &stack, bool& logic) {
  double element = *stack.pop();
  if (element <= *stack.showTop()) {
    logic = true;
  } else {
    logic = false;
  }

  stack.push(element);
  return true;
}

bool ja(Stack<double> &stack, bool& logic) {
  double* element = stack.pop();
  if (*element > *stack.showTop()) {
    logic = true;
  } else {
    logic = false;
  }

  stack.push(*element);
  return true;
}
