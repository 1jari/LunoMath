#include "./mach.h"

void exec_mach(mach_t *mach) {
  int pos = 0;
  while(pos < mach->p_sz) {
    u8_t c_op = mach->prog[pos];  
    switch(c_op){
    case OP_SPAWN:
      printf("spawn\n");
      break;
    default:
      printf("error");
      pos = mach->p_sz;  
      break;
    }
    pos++;
  }
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
