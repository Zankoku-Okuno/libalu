// REQUIRES: <stdint.h>. <stdbool.h>

#ifndef LIBPREDICTMATIC_INLINE
  #define LIBPREDICTMATIC_INLINE inline
#endif

typedef struct _carry_uint64_t {
    uint64_t low;
    uint64_t high;
} carry_uint64_t;


LIBPREDICTMATIC_INLINE
carry_uint64_t add_carry_uint64_t(uint64_t a, uint64_t b);
LIBPREDICTMATIC_INLINE
carry_uint64_t adc_carry_uint64_t(carry_uint64_t a, uint64_t b);
LIBPREDICTMATIC_INLINE
carry_uint64_t mul_carry_uint64_t(uint64_t a, uint64_t b);
LIBPREDICTMATIC_INLINE
uint64_t add_check_uint64_t(uint64_t a, uint64_t b, bool* sticky_bit);
LIBPREDICTMATIC_INLINE
uint64_t mul_check_uint64_t(uint64_t a, uint64_t b, bool* sticky_bit);

