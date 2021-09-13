#ifndef ARGO_VM__OPTS_H
#define ARGO_VM__OPTS_H

#include "../types/cli.h"
#include "../types/options.h"

vm__opts_t *vm__opts_create(vm__cli_args_t *args);
void vm__opts_free(vm__opts_t **opts);

vm__opts_dbg_t *vm__opts_dbg_create(unsigned int size);
void vm__opts_dbg_free(vm__opts_dbg_t **dbg);

vm__opts_snaps_t *vm__opts_snaps_create();
void vm__opts_snaps_free(vm__opts_snaps_t **snaps);

#endif
