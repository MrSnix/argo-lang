#ifndef ARGO_VM__DEBUG_H
#define ARGO_VM__DEBUG_H

#include "../types/isa/operation.h"
#include "../types/vm.h"

void vm__snaps(vm_t *vm);
void vm__snaps_internal(vm_t *vm);
void vm__snaps_operation(vm_t *vm);
void vm__snaps_memory(vm_t *vm);

#endif
