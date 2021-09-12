#ifndef ARGO_VM__TYPES_VM__H
#define ARGO_VM__TYPES_VM__H

#include <stdbool.h>
#include <stdint.h>

#include "isa/operation.h"
#include "stack.h"
#include "options.h"

typedef enum { LESSER = -1, EQUALS = 0, GREATER = 1 } Comparator;

typedef struct
{
  // Is VM running?
  bool running;
  // Program instructions
  const int32_t *bytecode;
  // Instruction pointer
  uint32_t ip;
  // Comparator
  Comparator cm;
  // Stack
  Stack *stack;
  // Current operation
  Operation *op;
  // Options
  OptionsVM *opts;
} VM;

#endif
