#ifndef ARGO_VM__TYPES_VM__H
#define ARGO_VM__TYPES_VM__H

#include <stdbool.h>
#include <stdint.h>

#include "bytecode.h"
#include "isa/operation.h"
#include "options.h"
#include "stack.h"

typedef enum { LESSER = -1, EQUALS = 0, GREATER = 1 } Comparator;

typedef struct {
  // Is VM running?
  bool running;
  // Program instructions
  vm__bc_t *bc;
  // Comparator
  Comparator cmp;
  // Stack
  vm__stack_t *stack;
  // Current operation
  vm__op_t *op;
  // Options
  vm__opts_t *opts;
} vm_t;

#endif
