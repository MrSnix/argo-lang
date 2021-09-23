#ifndef ARGO_VM__INSTRUCTIONS_H
#define ARGO_VM__INSTRUCTIONS_H

#include "../types/vm.h"

void vm__exc_hlt(vm_t *vm);
void vm__exc_ret(vm_t *vm);
void vm__exc_pop(vm_t *vm);
void vm__exc_psh(vm_t *vm);
void vm__exc_add(vm_t *vm);
void vm__exc_sub(vm_t *vm);
void vm__exc_mul(vm_t *vm);
void vm__exc_div(vm_t *vm);
void vm__exc_neg(vm_t *vm);
void vm__exc_swp(vm_t *vm);
void vm__exc_jmp(vm_t *vm);
void vm__exc_jeq(vm_t *vm);
void vm__exc_jne(vm_t *vm);
void vm__exc_jmg(vm_t *vm);
void vm__exc_jml(vm_t *vm);
void vm__exc_jge(vm_t *vm);
void vm__exc_jle(vm_t *vm);
void vm__exc_cmp(vm_t *vm);
void vm__exc_cll(vm_t *vm);
void vm__exc_print(vm_t *vm);

#endif
