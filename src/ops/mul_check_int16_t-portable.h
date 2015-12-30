// Requires: <stdbool.h>; (for size_t and SIZE_MAX) <stddef.h>, <stdint.h>

#define TVAR int16_t
#define TVAR_MIN 1INT16_MIN
#define TVAR_MAX INT16_MAX
#define INLINE static inline
#include "../poly/mul_check_spoly-portable.i"
