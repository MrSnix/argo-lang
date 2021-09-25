#ifndef ARGO_VM__OPTS_H
#define ARGO_VM__OPTS_H

#include "../types/cli.h"
#include "../types/options.h"

vm__opts_t *vm__opts_create(vm__cli_args_t *args);
vm__opts_dbg_t *vm__opts_dbg_create(unsigned int size);
vm__opts_snaps_t vm__opts_snaps_init();

void vm__opts_free(vm__opts_t **opts);
void vm__opts_dbg_free(vm__opts_dbg_t **dbg);

#endif
