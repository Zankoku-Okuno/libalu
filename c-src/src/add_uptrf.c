#include <stdint.h>
#include <stdbool.h>
#include "add_uptrf.h"

extern inline
uintptr_t add_uptrf(uintptr_t a, uintptr_t b, bool* sticky_bit);

#include "add_uptrf.inl.h"
