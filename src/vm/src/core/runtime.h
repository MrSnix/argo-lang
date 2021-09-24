#ifndef ARGO_VM__RUNTIME_H
#define ARGO_VM__RUNTIME_H

#include "../types/vm.h"

int32_t vm__fetch(vm_t *vm);
int32_t vm__fetch_next(vm_t *vm);
int32_t vm__fetch_peek(vm_t *vm, int32_t offset);
int32_t vm__current_ip(vm_t *vm);

void vm__execute(vm_t *vm);
void vm__safe_increase_ip(vm_t *vm);
void vm__set_ip(vm_t *vm, int32_t addr);
void vm__decode(vm_t *vm, int32_t instr);
void vm__set_running(vm_t *vm, bool running);
void vm__set_increase_ip(vm_t *vm, bool fetch_next);

#endif
