#include "cpu.h"

#define ERROR_OUT              \
  do {                         \
    if (error > CRASH_NORMAL)  \
      return false;            \
} while (false)


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

bool CPU::Compiler(const char* fread) {
  Scanf(fread);
  Stack<double> stack;
  Resistor<double> set1_resistors;
  Operative<double> operative(0);

  size_t size = code_.size();
  int i = 0;

  while (i < size) {
    if ((int) (code_[i] - 1) % 10 == 0) {
      if (isEqual(code_[i], 11)) {
        pushDoubl(stack, code_[i + 1], &error);
        i += 2;
        ERROR_OUT;
        continue;
      }

      if (isEqual(code_[i], 21)) {
        popDoubl(stack, &error);
        i += 1;
        ERROR_OUT;
        continue;
      }

      if (isEqual(code_[i], 31)) {
        addDoubl(stack, code_[i + 1], &error);
        i += 2;
        ERROR_OUT;
        continue;
      }

      if (isEqual(code_[i], 41)) {
        mulDoubl(stack, code_[i + 1], &error);
        i += 2;
        ERROR_OUT;
        continue;
      }

      if (isEqual(code_[i], 51)) {
        minusDoubl(stack, code_[i + 1], &error);
        i += 2;
        ERROR_OUT;
        continue;
      }

      if (isEqual(code_[i], 61)) {
        devideDoubl(stack, code_[i + 1], &error);
        i += 2;
        ERROR_OUT;
        continue;
      }

      if (isEqual(code_[i], 71)) {
        sqrtDoubl(stack, &error);
        i += 2;
        ERROR_OUT;
        continue;
      }

      if (isEqual(code_[i], 81)) {
        inDouble(stack, &error);
        i += 1;
        ERROR_OUT;
        continue;
      }

      if (isEqual(code_[i], 91)) {
        outDouble(stack, &error);
        i += 1;
        ERROR_OUT;
        continue;
      }
    }

    if ((int) (code_[i] - 2) % 10 == 0) {
      if (isEqual(code_[i], 12)) {
        set1_resistors.pushResistor((int)code_[i+1], code_[i + 2], &error);
        i += 3;
        ERROR_OUT;
        continue;
      }

      if (isEqual(code_[i], 22)) {
        set1_resistors.addResistorToStack(stack, (int)code_[i+1], (int)code_[i + 2], &error);
        i += 3;
        ERROR_OUT;
        continue;
      }

      if (isEqual(code_[i], 32)) {
        set1_resistors.mulResistorToStack(stack, (int)code_[i+1], (int)code_[i + 2], &error);
        i += 3;
        ERROR_OUT;
        continue;
      }

      if (isEqual(code_[i], 42)) {
        set1_resistors.minusResistorToStack(stack, (int)code_[i+1], (int)code_[i + 2], &error);
        i += 3;
        ERROR_OUT;
        continue;
      }

      if (isEqual(code_[i], 52)) {
        set1_resistors.devideResistorToStack(stack, (int)code_[i+1], (int)code_[i + 2], &error);
        i += 3;
        ERROR_OUT;
        continue;
      }

      if (isEqual(code_[i], 62)) {
        set1_resistors.popResistorToStack(stack, (int)code_[i+1], &error);
        i += 2;
        ERROR_OUT;
        continue;
      }

      if (isEqual(code_[i], 72)) {
        set1_resistors.pushResistorFromStack(stack, (int)code_[i+1], &error);
        i += 2;
        ERROR_OUT;
        continue;
      }

      if (isEqual(code_[i], 82)) {
        set1_resistors.sqrtResistorToStack(stack, (int)code_[i+1], &error);
        i += 2;
        ERROR_OUT;
        continue;
      }

      if (isEqual(code_[i], 92)) {
        set1_resistors.scanfResistor(stack, (int)code_[i+1], &error);
        i += 2;
        ERROR_OUT;
        continue;
      }

      if (isEqual(code_[i], 102)) {
        set1_resistors.printfResistor(stack, (int)code_[i+1], &error);
        i += 2;
        ERROR_OUT;
        continue;
      }

    }
    if ((int) (code_[i] - 3) % 10 == 0) {
      if (isEqual(code_[i], 13)) {
        operative.pushOperative(code_[i+1], (int)code_[i + 2], &error);
        i += 3;
        ERROR_OUT;
        continue;
      }

      if (isEqual(code_[i], 23)) {
        operative.pushOperativeFromStack((int)code_[i+1], stack, &error);
        i += 2;
        ERROR_OUT;
        continue;
      }

      if (isEqual(code_[i], 33)) {
        operative.pushOperativeFromRegistr((int)code_[i+1], (int)code_[i + 2], set1_resistors, &error);
        i += 3;
        ERROR_OUT;
        continue;
      }

      if (isEqual(code_[i], 43)) {
        operative.popOperativeToStack((int)code_[i+1], stack, &error);
        i += 2;
        ERROR_OUT;
        continue;
      }

      if (isEqual(code_[i], 53)) {
        operative.popOperativeToRegistr((int)code_[i+1], (int)code_[i+2], set1_resistors, &error);
        i += 3;
        ERROR_OUT;
        continue;
      }
    }
    if ((int) (code_[i] - 4) % 10 == 0) {
      bool logic = true;
      if (isEqual(code_[i], 14)) {
        i = (int) code_[i + 1];
        continue;
      }
      if (isEqual(code_[i], 24)) {
        je(stack, logic);
        if (logic)
          i = (int) code_[i + 1];
        else
          i += 2;
        continue;
      }
      if (isEqual(code_[i], 34)) {
        jne(stack, logic);
        if (logic)
          i = (int) code_[i + 1];
        else
          i += 2;
        continue;
      }
      if (isEqual(code_[i], 44)) {
        jae(stack, logic);
        if (logic)
          i = (int) code_[i + 1];
        else
          i += 2;
        continue;
      }
      if (isEqual(code_[i], 54)) {
        jb(stack, logic);
        if (logic)
          i = (int) code_[i + 1];
        else
          i += 2;
        continue;
      }
      if (isEqual(code_[i], 64)) {
        jbe(stack, logic);
        if (logic)
          i = (int) code_[i + 1];
        else
          i += 2;
        continue;
      }
      if (isEqual(code_[i], 74)) {
        ja(stack, logic);
        if (logic)
          i = (int) code_[i + 1];
        else
          i += 2;
        continue;
      }
    }

    if ((int) (code_[i] - 5) % 10 == 0) {
      if (isEqual(code_[i], 15)) {
        return true;
      }
    }
  }
}



bool CPU::isEqual(double x, double y) {
  return std::fabs(x - y) < std::numeric_limits<double>::epsilon();
}

bool CPU::Scanf(const char* input) {
  FILE* fr;

  if (!(fr = fopen(input, "r")))
    return false;

  char c = 'a';
  auto num = new char[SIZE_FILE];
  double number = 0;
  int j = 0;

  fscanf(fr, "%c", &c);
  while (1) {
    if (c == ' ' || c == '&') {
      num[j] = '\0';
      char *ptrEnd = nullptr;
      number = strtod(num, &ptrEnd);
      if (*ptrEnd != '\n') {
        code_.push_back(number);
        j = 0;
        while (c == ' ') {
          fscanf(fr, "%c", &c);
          if (c == '&') return true;
        }
      }
    } else {
      num[j] = c;
      j++;
      fscanf(fr, "%c", &c);
      if (c == '&') return true;
    }
  }
}