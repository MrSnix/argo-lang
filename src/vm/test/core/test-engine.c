#include "test-engine.h"

#include <engine.h>

MunitResult vm__create_test() {
  // HLT instruction bytecode
  const int32_t *bytecode = {0};
  // VM instance
  vm_t *vm = vm__create(bytecode, NULL);
  // Asserting
  assert_false(vm->running);
  assert_ptr_equal(bytecode, vm->bytecode);
  assert_uint32(vm->ip, ==, 0);
  assert_null(vm->op);
  assert_not_null(vm->opts);
  // Freeing
  vm__free(&vm);
  return MUNIT_OK;
}

MunitResult vm__run_test() {
  // HLT instruction bytecode
  const int32_t bytecode[] = {0, 0};
  // VM instance
  vm_t *vm = vm__create(bytecode, NULL);
  // Make it run
  vm__run(vm);
  // Asserting
  assert_false(vm->running);
  assert_ptr_equal(bytecode, vm->bytecode);
  assert_uint32(vm->ip, ==, 1);
  // Freeing
  vm__free(&vm);
  return MUNIT_OK;
}

MunitResult vm__free_test() {
  // HLT instruction bytecode
  const int32_t *bytecode = {0};
  // VM instance
  vm_t *vm = vm__create(bytecode, NULL);
  // Now freeing
  vm__free(&vm);
  // Asserting
  assert_null(vm);

  return MUNIT_OK;
}
