#ifndef __VEC3_H__
#define __VEC3_H__

#include "../../../common.h"
#include "../../../mgmt/mgmt.h"

typedef struct {
  fixed_t x;
  fixed_t y;
  fixed_t z;
} vec3f_t;

LUNOMATH_API static inline
vec3f_t vec3f(fixed_t x,
              fixed_t y,
              fixed_t z) {
  vec3f_t r;
  r.x = x;
  r.y = y;
  r.z = z;
  return r;
}
          
LUNOMATH_API
vec3f_t vec3f_add(vec3f_t a,
                  vec3f_t b);
LUNOMATH_API
vec3f_t vec3f_sub(vec3f_t a,
                  vec3f_t b);

#endif //__VEC3_H__
