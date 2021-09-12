#ifndef ARGO_VM__TYPES_STACK_H
#define ARGO_VM__TYPES_STACK_H

#include <stdint.h>

#define STACK_DEFAULT_SIZE 8
#define STACK_1MB_SIZE 250000

typedef struct
{
  int32_t *data;
  int32_t offset;
  int32_t counter;
  int32_t current;
  int32_t max;
} Stack;

#endif
