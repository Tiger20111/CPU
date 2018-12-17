#include <iostream>
#include "cpu.h"
int main(int argc, char* argv[]) {
  CPU T;
  T.Compiler(argv[1]);
  return 0;
}