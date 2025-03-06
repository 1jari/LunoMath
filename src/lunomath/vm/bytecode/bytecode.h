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
  OP_SPAWN,     // create an instance for an parent object
  OP_LINK,      // link a value to another object(s)
  OP_ATTACH,    // link an object to another object(s)
  OP_NOP
} opcode_e;

/*
  +------+                      +----------------------+
  |       /=====> opcode        | SPAWN                |
  + 3====|                      +----------------------+
  |       \=====> op modifier   | OPMOD_ANGLE          |
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

#endif //__BYTECODE_H__
