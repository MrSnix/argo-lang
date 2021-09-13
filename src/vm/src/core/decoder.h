#ifndef ARGO_VM__DECODER_H
#define ARGO_VM__DECODER_H

#include "../types/vm.h"

Operation *vm__op_create(OpCode id, char *name, uint32_t ip, uint8_t args_size);
Operation *vm__op_clone(Operation *op);

void vm__op_free(Operation **op);

OpArgument *vm__op_args_create(uint8_t args_size);
void vm__op_args_free(OpArgument **arg);

void vm__dec_hlt(VM *vm);
void vm__dec_psh(VM *vm);
void vm__dec_pop(VM *vm);
void vm__dec_add(VM *vm);
void vm__dec_sub(VM *vm);
void vm__dec_mul(VM *vm);
void vm__dec_div(VM *vm);
void vm__dec_jmp(VM *vm);
void vm__dec_jme(VM *vm);
void vm__dec_jmn(VM *vm);
void vm__dec_jmg(VM *vm);
void vm__dec_jml(VM *vm);
void vm__dec_nop(VM *vm);
void vm__dec_cmp(VM *vm);
void vm__dec_cll(VM *vm);

#endif
