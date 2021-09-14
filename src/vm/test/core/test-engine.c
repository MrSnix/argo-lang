#include "test-engine.h"

#include <engine.h>

MunitResult vm__create_test() {
  // HLT instruction bc
  const int32_t *bc = {0};
  // VM instance
  vm_t *vm = vm__create(bc, NULL);
  // Asserting
  assert_false(vm->running);
  assert_ptr_equal(bc, vm->bc);
  assert_uint32(vm->bc->main->ip, ==, 0);
  assert_null(vm->op);
  assert_not_null(vm->opts);
  // Freeing
  vm__free(&vm);
  return MUNIT_OK;
}

MunitResult vm__run_test() {
  // HLT instruction bc
  const int32_t bc[] = {0, 0};
  // VM instance
  vm_t *vm = vm__create(bc, NULL);
  // Make it run
  vm__run(vm);
  // Asserting
  assert_false(vm->running);
  assert_ptr_equal(bc, vm->bc);
  assert_uint32(vm->bc->main->ip, ==, 1);
  // Freeing
  vm__free(&vm);
  return MUNIT_OK;
}

MunitResult vm__free_test() {
  // HLT instruction bc
  const int32_t *bc = {0};
  // VM instance
  vm_t *vm = vm__create(bc, NULL);
  // Now freeing
  vm__free(&vm);
  // Asserting
  assert_null(vm);

  return MUNIT_OK;
}
