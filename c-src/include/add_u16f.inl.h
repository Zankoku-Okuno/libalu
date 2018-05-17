// DEPS: <stdint.h> <stdbool.h>
inline
uint16_t add_u16f(uint16_t a, uint16_t b, bool* sticky_bit) {
    uint16_t r = a + b;
    *sticky_bit |= (r < a);
    return r;
}
