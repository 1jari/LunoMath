#ifndef __BYTECODE_H__
#define __BYTECODE_H__

#include "../../mgmt/mgmt.h"
#include "../../common.h"

// Operation Modifiers
typedef enum {
  OPMOD_BAM,  // Example modifier
  OPMOD_DEG,  // Example modifier
  OPMOD_CM,   // Example modifier
  OPMOD_NUMBER,
} mod_e;

typedef enum {
  OP_LD,           // Load
  OP_STR,          // Store
  OP_NOP = 0b1111, 
} opcode_e;

/*
  +------+ 
  |       /=====> opcode
  + 3====|
  |       \=====> type
  +------+
  | 5     ===|
  +------+   |=> x
  | 4     ===|
  +------+ 
  | 1     ===|
  +------+   |======> Target
  | 0     ===|
  +------+
*/

// Instruction structure
typedef struct {
  opcode_e  op;  // The opcode
  mod_e     t;   // The modifier type
  u32_t     x;   // Operand or register x
  u16_t     y;   // Operand or register y
} opcode_t;

#endif //__BYTECODE_H__
