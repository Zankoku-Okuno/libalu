// Requires: <stdbool.h>; (for size_t and SIZE_MAX) <stddef.h>, <stdint.h>

#define TVAR ptrdiff_t
#define TVAR_MIN PTRDIFF_MIN
#define TVAR_MAX PTRDIFF_MAX
#define INLINE static inline
#include "../poly/add_check_spoly-portable.i"
