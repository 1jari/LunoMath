#ifndef __ERROR_H__
#define __ERROR_H__
#include "../../common.h"

#define ERROR_OK (throw_error("", 0))

typedef struct {
  char* msg;
  int   code;
} error_t;

LUNOMATH_API static
error_t throw_error(char* msg, int code) {
  error_t err;
  err.msg   = msg;
  err.code  = code;
  return err;
}

#endif //__ERROR_H__