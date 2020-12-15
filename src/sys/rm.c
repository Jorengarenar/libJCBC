#include "rm.h"

#define _XOPEN_SOURCE 500

#include <ftw.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

static int jcbc_ntfw_rm(const char* fpath, const struct stat* sb, int typeflag, struct FTW* ftwbuf)
{
    return remove(fpath);
}

static int jcbc_ntfw_rmdir(const char* fpath, const struct stat* sb, int typeflag, struct FTW* ftwbuf)
{
    return rmdir(fpath);
}

int jcbc_rm(const char mode, const char* fmt, ...)
{
    va_list vars;
    va_start(vars, fmt);
    char path[BUFSIZ];
    vsnprintf(path, BUFSIZ, fmt, vars);
    va_end(vars);

    switch (mode) {
        case 'r': // remove recursively
            return nftw(path, jcbc_ntfw_rm, 100, FTW_DEPTH|FTW_PHYS);
        case 'd': // remove dir
            return rmdir(path);
        case 'D': // remove empty subdirs and if emptied, then dir too
            return nftw(path, jcbc_ntfw_rmdir, 100, FTW_DEPTH|FTW_PHYS);
        default:  // remove file
            return unlink(path);
    }
}
