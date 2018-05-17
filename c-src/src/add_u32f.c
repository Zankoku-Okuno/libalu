#include <stdint.h>
#include <stdbool.h>
#include "add_u32f.h"

extern inline
uint32_t add_u32f(uint32_t a, uint32_t b, bool* sticky_bit);

#include "add_u32f.inl.h"
