#include "./axis.h"

LUNOMATH_API
axis_t  create_axis(  angle_t a,
                      vec2f_t v) {
  axis_t axis;
  axis.a = a;
  axis.v = v;
  return axis;
}
