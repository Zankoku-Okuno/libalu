#include <stdint.h>
#include <stdbool.h>
#include "add_uMf.h"

extern inline
uintmax_t add_uMf(uintmax_t a, uintmax_t b, bool* sticky_bit);

#include "add_uMf.inl.h"
