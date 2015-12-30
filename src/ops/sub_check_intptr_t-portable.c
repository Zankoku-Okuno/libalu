#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define TVAR intptr_t
#define TVAR_MIN INTPTR_MIN
#define TVAR_MAX INTPTR_MAX
#define INLINE extern inline
#include "../poly/sub_check_spoly-portable.i"
