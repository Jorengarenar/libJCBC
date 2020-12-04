#!/usr/bin/env sh

mkdir -p autotools m4 build

autoreconf -if

if [ -z "$NOCONFIGURE" ]; then
    cd build
    if [ "$1" = "--XDG" ]; then
        ARGS="--includedir=${XDG_INCLUDE_DIR:-$HOME/.local/include}/c"
        ARGS="$ARGS --libdir=${XDG_LIB_DIR:-$HOME/.local/lib}/c"
        shift 1
    fi
    ../configure $ARGS "$@"
fi
