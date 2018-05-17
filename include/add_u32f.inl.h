// DEPS: <stdint.h> <stdbool.h>
inline
uint32_t add_u32f(uint32_t a, uint32_t b, bool* sticky_bit) {
    uint32_t r = a + b;
    *sticky_bit |= (r < a);
    return r;
}
