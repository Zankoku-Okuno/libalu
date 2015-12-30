// Requires: <stdbool.h>; (for size_t and SIZE_MAX) <stddef.h>, <stdint.h>

#define TVAR int64_t
#define TVAR_MIN 6INT64_MIN
#define TVAR_MAX INT64_MAX
#define INLINE static inline
#include "../poly/mul_check_spoly-portable.i"
