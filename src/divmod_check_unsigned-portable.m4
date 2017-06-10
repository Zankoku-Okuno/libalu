// Defines: `divmod_check_'TVAR
INLINE
TVAR`_divmod' `divmod_check_'TVAR (TVAR a, TVAR b, bool* sticky_bit) {
    if (b == 0) {
        *sticky_bit |= true;
        TVAR`_divmod' r = { .div = a, .mod = b };
        return r;
    }
    else {
        TVAR`_divmod' r = { .div = a / b, .mod = a % b };
        return r;
    }
}

// Defines: `div_check_'TVAR
INLINE
TVAR `div_check_'TVAR (TVAR a, TVAR b, bool* sticky_bit) {
    TVAR`_divmod' r = `divmod_check_'TVAR()(a, b, sticky_bit);
    return r.div;
}

// Defines: `mod_check_'TVAR
INLINE
TVAR `mod_check_'TVAR (TVAR a, TVAR b, bool* sticky_bit) {
    TVAR`_divmod' r = `divmod_check_'TVAR()(a, b, sticky_bit);
    return r.div;
}

