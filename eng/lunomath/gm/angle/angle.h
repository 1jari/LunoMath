#ifndef __ANGLE_H__
#define __ANGLE_H__

#include "../../common.h"
#include "../../mgmt/fixed/fixed.h"

// Not accurate, but is useful...
#define FIXED_PI  0x3243f

// Angle constants
#define BAM_MAX   0x1000
#define ANGLE_STEP  \
  (360.0 / (BAM_MAX + 1))

typedef unsigned angle_t;

LUNOMATH_API
fixed_t angle_to_deg(angle_t ang);

LUNOMATH_API
angle_t angle_from_deg(fixed_t deg);


#endif // FIXED_ANGLE_H
