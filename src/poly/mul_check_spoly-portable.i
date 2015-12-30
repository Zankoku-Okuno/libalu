INLINE
TVAR POLY(mul_check)(TVAR a, TVAR b) {
    bool apos = a > 0;
    bool bpos = b > 0;
    bool aneg = a < 0;
    bool bneg = b < 0;

    {
        if (apos & bpos
           && a > TVAR_MAX / b) {
            goto error;
        }
        else if (apos & bneg
                && b < TVAR_MIN / a) {
            goto error;
        }
        else if (aneg & bpos
                && a < TVAR_MIN / b) {
            goto error;
        }
        else if (aneg & bneg
                && b < TVAR_MAX / a) {
            goto error;
        }
        return a * b;
    }
    error: {
        *sticky_bit |= true;
        return a;
    }
}