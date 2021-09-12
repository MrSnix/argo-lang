#ifndef ARGO_VM__DEBUG_H
#define ARGO_VM__DEBUG_H

#include "../types/vm.h"
#include "../types/isa/operation.h"

void vm__snaps(VM *vm);
void vm__snaps_internal(VM *vm);
void vm__snaps_operation(VM *vm);
void vm__snaps_memory(VM *vm);

#endif
