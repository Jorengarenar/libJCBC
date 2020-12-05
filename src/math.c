#include "math.h"

intmax_t jcbc_min(intmax_t a, intmax_t b)
{
    return a < b ? a : b;
}

intmax_t jcbc_max(intmax_t a, intmax_t b)
{
    return a > b ? a : b;
}

intmax_t jcbc_gcd(intmax_t a, intmax_t b)
{
    intmax_t temp;
    while (b) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

intmax_t jcbc_lcm(intmax_t a, intmax_t b)
{
    if (a == 0 || b == 0) {
        return 0;
    }
    return (a * b) / jcbc_gcd(a, b);
}
