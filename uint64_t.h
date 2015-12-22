#include <stdint.h>
#include <stdbool.h>

typedef struct _carry_uint64_t {
    uint64_t low;
    uint64_t high;
} carry_uint64_t;


// FIXME make this inlined right
// extern inline
// carry_uint64_t mul_carry_uint64_t(uint64_t a, uint64_t b);
// extern inline
// uint64_t mul_check_uint64_t(uint64_t a, uint64_t b, bool* sticky_bit);
// extern inline
// carry_uint64_t add_carry_uint64_t(uint64_t a, uint64_t b);
// extern inline
// carry_uint64_t adc_carry_uint64_t(carry_uint64_t a, uint64_t b);
// extern inline
// uint64_t add_check_uint64_t(uint64_t a, uint64_t b, bool* sticky_bit);