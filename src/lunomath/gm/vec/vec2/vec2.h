#ifndef __VEC2_H__
#define __VEC2_H__

#include "../../../common.h"
#include "../../../mgmt/mgmt.h"

typedef struct {
  int     x;
  int     y;
} vec2i_t;

typedef struct {
  fixed_t x;
  fixed_t y;
} vec2f_t;

LUNOMATH_API
vec2f_t  vec2f(  fixed_t x,
                 fixed_t y);
LUNOMATH_API
vec2i_t  vec2i(  int     x,
                 int     y);

#endif //__VEC2_H__
