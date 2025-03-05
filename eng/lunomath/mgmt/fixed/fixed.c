#include "./fixed.h"

LUNOMATH_API
fixed_t   fixed_mul( fixed_t a,
                     fixed_t b) {
  return (fixed_t)((a) * (b) / (1 << FR_BITS));
}

LUNOMATH_API
fixed_t fixed_div( fixed_t a,
                   fixed_t b) {
  if ( (abs(a)>>14) >= abs(b))
    return (a^b)<0 ? INT_MIN : INT_MAX;
  return fixed_div2(a,b);
}

LUNOMATH_API
fixed_t fixed_div2(fixed_t a,
                   fixed_t b) {
#if 0
  i64_t c;
  c = ((i64_t)a<<16) / ((i64_t)b);
  return (fixed_t) c;
#endif

  double c = ((double)a) / ((double)b);

  if (c >= I32_MAX || c < I32_MIN)
    fprintf(stderr, "FixedDiv: divide by zero");
  return (fixed_t) c;
}
