#include "./angle.h"

LUNOMATH_API
fixed_t angle_to_deg(angle_t ang) {
  return F_TO_FX(ang * ANGLE_STEP);
}

LUNOMATH_API
angle_t angle_from_deg(fixed_t deg) {
  if (FX_TO_I(deg) < 0) deg = 0;
  if (FX_TO_I(deg) > 360) deg = I_TO_FX(360);
    
  return (angle_t)(FX_TO_F(deg) / ANGLE_STEP);
}
