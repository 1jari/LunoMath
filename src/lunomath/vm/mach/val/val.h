#ifndef __VM_MACH_VAL_H__
#define __VM_MACH_VAL_H__

#include "../../../gm/gm.h"
#include "../../../common.h"
#include "../../../mgmt/mgmt.h"

/* * * * * * * * * *     +---------------+    * * * * * * * * * * 
 * * * * * * * * * *     |   Positions   |    * * * * * * * * * * 
 * * * * * * * * * *     +---------------+    * * * * * * * * * */

#define VAL_POS_PREFIX  0
#define VAL_POS_CONV    2
#define VAL_POS_DATA    4

/* * * * * * * * * *     +---------------+    * * * * * * * * * * 
 * * * * * * * * * *     |   Prefixes    |    * * * * * * * * * * 
 * * * * * * * * * *     +---------------+    * * * * * * * * * */

#define VAL_PREFIX_NUMBER       0b00
#define VAL_PREFIX_ANGLE        0b01
#define VAL_PREFIX_VEC2F        0b10
#define VAL_PREFIX_AXIS         0b11

/* * * * * * * * * *    +---------------+    * * * * * * * * * * 
 * * * * * * * * * *     |  Conventions  |    * * * * * * * * * * 
 * * * * * * * * * *     +---------------+    * * * * * * * * * */

                                      /////////////////////////////////////////////////////////////
                                      ///                 Literal Conventions                   ///
                                      /////////////////////////////////////////////////////////////
#define VAL_CONV_LITERAL_POS    0b00  // Current element has the following positive value.
#define VAL_CONV_LITERAL_NEG    0x01  // Current element has the following negative value.

                                      /////////////////////////////////////////////////////////////
                                      ///                 Call-ID Conventions                   ///
                                      /// Before anyone ask: Yes, this is a metallica reference ///
                                      /////////////////////////////////////////////////////////////
#define VAL_CONV_CALL_ID_MASTER 0b10  // The following object is owned by the current object.
#define VAL_CONV_CALL_ID_PUPPET 0b10  // The current object is owned by the following object.

typedef u32_t vm_val_t;

LUNOMATH_API static
vm_val_t  create_val(         u8_t    prefix,
                              u8_t    conv,
                              u32_t   data) {
  return  (((vm_val_t)prefix & 0b11)    << VAL_POS_PREFIX)      // 2 bits for prefix
    |     (((vm_val_t)conv & 0b10)      << VAL_POS_CONV)          // 2 bits for conv
    |     (((vm_val_t)data & 0xFFFFFFFF) << VAL_POS_DATA);   // 28 bits for data
}

LUNOMATH_API
vm_val_t  convert_angle_val(  angle_t ang);

#endif //__VM_MACH_VAL_H__