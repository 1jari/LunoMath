#include "./vec3.h"

LUNOMATH_API
vec3f_t vec3f_add(vec3f_t a,
                  vec3f_t b) {
  return vec3f(a.x + b.x, a.y + b.y, a.z + a.z);
}
LUNOMATH_API
vec3f_t vec3f_sub(vec3f_t a,
                  vec3f_t b) {
  return vec3f(a.x - b.x, a.y - b.y, a.z - a.z);
}