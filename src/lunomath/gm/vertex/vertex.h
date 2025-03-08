#ifndef __VERTEX_H__
#define __VERTEX_H__

// This is basically high level assembly

#include "../angle/angle.h"
#include "../../mgmt/mgmt.h"

#define VERTEX_DIST_POS 00
#define VERTEX_ANG_POS  32
#define VERTEX_H_POS    56

typedef u64_t vertex_t;

LUNOMATH_API static
vertex_t create_vertex(u8_t h, 
                       angle_t a, 
                       fixed_t d) {
  vertex_t z = 0;
  z |= ((vertex_t)d << VERTEX_DIST_POS);
  z |= ((vertex_t)a << VERTEX_ANG_POS);
  z |= ((vertex_t)h << VERTEX_H_POS);
  return z;
}

LUNOMATH_API static inline
fixed_t vertex_get_d(vertex_t v) {
  return (fixed_t)((v >> VERTEX_DIST_POS) & 0xFFFFFFFF);
}

LUNOMATH_API static inline
angle_t vertex_get_a(vec2f_t v) {
  return (angle_t)((v >> VERTEX_ANG_POS) & 0xFFFF);
}

LUNOMATH_API static inline
u8_t    vertex_get_h(vec2f_t v) {
  return (u8_t)((v >> VERTEX_H_POS) & 0xFF);
}

#endif // __VERTEX_H__
