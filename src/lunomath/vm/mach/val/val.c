#include "./val.h"

LUNOMATH_API
vm_val_t  convert_angle_val(  angle_t ang) {
  return create_val(  VAL_PREFIX_ANGLE,
                      VAL_CONV_LITERAL_POS,
                      (u32_t) ang);
}