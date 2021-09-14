#include "core/bytecode.h"
#include "core/cli.h"
#include "core/engine.h"
#include "core/options.h"
#include "types/isa/opcode.h"

static vm__bc_t *init() {
  // Routines
  int32_t sum_rtn[] = {ADD, RET};
  // Main routine
  int32_t main[] = {PSH, 5, PSH, 4, CLL, 1, HLT};
  // Class infos
  vm__bc_version_t version = {.major = 1, .minor = 0};
  // Remeber to set routine length
  vm__bc_routine_t *table[] = {
      vm__routine_create(0, "main", 7, main),
      vm__routine_create(1, "sum(a, b)", 2, sum_rtn),
  };
  // Remember to set routine table new size
  return vm__bc_create(version, 2, table);
}

int main(int argc, char *argv[]) {
  // Create sample class-file
  vm__bc_t *bc = init();
  // Parse command line
  vm__cli_t *cli = vm__cli(argc, argv);
  // Convert to compatible vm options interface
  vm__opts_t *opts = vm__opts_create(cli->vm);
  // Execute with given args
  if (opts->in != NULL || bc != NULL) {
    // Create vm
    vm_t *vm = vm__create(bc, opts);
    // Execute
    vm__run(vm);
    // Clean
    vm__free(&vm);
  }
  // Free & return status
  return vm__cli_free(&cli);
}
