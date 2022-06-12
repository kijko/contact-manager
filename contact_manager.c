#include <stdlib.h>

#include "cmd_interpreter.h"

char * cm_run(short cmd) {
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


