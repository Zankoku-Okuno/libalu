#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define TVAR int16_t
#define TVAR_MIN 1INT16_MIN
#define TVAR_MAX INT16_MAX
#define INLINE extern inline
#include "../poly/mul_check_spoly-portable.i"
