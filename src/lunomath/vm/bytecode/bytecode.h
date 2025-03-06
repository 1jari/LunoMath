#ifndef __BYTECODE_H__
#define __BYTECODE_H__

#include "../../mgmt/mgmt.h"
#include "../../common.h"

#define GLOBAL_FIELD 0

// Operation Modifiers
typedef enum {
  OPMOD_ANGLE,
  OPMOD_VEC2F,
  OPMOD_AXIS,
} mod_e;

typedef enum {
  OP_SPAWN      = 0b0000,
  OP_LINK       = 0b0001,
  OP_ATTACH     = 0b0010,
  OP_NOP        = 0b1111
} opcode_e;

/*
  +------+                      +----------------------+
  |       /=====> opcode        | SPAWN                |
  + 3====|                      +----------------------+
  |       \=====> type          | OPMOD_ANGLE          |
  +------+                      +----------------------+
  | 5     ===|                  |                      |
  +------+   |=> x              | from-deg(211.2 deg)  |
  | 4     ===|                  |                      |
  +------+                      +----------------------+
  | 1     ===|                  |                      |
  +------+   |======> Target    | 0x0000 (global)      |
  | 0     ===|                  |                      |
  +------+                      +----------------------+
*/

// Instruction structure
typedef struct {
  opcode_e  op;  // The opcode
  mod_e     t;   // The modifier type
  u32_t     x;   // Operand or register x
  u16_t     y;   // Operand or register y
} opcode_t;

#endif //__BYTECODE_H__
