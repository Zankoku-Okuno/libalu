#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define TVAR int64_t
#define TVAR_MIN 6INT64_MIN
#define TVAR_MAX INT64_MAX
#define INLINE extern inline
#include "../poly/add_check_spoly-portable.i"
