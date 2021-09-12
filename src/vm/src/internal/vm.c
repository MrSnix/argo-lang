// [HEAD] Definitions
#include "../core/engine.h"
// [IMPL] Headers
#include <stdlib.h>
#include "../core/stack.h"
#include "../core/runtime.h"
#include "../core/decoder.h"
#include "../core/options.h"
#include "../core/eflags.h"
#include "../types/isa/operation.h"
#include "../diagnostic/snapshots.h"

static VM *vm__init(const int32_t *bytecode)
{
  VM *vm = (VM *)malloc(sizeof(VM));

  vm->running = false;
  vm->bytecode = bytecode;
  vm->ip = 0;
  vm->flags = vm__eflags_create();
  vm->stack = vm__stack_create(STACK_DEFAULT_SIZE, STACK_1MB_SIZE);
  vm->op = NULL;
  vm->opts = NULL;

  return vm;
}

VM *vm__create(const int32_t *bytecode, OptionsVM *opts)
{
  VM *vm = vm__init(bytecode);
  vm->opts = opts == NULL ? vm__opts_create(NULL) : opts;
  return vm;
}

void vm__run(VM *vm)
{
  // Init
  vm->running = true;
  // Execute cycle
  while (vm->running)
  {
    // Read
    int32_t instruction = vm__fetch(vm);
    // Decode
    vm__decode(vm, instruction);
    // Execute
    vm__execute(vm);
    // Dump on request
    vm__snaps(vm);
    // Free the operation
    vm__op_free(&vm->op);
  }
}

void vm__free(VM **vm)
{
  vm__stack_free(&(*vm)->stack);
  vm__eflags_free(&(*vm)->flags);
  vm__opts_free(&(*vm)->opts);
  free(*vm);
  *vm = NULL;
}
