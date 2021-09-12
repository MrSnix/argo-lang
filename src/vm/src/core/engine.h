#ifndef ARGO_VM__ENGINE_H
#define ARGO_VM__ENGINE_H

#include "../types/vm.h"

VM *vm__create(const int32_t *bytecode, OptionsVM* opts);
void vm__run(VM *vm);
void vm__free(VM **vm);

#endif
