#ifndef __FIXED_H__
#define __FIXED_H__

#include "../../common.h"

#include "../stdint.h"

// Specifications...
#define FR_BITS  16
#define FR_UNIT  (1 << FR_BITS)

typedef i32_t fixed_t;  // Assuming i32_t is equivalent to int32_t

/* +-----------------------+
   |       CONVERTERS      |
   +-----------------------+ */
#define F_TO_FX(f)      ((fixed_t)((f) * 65536.0f))
#define I_TO_FX(i)      ((fixed_t)((i) << FR_BITS))
#define FX_TO_F(x)      ((float)((x) / 65536.0f))
#define FX_TO_I(x)      ((int)((x) >> FR_BITS))

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
