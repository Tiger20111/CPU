
#ifndef MYCPU_STACK_H
#define MYCPU_STACK_H

#undef private

#include <iostream>
#include <cerrno>
#include <cassert>

#define MAGIC1 2147483647
#define MAGIC2 2147483646
#define MAGIC3 2147483645
#define MAGIC4 2147483644

#define FULL    10011
#define EMPTY   10012
#define CRASHBE 10013

#define CRASHS  10014
#define CRASHB  10015
#define CRASHI  10016

template<typename T>
class Stack {
 private:
  static const int kDefaultCapacity = 16;
 private:
  int canary_begin = MAGIC1;                            // first canary
  T *stack;                                             // point to stack
  const int size_buffer;                              // max size stack
  int index_head;                                       // number of top element
  int control_sum = 0;                                  // control sum
  int canary_end = MAGIC2;                              // second canary

  bool okStackCanary() const;                           // canary check
  int doStackSum();                                     // do control sum
  bool okStackSum();                                    // check control sum
  bool okStackSize() const;                             // check current size of stack

 public:
  explicit Stack(int = kDefaultCapacity);               // constructor
  ~Stack();                                             // destructor

  inline void push(const T &, int *error = nullptr);    // add element to stack
  inline T *pop(int *error = nullptr);                  // return clone top element
  inline int size(int *error = nullptr);        // return size of
  inline T *showTop(int *error = nullptr);              // give top element
  void showStack(int *error = nullptr);
  bool isEmpty(int *error = nullptr);
};

template class Stack <double>;

#endif //MYCPU_STACK_H
