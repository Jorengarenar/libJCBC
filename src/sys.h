#ifndef JCBC_SYS_H_
#define JCBC_SYS_H_

#ifdef __cplusplus
extern "C" {
#endif

const char* jcbc_getenv(const char* name, const char* fallback);
int jcbc_mkdir_p(const char* path_);
int jcbc_rm(const char mode, const char* fmt, ...);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // JCBC_SYS_H_
