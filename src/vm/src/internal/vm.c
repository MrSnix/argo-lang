// [HEAD] Definitions
#include "../core/engine.h"
// [IMPL] Headers
#include <stdlib.h>

#include "../core/bytecode.h"
#include "../core/decoder.h"
#include "../core/options.h"
#include "../core/runtime.h"
#include "../core/stack.h"
#include "../diagnostic/snapshots.h"
#include "../types/isa/operation.h"

static vm_t *vm__init(vm__bc_t *bc) {
  vm_t *vm = malloc(sizeof(vm_t));

  vm->running = false;
  vm->bc = bc;
  vm->bc->main->ip = 0;
  vm->cmp = EQUALS;
  vm->stack = vm__stack_create(STACK_DEFAULT_SIZE, STACK_1MB_SIZE);
  vm->op = NULL;
  vm->opts = NULL;

  return vm;
}

vm_t *vm__create(vm__bc_t *bc, vm__opts_t *opts) {
  vm_t *vm = vm__init(bc);
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
    // Dump on request
    vm__snaps(vm);
    // Execute
    vm__execute(vm);
    // Free the operation
    vm__op_free(&vm->op);
  }
}

void vm__free(vm_t **vm) {
  vm__stack_free(&(*vm)->stack);
  vm__opts_free(&(*vm)->opts);
  vm__bc_free(&(*vm)->bc);
  free(*vm);
  *vm = NULL;
}
