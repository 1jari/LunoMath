/* Mathematical transforms */
#ifndef __TRF_H__
#define __TRF_H__

#include "../tables/tables.h"
#include "../../mgmt/mgmt.h"
#include "../angle/angle.h"
#include "../vec/vec.h"

LUNOMATH_API static
vec2f_t apply_angle_vec2f(angle_t a, vec2f_t v) {
  return vec2f( fixed_mul(vec2f_get_x(v), cos_table[a]),
                fixed_mul(vec2f_get_y(v), sin_table[a])); 
}
#endif //__TRF_H__
