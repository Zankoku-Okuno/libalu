// Requires: <stdbool.h>; (for size_t and SIZE_MAX) <stddef.h>, <stdint.h>

#define TVAR intptr_t
#define TVAR_MIN INTPTR_MIN
#define TVAR_MAX INTPTR_MAX
#define INLINE static inline
#include "../poly/mul_check_spoly-portable.i"
