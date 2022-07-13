#!/bin/bash

gcc -std=c17 -x c -Wextra -g \
main.c \
cmd_interpreter.c \
contact_manager.c \
linkedlist.c \
-o ./build/main

