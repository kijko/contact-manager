#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "cmd_interpreter.h"
#include "contact_manager.h"

#define BUFFER_LEN 64

int main(int argc, char *argv[]) {
    char buffer[BUFFER_LEN], *result;
    short cmd;

    while (1) {
        printf("> ");
        scanf("%s", buffer);

        cmd = interpret_cmd(buffer, BUFFER_LEN);
        
        if (cmd == QUIT_CMD) {
            printf("bye, bye\n");
            break;
        } else {
            result = cm_run(cmd);
            printf("%s\n", result);

            free(result);
        }
    }

    return 0;
}

