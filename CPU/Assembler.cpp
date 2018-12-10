#include "Assembler.h"

bool pushChoose(std::vector<double> &code, const char *line) {

  line += 5;
  while (line[0] == ' ') {
    line += 1;
  }

  if (isdigit(line[0])) {
    return pushDouble(code, line);
  }

  if (line[0] == '[') {
    //Operative
  }

  if (line[0] != '[') {
    return pushRegistr(code, line);
  }

  perror("There is no such function push with such arguments");
  return false;
}
bool popChoose(std::vector<double> &code, const char *line) {
  line += 4;
  while (line[0] == ' ') {
    line += 1;
  }

  if (line[0] == '\n') {
    return popDouble(code);
  }

  if (line[0] == '[') {

  }

  if (line[0] != '[') {
    return popRegistr(code, line);
  }

  perror("There is no such function push with such arguments");
  return false;
}
bool mulChoose(std::vector<double> &code, const char *line) {

  line += 4;
  while (line[0] == ' ') {
    line += 1;
  }

  if (isdigit(line[0])) {
    return mulDouble(code, line);
  }

  if (line[0] == '[') {

  }

  if (line[0] != '[') {
    return mulRegistr(code, line);
  }

  perror("There is no such function push with such arguments");
  return false;
}

bool addChoose(std::vector<double> &code, const char *line) {

  line += 4;
  while (line[0] == ' ') {
    line += 1;
  }

  if (isdigit(line[0])) {
    return addDouble(code, line);
  }

  if (line[0] == '[') {

  }

  if (line[0] != '[') {
    return addRegistr(code, line);
  }
}

bool minusChoose(std::vector<double> &code, const char *line) {

  line += 4;
  while (line[0] == ' ') {
    line += 1;
  }

  if (isdigit(line[0])) {
    return minusDouble(code, line);
  }

  if (line[0] == '[') {

  }

  if (line[0] != '[') {
    return minusRegistr(code, line);
  }
}

bool divideChoose(std::vector<double> &code, const char *line) {

  line += 4;
  while (line[0] == ' ') {
    line += 1;
  }

  if (isdigit(line[0])) {
    return devideDouble(code, line);
  }

  if (line[0] == '[') {

  }

  if (line[0] != '[') {
    return devideRegistr(code, line);
  }
}

bool sqrtChoose(std::vector<double> &code, const char *line) {

  line += 4;
  while (line[0] == ' ') {
    line += 1;
  }

  if (line[0] == 'S') {

  }

  if (line[0] == '[') {

  }

  if (line[0] != '[') {
    return devideRegistr(code, line);
  }
}

void jmpChoose(std::vector<double> &code, const char *line) {

}

bool Scanf(char *line, const char *file_read) {

  int i = 0;

  if (file_read == nullptr) {

    scanf("%c", &line[i]);

    while (line[i] != '\n' && line[i] != '\0') {
      i++;
      scanf("%c", &line[i]);
    }
  }

  FILE *input = fopen(file_read, "r");

  scanf(file_read, "%c", &line[i]);

  while (line[i] != '\n' && line[i] != '\0') {
    i++;
    scanf(file_read, "%c", &line[i]);
  }
}


