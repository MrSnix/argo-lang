// [HEAD] Definitions
#include "snapshots.h"
// [IMPL] Headers
#include <stdio.h>
#include "../core/stack.h"

void vm__snaps_operation(VM *vm)
{

  printf("+========================================+\n");
  printf("| <OPERATION>%*s|\n", 28, "");
  printf("+========================================+\n");

  if (vm->op != NULL)
  {
    printf("| %-14s %-12s %-10s |\n", "TYPE", "NAME", "VALUE");
    printf("+----------------------------------------+\n");
    printf("| %-14s %-12s %-10d |\n", "(int32_t)", "identifier", vm->op->id);
    printf("| %-14s %-12s %-10s |\n", "(char*)", "name", vm->op->name);
    printf("| %-14s %-12s %-10d |\n", "(int32_t)", "address", vm->op->addr);
    printf("| %-14s %-12s %-10d |\n", "(uint8_t)", "args_size", vm->op->args_size);

    for (int i = 0; i < vm->op->args_size; ++i)
    {
      printf("+----------------------------------------+\n");
      printf("| <ARGUMENT>%*s|\n", 29, "");
      printf("+----------------------------------------+\n");
      printf("| %-14s %-12s %-10s |\n", "TYPE", "NAME", "VALUE");
      printf("+----------------------------------------+\n");
      printf("| %-14s %-12s %-10s |\n", "(char*)", "name", vm->op->args[i].name);
      printf("| %-14s %-12s %-10d |\n", "(int32_t)", "value", vm->op->args[i].value);
      printf("| %-14s %-12s %-10d |\n", "(int32_t)", "addr", vm->op->args[i].addr);
    }
  }
  else
  {
    printf("| [UNFETCHED]%*s|\n", 28, "");
  }

  printf("+----------------------------------------+\n");
}

void vm__snaps_memory(VM *vm)
{

  printf("+========================================+\n");
  printf("| <STACK>%*s|\n", 32, "");
  printf("+========================================+\n");
  printf("| %-14s %-12s %-10s |\n", "TYPE", "NAME", "VALUE");
  printf("+----------------------------------------+\n");
  printf("| %-14s %-12s %-10d |\n", "(int32_t)", "offset", vm->stack->offset);
  printf("| %-14s %-12s %-10d |\n", "(int32_t)", "counter", vm->stack->counter);
  printf("| %-14s %-12s %-10d |\n", "(int32_t)", "size", vm->stack->size);
  printf("| %-14s %-12s %-10d |\n", "(int32_t)", "max", vm->stack->max);
  printf("+----------------------------------------+\n");
  printf("| <DATA>%*s|\n", 33, "");
  printf("+----------------------------------------+\n");

  if (vm->stack->counter)
  {
    printf("| %-14s %-12s %-10s |\n", "TYPE", "ADDR", "VALUE");
    printf("+----------------------------------------+\n");

    for (int32_t i = 0; i < vm->stack->counter; ++i)
    {
      printf("| %-14s %-12d %-10d |\n", "(int32_t)", i, vm__stack_peek(vm->stack, i));
    }
  }
  else
  {

    printf("| [EMPTY]%*s|\n", 32, "");
  }

  printf("+----------------------------------------+\n");
}

void vm__snaps_internal(VM *vm)
{
  printf("+========================================+\n");
  printf("| <VM>%*s|\n", 35, "");
  printf("+========================================+\n");
  printf("| %-14s %-12s %-10s |\n", "TYPE", "NAME", "VALUE");
  printf("+----------------------------------------+\n");
  printf("| %-14s %-12s %-10d |\n", "(bool)", "running", vm->running);
  printf("| %-14s %-12s %-10d |\n", "(Comparator)", "cmp", vm->cmp);
  printf("| %-14s %-12s %-10d |\n", "(int32_t*)", "instr_ptr", vm->ip);
  printf("| %-14s %-12s %-10d |\n", "(int32_t*)", "bytecode", vm->bytecode[vm->ip]);
  printf("+----------------------------------------+\n");
}

void vm__snaps(VM *vm)
{
  if (vm->opts->snaps->internal)
    vm__snaps_internal(vm);
  if (vm->opts->snaps->operation)
    vm__snaps_operation(vm);
  if (vm->opts->snaps->memory)
    vm__snaps_memory(vm);
}
