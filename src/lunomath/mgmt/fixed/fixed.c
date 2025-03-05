#include "./fixed.h"
#include <stdint.h>
#include <stdio.h>
#include <math.h>

LUNOMATH_API
fixed_t fixed_mul(fixed_t a, fixed_t b) {
    // Perform multiplication and then scale back down by FR_BITS to maintain the fixed-point format
    return (fixed_t)(((int64_t)a * (int64_t)b) >> FR_BITS);  // Use int64_t to prevent overflow
}

LUNOMATH_API
fixed_t fixed_div(fixed_t a, fixed_t b) {
    // Handle the case where the denominator is zero (avoid division by zero)
    if (b == 0) {
        fprintf(stderr, "Error: Division by zero in fixed_div\n");
        return (a < 0) ? INT_MIN : INT_MAX;  // Return extreme values to indicate error
    }

    // Check for potential overflow/underflow when dividing
    if (abs(a) >= ((int64_t)INT_MAX << FR_BITS) || abs(b) >= ((int64_t)INT_MAX << FR_BITS)) {
        fprintf(stderr, "Error: Fixed-point division overflow/underflow\n");
        return (a < 0) ? INT_MIN : INT_MAX;
    }

    return fixed_div2(a, b);
}

LUNOMATH_API
fixed_t fixed_div2(fixed_t a, fixed_t b) {
    // Perform fixed-point division: scale the numerator by FR_BITS and then divide by the denominator
    // Convert the result to a fixed-point integer (scaled by FR_BITS)
    if (b == 0) {
        fprintf(stderr, "Error: Division by zero in fixed_div2\n");
        return (a < 0) ? INT_MIN : INT_MAX;  // Return extreme values to indicate error
    }

    // Using double precision to handle division and avoid integer overflow
    double result = ((double)a * (1 << FR_BITS)) / (double)b;

    // Ensure the result is within the range of the fixed-point type
    if (result >= INT_MAX || result < INT_MIN) {
        fprintf(stderr, "FixedDiv2: result out of bounds\n");
        return (a < 0) ? INT_MIN : INT_MAX;  // Return extreme values in case of overflow
    }

    return (fixed_t)result;  // Return the result cast back to fixed_t
}
