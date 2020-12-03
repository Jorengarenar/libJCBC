#ifndef JOREN_IO_H_
#define JOREN_IO_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

#if defined(__cplusplus) && !defined(restrict)
#define restrict
#endif

#define GETS(buf, n) joren_fgets(buf, n, stdin)

char* joren_fgets(char* s, int size, FILE* stream);

char* joren_popen(char* restrict out,
                  const int n,
                  const char* restrict cmd,
                  const int lines);

int joren_scanf(const char* restrict prompt,
                const char* restrict errMsg,
                void (* eofFunc)(),
                const char* restrict fmt,
                ...);

#ifdef __cplusplus
}
#endif

#endif // JOREN_IO_H_
