#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "build/predithmatic.h"

#include <stdio.h>
#include <inttypes.h>

int main() {
    {
        int64_t a, b;
        bool bit = false;
        int64_t_divmod r;

        a = 5;
        b = 3;
        r = divmod_check_int64_t(a, b, &bit);
        printf("divmod check: %"PRId64" / %"PRId64"\n", a, b);
        printf("      result: %"PRId64" rem %"PRId64"\n", r.div, r.mod);

        a = -5;
        b = 3;
        r = divmod_check_int64_t(a, b, &bit);
        printf("divmod check: %"PRId64" / %"PRId64"\n", a, b);
        printf("      result: %"PRId64" rem %"PRId64"\n", r.div, r.mod);

        a = 5;
        b = -3;
        r = divmod_check_int64_t(a, b, &bit);
        printf("divmod check: %"PRId64" / %"PRId64"\n", a, b);
        printf("      result: %"PRId64" rem %"PRId64"\n", r.div, r.mod);

        a = -5;
        b = -3;
        r = divmod_check_int64_t(a, b, &bit);
        printf("divmod check: %"PRId64" / %"PRId64"\n", a, b);
        printf("      result: %"PRId64" rem %"PRId64"\n", r.div, r.mod);
    }
}