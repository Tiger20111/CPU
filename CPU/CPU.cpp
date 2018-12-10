#include "CPU.h"

#define ERROR_OUT              \
  do {                         \
    if (error > CRASH_NORMAL)  \
      return false;            \
} while (false)


bool is_equal(double x, double y);

CPU::CPU(int size) {
  line_ = new char[size];
}

CPU::CPU() {
  line_ = new char[256];
  error = 0;
}

CPU::~CPU() {
  delete line_;
}

bool CPU::DisAssembler(const char *file, int hard) {
  while (true) {
    Scanf(line_, file);

    std::string command = {};

    int i = 0;
    while (line_[i] != ' ' && line_[i] != '\0' && line_[i] != '\n') {
      command += line_[i];
      i++;
    }

    if (command == "push") {
      bool success = pushChoose(code_, line_);
      if (hard == 1 && (!success)) {
        return false;
      }
      continue;
    }

    if (command == "pop") {
      popChoose(code_, line_);
      continue;
    }

    if (command == "mul") {
      mulChoose(code_, line_);
      continue;
    }

    if (command == "jmp") {
      jmpChoose(code_, line_);
      continue;
    }

    if (command == "add") {
      addChoose(code_, line_);
      continue;
    }

    if (command == "minus") {
      minusChoose(code_, line_);
    }

    if (command == "divide") {
      divideChoose(code_, line_);
    }

    if (command == "sqrt") {
      sqrtChoose(code_, line_);
    }

    if (command == "end") {
      return true;
    }
  }
}

bool CPU::Compiler() {
  Stack<double> stack;
  Resistor<double> set1_resistors; //////

  size_t size = code_.size();
  int i = 0;

  while (i <= size) {
    if ((int) (code_[i] - 1) % 10 == 0) {
      if (is_equal(code_[i], 11)) {
        pushDoubl(stack, code_[i + 1], &error);
        i += 2;
        ERROR_OUT;
      }

      if (is_equal(code_[i], 21)) {
        popDoubl(stack, &error);
        i += 1;
        ERROR_OUT;
      }

      if (is_equal(code_[i], 31)) {
        addDoubl(stack, code_[i + 1], &error);
        i += 2;
        ERROR_OUT;
      }

      if (is_equal(code_[i], 41)) {
        mulDoubl(stack, code_[i + 1], &error);
        i += 2;
        ERROR_OUT;
      }

      if (is_equal(code_[i], 51)) {
        minusDoubl(stack, code_[i + 1], &error);
        i += 2;
        ERROR_OUT;
      }

      if (is_equal(code_[i], 61)) {
        devideDoubl(stack, code_[i + 1], &error);
        i += 2;
        ERROR_OUT;
      }

      if (is_equal(code_[i], 71)) {
        sqrtDoubl(stack, &error);
        i += 2;
        ERROR_OUT;
      }
    }

    if ((int) (code_[i] - 2) % 10 == 0) {
      if (is_equal(code_[i], 12)) {
        set1_resistors.pushResistor(stack, (int)code_[i+1], code_[i + 2], &error);
        i += 3;
        ERROR_OUT;
      }

      if (is_equal(code_[i], 22)) {
        set1_resistors.addResistor(stack, (int)code_[i+1], (int)code_[i + 2], &error);
        i += 3;
        ERROR_OUT;
      }

      if (is_equal(code_[i], 32)) {
        set1_resistors.mulResistor(stack, (int)code_[i+1], (int)code_[i + 2], &error);
        i += 3;
        ERROR_OUT;
      }

      if (is_equal(code_[i], 42)) {
        set1_resistors.minusResistor(stack, (int)code_[i+1], (int)code_[i + 2], &error);
        i += 3;
        ERROR_OUT;
      }

      if (is_equal(code_[i], 52)) {
        set1_resistors.devideResistor(stack, (int)code_[i+1], (int)code_[i + 2], &error);
        i += 3;
        ERROR_OUT;
      }

      if (is_equal(code_[i], 62)) {
        set1_resistors.popResistor(stack, (int)code_[i+1], &error);
        i += 2;
        ERROR_OUT;
      }

    }
  }
}

bool is_equal(double x, double y) {
  return std::fabs(x - y) < std::numeric_limits<double>::epsilon();
}
