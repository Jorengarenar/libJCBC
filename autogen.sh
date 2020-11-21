#!/usr/bin/env sh

mkdir -p autotools

aclocal
libtoolize
autoheader
automake -a
autoconf
automake -a

if [ "$1" = "--XDG" ]; then
    XDG_INCLUDE_DIR="${XDG_INCLUDE_DIR:-$HOME/.local/include}"
    XDG_LIB_DIR="${XDG_LIB_DIR:-$HOME/.local/lib}"
    ./configure \
        --includedir=$XDG_INCLUDE_DIR/c \
        --libdir=$XDG_LIB_DIR/c
else
    ./configure "$@"
fi
