#ifndef ASSEMBLER_COMMONFUNC_H
#define ASSEMBLER_COMMONFUNC_H

#include <iostream>
#include <cstring>
#include <vector>

bool castToDouble(char const *line, double *value);
int nameRegistr(std::string const *name, std::vector<std::string> &names_registers);

#endif //ASSEMBLER_COMMONFUNC_H
