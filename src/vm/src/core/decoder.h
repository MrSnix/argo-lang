#ifndef ARGO_VM__DECODER_H
#define ARGO_VM__DECODER_H

#include "../types/vm.h"

vm__op_t *vm__op_create(vm__code_t id, char *name, uint32_t ip,
                        uint8_t args_size);
vm__op_t *vm__op_clone(vm__op_t *op);

void vm__op_free(vm__op_t **op);

vm__op_args_t *vm__op_args_create(uint8_t args_size);
void vm__op_args_free(vm__op_args_t **arg);

void vm__dec_hlt(vm_t *vm);
void vm__dec_psh(vm_t *vm);
void vm__dec_pop(vm_t *vm);
void vm__dec_add(vm_t *vm);
void vm__dec_sub(vm_t *vm);
void vm__dec_mul(vm_t *vm);
void vm__dec_div(vm_t *vm);
void vm__dec_jmp(vm_t *vm);
void vm__dec_jme(vm_t *vm);
void vm__dec_jmn(vm_t *vm);
void vm__dec_jmg(vm_t *vm);
void vm__dec_jml(vm_t *vm);
void vm__dec_nop(vm_t *vm);
void vm__dec_cmp(vm_t *vm);
void vm__dec_cll(vm_t *vm);
void vm__dec_ret(vm_t *vm);
void vm__dec_print(vm_t *vm);

#endif
