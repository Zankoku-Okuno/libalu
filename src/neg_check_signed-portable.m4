// Defines: `neg_check_'TVAR
INLINE
TVAR `neg_check_'TVAR (TVAR a, bool* sticky_bit) {
    if (a == MIN) {
        *sticky_bit |= true;
        return a;
    }
    else {
        return -a;
    }
}

