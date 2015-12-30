#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define TVAR uintptr_t
#define TVAR_MAX UINTPTR_MAX
#define INLINE extern inline
#include "../poly/add_check_upoly-portable.i"
