#include <stdint.h>
#include <stdbool.h>

#include "uint64_t.h"
#include "uint64_t-x64.h"


#include <stdio.h>
#include <inttypes.h>
int main() {
    {
        uint64_t a = 0x1000000000000000;
        uint64_t b = 0xdeadbeef;
        printf("mul carry: %"PRIx64" * %"PRIx64"\n", a, b);
        carry_uint64_t r = mul_carry_uint64_t(a, b);
        printf("   result: %"PRIx64" %"PRIx64"\n", r.high, r.low);
    }
    {
        uint64_t a = 0x4000000000000001;
        uint64_t b = 0x2;
        bool of = false;
        printf("mul check: (%d) %"PRIx64" * 2\n", of, a);
        a = mul_check_uint64_t(a, b, &of);
        printf("   result: (%d) %"PRIx64" * 2\n", of, a);
        a = mul_check_uint64_t(a, b, &of);
        printf("   result: (%d) %"PRIx64" * 2\n", of, a);
        a = mul_check_uint64_t(a, b, &of);
        printf("   result: (%d) %"PRIx64"\n", of, a);
    }
    {
        uint64_t a = 0xfffffffffffffffe;
        uint64_t b = 0x1;
        bool of = false;
        printf("add check: (%d) %"PRIx64" + 1\n", of, a);
        a = add_check_uint64_t(a, b, &of);
        printf("   result: (%d) %"PRIx64" + 1\n", of, a);
        a = add_check_uint64_t(a, b, &of);
        printf("   result: (%d) %"PRIx64" + 1\n", of, a);
        a = add_check_uint64_t(a, b, &of);
        printf("   result: (%d) %"PRIx64"\n", of, a);
    }
    {
        carry_uint64_t r;
        uint64_t a = 0xffffffffffffffff;
        r.low = 0xffffffffffffffff;
        r.high = 0;
        printf("add carry: %"PRIx64" %"PRIx64" + ~0\n", r.high, r.low);
        r = add_carry_uint64_t(r.low, a);
        printf("   result: %"PRIx64" %"PRIx64" + ~0\n", r.high, r.low);
        r = adc_carry_uint64_t(r, a);
        printf("   result: %"PRIx64" %"PRIx64" + ~0\n", r.high, r.low);
        r = adc_carry_uint64_t(r, a);
        printf("   result: %"PRIx64" %"PRIx64"\n", r.high, r.low);
    }

    return 0;
}