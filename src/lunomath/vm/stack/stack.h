#ifndef __STACK_H__
#define __STACK_H__

#include "../bytecode/bytecode.h"

typedef u32_t value_t;

typedef struct {
  value_t *data;
  u16_t    size;
} q_stack_t;

LUNOMATH_API
q_stack_t  create_q_stack();
LUNOMATH_API
value_t     q_stack_pop(  q_stack_t *s);
LUNOMATH_API
u16_t       q_stack_push( value_t    x,
                          q_stack_t *s);
LUNOMATH_API
value_t     q_stack_base( q_stack_t *s);
LUNOMATH_API
value_t     q_stack_top(  q_stack_t *s);
LUNOMATH_API
void        clean_q_stack(q_stack_t *s);
#endif //__STACK_H__
