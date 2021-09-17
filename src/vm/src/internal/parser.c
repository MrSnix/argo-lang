// [HEAD] Definitions
#include "../core/decoder.h"
// [IMPL] Headers
#include <stdlib.h>

#include "../core/runtime.h"
#include "../core/stack.h"
#include "../types/isa/opcode.h"
#include "../types/isa/operation.h"

vm__op_t *vm__op_create(vm__code_t id, char *name, uint32_t ip,
                        uint8_t args_size) {
  vm__op_t *op = malloc(sizeof(vm__op_t));

  op->id = id;
  op->name = name;
  op->addr = ip;
  op->args_size = args_size;
  op->args = args_size ? vm__op_args_create(args_size) : NULL;

  return op;
}

void vm__op_free(vm__op_t **op) {
  if ((*op)->args_size) {
    vm__op_args_free(&(*op)->args);
  }

  free(*op);
  *op = NULL;
}

vm__op_args_t *vm__op_args_create(uint8_t args_size) {
  return (vm__op_args_t *)malloc(sizeof(vm__op_args_t) * args_size);
}

void vm__op_args_free(vm__op_args_t **args) {
  free(*args);
  *args = NULL;
}

void vm__dec_hlt(vm_t *vm) {
  vm->op = vm__op_create(HLT, "HLT", vm->bc->main->ip, HLT_ARGS);
}

void vm__dec_ret(vm_t *vm) {
  vm__op_t *op = vm__op_create(RET, "RET", vm->bc->main->ip, RET_ARGS);

  op->args[0].name = "ID";
  op->args[0].value = vm->bc->main->caller;
  // Address is internal, not on stack
  op->args[0].addr = -1;

  vm->op = op;
}

void vm__dec_psh(vm_t *vm) {
  vm__op_t *op = vm__op_create(PSH, "PSH", vm->bc->main->ip, PSH_ARGS);

  op->args[0].name = "VALUE";
  op->args[0].value = vm__fetch_next(vm);
  op->args[0].addr = vm__current_ip(vm);

  vm->op = op;
}

void vm__dec_pop(vm_t *vm) {
  vm__op_t *op = vm__op_create(POP, "POP", vm->bc->main->ip, POP_ARGS);

  op->args[0].name = "VALUE";
  op->args[0].value = vm__stack_top(vm->stack);
  op->args[0].addr = vm__stack_size(vm->stack);

  vm->op = op;
}

void vm__dec_add(vm_t *vm) {
  vm__op_t *op = vm__op_create(ADD, "ADD", vm->bc->main->ip, ADD_ARGS);

  op->args[0].name = "ADD0";
  op->args[0].value = vm__stack_pop(vm->stack);
  op->args[0].addr = vm__stack_size(vm->stack);

  op->args[1].name = "ADD1";
  op->args[1].value = vm__stack_pop(vm->stack);
  op->args[1].addr = vm__stack_size(vm->stack);

  vm->op = op;
}

void vm__dec_sub(vm_t *vm) {
  vm__op_t *op = vm__op_create(SUB, "SUB", vm->bc->main->ip, SUB_ARGS);

  op->args[0].name = "SUB0";
  op->args[0].value = vm__stack_pop(vm->stack);
  op->args[0].addr = vm__stack_size(vm->stack);

  op->args[1].name = "SUB1";
  op->args[1].value = vm__stack_pop(vm->stack);
  op->args[1].addr = vm__stack_size(vm->stack);

  vm->op = op;
}

void vm__dec_mul(vm_t *vm) {
  vm__op_t *op = vm__op_create(MUL, "MUL", vm->bc->main->ip, MUL_ARGS);

  op->args[0].name = "MUL0";
  op->args[0].value = vm__stack_pop(vm->stack);
  op->args[0].addr = vm__stack_size(vm->stack);

  op->args[1].name = "MUL1";
  op->args[1].value = vm__stack_pop(vm->stack);
  op->args[1].addr = vm__stack_size(vm->stack);

  vm->op = op;
}

void vm__dec_div(vm_t *vm) {
  vm__op_t *op = vm__op_create(DIV, "DIV", vm->bc->main->ip, DIV_ARGS);

  op->args[0].name = "DIV0";
  op->args[0].value = vm__stack_pop(vm->stack);
  op->args[0].addr = vm__stack_size(vm->stack);

  op->args[1].name = "DIV1";
  op->args[1].value = vm__stack_pop(vm->stack);
  op->args[1].addr = vm__stack_size(vm->stack);

  vm->op = op;
}

void vm__dec_jmp(vm_t *vm) {
  vm__op_t *op = vm__op_create(JMP, "JMP", vm->bc->main->ip, JMP_ARGS);

  op->args[0].name = "VALUE";
  op->args[0].value = vm__fetch_next(vm);
  op->args[0].addr = vm__current_ip(vm);

  vm->op = op;
}

void vm__dec_jme(vm_t *vm) {
  vm__op_t *op = vm__op_create(JME, "JME", vm->bc->main->ip, JMP_ARGS);

  op->args[0].name = "VALUE";
  op->args[0].value = vm__fetch_next(vm);
  op->args[0].addr = vm__current_ip(vm);

  vm->op = op;
}

void vm__dec_jmn(vm_t *vm) {
  vm__op_t *op = vm__op_create(JMN, "JMN", vm->bc->main->ip, JMP_ARGS);

  op->args[0].name = "VALUE";
  op->args[0].value = vm__fetch_next(vm);
  op->args[0].addr = vm__current_ip(vm);

  vm->op = op;
}

void vm__dec_jmg(vm_t *vm) {
  vm__op_t *op = vm__op_create(JMG, "JMG", vm->bc->main->ip, JMP_ARGS);

  op->args[0].name = "VALUE";
  op->args[0].value = vm__fetch_next(vm);
  op->args[0].addr = vm__current_ip(vm);

  vm->op = op;
}

void vm__dec_jml(vm_t *vm) {
  vm__op_t *op = vm__op_create(JML, "JML", vm->bc->main->ip, JMP_ARGS);

  op->args[0].name = "VALUE";
  op->args[0].value = vm__fetch_next(vm);
  op->args[0].addr = vm__current_ip(vm);

  vm->op = op;
}

void vm__dec_nop(vm_t *vm) {
  vm->op = vm__op_create(NOP, "NOP", vm->bc->main->ip, NOP_ARGS);
}

void vm__dec_cmp(vm_t *vm) {
  vm__op_t *op = vm__op_create(CMP, "CMP", vm->bc->main->ip, CMP_ARGS);

  op->args[0].name = "OP0";
  op->args[0].value = vm__stack_top(vm->stack);
  op->args[0].addr = vm__stack_size(vm->stack);

  op->args[1].name = "OP1";
  op->args[1].value = vm__stack_peek(vm->stack, vm->stack->offset - 1);
  op->args[1].addr = vm__stack_size(vm->stack);

  vm->op = op;
}

void vm__dec_cll(vm_t *vm) {
  vm__op_t *op = vm__op_create(CLL, "CLL", vm->bc->main->ip, CLL_ARGS);

  op->args[0].name = "ID";
  op->args[0].value = vm__fetch_next(vm);
  op->args[0].addr = vm__stack_size(vm->stack);

  vm->op = op;
}

void vm__dec_print(vm_t *vm) {
  vm__op_t *op = vm__op_create(PRINT, "PRINT", vm->bc->main->ip, PRINT_ARGS);

  op->args[0].name = "VALUE";
  op->args[0].value = vm__stack_peek(vm->stack, vm->stack->offset);
  op->args[0].addr = vm__stack_size(vm->stack);
  
  vm->op = op;
}
