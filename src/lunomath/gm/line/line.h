#ifndef __LINES_H__
#define __LINES_H__

#include "../vec/vec.h"

typedef struct {
  vec2f_t   a;
  vec2f_t   b;
} line_t;

LUNOMATH_API static
line_t  create_line(vec2f_t   a,
                    vec2f_t   b) {
  line_t line;
  line.a = a;
  line.b = b;
}

#endif //__LINES_H__