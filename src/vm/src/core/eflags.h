#ifndef ARGO_VM__EFLAGS_H
#define ARGO_VM__EFLAGS_H

#include "../types/eflags.h"

EFLAGS *vm__eflags_create();
void vm__eflags_free(EFLAGS **eflags);

#endif
