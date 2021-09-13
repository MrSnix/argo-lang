// [HEAD] Definitions
#include "../core/options.h"
// [HEAD] Implementation
#include <stdlib.h>

vm__opts_t *vm__opts_create(vm__cli_args_t *args) {
  vm__opts_t *ptr = (vm__opts_t *)malloc(sizeof(vm__opts_t));

  ptr->in = NULL;
  ptr->snaps = vm__opts_snaps_create();
  ptr->dbg = vm__opts_dbg_create(0);

  if (args != NULL) {
    if (args->in->count > 0) {
      ptr->in = args->in->filename[0];
    }

    if (args->snaps->count > 0) {
      ptr->snaps->internal = true;
      ptr->snaps->memory = true;
      ptr->snaps->operation = true;
    }

    if (args->snaps__internal->count > 0) {
      ptr->snaps->internal = true;
    }

    if (args->snaps__memory->count > 0) {
      ptr->snaps->memory = true;
    }

    if (args->snaps__operation->count > 0) {
      ptr->snaps->operation = true;
    }
  }

  return ptr;
}

vm__opts_snaps_t *vm__opts_snaps_create() {
  vm__opts_snaps_t *ptr =
      (vm__opts_snaps_t *)malloc(sizeof(vm__opts_snaps_t));
  ptr->internal = false;
  ptr->memory = false;
  ptr->operation = false;
  return ptr;
}

void vm__opts_snaps_free(vm__opts_snaps_t **snaps) {
  free(*snaps);
  *snaps = NULL;
}

DebuggerOptionsVM *vm__opts_dbg_create(unsigned int size) {
  DebuggerOptionsVM *ptr = NULL;

  if (size) {
    DebuggerOptionsVM *ptr =
        (DebuggerOptionsVM *)malloc(sizeof(DebuggerOptionsVM));
    ptr->size = size;
    ptr->breakpoints = (unsigned int *)malloc(sizeof(unsigned int) * size);
  }

  return ptr;
}

void vm__opts_dbg_free(DebuggerOptionsVM **dbg) {
  if (*dbg != NULL) {
    free((*dbg)->breakpoints);
    (*dbg)->breakpoints = NULL;
    free(*dbg);
    *dbg = NULL;
  }
}

void vm__opts_free(vm__opts_t **opts) {
  vm__opts_dbg_free(&(*opts)->dbg);
  vm__opts_snaps_free(&(*opts)->snaps);
  free(*opts);
  *opts = NULL;
}
