#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define TVAR ptrdiff_t
#define TVAR_MIN PTRDIFF_MIN
#define TVAR_MAX PTRDIFF_MAX
#define INLINE extern inline
#include "../poly/mul_check_spoly-portable.i"
