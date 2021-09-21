#ifndef ARGO_VM__STACK_H
#define ARGO_VM__STACK_H

#include "../types/stack.h"

vm__stack_t *vm__stack_create(int32_t current_size, int32_t max_size);
void vm__stack_free(vm__stack_t **stack);

void vm__stack_push(vm__stack_t *stack, int32_t object);
int32_t vm__stack_pop(vm__stack_t *stack);
int32_t vm__stack_offset(vm__stack_t *stack);
int32_t vm__stack_size(vm__stack_t *stack);
int32_t vm__stack_empty(vm__stack_t *stack);
int32_t vm__stack_peek(vm__stack_t *stack, int32_t offset);
int32_t vm__stack_top(vm__stack_t *stack);

#endif
