// REQUIRES: <stdint.h>. <stdbool.h>, "./macro-util.h"



#ifndef LIBPREDICTMATIC_INLINE
    #define LIBPREDICTMATIC_INLINE inline
#endif

/* 
    Polymorphism is accomplished setting LIBPREDICTMATIC_TYPEVAR before including this file.
    We need to know the maximum number stored in the type as well, so set LIBPREDICTMATIC_LIMITS
    to the prefix of the associated <typename>_MAX and <typename>_MIN macros set in <limits.h>.
    A polymorphic name has the typename appended after an underscore.
*/

#ifndef LIBPREDICTMATIC_TYPEVAR
  #error "predictmatic: no type set"
#endif

#define TVAR LIBPREDICTMATIC_TYPEVAR
#define TVAR_MIN CAT(LIBPREDICTMATIC_LIMITS, _MIN)
#define TVAR_MAX CAT(LIBPREDICTMATIC_LIMITS, _MAX)




typedef struct POLY(_carry) {
    TVAR low;
    TVAR high;
} POLY(carry);


// LIBPREDICTMATIC_INLINE
// POLY(carry) POLY(add_carry)(TVAR a, TVAR b);
// LIBPREDICTMATIC_INLINE
// POLY(carry) POLY(adc_carry)(POLY(carry) a, TVAR b);
// LIBPREDICTMATIC_INLINE
// POLY(carry) POLY(mul_carry)(TVAR a, TVAR b);
LIBPREDICTMATIC_INLINE
TVAR POLY(add_check)(TVAR a, TVAR b, bool* sticky_bit);
LIBPREDICTMATIC_INLINE
TVAR POLY(sub_check)(TVAR a, TVAR b, bool* sticky_bit);
LIBPREDICTMATIC_INLINE
TVAR POLY(mul_check)(TVAR a, TVAR b, bool* sticky_bit);

