// Requires: <stdbool.h>
#include "../macro-util.i"

INLINE
TVAR POLY(sub_check)(TVAR a, TVAR b, bool* sticky_bit) {
    TVAR r = a - b;
    *sticky_bit |= (r > a);
    return r;
}
