#ifndef __AXIS_H__
#define __AXIS_H__

#include "../vec/vec.h"
#include "../../common.h"
#include "../../mgmt/mgmt.h"
#include "../angle/angle.h"

typedef struct {
  u16_t    i;
  angle_t  a;
  vec2f_t  v;
} axis_t;

LUNOMATH_API
axis_t  create_axis(  angle_t a,
                      vec2f_t v);

#endif //__AXIS_H__
