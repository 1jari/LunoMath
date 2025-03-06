#ifndef __VEC2_H__
#define __VEC2_H__

#include "../../../common.h"
#include "../../../mgmt/mgmt.h"

#define VEC2F_BITS  32

// (16:16):(16:16) format
typedef i64_t vec2f_t;  

LUNOMATH_API static
vec2f_t vec2f(fixed_t x, fixed_t y) {
  vec2f_t z = ((vec2f_t)x << VEC2F_BITS) | (y & 0xFFFFFFFF);
  return z;
}


LUNOMATH_API static inline
fixed_t vec2f_get_x(vec2f_t z) {
  return (fixed_t)((z >> VEC2F_BITS) & 0xFFFFFFFF);
}


LUNOMATH_API static inline
fixed_t vec2f_get_y(vec2f_t z) {
  return (fixed_t)(z & 0xFFFFFFFF);
}
LUNOMATH_API
vec2f_t vec2f_add(vec2f_t a, vec2f_t b);

LUNOMATH_API
vec2f_t vec2f_sub(vec2f_t a, vec2f_t b);

#endif 
