#include "./vec2.h"

LUNOMATH_API
vec2f_t vec2f_add(vec2f_t a,
                  vec2f_t b) {
  return vec2f( get_vec2f_x(a) + get_vec2f_x(b),
                get_vec2f_y(a) + get_vec2f_y(b));
}
LUNOMATH_API
vec2f_t vec2f_sub(vec2f_t a,
                  vec2f_t b) {
  return vec2f( get_vec2f_x(b) + get_vec2f_x(b),
                get_vec2f_y(b) + get_vec2f_y(b));
}