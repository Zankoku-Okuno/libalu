// DEPS: <stdint.h> <stdbool.h>
inline
uintmax_t add_uMf(uintmax_t a, uintmax_t b, bool* sticky_bit) {
    uintmax_t r = a + b;
    *sticky_bit |= (r < a);
    return r;
}
