#include "parsingCommand.h"

bool pushChoose(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers) {

  line += 4;
  while (line[0] == ' ') {
    line += 1;
  }

  if (isdigit(line[0])) {
    return pushDouble(code, line);
  }

  if (line[0] == '[') {

  }

  if (line[0] != '[') {
    return pushRegistr(code, line, names_registers);
  }

  perror("There is no such function push with such arguments");
  return false;
}
bool popChoose(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers) {
  line += 3;
  while (line[0] == ' ') {
    line += 1;
  }

  if (line[0] == '\n') {
    return popDouble(code);
  }

  if (line[0] == '[') {

  }

  if (line[0] != '[') {
    return popRegistr(code, line, names_registers);
  }

  perror("There is no such function push with such arguments");
  return false;
}
bool mulChoose(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers) {

  line += 3;
  while (line[0] == ' ') {
    line += 1;
  }

  if (isdigit(line[0])) {
    return mulDouble(code, line);
  }

  if (line[0] == '[') {

  }

  if (line[0] != '[') {
    return mulRegistr(code, line, names_registers);
  }

  perror("There is no such function push with such arguments");
  return false;
}

bool addChoose(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers) {

  line += 3;
  while (line[0] == ' ') {
    line += 1;
  }

  if (isdigit(line[0])) {
    return addDouble(code, line);
  }

  if (line[0] == '[') {

  }

  if (line[0] != '[') {
    return addRegistr(code, line, names_registers);
  }
}

bool minusChoose(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers) {

  line += 5;
  while (line[0] == ' ') {
    line += 1;
  }

  if (isdigit(line[0])) {
    return minusDouble(code, line);
  }

  if (line[0] == '[') {

  }

  if (line[0] != '[') {
    return minusRegistr(code, line, names_registers);
  }
}

bool divideChoose(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers) {

  line += 6;
  while (line[0] == ' ') {
    line += 1;
  }

  if (isdigit(line[0])) {
    return devideDouble(code, line);
  }

  if (line[0] == '[') {

  }

  if (line[0] != '[') {
    return devideRegistr(code, line, names_registers);
  }
}

bool sqrtChoose(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers) {

  line += 4;
  while (line[0] == ' ') {
    line += 1;
  }

  if (line[0] == '\n') {
    return sqrtDouble(code);
  }

  if (line[0] == '[') {

  }

  if (line[0] != '[') {
    return devideRegistr(code, line, names_registers);
  }
}

void jmpChoose(std::vector<double> &code, const char *line) {

}


