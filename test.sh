#!/bin/bash
clear

gcc -std=c17 -x c -Wextra -g \
    "$1".test.c "$1".c test.h \
    -o ./build/test/main &&\
        ./build/test/main

