#ifndef ARGO_VM__TYPES_VM__H
#define ARGO_VM__TYPES_VM__H

#include <stdbool.h>
#include <stdint.h>

#include "bytecode.h"
#include "isa/operation.h"
#include "options.h"
#include "stack.h"

typedef enum { LESSER = -1, EQUALS = 0, GREATER = 1 } vm__cmp_t;

typedef struct {
  // Is VM running?
  bool run;
  // If the instruction pointer should be increased
  bool fetch;
  // Program instructions
  vm__bc_t *bc;
  // vm__cmp_t
  vm__cmp_t cmp;
  // Stack
  vm__stack_t *stack;
  // Current operation
  vm__op_t *op;
  // Options
  vm__opts_t *opts;
} vm_t;

#endif
