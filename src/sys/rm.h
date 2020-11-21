#ifndef RM_H_
#define RM_H_

#ifdef __cplusplus
extern "C" {
#endif

#define _XOPEN_SOURCE 500

#include <ftw.h>
#include <stdarg.h>
#include <unistd.h>

int ntfw_rm(const char* fpath, const struct stat* sb, int typeflag, struct FTW* ftwbuf);
int ntfw_rmdir(const char* fpath, const struct stat* sb, int typeflag, struct FTW* ftwbuf);
int rm(const char mode, const char* fmt, ...);

#ifdef __cplusplus
}
#endif

#endif
