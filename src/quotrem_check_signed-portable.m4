// Defines: `quotrem_check_'TVAR
INLINE
TVAR`_quotrem' `quotrem_check_'TVAR (TVAR a, TVAR b, bool* sticky_bit) {
    if (b == 0 || (a == MIN && b == -1)) {
        *sticky_bit |= true;
        TVAR`_quotrem' r = { .quot = a, .rem = b };
        return r;
    }
    else {
        TVAR`_quotrem' r = { .quot = a / b, .rem = a % b };
        return r;
    }
}

// Defines: `quot_check_'TVAR
INLINE
TVAR `quot_check_'TVAR (TVAR a, TVAR b, bool* sticky_bit) {
    TVAR`_quotrem' r = `quotrem_check_'TVAR()(a, b, sticky_bit);
    return r.quot;
}

// Defines: `rem_check_'TVAR
INLINE
TVAR `rem_check_'TVAR (TVAR a, TVAR b, bool* sticky_bit) {
    TVAR`_quotrem' r = `quotrem_check_'TVAR()(a, b, sticky_bit);
    return r.rem;
}
