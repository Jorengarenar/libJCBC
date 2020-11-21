AC_INIT([libjorenc], [0.1], [https://joren.ga])
AC_CONFIG_AUX_DIR(autotools)
AC_CONFIG_SRCDIR([src])
AC_CONFIG_MACRO_DIR([m4])

AM_INIT_AUTOMAKE

AC_PROG_CC
AM_PROG_CC_C_O
AC_PROG_CXX
AC_PROG_LIBTOOL
AC_PROG_INSTALL
AC_PROG_MAKE_SET

if [[ "$GCC" = "yes" ]]; then
    # Turn on all warnings for gcc.  Turn off optimisation for the test build.
	WARNINGS="-Wall -Wsign-compare -Wconversion"
	CFLAGS="$CFLAGS $WARNINGS"
	TEST_CFLAGS="$TEST_CFLAGS $WARNINGS -O0"
fi

MAIN_CFLAGS="$CFLAGS"
CFLAGS=""

AM_CONFIG_HEADER(config.h:config.h.in)

AC_SUBST(MAIN_CFLAGS)
AC_SUBST(TEST_CFLAGS)
AC_SUBST(ac_aux_dir)

AC_OUTPUT([
    Makefile
    libjorenc-1.0.pc
    doc/Makefile
    src/Makefile
])
    #test/Makefile
