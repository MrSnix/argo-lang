// [HEAD] Definitions
#include "../core/cli.h"
// [IMPL] Headers
#include <stdio.h>
#include <stdlib.h>

vm__cli_t *vm__cli_create(int argc, char *argv[]) {
  vm__cli_t *args = (vm__cli_t *)malloc(sizeof(vm__cli_t));

  args->vm = (vm__cli_args_t *)malloc(sizeof(vm__cli_args_t));

  args->vm->in = arg_filen(NULL, NULL, "<file>", 1, 100, "Input file(s)"),

  args->vm->snaps =
      arg_litn("s", "snapshots", 0, 1, "Turn on run-time any snapshot logger");
  args->vm->snaps__internal = arg_litn(
      NULL, "sInt", 0, 1, "Turn on run-time snapshot logger (internal-only)");
  args->vm->snaps__memory = arg_litn(
      NULL, "sMem", 0, 1, "Turn on run-time snapshot logger (memory-only)");
  args->vm->snaps__operation = arg_litn(
      NULL, "sOpr", 0, 1, "Turn on run-time snapshot logger (operation-only)");

  args->vm->benchmark =
      arg_litn("b", "benchmark", 0, 1, "Turn on run-time performance logging");

  args->help =
      arg_litn(NULL, "help", 0, 1, "Display this help and exit");
  args->version =
      arg_litn(NULL, "version", 0, 1, "Displays version information and exit");
  args->end = arg_end(CLI_ERRORS);

  args->table[0] = args->vm->in;
  args->table[1] = args->vm->snaps;
  args->table[2] = args->vm->snaps__internal;
  args->table[3] = args->vm->snaps__memory;
  args->table[4] = args->vm->snaps__operation;
  args->table[5] = args->vm->benchmark;
  args->table[6] = args->help;
  args->table[7] = args->version;
  args->table[8] = args->end;

  args->errors = arg_parse(argc, argv, args->table);
  args->status = args->errors ? args->errors : OK_CLI_EXIT;

  return args;
}

int vm__cli_free(vm__cli_t **args) {
  // Save status
  int status = (*args)->status;
  // Now free
  arg_freetable((*args)->table, CLI_ARGS);
  free((*args)->vm);
  free(*args);
  *args = NULL;
  return status;
}

void vm__cli_help(vm__cli_t *args) {
  printf("Usage: %s", CLI_EXE_NAME);
  arg_print_syntax(stdout, args->table, "\n");
  arg_print_glossary(stdout, args->table, "  %-50s %s\n");
  args->status = OK_CLI_EXIT;
}

void vm__cli_version(vm__cli_t *args) {
  printf("%s %s\n", CLI_NAME, CLI_VERSION);
  args->status = OK_CLI_EXIT;
}

void vm__cli_errors(vm__cli_t *args) {
  /* Display the error details contained in the arg_end struct.*/
  arg_print_errors(stdout, args->end, CLI_EXE_NAME);
  printf("Try '%s --help' for more information.\n", CLI_EXE_NAME);
  args->status = ERR_CLI_PARSE;
}

vm__cli_t *vm__cli(int argc, char *argv[]) {
  vm__cli_t *args = vm__cli_create(argc, argv);

  /* special case: '--help' takes precedence over error reporting */
  if (args->help->count > 0) {
    vm__cli_help(args);
  } else if (args->version->count > 0) {
    vm__cli_version(args);
  } else if (args->errors > 0) {
    vm__cli_errors(args);
  }

  return args;
}
