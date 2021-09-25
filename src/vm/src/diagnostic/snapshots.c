// [HEAD] Definitions
#include "snapshots.h"
// [IMPL] Headers
#include <stdio.h>

#include "../core/stack.h"

void vm__snaps_internal(vm_t *vm) {
  printf("+========================================+\n");
  printf("| <VM>%*s|\n", 35, "");
  printf("+========================================+\n");
  printf("| %-14s %-12s %-10s |\n", "TYPE", "NAME", "VALUE");
  printf("+----------------------------------------+\n");
  printf("| %-14s %-12s %-10d |\n", "(bool)", "run", vm->run);
  printf("| %-14s %-12s %-10d |\n", "(vm__cmp_t)", "cmp", vm->cmp);
  printf("| %-14s %-12s %-10d |\n", "(vm__bc_t*)", "bc", vm->bc->main->id);
  printf("+----------------------------------------+\n");
}

void vm__snaps_callstack(vm_t *vm) {
  printf("+========================================+\n");
  printf("| <CURRENT CALL>%*s|\n", 25, "");
  printf("+========================================+\n");
  printf("| %-14s %-12s %-10s |\n", "TYPE", "NAME", "VALUE");
  printf("+----------------------------------------+\n");
  printf("| %-14s %-12s %-10d |\n", "(uint16_t)", "id", vm->bc->main->id);
  printf("| %-14s %-12s %-10s |\n", "(const char*)", "name", vm->bc->main->name);
  printf("| %-14s %-12s %-10d |\n", "(uint32_t*)", "instr_ptr", vm->bc->main->ip);
  printf("| %-14s %-12s %-10d |\n", "(uint16_t)", "caller", vm->bc->main->caller);
  printf("+----------------------------------------+\n");
}

void vm__snaps_operation(vm_t *vm) {
  printf("+========================================+\n");
  printf("| <OPERATION>%*s|\n", 28, "");
  printf("+========================================+\n");

  if (vm->op != NULL) {
    printf("| %-14s %-12s %-10s |\n", "TYPE", "NAME", "VALUE");
    printf("+----------------------------------------+\n");
    printf("| %-14s %-12s %-10d |\n", "(int32_t)", "identifier", vm->op->id);
    printf("| %-14s %-12s %-10s |\n", "(char*)", "name", vm->op->name);
    printf("| %-14s %-12s %-10d |\n", "(int32_t)", "address", vm->op->addr);
    printf("| %-14s %-12s %-10d |\n", "(uint8_t)", "args_size", vm->op->args_size);

    for (int i = 0; i < vm->op->args_size; ++i) {
      printf("+----------------------------------------+\n");
      printf("| <ARGUMENT>%*s|\n", 29, "");
      printf("+----------------------------------------+\n");
      printf("| %-14s %-12s %-10s |\n", "TYPE", "NAME", "VALUE");
      printf("+----------------------------------------+\n");
      printf("| %-14s %-12s %-10s |\n", "(char*)", "name", vm->op->args[i].name);
      printf("| %-14s %-12s %-10d |\n", "(int32_t)", "value", vm->op->args[i].value);
      printf("| %-14s %-12s %-10d |\n", "(int32_t)", "addr", vm->op->args[i].addr);
    }
  } else {
    printf("| [UNFETCHED]%*s|\n", 28, "");
  }

  printf("+----------------------------------------+\n");
}

void vm__snaps_memory(vm_t *vm) {
  printf("+========================================+\n");
  printf("| <STACK>%*s|\n", 32, "");
  printf("+========================================+\n");
  printf("| %-14s %-12s %-10s |\n", "TYPE", "NAME", "VALUE");
  printf("+----------------------------------------+\n");
  printf("| %-14s %-12s %-10d |\n", "(uint32_t)", "growth", vm->stack->growth);
  printf("| %-14s %-12s %-10d |\n", "(int32_t)", "offset", vm->stack->offset);
  printf("| %-14s %-12s %-10d |\n", "(uint32_t)", "count", vm->stack->count);
  printf("| %-14s %-12s %-10d |\n", "(uint32_t)", "size", vm->stack->size);
  printf("| %-14s %-12s %-10d |\n", "(uint32_t)", "max", vm->stack->max);
  printf("+----------------------------------------+\n");
  printf("| <DATA>%*s|\n", 33, "");
  printf("+----------------------------------------+\n");

  if (vm->stack->count) {
    printf("| %-14s %-12s %-10s |\n", "TYPE", "ADDR", "VALUE");
    printf("+----------------------------------------+\n");

    for (uint32_t i = 0; i < vm->stack->count; ++i) {
      printf("| %-14s %-12d %-10d |\n", "(int32_t)", i, vm__stack_peek(vm->stack, i));
    }
  } else {
    printf("| [EMPTY]%*s|\n", 32, "");
  }

  printf("+----------------------------------------+\n\n");
}

void vm__snaps(vm_t *vm) {
  if (vm->opts->snaps.internal) vm__snaps_internal(vm);
  if (vm->opts->snaps.callstack) vm__snaps_callstack(vm);
  if (vm->opts->snaps.operation) vm__snaps_operation(vm);
  if (vm->opts->snaps.memory) vm__snaps_memory(vm);
}
