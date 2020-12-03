AUTOMAKE_OPTIONS = foreign subdir-objects

ACLOCAL_AMFLAGS = -I m4

AUX_DIST_GEN = $(ac_aux_dir)

EXTRA_DIST = $(AUX_DIST_GEN) libjoren-1.0.pc.in
MAINTAINERCLEANFILES = $(AUX_DIST_GEN)

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = libjoren-1.0.pc

$(pkgconfig_DATA) : config.status

SUBDIRS=src
