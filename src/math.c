#include "math.h"

long long jcbc_min(long long a, long long b)
{
    return a < b ? a : b;
}

long long jcbc_max(long long a, long long b)
{
    return a > b ? a : b;
}

long long jcbc_gcd(long long a, long long b)
{
    long long temp;
    while (b) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

long long jcbc_lcm(long long a, long long b)
{
    if (a == 0 || b == 0) {
        return 0;
    }
    return (a * b) / jcbc_gcd(a, b);
}
