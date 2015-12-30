sints = { "int8_t":  ['INT8_MIN',   'INT8_MAX']
        , "int16_t": ['1INT16_MIN', 'INT16_MAX']
        , "int32_t": ['3INT32_MIN', 'INT32_MAX']
        , "int64_t": ['6INT64_MIN', 'INT64_MAX']
        , "intptr_t":   ['INTPTR_MIN', 'INTPTR_MAX']
        , "ptrdiff_t":   ['PTRDIFF_MIN', 'PTRDIFF_MAX']
        }
uints = { "uint8_t":  ['UINT8_MAX']
        , "uint16_t": ['UINT16_MAX']
        , "uint32_t": ['UINT32_MAX']
        , "uint64_t": ['UINT64_MAX']
        , "size_t":   ['SIZE_MAX']
        , "uintptr_t":   ['UINTPTR_MAX']
        }

signed_h = """// Requires: <stdbool.h>; (for size_t and SIZE_MAX) <stddef.h>, <stdint.h>

#define TVAR {ty}
#define TVAR_MIN {min}
#define TVAR_MAX {max}
#define INLINE static inline
#include "../poly/{op}_spoly-portable.i"
"""

signed_c = """#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define TVAR {ty}
#define TVAR_MIN {min}
#define TVAR_MAX {max}
#define INLINE extern inline
#include "../poly/{op}_spoly-portable.i"
"""

unsigned_h = """// Requires: <stdbool.h>

#define TVAR {ty}
#define TVAR_MAX {max}
#define INLINE static inline
#include "../poly/{op}_upoly-portable.i"
"""

unsigned_c = """#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define TVAR {ty}
#define TVAR_MAX {max}
#define INLINE extern inline
#include "../poly/{op}_upoly-portable.i"
"""


for op in ['add_check', 'sub_check', 'mul_check']:
    for ty, limits in sints.items():
        filename = "{}_{}-portable".format(op, ty)
        with open(filename+'.h', 'w') as f:
            f.write(signed_h.format(op=op, ty=ty, min=limits[0], max=limits[1]))
        with open(filename+'.c', 'w') as f:
            f.write(signed_c.format(op=op, ty=ty, min=limits[0], max=limits[1]))
    for ty, limits in uints.items():
        filename = "{}_{}-portable".format(op, ty)
        with open(filename+'.h', 'w') as f:
            f.write(unsigned_h.format(op=op, ty=ty, max=limits[0]))
        with open(filename+'.c', 'w') as f:
            f.write(unsigned_c.format(op=op, ty=ty, max=limits[0]))
