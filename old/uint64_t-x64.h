// ------------ Check Mode ------------

LIBPREDICTMATIC_INLINE
uint64_t add_check_uint64_t(uint64_t a, uint64_t b, bool* sticky_bit) {
    bool c;
    __asm__ (
        "addq %[b], %[a]\n\t" // a <- a + b;
        "setc %[c]" // c <- FLAGS[CARRY]
        : [a] "+rm" (a)  // output
        , [c] "=rm" (c)
        : [b] "rm" (b) // input
        : "cc" // clobber
        );
    *sticky_bit |= c;
    return a;
}

LIBPREDICTMATIC_INLINE
uint64_t mul_check_uint64_t(uint64_t a, uint64_t b, bool* sticky_bit) {
    uint64_t r;
    bool c;
    __asm__ (
        "mulq %[b]\n\t" // RDX:RAX <- a * b;
        "setc %[c]" // RDX <- FLAGS[CARRY]
        : [rl] "=a" (r)  // output
        , [c] "=d" (c)
        : [a] "[rl]" (a) // input
        , [b] "rm" (b)
        : "cc" // clobber
        );
    *sticky_bit |= c;
    return r;
}


// ------------ Carry Mode ------------

LIBPREDICTMATIC_INLINE
carry_uint64_t add_carry_uint64_t(uint64_t a, uint64_t b) {
    carry_uint64_t r;
    bool c;
    __asm__ (
        "addq %[b], %[rl]\n\t" // r.low <- a + b;
        "setc %[c]" // r.high <- FLAGS[CARRY]
        : [rl] "=rm" (r.low)  // output
        , [c] "=rm" (c)
        : [a] "[rl]" (a) // input
        , [b] "rm" (b)
        : "cc" // clobber
        );
    r.high = (uint64_t)c;
    return r;
}

LIBPREDICTMATIC_INLINE
carry_uint64_t adc_carry_uint64_t(carry_uint64_t a, uint64_t b) {
    carry_uint64_t r;
    bool c;
    __asm__ (
        "addq %[b], %[rl]\n\t" // r.low <- a.low + b;
        "setc %[c]" // r.high <- FLAGS[CARRY]
        : [rl] "=rm" (r.low)  // output
        , [rh] "=rm" (r.high)
        , [c] "=rm" (c)
        : [al] "[rl]" (a.low) // input
        , [ah] "[rh]" (a.high)
        , [b] "rm" (b)
        : "cc" // clobber
        );
    r.high += c;
    return r;
}

LIBPREDICTMATIC_INLINE
carry_uint64_t mul_carry_uint64_t(uint64_t a, uint64_t b) {
    carry_uint64_t r;
    __asm__ (
        "mulq %[b]" // RDX:RAX <- a * b;
        : [rl] "=a" (r.low)  // output
        , [rh] "=d" (r.high)
        : [a] "[rl]" (a) // input
        , [b] "rm" (b)
        : "cc" // clobber
        );
    return r;
}
