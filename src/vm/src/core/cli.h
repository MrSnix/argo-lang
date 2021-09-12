#ifndef ARGO_VM__CLI_H
#define ARGO_VM__CLI_H

#include "../types/cli.h"

ArgsCLI *vm__cli_create(int argc, char *argv[]);
int vm__cli_free(ArgsCLI **args);

ArgsCLI *vm__cli(int argc, char *argv[]);
void vm__cli_help(ArgsCLI *args);
void vm__cli_version(ArgsCLI *args);
void vm__cli_errors(ArgsCLI *args);

#endif
