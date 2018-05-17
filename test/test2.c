#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

// #include "size_t.h"
#include "src/ops/add_check_size_t-portable.h"
#include "src/ops/sub_check_size_t-portable.h"
#include "src/ops/mul_check_size_t-portable.h"


#include <stdio.h>
#include <inttypes.h>
int main() {
    {
        size_t a = 0xfffffffffffffffe;
        size_t b = 0x1;
        bool of = false;
        printf("add check: (%d) %"PRIx64" + 1\n", of, a);
        a = add_check_size_t(a, b, &of);
        printf("   result: (%d) %"PRIx64" + 1\n", of, a);
        a = add_check_size_t(a, b, &of);
        printf("   result: (%d) %"PRIx64" + 1\n", of, a);
        a = add_check_size_t(a, b, &of);
        printf("   result: (%d) %"PRIx64"\n", of, a);
    }
    {
        size_t a = 0x5;
        size_t b = 0x3;
        bool of = false;
        printf("sub check: (%d) %"PRIx64" - 3\n", of, a);
        a = sub_check_size_t(a, b, &of);
        printf("   result: (%d) %"PRIx64" - 3\n", of, a);
        a = sub_check_size_t(a, b, &of);
        printf("   result: (%d) %"PRIx64" - 3\n", of, a);
        a = sub_check_size_t(a, b, &of);
        printf("   result: (%d) %"PRIx64"\n", of, a);
    }
    {
        size_t a = 0x4000000000000001;
        size_t b = 0x2;
        bool of = false;
        printf("mul check: (%d) %"PRIx64" * 2\n", of, a);
        a = mul_check_size_t(a, b, &of);
        printf("   result: (%d) %"PRIx64" * 2\n", of, a);
        a = mul_check_size_t(a, b, &of);
        printf("   result: (%d) %"PRIx64" * 2\n", of, a);
        a = mul_check_size_t(a, b, &of);
        printf("   result: (%d) %"PRIx64"\n", of, a);
    }

    return 0;
}