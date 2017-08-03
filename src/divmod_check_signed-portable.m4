// Defines: `divmod_check_'TVAR
INLINE
TVAR`_divmod' `divmod_check_'TVAR (TVAR a, TVAR b, bool* sticky_bit) {
    TVAR`_divmod' r;
    if (b == 0 || (a == MIN && b == -1)) {
        r.div = a;
        r.mod = b;
    }
    else {
        r.div = a / b;
        r.mod = a % b;
        if (r.mod < 0) {
            if (b > 0) {
                r.div -= 1; // unchecked sub allowed b/c r.div can't be MIN when the only way r.mod < 0 is if the magnitude of the divisor is at least 2
                r.mod += b; // unchecked add allowed b/c worst case is b is 1, but r.mod negative
            }
            else if (b < 0) {
                r.div += 1; // unchecked add allowed b/c/ r.div can't be MAX when the only way r.mod < 0 is if the magnitude of the divisor is at least 2
                r.mod -= b; // unchecked sub allowed b/c worst case is b is -1, but r.mod negative
            }
        }
    }
    return r;
}

// Defines: `div_check_'TVAR
INLINE
TVAR `div_check_'TVAR (TVAR a, TVAR b, bool* sticky_bit) {
    TVAR`_divmod' tmp = `divmod_check_'TVAR (a, b, sticky_bit);
    return tmp.div;
}

// Defines: `mod_check_'TVAR
INLINE
TVAR `mod_check_'TVAR (TVAR a, TVAR b, bool* sticky_bit) {
    TVAR`_divmod' tmp = `divmod_check_'TVAR (a, b, sticky_bit);
    return tmp.mod;
}
