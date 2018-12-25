#include "assembler.h"

#define SPECIAL_SCANF                 \
  do {                                \
    if (!input)                       \
      scanf("%c", &line[i]);          \
    else                              \
      line[i] = fgetc(input);         \
  } while (false)

//fscanf(input, "%c", &line[i]);  \

Assembler::Assembler(int size) {
  InputNamesRegisters();
  InputNamesJumps();

  line_ = new char[size];
  delete_line_ = line_;

  error = 0;
}

Assembler::Assembler() {
  InputNamesRegisters();
  InputNamesJumps();

  line_ = new char[256];
  delete_line_ = line_;

  error = 0;
}

bool Assembler::InputNamesRegisters() {
  std::string registr = "ax";

  for (int i = 0; i < 10; i++) {
    names_registers_.push_back(registr);
    registr[0]++;
  }
  return true;
}

bool Assembler::InputNamesJumps() {
  names_jumps_.emplace_back("jmp");
  names_jumps_.emplace_back("je");
  names_jumps_.emplace_back("jne");
  names_jumps_.emplace_back("jae");
  names_jumps_.emplace_back("jb");
  names_jumps_.emplace_back("jbe");
  names_jumps_.emplace_back("ja");
  return true;
}

Assembler::~Assembler() {
  delete[] delete_line_;
}

bool Assembler::Assemble(const char *input, const char *output, int hard) {

  FILE *in = fopen(input, "r");
  bool success = true;
  bool exit = false;

  while (true) {
    if (exit)
      break;
    if (hard == 1 && (!success)) {
      return false;
    }
    Scanf(line_, in);

    std::string command = {};

    int i = 0;

    while ((line_[0] == ' ') || (line_[0] == '\t'))
      line_++;

    while (line_[i] != ' ' && line_[i] != '\0' && line_[i] != '\n') {
      command += line_[i];
      i++;
    }

    if (command.empty()) {
      continue;
    }

    if (command == "push") {
      success = pushChoose(code_, line_, names_registers_);
      continue;
    }

    if (command == "pop") {
      success = popChoose(code_, line_, names_registers_);
      continue;
    }

    if (command == "mul") {
      success = mulChoose(code_, line_, names_registers_);
      continue;
    }

    if (command == "add") {
      success = addChoose(code_, line_, names_registers_);
      continue;
    }

    if (command == "minus") {
      success = minusChoose(code_, line_, names_registers_);
      continue;
    }

    if (command == "divide") {
      success = divideChoose(code_, line_, names_registers_);
      continue;
    }

    if (command == "sqrt") {
      success = sqrtChoose(code_, line_, names_registers_);
      continue;
    }

    if (command == "scanf") {
      success = scanfChoose(code_, line_, names_registers_);
      continue;
    }

    if (command == "printf") {
      success = printfChoose(code_, line_, names_registers_);
      continue;
    }

    if (command == "in") {
      code_.push_back(81);
    }

    if (command == "out") {
      code_.push_back(91);
    }

    if (command[0] == 'j') {
      int number_jump = 0;
      for (const std::string &it : names_jumps_) {
        if (command != it)
          number_jump++;
        else
          break;
      }
      if (number_jump >= names_jumps_.size())
        break;

      line_ += command.size();

      success = jmpChoose(code_, number_jump, line_, tags_, 1);
      continue;
    }

    if (command[i - 1] == ':') {
      command.pop_back();
      tags_[command].first = (int) code_.size();
      continue;
    }

    if (command == "end") {
      code_.push_back(15);
    }

    if (command == "END") {
      enterTitle(code_, tags_);
      endAssembler(output, code_);
      fclose(in);
      exit = true;
      continue;
    }

  }

}

bool Assembler::endAssembler(const char *output, std::vector<double> &code) {
  FILE *assembler_out = fopen(output, "w");
  if (!assembler_out) return false;
  for (int i = 0; i < code_.size(); i++) {
    fprintf(assembler_out, "%.2lf ", code[i]);
  }
  fprintf(assembler_out, "&");
  fclose(assembler_out);
  return true;
}

bool Assembler::Scanf(char *line, FILE *input) {

  int i = 0;

  SPECIAL_SCANF;

  while (line[i] != '\n' && line[i] != '\0' && (char) line[i] != -1) {
    i++;
    SPECIAL_SCANF;
  }
  line[i] = '\0';
}
