#ifndef ARGO_VM__TYPES_EFLAGS_H
#define ARGO_VM__TYPES_EFLAGS_H

typedef enum { LESSER = -1, EQUALS = 0, GREATER = 1 } Comparator;

typedef struct {
  Comparator CM;
} EFLAGS;

#endif
