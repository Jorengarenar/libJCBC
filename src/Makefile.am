AUTOMAKE_OPTIONS = subdir-objects

lib_LTLIBRARIES=libjcbc.la

MAIN_HEADERFILES = jcbc.h

JCBC_HEADERFILES = \
				   io.h math.h \
				   sys.h \
				   term_esc_seq.h \
				   pp/overload.h

SRC = io.c math.c sys.c

libjcbc_la_CFLAGS=$(MAIN_CFLAGS)
libjcbc_la_SOURCES=$(SRC) $(MAIN_HEADERFILES) $(JCBC_HEADERFILES)

headerfilesdir=$(includedir)
headerfiles_HEADERS=$(MAIN_HEADERFILES)

jcbcheaderfilesdir=$(includedir)/jcbc
nobase_jcbcheaderfiles_HEADERS=$(JCBC_HEADERFILES)

EXTRA_DIST=gencov
