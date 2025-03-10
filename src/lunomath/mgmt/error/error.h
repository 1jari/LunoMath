#ifndef __ERROR_H__
#define __ERROR_H__
#include "../../common.h"

// Updated macros to avoid dereferencing error_t
#define ERROR_OK(msg)     (throw_error(msg, ERR_G_EARTH))
#define ERROR_FATAL(msg)  (throw_error(msg, ERR_G_JUPITER))
#define ERROR_NIL()       (throw_error("", ERR_G_SPACE))

typedef enum {
  ERR_G_SPACE   = 0,    // ignore
  ERR_G_EARTH   = 98,   // normal, just message
  ERR_G_MOON    = 16,   // warning
  ERR_G_JUPITER = 248,  // fatal error
} error_g_e;

typedef struct {
  const char* msg;
  error_g_e   code;
} error_t;

LUNOMATH_API static
error_t throw_error(const char* msg, error_g_e code) {
  error_t err;
  err.msg   = msg;
  err.code  = code;
  return err;
}
#endif //__ERROR_H__