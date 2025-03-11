#ifndef __BYTECODE_H__
#define __BYTECODE_H__

#include "../../mgmt/mgmt.h"
#include "../../common.h"

#define GLOBAL_FIELD 0

// Operation Modifiers
typedef enum {
  OPMOD_ANGLE   = 0b0000,   // 16-bits
  OPMOD_VEC2F   = 0b0001,   // 64-bits
  OPMOD_AXIS    = 0b0010,   // 64+16 bits
  OPMOD_ID      = 0b0011,   // 16-bits
} mod_e;

typedef enum {
  OP_NOP      = 0b0000,
  OP_SPAWN    = 0b0001,  // create an instance for an parent object
  OP_LINK     = 0b0010,  // link a value to another object(s)
  OP_ATTACH   = 0b0011,  // link an object to another object(s)
  OP_CALL_ID  = 0b0100,  // Set the current object
  OP_BREAK    = 0b1111,
} opcode_e;

typedef struct {
  opcode_e  op;
  mod_e     mod;
  u16_t     value;
  u8_t      target;
} opcode_t;

// example: SPAWN OPMOD_ANGLE 4000 2112

LUNOMATH_API static
u8_t opcode_prefix(opcode_e op, mod_e mod) {
  u8_t prefix =
    ((u8_t)op << 4) | (((u8_t)mod) & 0xF);
  return prefix;
}

#endif //__BYTECODE_H__
