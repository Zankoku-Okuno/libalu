#include <stdint.h>
#include <stdbool.h>
#include "add_u8f.h"

extern inline
uint8_t add_u8f(uint8_t a, uint8_t b, bool* sticky_bit);

#include "add_u8f.inl.h"
