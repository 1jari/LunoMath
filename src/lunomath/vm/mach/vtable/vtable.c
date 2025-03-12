#include "./vtable.h"

LUNOMATH_API
vtable_t create_vtable() {
  vtable_t stack;

  // Allocate some memory
  stack.data = (vm_val_t*)malloc(sizeof(vm_val_t));

  stack.size = 0;

  return stack;
}

LUNOMATH_API
vm_val_t vtable_pop(vtable_t *s) {
  if (s->size == 0) {
    // Handle stack underflow
    printf("Error: Stack underflow\n");
    return 0;  // Or handle an error as appropriate
  }

  vm_val_t top_value = s->data[s->size - 1];  // Get the top value
  s->size--;  // Decrease size
  
  // Optional: Reallocate memory to shrink stack size
  s->data = (vm_val_t*)realloc(s->data, s->size * sizeof(vm_val_t));

  return top_value;
}

LUNOMATH_API
u16_t vtable_push(vm_val_t x, vtable_t *s) {
  // Reallocate memory for the stack, increase the size
  s->data = (vm_val_t*)realloc(s->data, (s->size + 1) * sizeof(vm_val_t));

  s->data[s->size] = x;  // Push the new value
  s->size++;  // Increase the size

  printf("Pushed %d\n", vtable_top(s));

  return s->size;
}

LUNOMATH_API
vm_val_t vtable_base(vtable_t *s) {
  if (s->size == 0) {
    printf("Error: Stack is empty\n");
    return 0;  // Or handle an error as appropriate
  }

  return s->data[0];  // Return the base (bottom) element of the stack
}

LUNOMATH_API
vm_val_t vtable_top(vtable_t *s) {
  if (s->size == 0) {
    printf("Error: Stack is empty\n");
    return 0;  // Or handle an error as appropriate
  }

  return s->data[s->size - 1];  // Return the top element of the stack
}

LUNOMATH_API
void clean_vtable(vtable_t *s) {
  if (s->data) {
    free(s->data);  // Free allocated memory
    s->data = NULL; // Prevent dangling pointer
  }
  s->size = 0; // Reset stack size
}
