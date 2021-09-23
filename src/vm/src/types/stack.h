#ifndef ARGO_VM__TYPES_STACK_H
#define ARGO_VM__TYPES_STACK_H

#include <stdint.h>

#define STACK_DEFAULT_SIZE 8
#define STACK_8MB_SIZE 2000000

typedef struct {
  int32_t *data;
  int32_t offset;
  uint32_t counter;
  uint32_t growth;
  uint32_t size;
  uint32_t max;
} vm__stack_t;

#endif
