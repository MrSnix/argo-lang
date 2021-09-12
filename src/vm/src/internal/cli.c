// [HEAD] Definitions
#include "../core/cli.h"
// [IMPL] Headers
#include <stdlib.h>
#include <stdio.h>

ArgsCLI *vm__cli_create(int argc, char *argv[]) {

  ArgsCLI *args = (ArgsCLI*)malloc(sizeof(ArgsCLI));

  args->name = CLI_NAME;
  args->exe_name = CLI_EXE_NAME;
  args->version = CLI_VERSION;

  args->vm = (ArgsVM*)malloc(sizeof(ArgsVM));
  
  args->vm->in = arg_filen(NULL, NULL, "<file>", 1, 100, "Input file(s)"),

  args->vm->snaps = arg_litn("s", "snapshots", 0, 1, "Turn on run-time any snapshot logger");
  args->vm->snaps__internal = arg_litn(NULL, "sInt", 0, 1, "Turn on run-time snapshot logger (internal-only)");
  args->vm->snaps__memory = arg_litn(NULL, "sMem", 0, 1, "Turn on run-time snapshot logger (memory-only)");
  args->vm->snaps__operation = arg_litn(NULL, "sOpr", 0, 1, "Turn on run-time snapshot logger (operation-only)");

  args->vm->benchmark = arg_litn("b", "benchmark", 0, 1, "Turn on run-time performance logging");

  args->common = (ArgsCommon*)malloc(sizeof(ArgsCommon));
  args->common->help = arg_litn(NULL, "help", 0, 1, "Display this help and exit");
  args->common->version = arg_litn(NULL, "version", 0, 1, "Displays version information and exit");
  args->common->end = arg_end(CLI_ERRORS);

  args->table[0] = args->vm->in;
  args->table[1] = args->vm->snaps;
  args->table[2] = args->vm->snaps__internal;
  args->table[3] = args->vm->snaps__memory;
  args->table[4] = args->vm->snaps__operation;
  args->table[5] = args->vm->benchmark;
  args->table[6] = args->common->help;
  args->table[7] = args->common->version;
  args->table[8] = args->common->end;

  args->errors = arg_parse(argc, argv, args->table);
  args->status = args->errors ? args->errors : OK_CLI_EXIT;

  return args;
}

int vm__cli_free(ArgsCLI **args) {
  // Save status
  int status = (*args)->status;
  // Now free
  arg_freetable((*args)->table, CLI_ARGS);
  free((*args)->vm);
  free((*args)->common);
  free(*args);
  *args = NULL;
  return status;
}

void vm__cli_help(ArgsCLI *args) {
  printf("Usage: %s", args->exe_name);
  arg_print_syntax(stdout, args->table, "\n");
  arg_print_glossary(stdout, args->table, "  %-50s %s\n");
  args->status = OK_CLI_EXIT;
}

void vm__cli_version(ArgsCLI *args) {
  printf("%s %s\n", args->name, args->version);
  args->status = OK_CLI_EXIT;
}

void vm__cli_errors(ArgsCLI *args) {
  /* Display the error details contained in the arg_end struct.*/
  arg_print_errors(stdout, args->common->end, CLI_EXE_NAME);
  printf("Try '%s --help' for more information.\n", CLI_EXE_NAME);
  args->status = ERR_CLI_PARSE;
}

ArgsCLI *vm__cli(int argc, char *argv[]) {

  ArgsCLI *args = vm__cli_create(argc, argv);

  /* special case: '--help' takes precedence over error reporting */
  if (args->common->help->count > 0) {
    vm__cli_help(args);
  } else if (args->common->version->count > 0) {
    vm__cli_version(args);
  } else if (args->errors > 0) {
    vm__cli_errors(args);
  }

  return args;
}
