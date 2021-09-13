#include "test-decoder.h"

#include "engine.h"

MunitResult vm__op_create_test() {
  // HLT instruction bytecode
  const int32_t bytecode[] = {0};
  // VM instance
  VM *vm = vm__create(bytecode, NULL);

  return MUNIT_OK;
}

MunitResult vm__op_free_test() { return MUNIT_OK; }
