#include <iostream>
#include "CPU.h"

int main() {
  CPU T;
  T.DisAssembler();
  T.Compiler();
  std::cout << "Hello, World!" << std::endl;
  return 0;
}