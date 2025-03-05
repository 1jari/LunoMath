#include "./stack.h"
#include <stdio.h>
#include <stdlib.h>

LUNOMATH_API
q_stack_t create_stack() {
  q_stack_t stack;

  // Allocate some memory
  stack.data = (u32_t*)malloc(sizeof(u32_t));

  stack.size = 0;

  return stack;
}

LUNOMATH_API
u32_t stack_pop(q_stack_t *s) {
  if (s->size == 0) {
    // Handle stack underflow
    printf("Error: Stack underflow\n");
    return 0;  // Or handle an error as appropriate
  }

  u32_t top_value = s->data[s->size - 1];  // Get the top value
  s->size--;  // Decrease size
  
  // Optional: Reallocate memory to shrink stack size
  s->data = (u32_t*)realloc(s->data, s->size * sizeof(u32_t));

  return top_value;
}

LUNOMATH_API
u16_t stack_push(u32_t x, q_stack_t *s) {
  // Reallocate memory for the stack, increase the size
  s->data = (u32_t*)realloc(s->data, (s->size + 1) * sizeof(u32_t));

  s->data[s->size] = x;  // Push the new value
  s->size++;  // Increase the size

  printf("Pushed %d\n", stack_top(s));

  return s->size;
}

LUNOMATH_API
u32_t stack_base(q_stack_t *s) {
  if (s->size == 0) {
    printf("Error: Stack is empty\n");
    return 0;  // Or handle an error as appropriate
  }

  return s->data[0];  // Return the base (bottom) element of the stack
}

LUNOMATH_API
u32_t stack_top(q_stack_t *s) {
  if (s->size == 0) {
    printf("Error: Stack is empty\n");
    return 0;  // Or handle an error as appropriate
  }

  return s->data[s->size - 1];  // Return the top element of the stack
}

LUNOMATH_API
void clean_stack(q_stack_t *s) {
  if (s->data) {
    free(s->data);  // Free allocated memory
    s->data = NULL; // Prevent dangling pointer
  }
  s->size = 0; // Reset stack size
}
