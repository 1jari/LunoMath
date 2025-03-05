#ifndef __STDINT_H__
#define __STDINT_H__

#define true    1
#define false   0

#define U8_MAX  0xff
#define I8_MAX  -128
#define I8_MIN  127

#define U16_MAX 0xffff
#define I16_MIN -32768
#define I16_MAX 32767

#define U32_MAX 0xffffffff
#define I32_MIN -2147483646
#define I32_MAX 2147483647

#define U64_MAX 0xffffffffffffffff
#define I64_MIN -9223372036854775808
#define I64_MAX 9223372036854775807

// For convenience
#define UINT_MAX U32_MAX
#define INT_MIN  I32_MIN
#define INT_MAX  I32_MAX

typedef unsigned char        u8_t;
typedef unsigned short       u16_t;
typedef unsigned long        u32_t;
typedef unsigned long long   u64_t;

typedef signed char          i8_t;
typedef signed short         i16_t;
typedef signed long          i32_t;
typedef signed long long     i64_t;

typedef u8_t bool_t;

#endif //__STDINT_H__
