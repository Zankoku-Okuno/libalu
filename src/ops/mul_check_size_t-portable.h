// Requires: <stdbool.h>; (for size_t and SIZE_MAX) <stddef.h>, <stdint.h>

#define TVAR size_t
#define TVAR_MAX SIZE_MAX
#define INLINE static inline
#include "../poly/mul_check_upoly-portable.i"