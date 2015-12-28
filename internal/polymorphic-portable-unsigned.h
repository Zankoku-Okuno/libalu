// ------------ Check Mode ------------

LIBPREDICTMATIC_INLINE
TVAR POLY(add_check)(TVAR a, TVAR b, bool* sticky_bit) {
    TVAR r = a + b;
    *sticky_bit |= (r < a);
    return r;
}

LIBPREDICTMATIC_INLINE
TVAR POLY(sub_check)(TVAR a, TVAR b, bool* sticky_bit) {
    TVAR r = a - b;
    *sticky_bit |= (r > a);
    return r;
}

LIBPREDICTMATIC_INLINE
TVAR POLY(mul_check)(TVAR a, TVAR b, bool* sticky_bit) {
    if (b > TVAR_MAX / a) {
        *sticky_bit |= true;
        return a;
    }
    else {
        return a * b;
    }
}


// ------------ Carry Mode ------------

// TODO