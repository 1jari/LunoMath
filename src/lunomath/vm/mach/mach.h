#ifndef __MACH_H__
#define __MACH_H__

#define N_REGS 3

#include "../../common.h"
#include "../stack/stack.h"
#include "../../mgmt/mgmt.h"
#include "../bytecode/bytecode.h"

typedef struct {
  
  struct {
    u8_t   *prog;
    u16_t   p_sz;
    //u16_t   pos;
  };

  q_stack_t st;         // main stack
  u8_t      id;         // machine id
  value_t   r[N_REGS];  // register
} mach_t;

LUNOMATH_API static
mach_t  create_mach(u8_t *prog, u16_t size) {

  if((!prog) || (size == 0)) {
    printf("Fatal error! program is null!\n");
    exit(0);
  }
  
  mach_t machine;
  machine.id  = q_rand_u8((int*)2112);
  machine.st  = create_q_stack();

  machine.p_sz  = size;
  machine.prog  = (u8_t*)malloc(machine.p_sz * sizeof(u8_t));
  //machine.pos   = 0;

  for(int i = 0; i < N_REGS; i++) {
    machine.r[i] = 0;
  }

  printf("+---------------------+\n");
  printf("| created machine %x! |\n", machine.id);
  printf("+---------------------+\n");
  return machine;
}

LUNOMATH_API
void exec_mach(mach_t *mach);

LUNOMATH_API static
void shutdown_mach(mach_t *machine) {
  clean_q_stack(&machine->st);
}

#endif //__MACH_H__