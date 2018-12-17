#define private public
#include "stack.h"
#undef private



#define EXIT(ret_value)  \
  do {                   \
    return ret_value;    \
  } while (false)

#define FAILWITH(message, crash, error_v)  \
  do {                                     \
    errno = crash;                      \
    perror(message);                       \
    if (error_v) {                         \
      *error = crash;                      \
      }                                    \
  } while (false)

#define WORK_STACK(ret_value, exit_value, error_v)     \
  do {                                                 \
    if (!okStackSize()) {                              \
      FAILWITH("Size stack is wrong"                   \
             " between operations", CRASHS, error_v);  \
      if (exit_value) {                                \
          EXIT(ret_value);                             \
      }                                                \
    }                                                  \
    if (!okStackSum()) {                               \
      FAILWITH("Something happened with stack"         \
             " between operations", CRASHB, error_v);  \
      if (exit_value) {                                \
          EXIT(ret_value);                             \
      }                                                \
    }                                                  \
                                                       \
    if (!okStackCanary()) {                            \
      FAILWITH("Something happened with stack"         \
             " between operations", CRASHB, error_v);  \
      if (exit_value) {                                \
          EXIT(ret_value);                             \
      }                                                \
    }                                                  \
  } while (false)

#define STATE_RECALCULATION(ret_value, exit_value, error_v)  \
  do {                                                       \
    doStackSum();                                            \
    if (!okStackCanary()) {                                  \
      FAILWITH("Something happened with stack"               \
               " between operations", CRASHI, error_v);      \
      if (exit_value) {                                      \
          EXIT(ret_value);                                   \
      }                                                      \
    }                                                        \
  } while (false)

//!
//! \tparam T       any type
//! \param maxSize  size of buffer stack
template<typename T>
Stack<T>::Stack(int maxSize) :
    size_buffer(maxSize + 1) {
  if (size_buffer < 1) {
    index_head = -1;
    perror("Invalid start size of stack");
    return;
  }

  stack = new T[size_buffer + 1];
  index_head = 1;
  stack[0] = MAGIC3;
  stack[size_buffer] = MAGIC4;
  control_sum = doStackSum();
}

//!
//! \tparam T
template<typename T>
Stack<T>::~Stack() {
  int* error;
  WORK_STACK( , 0, 0);
  delete[] stack;
}

//!
//! \tparam T       any type
//! \param value    object that we put to stack
template<typename T>
inline void Stack<T>::push(const T &value, int *error) {
  WORK_STACK(, 1, 1);
  if (index_head >= size_buffer) {
    FAILWITH("Stack is full", FULL, 1);
    return;
  }

  stack[index_head++] = value;

  STATE_RECALCULATION (, 1, 1);
}

//!
//! \tparam T any type
//! \param error if func wii broken put type of error
//! \return link to top element
template<typename T>
inline T *Stack<T>::pop(int *error) {
  WORK_STACK(nullptr, 1, 1);
  if (index_head <= 1) {
    FAILWITH("Stack is empty", EMPTY, 1);
    perror("Stack is empty");
    return nullptr;
  }

  try {
    assert(stack[index_head - 1]);
  } catch (int e) {
    FAILWITH("element in stack was broken", CRASHBE, 1);
    return nullptr;
  }

  index_head--;

  STATE_RECALCULATION(nullptr, 1, 1);

  return (&stack[index_head]);
}

//!
//! \tparam T any type
//! \param error if func wii broken put type of error
//! \return link to cope of top element
template<typename T>
inline T *Stack<T>::showTop(int *error) {
  WORK_STACK(nullptr, 1, 1);

  auto *trash = new T;
  *trash = stack[index_head - 1];

  STATE_RECALCULATION(nullptr, 1, 1);

  return trash;
}

//!
//! \tparam T any type
//! \param error if func wii broken put type of error
//! \return current size of filled stack
template<typename T>
inline int Stack<T>::size(int *error) {
  WORK_STACK(-1, 1, 1);
  return index_head - 1;
}

//!
//! \tparam T any type
//! \param error if func wii broken put type of error
//! \return empty stack or not
template<typename T>
bool Stack<T>::isEmpty(int *error) {
  WORK_STACK(false, 1, 1);

  return (index_head == 1);
}

//!
//! \tparam T any type
//! \param error if func wii broken put type of error
template<typename T>
void Stack<T>::showStack(int *error) {
  WORK_STACK(, 1, 1);

  for (int i = index_head - 1; i >= 1; i--) {
    std::cout << stack[i] << " ";
  }

  STATE_RECALCULATION(, 1, 1);
}

template<typename T>
bool Stack<T>::okStackCanary() const {
  return (canary_begin == MAGIC1 && canary_end == MAGIC2) &&
      (stack[0] == MAGIC3 && stack[size_buffer]);
}

template<typename T>
bool Stack<T>::okStackSize() const {
  return (1 <= index_head && index_head <= size_buffer);
}
template<typename T>
int Stack<T>::doStackSum() {
  auto *think = (char *) this;
  int sum = 0;
  for (int i = 0; i < sizeof(think); i++) {
    sum += think[i];
  }

  auto *ptr = (char *) (&stack);
  for (int i = 0; i < sizeof(ptr); i++) {
    sum += ptr[i];
  }

  return sum;
}

template<typename T>
bool Stack<T>::okStackSum() {
  int check_sum = doStackSum();
  return (check_sum == control_sum);
}
