// [HEAD] Definitions
#include "../core/instructions.h"
// [HEAD] Implementations
#include "../core/runtime.h"
#include "../core/stack.h"

bool vm__exc_hlt(vm_t *vm) {
  vm->running = false;
  return false;
}

void vm__exc_psh(vm_t *vm) {
  // PSH to stack
  vm__stack_push(vm->stack, vm->op->args[0].value);
}

void vm__exc_pop(vm_t *vm) { vm__stack_pop(vm->stack); }

void vm__exc_add(vm_t *vm) {
  // Result
  int32_t res = vm->op->args[0].value + vm->op->args[1].value;
  // PSH to stack
  vm__stack_push(vm->stack, res);
}

void vm__exc_sub(vm_t *vm) {
  // Result
  int32_t res = vm->op->args[0].value - vm->op->args[1].value;
  // PSH to stack
  vm__stack_push(vm->stack, res);
}

void vm__exc_mul(vm_t *vm) {
  // Result
  int32_t res = vm->op->args[0].value * vm->op->args[1].value;
  // PSH to stack
  vm__stack_push(vm->stack, res);
}

void vm__exc_div(vm_t *vm) {
  // Op
  int32_t div = vm->op->args[0].value / vm->op->args[1].value;
  int32_t rem = vm->op->args[0].value % vm->op->args[1].value;
  // PSH to stack
  vm__stack_push(vm->stack, div);
  vm__stack_push(vm->stack, rem);
}

bool vm__exc_jmp(vm_t *vm) {
  vm__set_ip(vm, vm->op->args[0].value);
  // When we jump, we don't increase
  return false;
}

bool vm__exc_jme(vm_t *vm) {
  bool cmp = vm->cmp == EQUALS;

  if (cmp) {
    vm__set_ip(vm, vm->op->args[0].value);
  }

  return !cmp;
}

bool vm__exc_jmn(vm_t *vm) {
  bool cmp = vm->cmp != EQUALS;

  if (cmp) {
    vm__set_ip(vm, vm->op->args[0].value);
  }

  return !cmp;
}

bool vm__exc_jmg(vm_t *vm) {
  bool cmp = vm->cmp == GREATER;

  if (cmp) {
    vm__set_ip(vm, vm->op->args[0].value);
  }

  return !cmp;
}

bool vm__exc_jml(vm_t *vm) {
  bool cmp = vm->cmp == LESSER;

  if (cmp) {
    vm__set_ip(vm, vm->op->args[0].value);
  }

  return !cmp;
}

void vm__exc_cmp(vm_t *vm) {
  if (vm->op->args[1].value > vm->op->args[0].value) {
    vm->cmp = GREATER;
  } else if (vm->op->args[1].value < vm->op->args[0].value) {
    vm->cmp = LESSER;
  } else {
    vm->cmp = EQUALS;
  }
}

void vm__exc_cll(vm_t *vm) {
  // Save current return address
  uint16_t return_address = vm->bc->main->id;
  // Switch to new call frame
  vm->bc->main = vm->bc->routines[vm->op->args[0].value];
  // Set the caller address
  vm->bc->main->caller = return_address;
}
