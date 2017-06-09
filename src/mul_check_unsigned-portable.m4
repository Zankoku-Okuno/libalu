// Defines: `mul_check_'TVAR
INLINE
TVAR `mul_check_'TVAR (TVAR a, TVAR b, bool* sticky_bit) {
    if (a != 0 && b > MAX / a) {
        *sticky_bit |= true;
        return a;
    }
    else {
        return a * b;
    }
}
