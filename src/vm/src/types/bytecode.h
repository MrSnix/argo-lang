#ifndef ARGO_VM__TYPES_BYTECODE_H
#define ARGO_VM__TYPES_BYTECODE_H

#include <stdint.h>

typedef struct {
  uint16_t major;
  uint16_t minor;
} vm__bc_version_t;

typedef struct {
  uint16_t id;
  const char *name;
  int32_t *data;
  uint32_t ip;
} vm__bc_routine_t;

typedef struct {
  vm__bc_version_t version;
  vm__bc_routine_t main;
  vm__bc_routine_t *routines;
  uint16_t routines_size;
} vm__bc_t;

#endif
