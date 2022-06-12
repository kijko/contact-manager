#include <stdio.h>
#include <string.h>
#include "cmd_interpreter.h"

const char *LIST_CMD_ALIASES[] = { "list", "ls", "l", "\0" };
const char *QUIT_CMD_ALIASES[] = { "quit", "q", "exit", "end", "\0" };

int is_cmd(char *cmd_buffer, const char **aliases);

short interpret_cmd(char *buffer, short buffer_len) {
    if (buffer_len == 0) {
        return UNDEF_CMD;
    }

    int cmd_len = 0;
    int has_ending = 0;
    for (int i = 1; i <= buffer_len; i++) {
        cmd_len++;
        if (buffer[i] == '\0') {
            has_ending = 1;
            break;
        }
    }

    if (cmd_len <= buffer_len && has_ending) {

        if (is_cmd(buffer, LIST_CMD_ALIASES)) return LIST_CMD;
        if (is_cmd(buffer, QUIT_CMD_ALIASES)) return QUIT_CMD;

        return UNDEF_CMD;

    } else {
        return BUFFER_OVERFLOW_CMD;
    }
}

int is_cmd(char *cmd_buffer, const char **aliases) {
    int i = 0;
    const char *alias = aliases[i], *break_str = "\0";

    while (strcmp(alias, break_str) != 0) {
        if (strcmp(alias, cmd_buffer) == 0) {
            return 1;
        }
        
        i++;
        alias = aliases[i];
    }
    
    return 0;
}

//    char *quital[] = { "q", "quit", "exit", "ex", "end" };
//    long unsigned int quitallen = sizeof(quital);
//    printf("%ld", quitallen);
//    for (int i = 0; i < quitallen; i++) {
//        if (strcmp(quital[i], cmd) == 0) {
//            return QUIT;
//        }
//    }


