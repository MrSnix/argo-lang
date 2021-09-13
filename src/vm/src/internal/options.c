// [HEAD] Definitions
#include "../core/options.h"
// [HEAD] Implementation
#include <stdlib.h>

OptionsVM *vm__opts_create(ArgsVM *args) {
  OptionsVM *ptr = (OptionsVM *)malloc(sizeof(OptionsVM));

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

SnapshotOptionsVM *vm__opts_snaps_create() {
  SnapshotOptionsVM *ptr =
      (SnapshotOptionsVM *)malloc(sizeof(SnapshotOptionsVM));
  ptr->internal = false;
  ptr->memory = false;
  ptr->operation = false;
  return ptr;
}

void vm__opts_snaps_free(SnapshotOptionsVM **snaps) {
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

void vm__opts_free(OptionsVM **opts) {
  vm__opts_dbg_free(&(*opts)->dbg);
  vm__opts_snaps_free(&(*opts)->snaps);
  free(*opts);
  *opts = NULL;
}
