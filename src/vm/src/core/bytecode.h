#ifndef ARGO_VM__BYTECODE_H
#define ARGO_VM__BYTECODE_H

#include "../types/bytecode.h"

vm__bc_t *vm__bc_create(vm__bc_version_t version, uint16_t routines_size, vm__bc_routine_t *routines[]);
void vm__bc_free(vm__bc_t **bc);

vm__bc_routine_t *vm__routine_create(uint16_t id, const char *name, uint32_t data_size, int32_t *data);
void vm__routine_free(vm__bc_routine_t **rtn);

#endif
