#ifndef __FIXED_H__
#define __FIXED_H__

#include "../../common.h"
#include "./fixed_common.h"


/* +-----------------------+
   |       OPERATIONS      |
   +-----------------------+ */
LUNOMATH_API
fixed_t fixed_mul(   fixed_t a,
                     fixed_t b);
LUNOMATH_API
fixed_t fixed_div(   fixed_t a,
                     fixed_t b);

LUNOMATH_API
fixed_t fixed_div2(  fixed_t a,
                     fixed_t b);

#endif //__FIXED_H__
