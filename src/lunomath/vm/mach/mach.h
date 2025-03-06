#ifndef __MACH_H__
#define __MACH_H__

#define N_REGS 3

#include "../../common.h"
#include "../stack/stack.h"
#include "../../mgmt/mgmt.h"
#include "../bytecode/bytecode.h"

typedef struct {
  q_stack_t st;         // main stack
  u8_t      id;         // machine id
  value_t   r[N_REGS];  // register
  opcode_t  c_op;       // current op
} mach_t;

LUNOMATH_API static
mach_t  create_mach() {
  mach_t machine;
  machine.id  = q_rand_u8((int*)2112);
  machine.st  = create_q_stack();
  printf("+---------------------+\n");
  printf("| created machine %x! |\n", machine.id);
  printf("+---------------------+\n");
  return machine;
}

LUNOMATH_API static
void shutdown_mach(mach_t *machine) {
  clean_q_stack(&machine->st);
}

#endif //__MACH_H__