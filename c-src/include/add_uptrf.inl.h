// DEPS: <stdint.h> <stdbool.h>
inline
uintptr_t add_uptrf(uintptr_t a, uintptr_t b, bool* sticky_bit) {
    uintptr_t r = a + b;
    *sticky_bit |= (r < a);
    return r;
}
