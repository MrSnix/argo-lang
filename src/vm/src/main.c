#include "core/cli.h"
#include "core/engine.h"
#include "core/options.h"
#include "types/isa/opcode.h"

int main(int argc, char *argv[]) {
  int32_t bytecode[] = {PSH, 1, PSH, 1, ADD, POP, HLT};
  // Parse command line
  ArgsCLI *cli = vm__cli(argc, argv);
  // Convert to compatible vm options interface
  OptionsVM *opts = vm__opts_create(cli->vm);
  // Execute with given args
  if (opts->in != NULL || bytecode != NULL) {
    // Create vm
    VM *vm = vm__create(bytecode, opts);
    // Execute
    vm__run(vm);
    // Clean
    vm__free(&vm);
  }
  // Free & return status
  return vm__cli_free(&cli);
}
