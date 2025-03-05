#ifndef __MGMT_TABLES_H__
#define __MGMT_TABLES_H__
#include "../stdint.h"
#include "../../common.h"

extern const
u8_t q_rnd_table[256];

extern
u8_t q_rnd_idx;

LUNOMATH_API
u8_t q_rand(int *seed);

#endif //__RND_H__
