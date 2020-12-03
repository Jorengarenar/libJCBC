#include "math.h"

intmax_t joren_min(intmax_t a, intmax_t b)
{
    return a < b ? a : b;
}

intmax_t joren_max(intmax_t a, intmax_t b)
{
    return a > b ? a : b;
}

intmax_t joren_gcd(intmax_t a, intmax_t b)
{
    intmax_t temp;
    while (b) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

intmax_t joren_lcm(intmax_t a, intmax_t b)
{
    if (a == 0 || b == 0) {
        return 0;
    }
    return (a * b) / joren_gcd(a, b);
}
