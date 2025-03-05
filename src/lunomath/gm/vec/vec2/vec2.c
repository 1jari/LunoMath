#include "./vec2.h"

LUNOMATH_API
vec2f_t vec2f_add(vec2f_t a,
                  vec2f_t b) {
  return vec2f(a.x + b.x, a.y + b.y);
}
LUNOMATH_API
vec2f_t vec2f_sub(vec2f_t a,
                  vec2f_t b) {
  return vec2f(a.x - b.x, a.y - b.y);
}