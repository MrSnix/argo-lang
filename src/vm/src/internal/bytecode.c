#include "../core/bytecode.h"

#include <stdlib.h>
#include <string.h>

vm__bc_routine_t *vm__routine_read(FILE *ptr) {
  uint16_t id = 0;
  uint8_t name_size = 0;
  char *name = NULL;
  uint32_t data_size = 0;
  int32_t *data = NULL;

  fread(&id, sizeof(uint16_t), 1, ptr);
  fread(&name_size, sizeof(uint8_t), 1, ptr);
  name = malloc(name_size + 1);
  fread(name, sizeof(uint8_t) * name_size, 1, ptr);
  name[name_size] = '\0';
  fread(&data_size, sizeof(uint32_t), 1, ptr);
  data = malloc(sizeof(int32_t) * data_size);
  fread(data, sizeof(int32_t) * data_size, 1, ptr);

  return vm__routine_create(id, name_size, name, data_size, data);
}

void vm__bc_read_table_size(FILE *ptr, uint16_t *version) {
  fread(version, sizeof(uint16_t), 1, ptr);
}

void vm__bc_read_version(FILE *ptr, vm__bc_version_t *version) {
  // Read major version
  fread(&version->major, sizeof(uint16_t), 1, ptr);
  // Read minor version
  fread(&version->minor, sizeof(uint16_t), 1, ptr);
}

vm__bc_t *vm__bc_read(const char *in) {
  // Working vars
  FILE *fp;
  uint16_t table_size;
  vm__bc_routine_t **table;
  vm__bc_version_t version = {.major = 0, .minor = 0};
  vm__bc_t *bc = NULL;

  // Open file stream ((r)ead (b)inary)
  fp = fopen(in, "rb");
  // Check it's really open
  if (fp == NULL) {
    printf("Cannot open the file.");
    exit(1);
  }
  // Skip signature data for now
  fseek(fp, 8, SEEK_CUR);

  vm__bc_read_version(fp, &version);
  vm__bc_read_table_size(fp, &table_size);

  table = malloc(sizeof(vm__bc_routine_t *) * table_size);

  for (int i = 0; i < table_size; ++i) table[i] = vm__routine_read(fp);
  bc = vm__bc_create(version, table_size, table);

  free(table);

  return bc;
}

vm__bc_t *vm__bc_create(vm__bc_version_t version, uint16_t routines_size,
                        vm__bc_routine_t *routines[]) {
  vm__bc_t *ptr =
      malloc(sizeof(vm__bc_t) + sizeof(vm__bc_routine_t *[routines_size]));
  ptr->version = version;
  ptr->routines_size = routines_size;
  memcpy(ptr->routines, routines, sizeof(vm__bc_routine_t *) * routines_size);
  ptr->main = routines[0];
  return ptr;
}

vm__bc_routine_t *vm__routine_create(uint16_t id, uint8_t name_size, char *name,
                                     uint32_t data_size, int32_t *data) {
  vm__bc_routine_t *ptr = malloc(sizeof(vm__bc_routine_t));
  ptr->id = id;
  ptr->ip = 0;
  ptr->name_size = name_size;
  ptr->name = name;
  ptr->data = data;
  ptr->data_size = data_size;
  memcpy(ptr->data, data, sizeof(int32_t) * data_size);
  ptr->caller = 0;
  return ptr;
}

void vm__bc_free(vm__bc_t **bc) {
  for (int i = 0; i < (*bc)->routines_size; ++i) {
    vm__routine_free(&(*bc)->routines[i]);
    (*bc)->routines[i] = NULL;
  }
  free(*bc);
  *bc = NULL;
}

void vm__routine_free(vm__bc_routine_t **rtn) {
  free((*rtn)->name);
  (*rtn)->name = NULL;
  free((*rtn)->data);
  (*rtn)->data = NULL;
  free(*rtn);
  *rtn = NULL;
}
