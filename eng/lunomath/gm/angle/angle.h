#ifndef __ANGLE_H__
#define __ANGLE_H__

#include "../../common.h"
#include "./angle_common.h"
#include "../../mgmt/fixed/fixed_common.h"

LUNOMATH_API
fixed_t angle_to_deg(angle_t ang);

LUNOMATH_API
angle_t angle_from_deg(fixed_t deg);


#endif // FIXED_ANGLE_H
