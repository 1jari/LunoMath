#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdio.h>
#include <stdlib.h>

#ifndef LUNOMATH_SHARED
#define LUNOMATH_API
#else
#ifndef LUNOMATH_EXPORT
#else
#endif //LUNOMATH_EXPORT
#endif //LUNOMATH_SHARED

#endif //__COMMON_H__
