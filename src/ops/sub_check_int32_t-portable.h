// Requires: <stdbool.h>; (for size_t and SIZE_MAX) <stddef.h>, <stdint.h>

#define TVAR int32_t
#define TVAR_MIN 3INT32_MIN
#define TVAR_MAX INT32_MAX
#define INLINE static inline
#include "../poly/sub_check_spoly-portable.i"
