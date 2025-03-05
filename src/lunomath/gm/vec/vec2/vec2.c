#include "./vec2.h"

LUNOMATH_API
vec2f_t  vec2f(  fixed_t x,
                 fixed_t y) {
  vec2f_t z;
  z.x = x;
  z.y = y;
  return z;
}

LUNOMATH_API
vec2i_t vec2i( int x,
               int y) {
  vec2i_t z;
  z.x = x;
  z.y = y;
  return z;
}
