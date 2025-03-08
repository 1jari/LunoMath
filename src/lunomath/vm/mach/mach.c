#include "./mach.h"

void exec_mach(mach_t *mach) {
  int pos = 0;
  while(pos < mach->p_sz) {
    u8_t c_op = mach->prog[mach->p_sz];
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