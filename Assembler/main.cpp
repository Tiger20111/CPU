#include <iostream>
#include "assembler.h"

int main(int argc, char* argv[]) {
  Assembler T;

  if (argc == 2) {
    T.Assemble(argv[1]);
  }

  if (argc == 3) {
    T.Assemble(argv[1], argv[2]);
  }

  std::cout<<"hm";
  return 0;
}