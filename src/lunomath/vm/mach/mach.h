#ifndef __MACH_H__
#define __MACH_H__

#define N_REGS 3

#include "../../common.h"
#include "../stack/stack.h"
#include "../../mgmt/mgmt.h"
#include "../bytecode/bytecode.h"

typedef struct {
  
  struct {
    u8_t     *prog;
    u16_t     p_sz;
    opcode_t  c_op;     // current op
  };
  error_t     c_err;      // current error
  q_stack_t   st;         // main stack
  u8_t        id;         // mach id
  value_t     r[N_REGS];  // register
} mach_t;

LUNOMATH_API static
mach_t  create_mach(u8_t *prog, u16_t size) {

  mach_t mach;
  if((!prog) || (size == 0 || NULL)) {
    mach.c_err = ERROR_FATAL("Fatal error! program is null!");
  }
  
  mach.id  = q_rand_u8((int*)2112);
  mach.st  = create_q_stack();

  mach.p_sz  = size;
  mach.prog  = (u8_t*)malloc(mach.p_sz * sizeof(u8_t));
  //mach.pos   = 0;

  for(int i = 0; i < N_REGS; i++) {
    mach.r[i] = 0;
  }

  mach.c_err = ERROR_OK("| created mach |");
  return mach;
}

LUNOMATH_API
void exec_mach(mach_t *mach);

LUNOMATH_API
char* catch_mach_err(mach_t *mach);

LUNOMATH_API static
void shutdown_mach(mach_t *mach) {
  clean_q_stack(&mach->st);
}

#endif //__MACH_H__