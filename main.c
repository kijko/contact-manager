#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "cmd_interpreter.h"
#include "contact_manager.h"

#define BUFFER_LEN 64

int main(int argc, char *argv[]) {
    char buffer[BUFFER_LEN], *result, args_buffer[BUFFER_LEN];
    short cmd;
    struct statement *args;

    while (1) {
        printf("> ");
        fgets(buffer, BUFFER_LEN, stdin);

        cmd = interpret_cmd(buffer, BUFFER_LEN);
        args = interpret_args(args_buffer, BUFFER_LEN);
        
        if (cmd == QUIT_CMD) {
            printf("bye, bye\n");
            break;
        } else {
            result = cm_run(cmd, 3, NULL);
            printf("%s\n", result);

            free(result);
        }
        
        if (args != NULL) {
            free(args);
        }
    }

    return 0;
}

