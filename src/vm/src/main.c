#include "core/bytecode.h"
#include "core/cli.h"
#include "core/engine.h"
#include "core/options.h"
#include "types/isa/opcode.h"

int main(int argc, char *argv[]) {
  // Parse command line
  vm__cli_t *cli = vm__cli(argc, argv);
  // Execute with given args
  if (cli->vm->in->count > 0) {
    // Convert to compatible vm options interface
    vm__opts_t *opts = vm__opts_create(cli->vm);
    // Read input
    vm__bc_t *bc = vm__bc_read(opts->in);
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
