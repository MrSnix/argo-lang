#include "../core/stack.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static void vm__stack_create_data(vm__stack_t *stack) {
  // Allocate array of pointers
  stack->data = malloc(sizeof(int32_t *) * stack->size);
  // For each pointer allocate memory for an int32_t
  for (uint32_t i = 0; i < stack->size; ++i) {
    // Set to zero
    stack->data[i] = 0;
  }
}

vm__stack_t *vm__stack_create(int32_t current_size, int32_t max_size) {
  vm__stack_t *stack = malloc(sizeof(vm__stack_t));

  stack->size = current_size;
  stack->max = max_size;

  stack->counter = 0;
  stack->offset = -1;

  vm__stack_create_data(stack);

  return stack;
}

void vm__stack_free(vm__stack_t **stack) {
  free((*stack)->data);
  (*stack)->data = NULL;

  free(*stack);
  *stack = NULL;
}

void vm__stack_grow(vm__stack_t *stack) {
  stack->size += 8;
  int32_t *tmp = malloc(sizeof(int32_t *) * stack->size);

  for (uint32_t i = 0; i < stack->size - 8; i++) {
    tmp[i] = stack->data[i];
  }

  free(stack->data);
  stack->data = tmp;
}

void vm__stack_push(vm__stack_t *stack, int32_t value) {
  assert(stack->size < stack->max);

  if (stack->counter < stack->size) {
    stack->offset++;
    stack->data[stack->offset] = value;
    stack->counter++;
  } else {
    vm__stack_grow(stack);
    vm__stack_push(stack, value);
  }
}

int32_t vm__stack_pop(vm__stack_t *stack) {
  int32_t top = stack->data[stack->offset];

  assert(!vm__stack_empty(stack));

  stack->data[stack->offset] = 0;

  stack->offset--;
  stack->counter--;

  return top;
}

int32_t vm__stack_size(vm__stack_t *stack) { return stack->counter; }
int32_t vm__stack_empty(vm__stack_t *stack) { return stack->counter == 0; }
int32_t vm__stack_offset(vm__stack_t *stack) { return stack->offset; }
int32_t vm__stack_top(vm__stack_t *stack) { return stack->data[stack->offset]; }
int32_t vm__stack_peek(vm__stack_t *stack, int32_t offset) {
  return stack->data[offset];
}
