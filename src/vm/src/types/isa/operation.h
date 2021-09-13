#ifndef ARGO_VM__TYPES_OPERATION_H
#define ARGO_VM__TYPES_OPERATION_H

#include <stdint.h>

#include "opcode.h"

typedef struct {
  char *name;
  int32_t value;
  int32_t addr;
} OpArgument;

typedef struct {
  OpCode id;
  char *name;
  OpArgument *args;
  uint8_t args_size;
  int32_t addr;
} vm__op_t;

#endif
