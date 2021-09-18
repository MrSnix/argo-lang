#ifndef ARGO_VM__BYTECODE_H
#define ARGO_VM__BYTECODE_H

#include "../types/bytecode.h"
#include <stdio.h>

vm__bc_routine_t *vm__routine_read(FILE* ptr);
void vm__bc_read_table_size(FILE *ptr, uint16_t* version);
void vm__bc_read_version(FILE *ptr, vm__bc_version_t* version);
vm__bc_t *vm__bc_read(const char* in);

vm__bc_t *vm__bc_create(vm__bc_version_t version, uint16_t routines_size,
                        vm__bc_routine_t *routines[]);
void vm__bc_free(vm__bc_t **bc);

vm__bc_routine_t *vm__routine_create(uint16_t id, uint8_t name_size, char *name,
                                     uint32_t data_size, int32_t *data);
void vm__routine_free(vm__bc_routine_t **rtn);

#endif
