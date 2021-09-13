#ifndef ARGO_VM__TYPES_OPTS_H
#define ARGO_VM__TYPES_OPTS_H

#include <stdbool.h>

typedef struct {
  unsigned int size;
  unsigned int *breakpoints;
} DebuggerOptionsVM;

typedef struct {
  bool internal;
  bool operation;
  bool memory;
} vm__opts_snaps_t;

typedef struct {
  const char *in;
  vm__opts_snaps_t *snaps;
  DebuggerOptionsVM *dbg;
} vm__opts_t;

#endif
