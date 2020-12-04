#!/usr/bin/env sh

mkdir -p autotools m4 build

autoreconf -if

if [ -z "$NOCONFIGURE" ]; then
    cd build
    ../configure "$@"
fi
