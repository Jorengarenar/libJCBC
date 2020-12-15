#ifndef JCBC_MATH_H_
#define JCBC_MATH_H_

#include <stdint.h>

#ifdef __GNUC__

#ifndef MIN
#define MIN(a, b)            \
    ({ __typeof__(a) _a = a; \
       __typeof__(b) _b = b; \
       _a < _b ? _a : _b; })
#endif

#ifndef MAX
#define MAX(a, b)            \
    ({ __typeof__(a) _a = a; \
       __typeof__(b) _b = b; \
       _a > _b ? _a : _b; })
#endif

#elif defined(JCBC_UNSAFE_MINMAX) // ifdef __GNUC__

#ifndef MIN
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif

#ifndef MAX
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif

#else // ifdef __GNUC__

#ifndef MIN
#define MIN @ "To use unsafe MIN/MAX macro define JCBC_UNSAFE_MINMAX"
#endif

#ifndef MAX
#define MAX @ "To use unsafe MIN/MAX macro define JCBC_UNSAFE_MINMAX"
#endif

#endif // ifdef __GNUC__

long long jcbc_min(long long a, long long b);
long long jcbc_max(long long a, long long b);

long long jcbc_gcd(long long a, long long b);
long long jcbc_lcm(long long a, long long b);

#endif // JCBC_MATH_H_
