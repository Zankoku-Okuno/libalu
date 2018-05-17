#include <stdint.h>
#include <stdbool.h>
#include "add_u64f.h"

extern inline
uint64_t add_u64f(uint64_t a, uint64_t b, bool* sticky_bit);

#include "add_u64f.inl.h"
