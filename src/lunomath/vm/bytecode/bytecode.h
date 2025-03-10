#ifndef __BYTECODE_H__
#define __BYTECODE_H__

#include "../../mgmt/mgmt.h"
#include "../../common.h"

#define GLOBAL_FIELD 0

// Operation Modifiers
typedef enum {
  OPMOD_ANGLE,    // 16-bits
  OPMOD_CALL_ID,  // 16-bits
  OPMOD_VEC2F,    // 64-bits
  OPMOD_AXIS,     // 
  OPMOD_ID,       // 16 bits
} mod_e;

typedef enum {
  OP_NOP      = 0b0000,
  OP_SPAWN    = 0b0001,  // create an instance for an parent object
  OP_LINK     = 0b0010,  // link a value to another object(s)
  OP_ATTACH   = 0b0011,  // link an object to another object(s)
  OP_CALL_ID  = 0b0100,  // Set the current object
  OP_BREAK    = 0b1111,
} opcode_e;

/*
  example:
  +------+                      +----------------------+
  |      |  /=====> opcode      | SPAWN                |
  + 3======|                    +----------------------+
  |      |  \=====> op modifier | OPMOD_ANGLE          |
  +------+                      +----------------------+
  | 2    |===\                  |                      |
  +------+   |====> value       | from-deg(211.2 deg)  |
  | 1    |===/                  |                      |
  +------+                      +----------------------+
  | 0    |========> Target obj  | 2112                 |
  +------+                      +----------------------+
*/

typedef struct {
  opcode_e  op;
  mod_e     mod;
  u16_t     value;
  u8_t      target;
} opcode_t;

#endif //__BYTECODE_H__
