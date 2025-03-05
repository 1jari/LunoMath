#ifndef __VM_COMMON_H__
#define __VM_COMMON_H__

#include "../common.h"
#include "./bytecode/bytecode.h"
#include "./stack/stack.h"

typedef struct {
  stack_t  prog; // YES!
  u32_t    r;
} vm_t;

#endif //__VM_COMMON_H__
