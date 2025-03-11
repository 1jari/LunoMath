#ifndef __WHANDLER_H__
#define __WHANDLER_H__

#include "../stdint.h"
#include "../../common.h"

LUNOMATH_API
void little_endian_encode(u32_t value, u8_t *output);
LUNOMATH_API
u32_t little_endian_decode( const u8_t *input);

#endif //__WHANDLER_H__