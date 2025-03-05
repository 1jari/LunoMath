#ifndef __ANGLE_COMMON_H__
#define __ANGLE_COMMON_H__

// Not accurate, but is useful...
#define FIXED_PI  0x3243f

// Angle constants
#define BAM_MAX   0x1000
#define ANGLE_STEP  \
  (360.0 / (BAM_MAX + 1))


typedef unsigned angle_t;

#endif //__ANGLE_COMMON_H__
