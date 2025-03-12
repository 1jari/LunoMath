#include "./whandler.h"

LUNOMATH_API
void little_endian_encode(u32_t   value,
                          u8_t   *output) {
  // Store the 32-bit value in little-endian byte order
  output[0] = (u8_t)(value & 0xFF);          // Least significant byte
  output[1] = (u8_t)((value >> 8) & 0xFF);   // Second byte
  output[2] = (u8_t)((value >> 16) & 0xFF);  // Third byte
  output[3] = (u8_t)((value >> 24) & 0xFF);  // Most significant byte
}

LUNOMATH_API
u32_t little_endian_decode( const u8_t *input) {
    u32_t value = 0;
    
    // Combine the bytes from the little-endian array
    value |= (u32_t)input[0];               // Least significant byte
    value |= (u32_t)input[1] << 8;          // Second byte
    value |= (u32_t)input[2] << 16;         // Third byte
    value |= (u32_t)input[3] << 24;         // Most significant byte
    
    return value;
}