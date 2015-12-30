// Requires: <stdbool.h>
#include "../macro-util.i"

INLINE
TVAR POLY(mul_check)(TVAR a, TVAR b, bool* sticky_bit) {
    if (b > TVAR_MAX / a) {
        *sticky_bit |= true;
        return a;
    }
    else {
        return a * b;
    }
}
