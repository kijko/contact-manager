#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "cmd_interpreter.h"

const char *LIST_CMD_ALIASES[] = { "list", "ls", "l", "\0" };
const char *QUIT_CMD_ALIASES[] = { "quit", "q", "exit", "end", "\0" };

int is_cmd(char *cmd_buffer, const char **aliases);

// returns -1 if incorrect buffer
short count_input(char *buffer, short buffer_len);


short interpret_cmd(char *buffer, short buffer_len) {
    if (buffer_len == 0) {
        return UNDEF_CMD;
    }

    short input_len = count_input(buffer, buffer_len);

    short result;
    if (input_len > 0) {
        struct statement *s = parse_statement(buffer, input_len);        

        if (s != NULL) {
            if (is_cmd((s->cmd), LIST_CMD_ALIASES)) result = LIST_CMD;
            if (is_cmd((s->cmd), QUIT_CMD_ALIASES)) result = QUIT_CMD;
        }

        free_statement(s);
        result = UNDEF_CMD;
    } else {
        result = BUFFER_OVERFLOW_CMD;
    }

    return result;
}

short count_input(char *buffer, short buffer_len) {
    int input_len = 0;
    int has_ending = 0;
    for (int i = 0; i < buffer_len; i++) {
        input_len++;
        if (buffer[i] == '\0') {
            has_ending = 1;
            
            break;
        }
    }

    return has_ending ? input_len : -1; 
}

struct statement * parse_statement(char *buffer, short input_len) {
    // finished here. Make "cmd arg1 arg2" to ["cmd", "arg1", "arg2"]
    
    struct statement *s = (struct statement *) malloc(sizeof(struct statement));
    s->cmd = (char *) malloc(64 * sizeof(char));
    s->args = (char **) malloc(64 * sizeof(char *));
    for (int i = 0; i < 64; i++) {
        (s->args)[i] = (char *) malloc(64 * sizeof(char));
    }

    int start = 0, end = 0, args_index = 0;
    for (int i = 0; i < input_len; i++) {
        if (buffer[i] == ' ' || buffer[i] == '\0') {
            end = i;
            
            int current_char = 0;
            for (int j = start; j < end; j++) {
                if (start == 0) {

                    (s->cmd)[j] = buffer[j];
                    if (j + 1 == end) (s->cmd)[j + 1] = '\0';

                } else {
                    (s->args)[args_index][current_char] = buffer[j];
                    current_char++;
                    if (j + 1 == end) {
                        (s->args)[args_index][current_char] = '\0';
                        current_char++;
                    }
                }
            }

            if (current_char > 0 && i != (input_len - 1)) args_index++;
            
            start = end + 1;
        }
    }

    (s->args_count) = args_index + 1;

    return s;
}

void free_statement(struct statement *s) {
        free(s->cmd);
        for (int i = 0; i < 64; i++) {
            free((s->args)[i]);
        }
        free(s->args);

        free(s);
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

char ** interpret_args(char *buffer, short buffer_len) {
    if (buffer_len == 0) {
        return NULL;
    }

    return NULL;
}

