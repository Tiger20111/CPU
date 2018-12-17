#include "assembler.h"

#define SPECIAL_SCANF                 \
  do {                                \
    if (!input)                       \
      scanf("%c", &line[i]);          \
    else                              \
      fscanf(input, "%c", &line[i]);  \
  } while (false)

Assembler::Assembler(int size) {
  InputNamesRegisters();
  line_ = new char[size];
}

Assembler::Assembler() {
  InputNamesRegisters();
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

bool Assembler::Assemble(const char *input, const char *output, int hard) {
  FILE* in = fopen(input, "r");
  bool success = true;

  while (true) {

    if (hard == 1 && (!success)) {
      return false;
    }
    Scanf(line_, in);

    std::string command = {};

    int i = 0;
    while (line_[i] != ' ' && line_[i] != '\0' && line_[i] != '\n') {
      command += line_[i];
      i++;
    }

    if (command == "push") {
      success = pushChoose(code_, line_, names_registers);
      continue;
    }

    if (command == "pop") {
      success = popChoose(code_, line_, names_registers);
      continue;
    }

    if (command == "mul") {
      success = mulChoose(code_, line_, names_registers);
      continue;
    }

    if (command == "jmp") {
      jmpChoose(code_, line_);
      continue;
    }

    if (command == "add") {
      success = addChoose(code_, line_, names_registers);
      continue;
    }

    if (command == "minus") {
      success = minusChoose(code_, line_, names_registers);
      continue;
    }

    if (command == "divide") {
      success = divideChoose(code_, line_, names_registers);
      continue;
    }

    if (command == "sqrt") {
      success = sqrtChoose(code_, line_, names_registers);
      continue;
    }

    if (command == "scanf") {
      success = scanfChoose(code_, line_, names_registers);
      continue;
    }

    if (command == "printf") {
      success = printfChoose(code_, line_, names_registers);
      continue;
    }

    if (command == "end") {
      success = endAssembler(output, code_);
      return true;
    }
  }
}

bool Assembler::endAssembler(const char *output, std::vector<double> &code) {
  FILE* assembler_out = fopen(output, "w");
  if (!assembler_out) return false;
  for (int i = 0; i < code_.size(); i++) {
    fprintf(assembler_out, "%.2lf ", code[i]);
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
  line[i] = '\0';
}
