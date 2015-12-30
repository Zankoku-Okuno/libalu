INLINE
TVAR POLY(add_check)(TVAR a, TVAR b, bool* sticky_bit) {
    if ( (b > 0 && a > INT_MAX - b) 
       | (b < 0 && a < INT_MIN - b)) {
        *sticky_bit |= true;
        return a;
    }
    else {
        return a + b;
    }
}