// Defines: `mul_check_'TVAR
INLINE
TVAR `mul_check_'TVAR (TVAR a, TVAR b, bool* sticky_bit) {
    bool apos = a > 0;
    bool aneg = a < 0;
    bool bpos = b > 0;
    bool bneg = b < 0;

    {
        if (apos & bpos
           && a > MAX / b) {
            goto error;
        }
        else if (apos & bneg
                && b < MIN / a) {
            goto error;
        }
        else if (aneg & bpos
                && a < MIN / b) {
            goto error;
        }
        else if (aneg & bneg
                && b < MAX / a) {
            goto error;
        }
        return a * b;
    }
    error: {
        *sticky_bit |= true;
        return a;
    }
}

