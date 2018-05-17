// DEPS: <stdint.h> <stdbool.h>
inline
uint64_t add_u64f(uint64_t a, uint64_t b, bool* sticky_bit) {
    uint64_t r = a + b;
    *sticky_bit |= (r < a);
    return r;
}
