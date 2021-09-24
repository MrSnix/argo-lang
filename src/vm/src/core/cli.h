#ifndef ARGO_VM__CLI_H
#define ARGO_VM__CLI_H

#include "../types/cli.h"

vm__cli_t *vm__cli(int argc, char *argv[]);
vm__cli_t *vm__cli_create(int argc, char *argv[]);

int vm__cli_free(vm__cli_t **args);

void vm__cli_help(vm__cli_t *args);
void vm__cli_errors(vm__cli_t *args);
void vm__cli_version(vm__cli_t *args);

#endif
