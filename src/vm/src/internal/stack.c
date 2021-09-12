#include "../core/stack.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static void vm__stack_create_data(Stack *stack)
{
  // Allocate array of pointers
  stack->data = (int32_t *)malloc(sizeof(int32_t *) * stack->current);
  // For each pointer allocate memory for an int32_t
  for (int i = 0; i < stack->current; ++i)
  {
    // Set to zero
    stack->data[i] = 0;
  }
}

Stack *vm__stack_create(int32_t current_size, int32_t max_size)
{

  Stack *stack = (Stack *)malloc(sizeof(Stack));
  
  stack->current = current_size;
  stack->max = max_size;

  stack->counter = 0;
  stack->offset = -1;

  vm__stack_create_data(stack);

  return stack;
}

void vm__stack_free(Stack **stack)
{
  free((*stack)->data);
  (*stack)->data = NULL;

  free(*stack);
  *stack = NULL;
}

static void vm__stack_grow(Stack *stack)
{
  stack->current += 8;
  int32_t *tmp = (int32_t *)malloc(sizeof(int32_t *) * stack->current);

  for (int32_t i = 0; i < stack->current - 8; i++)
  {
    tmp[i] = stack->data[i];
  }

  free(stack->data);
  stack->data = tmp;
}

void vm__stack_push(Stack *stack, int32_t value)
{
  assert(stack->current < stack->max);

  if (stack->counter < stack->current)
  {
    stack->offset++;
    stack->data[stack->offset] = value;
    stack->counter++;
  }
  else
  {
    vm__stack_grow(stack);
    vm__stack_push(stack, value);
  }
}

int32_t vm__stack_pop(Stack *stack)
{

  int32_t top = stack->data[stack->offset];

  assert(!vm__stack_empty(stack));

  stack->data[stack->offset] = 0;

  stack->offset--;
  stack->counter--;

  return top;
}

int32_t vm__stack_size(Stack *stack) { return stack->counter; }
int32_t vm__stack_empty(Stack *stack) { return stack->counter == 0; }
int32_t vm__stack_top(Stack *stack) { return stack->data[stack->offset]; }
int32_t vm__stack_peek(Stack *stack, int32_t offset) { return stack->data[offset]; }
