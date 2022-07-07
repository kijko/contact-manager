#include <stdlib.h>
#include <stdio.h>

#include "cmd_interpreter.h"

char * cm_run(short cmd, short argc, char **args) {
    printf("cmd_id: %d, arg_count: %d, args: ", cmd, argc);
    for (int i = 0; i < argc; i++) printf("%s, ", args[i]);
    printf("\n");

    char *result;

    switch (cmd) {
        case LIST_CMD:
            result = (char *) malloc(8);
            result[0] = 'l';
            result[1] = 'i';
            result[2] = 's';
            result[3] = 't';
            result[4] = '.';
            result[5] = '.';
            result[6] = '.';
            result[7] = '\0';

            return result;

        default:
            result = (char *) malloc(8);
            result[0] = 'h';
            result[1] = 'e';
            result[2] = 'l';
            result[3] = 'p';
            result[4] = '.';
            result[5] = '.';
            result[6] = '.';
            result[7] = '\0';

            return result;
    }
}


