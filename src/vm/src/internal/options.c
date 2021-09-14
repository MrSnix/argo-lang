// [HEAD] Definitions
#include "../core/options.h"
// [HEAD] Implementation
#include <stdlib.h>

vm__opts_t *vm__opts_create(vm__cli_args_t *args) {
  vm__opts_t *ptr = malloc(sizeof(vm__opts_t));

  ptr->in = NULL;
  ptr->snaps = vm__opts_snaps_init();
  ptr->dbg = vm__opts_dbg_create(0);

  if (args != NULL) {
    if (args->in->count > 0) {
      ptr->in = args->in->filename[0];
    }

    if (args->snaps->count > 0) {
      ptr->snaps.internal = true;
      ptr->snaps.memory = true;
      ptr->snaps.operation = true;
    }

    if (args->snaps__internal->count > 0) {
      ptr->snaps.internal = true;
    }

    if (args->snaps__memory->count > 0) {
      ptr->snaps.memory = true;
    }

    if (args->snaps__operation->count > 0) {
      ptr->snaps.operation = true;
    }
  }

  return ptr;
}

vm__opts_snaps_t vm__opts_snaps_init() {
  vm__opts_snaps_t ptr;
  ptr.internal = false;
  ptr.memory = false;
  ptr.operation = false;
  return ptr;
}

void vm__opts_snaps_free(vm__opts_snaps_t **snaps) {
  free(*snaps);
  *snaps = NULL;
}

vm__opts_dbg_t *vm__opts_dbg_create(unsigned int size) {
  vm__opts_dbg_t *ptr = NULL;

  if (size) {
    vm__opts_dbg_t *ptr = malloc(sizeof(vm__opts_dbg_t));
    ptr->size = size;
    ptr->breakpoints = malloc(sizeof(unsigned int) * size);
  }

  return ptr;
}

void vm__opts_dbg_free(vm__opts_dbg_t **dbg) {
  if (*dbg != NULL) {
    free((*dbg)->breakpoints);
    (*dbg)->breakpoints = NULL;
    free(*dbg);
    *dbg = NULL;
  }
}

void vm__opts_free(vm__opts_t **opts) {
  vm__opts_dbg_free(&(*opts)->dbg);
  free(*opts);
  *opts = NULL;
}
