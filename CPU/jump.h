//
// Created by tig on 12/18/18.
//

#ifndef MYCPU_JUMP_H
#define MYCPU_JUMP_H

#include "stack.h"

bool je(Stack<double>& stack, bool& logic);
bool jne(Stack<double>& stack, bool& logic);
bool jae(Stack<double>& stack, bool& logic);
bool jb(Stack<double>& stack, bool& logic);
bool jbe(Stack<double>& stack, bool& logic);
bool ja(Stack<double>& stack, bool& logic);

#endif //MYCPU_JUMP_H
