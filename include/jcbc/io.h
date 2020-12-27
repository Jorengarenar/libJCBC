#ifndef JCBC_IO_H_
#define JCBC_IO_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

#if !defined(__GNUC__) && !defined(_MSC_VER)
# if __STDC_VERSION__ >= 199901L
#  define __restrict restrict
# else
#  define __restrict
# endif
#endif

#define GETS(buf, n) jcbc_fgets(buf, n, stdin)

char* jcbc_fgets(char* s, int size, FILE* stream);

char* jcbc_popen(char* __restrict out,
                  const int n,
                  const char* __restrict cmd,
                  const int lines);

int jcbc_scanf(const char* __restrict prompt,
                const char* __restrict errMsg,
                void (* eofFunc)(),
                const char* __restrict fmt,
                ...);

#ifdef __cplusplus
}
#endif

#endif // JCBC_IO_H_
