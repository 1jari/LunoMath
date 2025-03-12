#ifndef __STACK_H__
#define __STACK_H__

#include "../val/val.h"
#include "../../../mgmt/mgmt.h"

typedef struct {
  vm_val_t *data;
  u16_t    size;
} vtable_t;

LUNOMATH_API
vtable_t  create_vtable();
LUNOMATH_API
vm_val_t     vtable_pop(  vtable_t *s);
LUNOMATH_API
u16_t        vtable_push( vm_val_t    x,
                          vtable_t *s);
LUNOMATH_API
vm_val_t     vtable_base( vtable_t *s);
LUNOMATH_API
vm_val_t     vtable_top(  vtable_t *s);
LUNOMATH_API
void        clean_vtable(vtable_t *s);

#endif //__STACK_H__
