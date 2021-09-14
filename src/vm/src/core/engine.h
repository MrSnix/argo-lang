#ifndef ARGO_VM__ENGINE_H
#define ARGO_VM__ENGINE_H

#include "../types/vm.h"

vm_t *vm__create(const int32_t *bc, vm__opts_t *opts);
void vm__run(vm_t *vm);
void vm__free(vm_t **vm);

#endif
