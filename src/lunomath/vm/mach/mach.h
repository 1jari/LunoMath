#ifndef __MACH_H__
#define __MACH_H__

#define N_REGS 3

#include "./obj/obj.h"
#include "./prog/prog.h"
#include "../../common.h"
#include "../../mgmt/mgmt.h"
#include "./vtable/vtable.h"

typedef struct {

  struct {
                        /////////////////////
                        ///               ///
                        /// OBJECT TABLE  ///
                        ///               ///
                        /////////////////////
    obj_t  *tab;        //  Table data
    u16_t   t_sz;       //  Table size
  };

  vm_prog_t prog;

  error_t   c_err;      // current error/msg
  vtable_t  st;         // main stack
  u8_t      id;         // mach id
  vm_val_t  r[N_REGS];  // register
} mach_t;

LUNOMATH_API static
mach_t  create_mach(u8_t *prog, u16_t size) {

  mach_t mach;

  // Checking the input is valid
  if((!prog) || (size == 0 || NULL)) {
    mach.c_err = ERROR_FATAL("Fatal error! program is null!");
  }
  
  // Basic machine setup
  mach.id  = q_rand_u8((int*)2112); // Setting up machine id in a random ID
  mach.st  = create_vtable();     

  // Program input
  mach.prog = init_vm_prog(size);

  // Output that the procedure was successful
  mach.c_err = ERROR_OK("| created mach |");

  return mach;
}

LUNOMATH_API
void exec_mach(mach_t *mach);

LUNOMATH_API
char* catch_mach_err(mach_t *mach);

LUNOMATH_API static
void shutdown_mach(mach_t *mach) {
  if(mach->tab) {
    free(mach->tab);
  }
  clean_vtable(&mach->st);
  clean_vm_prog(&mach->prog);
}

#endif //__MACH_H__