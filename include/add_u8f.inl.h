// DEPS: <stdint.h> <stdbool.h>
inline
uint8_t add_u8f(uint8_t a, uint8_t b, bool* sticky_bit) {
    uint8_t r = a + b;
    *sticky_bit |= (r < a);
    return r;
}
