#ifndef JCBC_PP_OVERLOAD_H_
#define JCBC_PP_OVERLOAD_H_

// Based on:
//    https://gustedt.wordpress.com/2010/06/08/detect-empty-macro-arguments/
//    https://stackoverflow.com/a/30566098/10247460

#define JCBC_PP_OVERLOAD(M, ...) _OVR(M, VA_NUM_ARGS(__VA_ARGS__)) (__VA_ARGS__)
#define _OVR(name, num)           _OVR_EXPAND(name, num)
#define _OVR_EXPAND(name, num)    name ## num

// *INDENT-OFF*
#define _ARG64_N( \
         _0,  _1,  _2,  _3,  _4,  _5,  _6,  _7,  _8,  _9, \
        _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, \
        _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, \
        _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, \
        _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, \
        _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, \
        _60, _61, _62, _63, \
        N,  ...)  N
// *INDENT-ON*

#define HAS_COMMA(...)    _ARG64_N(__VA_ARGS__, \
                                   1  1, 1, 1, 1, 1, 1, 1, 1, 1, \
                                   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
                                   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
                                   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
                                   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
                                   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
                                   1, 1, 1, 1, \
                                   0)

#define HAS_NO_COMMA(...) _ARG64_N(__VA_ARGS__, \
                                   0  0, 0, 0, 0, 0, 0, 0, 0, 0, \
                                   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
                                   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
                                   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
                                   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
                                   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
                                   0, 0, 0, 0, \
                                   1)

#define _TRIGGER_PARENTHESIS_(...) ,

#define HAS_ZERO_OR_ONE_ARGS(...) \
    _HAS_ZERO_OR_ONE_ARGS( \
        /* test if one argument, eventually an empty one */ \
        HAS_COMMA(__VA_ARGS__), \
        /* test if _TRIGGER_PARENTHESIS_ with the argument adds a comma */ \
        HAS_COMMA(_TRIGGER_PARENTHESIS_ __VA_ARGS__), \
        /* test if the argument with a parenthesis adds a comma */ \
        HAS_COMMA(__VA_ARGS__ (~)), \
        /* test if placing it between _TRIGGER_PARENTHESIS_ and the parenthesis adds a comma */ \
        HAS_COMMA(_TRIGGER_PARENTHESIS_ __VA_ARGS__ (~)) \
    )

#define PASTE5(_0, _1, _2, _3, _4) _0 ## _1 ## _2 ## _3 ## _4
#define _HAS_ZERO_OR_ONE_ARGS(_0, _1, _2, _3) HAS_NO_COMMA(PASTE5(_IS_EMPTY_CASE_, _0, _1, _2, _3))
#define _IS_EMPTY_CASE_0001 ,

#define VA_NUM_ARGS(...) VA_NUM_ARGS_IMPL(__VA_ARGS__, PP_RSEQ_N(__VA_ARGS__) )
#define VA_NUM_ARGS_IMPL(...) _ARG64_N(__VA_ARGS__)

// *INDENT-OFF*
#define PP_RSEQ_N(...) \
                        64, 63, 62, 61, 60, \
    59, 58, 57, 56, 55, 54, 53, 52, 51, 50, \
    49, 48, 47, 46, 45, 44, 43, 42, 41, 40, \
    39, 38, 37, 36, 35, 34, 33, 32, 31, 30, \
    29, 28, 27, 26, 25, 24, 23, 22, 21, 20, \
    19, 18, 17, 16, 15, 14, 13, 12, 11, 10, \
     9,  8,  7,  6,  5,  4,  3,  2,         \
    HAS_ZERO_OR_ONE_ARGS(__VA_ARGS__),   0
// *INDENT-ON*

#endif // JCBC_PP_OVERLOAD_H_
