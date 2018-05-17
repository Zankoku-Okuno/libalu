#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "build/predithmatic.h"

#include <stdio.h>
#include <inttypes.h>

int main() {
    uintptr_t a, up, back;
    size_t b;
    bool bit = false;

    for (a = 0; a < 9; ++a) {
        // a = 5;
        b = 4;

        up = align_upto_uintptr_t(a, b, &bit);
        back = align_backto_uintptr_t(a, b, &bit);
        printf("         %"PRIdPTR" (%zd)\n", a, b);
        printf("  up to: %"PRIdPTR"\n", up);
        printf("back to: %"PRIdPTR"\n", back);

    }
}