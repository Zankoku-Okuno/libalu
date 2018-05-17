#include <stdint.h>
#include <stdbool.h>
#include "add_u16f.h"

extern inline
uint16_t add_u16f(uint16_t a, uint16_t b, bool* sticky_bit);

#include "add_u16f.inl.h"
