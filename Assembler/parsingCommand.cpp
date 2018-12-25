#include "parsingCommand.h"

#define ChooseOperativeRegistr  20001
#define ChooseOperativeStack    20002
#define ChooseOperativeDouble   20003

bool OperativeChooseStackOrRegistr(const char *line, int *value);

bool pushChoose(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers) {

  line += 4;
  while (line[0] == ' ') {
    line++;
  }

  if (isdigit(line[0]) || line[0] == '-') {
    return pushDouble(code, line);
  }

  if (line[0] == 'S') {
    std::string name_stack = "S";
    line++;
    for (int i = 0; i < 4; i++) {
      name_stack += line[0];
      line++;
    }
    if (name_stack != "Stack") {
      return false;
    }

    while (line[0] == ' ') {
      line++;
    }

    return pushRegistrFromStack(code, line, names_registers);

  }

  if (line[0] == '[') {
    line++;
    int value = 0;
    OperativeChooseStackOrRegistr(line, &value);

    switch (value) {
      case ChooseOperativeRegistr:pushOperativeFromRegistr(code, line, names_registers);
        break;
      case ChooseOperativeStack:pushOperativeFromStack(code, line);
        break;
      case ChooseOperativeDouble:pushOperative(code, line);
      default:return false;
    }
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

  if (line[0] == '\n' || line[0] == '\0') {
    return popDouble(code);
  }

  if (line[0] == '[') {
    line++;
    int value = 0;
    OperativeChooseStackOrRegistr(line, &value);

    switch (value) {
      case ChooseOperativeRegistr:popOperativeToRegistr(code, line, names_registers);
        break;
      case ChooseOperativeStack:popOperativeToStack(code, line);
        break;
      default:return false;
    }
  }

  if (line[0] != '[') {
    return popRegistrToStack(code, line, names_registers);
  }

  perror("There is no such function push with such arguments");
  return false;
}
bool mulChoose(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers) {

  line += 3;
  while (line[0] == ' ') {
    line += 1;
  }

  if (isdigit(line[0]) || line[0] == '-') {
    return mulDouble(code, line);
  }

  if (line[0] == '[') {
    return false;
  }

  if (line[0] != '[') {
    return mulRegistrToStack(code, line, names_registers);
  }

}

bool addChoose(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers) {

  line += 3;
  while (line[0] == ' ') {
    line += 1;
  }

  if (isdigit(line[0]) || line[0] == '-') {
    return addDouble(code, line);
  }

  if (line[0] == '[') {
    return false;
  }

  if (line[0] != '[') {
    return addRegistrToStack(code, line, names_registers);
  }
}

bool minusChoose(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers) {

  line += 5;
  while (line[0] == ' ') {
    line += 1;
  }

  if (isdigit(line[0]) || line[0] == '-') {
    return minusDouble(code, line);
  }

  if (line[0] == '[') {
    return false;
  }

  if (line[0] != '[') {
    return minusRegistrToStack(code, line, names_registers);
  }
}

bool divideChoose(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers) {

  line += 6;
  while (line[0] == ' ') {
    line += 1;
  }

  if (isdigit(line[0]) || line[0] == '-') {
    return devideDouble(code, line);
  }

  if (line[0] == '[') {
    return false;
  }

  if (line[0] != '[') {
    return devideRegistrToStack(code, line, names_registers);
  }
}

bool sqrtChoose(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers) {

  line += 4;
  while (line[0] == ' ') {
    line += 1;
  }

  if (line[0] == '\n' || line[0] == '\0') {
    return sqrtDouble(code);
  }

  if (line[0] == '[') {
    return false;
  }

  if (line[0] != '[') {
    return sqrtRegistrToStack(code, line, names_registers);
  }
}

bool scanfChoose(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers) {
  line += 5;
  while (line[0] == ' ') {
    line += 1;
  }

  if (line[0] == '\n' || line[0] == '\0') {
    return false;
  }

  if (line[0] == '[') {
    return false;
  }

  if (line[0] != '[') {
    return scanfRegistr(code, line, names_registers);
  }
}

bool printfChoose(std::vector<double> &code, const char *line, std::vector<std::string> &names_registers) {
  line += 6;
  while (line[0] == ' ') {
    line += 1;
  }

  if (line[0] == '\n' || line[0] == '\0') {
    return false;
  }

  if (line[0] == '[') {
    return false;
  }

  if (line[0] != '[') {
    return printfRegistr(code, line, names_registers);
  }
}

bool jmpChoose(std::vector<double> &code,
               const int command,
               const char *line,
               std::map<std::string,
                        std::pair<int, std::vector<int>>> &tags,
               int enter) {

  while (line[0] == ' ')
    line++;

  std::string argument = {};

  while (line[0] != '\n' && line[0] != '\0') {
    argument += line[0];
    line++;
  }

  int start_command = 14;

  code.push_back(start_command + command * 10);
  code.push_back(-1);

  tags[argument]; //
  tags[argument].second.push_back((int) code.size() - 1);
  return false;
}

bool enterTitle(std::vector<double> &code,
                std::map<std::string, std::pair<int, std::vector<int>>> &tags) {
  for (auto &item : tags) {
    std::cout << item.first << " " <<  tags[item.first].first << '\n';
    for (int j = 0; j < tags[item.first].second.size(); j++) {
      code[tags[item.first].second[j]] = tags[item.first].first;
    }
  }
  return true;
}

bool OperativeChooseStackOrRegistr(const char *line, int *value) {
  while (line[0] == ' ') {
    line++;
  }
  if (isdigit(line[0])) {
    *value = ChooseOperativeDouble;
    return true;
  }

  if (line[0] == 'S') {
    line++;
    std::string name_Stack = "S";
    for (int i = 0; i < 4; i++) {
      name_Stack += line[0];
      line++;
    }
    if (!(name_Stack == "Stack")) {
      return false;
    }

    while (line[0] != ',') {
      line++;
    }

    line++;
    *value = ChooseOperativeStack;
    return true;
  }

  *value = ChooseOperativeRegistr;
  return true;

}