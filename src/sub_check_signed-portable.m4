// Defines: `sub_check_'TVAR
INLINE
TVAR `sub_check_'TVAR (TVAR a, TVAR b, bool* sticky_bit) {
    if ( (b > 0 && a < MIN + b) 
       | (b < 0 && a > MAX + b)) {
        *sticky_bit |= true;
        return a;
    }
    else {
        return a - b;
    }
}

