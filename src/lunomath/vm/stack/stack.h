#ifndef __STACK_H__
#define __STACK_H__

#include "../bytecode/bytecode.h"

typedef struct {
  u32_t    *data;
  u16_t     size;
} q_stack_t;

LUNOMATH_API
q_stack_t  create_stack();
LUNOMATH_API
u32_t    stack_pop(    q_stack_t *s);
LUNOMATH_API
u16_t    stack_push(   u32_t    x,
                       q_stack_t *s);
LUNOMATH_API
u32_t    stack_base(   q_stack_t *s);
LUNOMATH_API
u32_t    stack_top(    q_stack_t *s);
LUNOMATH_API
void  clean_stack(  q_stack_t *s);
#endif //__STACK_H__
