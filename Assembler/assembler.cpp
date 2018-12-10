#include "assembler.h"

#define SPECIAL_SCANF                 \
  do {                                \
    if (!input)                       \
      scanf("%c", &line[i]);          \
    else                              \
      fscanf(input, "%c", &line[i]);  \
  } while (false)

Assembler::Assembler(int size) {
  line_ = new char[size];
}

Assembler::Assembler() {
  line_ = new char[256];

  error = 0;
}

bool Assembler::InputNamesRegisters() {
  std::string registr = "ax";

  for (int i = 0; i < 10; i++) {
    names_registers.push_back(registr);
    registr[0]++;
  }
}

Assembler::~Assembler() {
  delete line_;
}

bool Assembler::Assemble(const char *output, const char *input, int hard) {
  FILE* in = fopen(input, "r");


  while (true) {
    Scanf(line_, in);

    std::string command = {};

    int i = 0;
    while (line_[i] != ' ' && line_[i] != '\0' && line_[i] != '\n') {
      command += line_[i];
      i++;
    }

    if (command == "push") {
      bool success = pushChoose(code_, line_, names_registers);
      if (hard == 1 && (!success)) {
        return false;
      }
      continue;
    }

    if (command == "pop") {
      popChoose(code_, line_, names_registers);
      continue;
    }

    if (command == "mul") {
      mulChoose(code_, line_, names_registers);
      continue;
    }

    if (command == "jmp") {
      jmpChoose(code_, line_);
      continue;
    }

    if (command == "add") {
      addChoose(code_, line_, names_registers);
      continue;
    }

    if (command == "minus") {
      minusChoose(code_, line_, names_registers);
    }

    if (command == "divide") {
      divideChoose(code_, line_, names_registers);
    }

    if (command == "sqrt") {
      sqrtChoose(code_, line_, names_registers);
    }

    if (command == "end") {
      endAssembler(output, code_);
      return true;
    }
  }
}

bool Assembler::endAssembler(const char *output, std::vector<double> &code) {
  FILE* assembler_out = fopen(output, "w");
  if (!assembler_out) return false;
  for (int i = 0; i < code_.size(); i++) {
    fprintf(assembler_out, "%.2f ", code[i]);
  }
  fprintf(assembler_out, "&");
  return true;
}

bool Assembler::Scanf(char *line, FILE* input) {

  int i = 0;

  SPECIAL_SCANF;

  while (line[i] != '\n' && line[i] != '\0') {
    i++;
    SPECIAL_SCANF;
  }
}
