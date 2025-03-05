#ifndef __VEC2_H__
#define __VEC2_H__

#include "../../../common.h"
#include "../../../mgmt/mgmt.h"

typedef struct {
  fixed_t x;
  fixed_t y;
} vec2f_t;

LUNOMATH_API static inline
vec2f_t vec2f(fixed_t x,
              fixed_t y) {
  vec2f_t z;
  z.x = x;
  z.y = y;
  return z;
}
          
LUNOMATH_API
vec2f_t vec2f_add(vec2f_t a,
                  vec2f_t b);
LUNOMATH_API
vec2f_t vec2f_sub(vec2f_t a,
                  vec2f_t b);

#endif //__VEC2_H__
