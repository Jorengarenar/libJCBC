#include "jcbc/utils.h"

#ifdef WIN32
# include <windows.h>
#else
# include <unistd.h> // for usleep()
# if _POSIX_C_SOURCE >= 199309L
#  include <time.h>  // usleep() may not be available, so nanosleep()
# endif
#endif

void jcbc_msleep(int ms)  // cross-platform sleep function
{
#ifdef WIN32
    Sleep(ms);
#elif _POSIX_C_SOURCE >= 199309L
    struct timespec ts;
    ts.tv_sec = ms / 1000;
    ts.tv_nsec = (ms % 1000) * 1000000;
    nanosleep(&ts, NULL);
#else
    if (ms >= 1000) {
        sleep(ms / 1000);
    }
    usleep((ms % 1000) * 1000);
#endif
}
