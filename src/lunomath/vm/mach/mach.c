#include "./mach.h"

void exec_mach(mach_t *mach) {
  // TODO
}

// This is pretty bad written...
LUNOMATH_API
char* catch_mach_err(mach_t *mach) {
  
  if(mach->c_err.code != ERR_G_SPACE) {
    char* msg = mach->c_err.msg;
    mach->c_err = ERROR_NIL();
    return msg;
  }
  return NULL;
}
