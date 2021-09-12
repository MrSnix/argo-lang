#ifndef ARGO_VM__TYPES_VM__H
#define ARGO_VM__TYPES_VM__H

#include <stdbool.h>
#include <stdint.h>

#include "isa/operation.h"
#include "stack.h"
#include "eflags.h"
#include "options.h"

typedef struct
{
  // Is VM running?
  bool running;
  // Program instructions
  const int32_t *bytecode;
  // Instruction pointer
  uint32_t ip;
  // Flags
  EFLAGS *flags;
  // Stack
  Stack *stack;
  // Current operation
  Operation *op;
  // Options
  OptionsVM *opts;
} VM;

#endif
