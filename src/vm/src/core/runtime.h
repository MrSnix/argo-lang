#ifndef ARGO_VM__RUNTIME_H
#define ARGO_VM__RUNTIME_H

#include "../types/vm.h"

int32_t vm__fetch(VM *vm);
int32_t vm__fetch_next(VM *vm);
int32_t vm__fetch_peek(VM *vm, int32_t offset);

void vm__increase_ip(VM *vm);
void vm__decrease_ip(VM *vm);
int32_t vm__current_ip(VM *vm);
void vm__set_ip(VM *vm, int32_t addr);

void vm__decode(VM *vm, int32_t instr);
void vm__execute(VM *vm);

#endif
