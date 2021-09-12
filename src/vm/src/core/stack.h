#ifndef ARGO_VM__STACK_H
#define ARGO_VM__STACK_H

#include "../types/stack.h"

Stack *vm__stack_create(int32_t current_size, int32_t max_size);
void vm__stack_free(Stack **stack);

void vm__stack_push(Stack *stack, int32_t object);
int32_t vm__stack_pop(Stack *stack);
int32_t vm__stack_size(Stack *stack);
int32_t vm__stack_empty(Stack *stack);
int32_t vm__stack_peek(Stack *stack, int32_t offset);
int32_t vm__stack_top(Stack *stack);

#endif
