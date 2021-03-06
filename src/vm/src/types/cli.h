#ifndef ARGO_VM__TYPES_CLI_H
#define ARGO_VM__TYPES_CLI_H

#define CLI_NAME "ArgoVM"
#define CLI_EXE_NAME "argo"
#define CLI_VERSION "0.0.1"
#define CLI_ARGS 10
#define CLI_ERRORS 20

#include <argtable3.h>

#define OK_CLI_EXIT 0
#define ERR_CLI_PARSE -1

typedef struct {
  struct arg_file *in;
  struct arg_lit *benchmark;
  struct arg_lit *snaps;
  struct arg_lit *snaps__internal;
  struct arg_lit *snaps__memory;
  struct arg_lit *snaps__operation;
  struct arg_lit *snaps__callstack;
} vm__cli_args_t;

typedef struct {
  vm__cli_args_t *vm;
  struct arg_lit *version;
  struct arg_lit *help;
  struct arg_end *end;
  void *table[CLI_ARGS];
  int errors;
  int status;
} vm__cli_t;

#endif
