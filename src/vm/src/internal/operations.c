// [HEAD] Definitions
#include "../core/instructions.h"
// [HEAD] Implementations
#include <stdio.h>

#include "../core/runtime.h"
#include "../core/stack.h"

void vm__exc_hlt(vm_t *vm) {
  vm__set_running(vm, false);
  vm__set_increase_ip(vm, false);
}

void vm__exc_ret(vm_t *vm) {
  // Switch to new call frame
  vm->bc->main = vm->bc->routines[vm->bc->main->caller];
  // Do not increment, routine has been finished
  vm__set_increase_ip(vm, false);
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

void vm__exc_neg(vm_t *vm) {
  // Result
  int32_t res = -(vm->op->args[0].value);
  // PSH to stack
  vm__stack_push(vm->stack, res);
}

void vm__exc_swp(vm_t *vm) {
  // Just swap the order
  vm__stack_push(vm->stack, vm->op->args[0].value);
  vm__stack_push(vm->stack, vm->op->args[1].value);
}

void vm__exc_jmp(vm_t *vm) {
  vm__set_ip(vm, vm->op->args[0].value);
  // When we jump, we don't increase
  vm__set_increase_ip(vm, false);
}

void vm__exc_jeq(vm_t *vm) {
  bool cmp = vm->cmp == EQUALS;

  if (cmp) {
    vm__set_ip(vm, vm->op->args[0].value);
  }

  vm__set_increase_ip(vm, !cmp);
}

void vm__exc_jne(vm_t *vm) {
  bool cmp = vm->cmp != EQUALS;

  if (cmp) {
    vm__set_ip(vm, vm->op->args[0].value);
  }

  vm__set_increase_ip(vm, !cmp);
}

void vm__exc_jmg(vm_t *vm) {
  bool cmp = vm->cmp == GREATER;

  if (cmp) {
    vm__set_ip(vm, vm->op->args[0].value);
  }

  vm__set_increase_ip(vm, !cmp);
}

void vm__exc_jml(vm_t *vm) {
  bool cmp = vm->cmp == LESSER;

  if (cmp) {
    vm__set_ip(vm, vm->op->args[0].value);
  }

  vm__set_increase_ip(vm, !cmp);
}

void vm__exc_jge(vm_t *vm) {
  bool cmp = vm->cmp == GREATER || vm->cmp == EQUALS;

  if (cmp) {
    vm__set_ip(vm, vm->op->args[0].value);
  }

  vm__set_increase_ip(vm, !cmp);
}

void vm__exc_jle(vm_t *vm) {
  bool cmp = vm->cmp == LESSER || vm->cmp == EQUALS;

  if (cmp) {
    vm__set_ip(vm, vm->op->args[0].value);
  }

  vm__set_increase_ip(vm, !cmp);
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
  // Increase current ip now
  vm->bc->main->ip++;
  // Switch to new call frame
  vm->bc->main = vm->bc->routines[vm->op->args[0].value];
  // Set the caller address
  vm->bc->main->caller = return_address;
  // Do not increase ip now, we just switched
  // we have to execute the zero instruction
  vm__set_increase_ip(vm, false);
}

void vm__exc_print(vm_t *vm) { printf("%d\n", vm->op->args[0].value); }
