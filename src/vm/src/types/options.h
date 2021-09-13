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
} SnapshotOptionsVM;

typedef struct {
  const char *in;
  SnapshotOptionsVM *snaps;
  DebuggerOptionsVM *dbg;
} OptionsVM;

#endif
