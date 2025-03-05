#ifndef __GM_TABLES_H__
#define __GM_TABLES_H__

#include "../angle/angle.h"

#define FINEANGLES           4095

extern const
fixed_t   sin_table[FINEANGLES];
static const
fixed_t*  cos_table = &sin_table[FINEANGLES / 4];

#endif // __GM_TABLES_H__
