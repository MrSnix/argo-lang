#include "../core/bytecode.h"

#include <stdlib.h>
#include <string.h>

vm__bc_t *vm__bc_create(vm__bc_version_t version, uint16_t routines_size,
                        vm__bc_routine_t *routines[]) {
  vm__bc_t *ptr = malloc(sizeof(vm__bc_t) +
                                     sizeof(vm__bc_routine_t *[routines_size]));
  ptr->version = version;
  ptr->routines_size = routines_size;
  memcpy(ptr->routines, routines, sizeof(vm__bc_routine_t *) * routines_size);
  ptr->main = routines[0];
  return ptr;
}

vm__bc_routine_t *vm__routine_create(uint16_t id, const char *name,
                                     uint32_t data_size, int32_t *data) {
  vm__bc_routine_t *ptr = malloc(sizeof(vm__bc_routine_t));
  ptr->id = id;
  ptr->ip = 0;
  ptr->name = name;
  ptr->data = malloc(sizeof(int32_t) * data_size);
  ptr->data_size = data_size;
  memcpy(ptr->data, data, sizeof(int32_t) * data_size);
  return ptr;
}

void vm__bc_free(vm__bc_t **bc) {
  for (int i = 0; i < (*bc)->routines_size; ++i) {
    vm__routine_free(&(*bc)->routines[i]);
  }
  free(*bc);
  *bc = NULL;
}

void vm__routine_free(vm__bc_routine_t **rtn) {
  free((*rtn)->data);
  (*rtn)->data = NULL;
  free(*rtn);
  *rtn = NULL;
}
