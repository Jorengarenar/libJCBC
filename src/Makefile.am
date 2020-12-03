AUTOMAKE_OPTIONS = subdir-objects

lib_LTLIBRARIES=libjoren.la

MAIN_HEADERFILES = joren.h

JOREN_HEADERFILES = \
					 io.h math.h term_esc_seq.h sys/mkdir_p.h \
					 sys/rm.h \
					 pp/overload.h

SRC = io.c math.c sys/mkdir_p.c sys/rm.c

libjoren_la_CFLAGS=$(MAIN_CFLAGS)
libjoren_la_SOURCES=$(SRC) $(MAIN_HEADERFILES) $(JOREN_HEADERFILES)

headerfilesdir=$(includedir)
headerfiles_HEADERS=$(MAIN_HEADERFILES)

jorenheaderfilesdir=$(includedir)/joren
nobase_jorenheaderfiles_HEADERS=$(JOREN_HEADERFILES)

EXTRA_DIST=gencov
