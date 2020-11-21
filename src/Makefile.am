lib_LTLIBRARIES=libjorenc.la

MAIN_HEADERFILES = joren.h

JORENC_HEADERFILES = \
					 io.h math.h term_esc_seq.h sys/mkdir_p.h \
					 sys/rm.h sys/wrapper_exec.h

SRC = io.c math.c sys/mkdir_p.c sys/rm.c sys/wrapper_exec.c

libjorenc_la_CFLAGS=$(MAIN_CFLAGS)
libjorenc_la_SOURCES=$(SRC) $(MAIN_HEADERFILES) $(JORENC_HEADERFILES)

headerfilesdir=$(includedir)
headerfiles_HEADERS=$(MAIN_HEADERFILES)

jorencheaderfilesdir=$(includedir)/joren
nobase_jorencheaderfiles_HEADERS=$(JORENC_HEADERFILES)

EXTRA_DIST=gencov
