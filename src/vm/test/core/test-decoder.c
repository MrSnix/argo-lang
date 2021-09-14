#include "test-decoder.h"

#include "engine.h"

MunitResult vm__op_create_test() {
  // HLT instruction bc
  const int32_t bc[] = {0};
  // VM instance
  vm_t *vm = vm__create(bc, NULL);

  return MUNIT_OK;
}

MunitResult vm__op_free_test() { return MUNIT_OK; }
