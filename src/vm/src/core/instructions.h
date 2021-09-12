#ifndef ARGO_VM__INSTRUCTIONS_H
#define ARGO_VM__INSTRUCTIONS_H

#include "../types/vm.h"

bool vm__exc_hlt(VM *vm);
void vm__exc_pop(VM *vm);
void vm__exc_psh(VM *vm);
void vm__exc_add(VM *vm);
void vm__exc_sub(VM *vm);
void vm__exc_mul(VM *vm);
void vm__exc_div(VM *vm);
bool vm__exc_jmp(VM *vm);
bool vm__exc_jme(VM *vm);
bool vm__exc_jmn(VM *vm);
bool vm__exc_jmg(VM *vm);
bool vm__exc_jml(VM *vm);
void vm__exc_cmp(VM *vm);
void vm__exc_cll(VM *vm);

#endif
