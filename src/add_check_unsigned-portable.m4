// Defines: `add_check_'TVAR
INLINE
TVAR `add_check_'TVAR (TVAR a, TVAR b, bool* sticky_bit) {
    TVAR r = a + b;
    *sticky_bit |= (r < a);
    return r;
}
