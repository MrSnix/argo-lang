// [HEAD] Definitions
#include "../core/engine.h"
// [IMPL] Headers
#include <stdlib.h>

#include "../core/decoder.h"
#include "../core/options.h"
#include "../core/runtime.h"
#include "../core/stack.h"
#include "../diagnostic/snapshots.h"
#include "../types/isa/operation.h"

static vm_t *vm__init(const int32_t *bytecode) {
  vm_t *vm = (vm_t *)malloc(sizeof(vm_t));

  vm->running = false;
  vm->bytecode = bytecode;
  vm->ip = 0;
  vm->cmp = EQUALS;
  vm->stack = vm__stack_create(STACK_DEFAULT_SIZE, STACK_1MB_SIZE);
  vm->op = NULL;
  vm->opts = NULL;

  return vm;
}

vm_t *vm__create(const int32_t *bytecode, vm__opts_t *opts) {
  vm_t *vm = vm__init(bytecode);
  vm->opts = opts == NULL ? vm__opts_create(NULL) : opts;
  return vm;
}

void vm__run(vm_t *vm) {
  // Init
  vm->running = true;
  // Execute cycle
  while (vm->running) {
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

void vm__free(vm_t **vm) {
  vm__stack_free(&(*vm)->stack);
  vm__opts_free(&(*vm)->opts);
  free(*vm);
  *vm = NULL;
}
