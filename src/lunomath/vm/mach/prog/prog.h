#ifndef __VM_PROG_H__
#define __VM_PROG_H__

#include "../../../common.h"
#include "../../../mgmt/mgmt.h"
#include "./bytecode/bytecode.h"

typedef struct {
                    /////////////////////
                    ///               ///
                    /// PROGRAM STUFF ///
                    ///               ///
                    /////////////////////
  u8_t     *prog;   //  Program data  (SHARP! DISTANCE!....)
  u16_t     p_sz;   //  Program Size
  opcode_t  c_op;   //  Current Op
} vm_prog_t;

LUNOMATH_API static
vm_prog_t init_vm_prog(u16_t size) {
  vm_prog_t prog;
  prog.p_sz  = size;
  prog.prog  = (u8_t*)malloc(prog.p_sz * sizeof(u8_t));
  return prog;
}

LUNOMATH_API static
void clean_vm_prog(vm_prog_t *vmprog) {
  if(vmprog->prog) {
    free(vmprog->prog);
  }
}

#endif //__VM_PROGRAM