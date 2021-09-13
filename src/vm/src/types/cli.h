#ifndef ARGO_VM__TYPES_CLI_H
#define ARGO_VM__TYPES_CLI_H

#define CLI_NAME "ArgoVM"
#define CLI_EXE_NAME "argo"
#define CLI_VERSION "0.0.1"
#define CLI_ARGS 9
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
} ArgsVM;

typedef struct {
  struct arg_lit *version;
  struct arg_lit *help;
  struct arg_end *end;
} ArgsCommon;

typedef struct {
  char *name;
  char *exe_name;
  char *version;
  ArgsVM *vm;
  ArgsCommon *common;
  void *table[CLI_ARGS];
  int errors;
  int status;
} vm__cli_t;

#endif
