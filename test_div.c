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
        int64_t_quotrem r;
        int64_t_divmod s;

        a = 3;
        b = 2;
        r = quotrem_check_int64_t(a, b, &bit);
        s = divmod_check_int64_t(a, b, &bit);
        printf("quotrem: %"PRId64" / %"PRId64" = %"PRId64" rem %"PRId64"\n", a, b, r.quot, r.rem);
        printf(" divmod: %"PRId64" / %"PRId64" = %"PRId64" mod %"PRId64"\n", a, b, s.div, s.mod);

        a = -3;
        b = 2;
        r = quotrem_check_int64_t(a, b, &bit);
        s = divmod_check_int64_t(a, b, &bit);
        printf("quotrem: %"PRId64" / %"PRId64" = %"PRId64" rem %"PRId64"\n", a, b, r.quot, r.rem);
        printf(" divmod: %"PRId64" / %"PRId64" = %"PRId64" mod %"PRId64"\n", a, b, s.div, s.mod);

        a = 3;
        b = -2;
        r = quotrem_check_int64_t(a, b, &bit);
        s = divmod_check_int64_t(a, b, &bit);
        printf("quotrem: %"PRId64" / %"PRId64" = %"PRId64" rem %"PRId64"\n", a, b, r.quot, r.rem);
        printf(" divmod: %"PRId64" / %"PRId64" = %"PRId64" mod %"PRId64"\n", a, b, s.div, s.mod);

        a = -3;
        b = -2;
        r = quotrem_check_int64_t(a, b, &bit);
        s = divmod_check_int64_t(a, b, &bit);
        printf("quotrem: %"PRId64" / %"PRId64" = %"PRId64" rem %"PRId64"\n", a, b, r.quot, r.rem);
        printf(" divmod: %"PRId64" / %"PRId64" = %"PRId64" mod %"PRId64"\n", a, b, s.div, s.mod);
    }
}