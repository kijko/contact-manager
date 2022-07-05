
#define BUFFER_OVERFLOW_CMD -1
#define UNDEF_CMD 0
#define QUIT_CMD 1

#define LIST_CMD 2 

// returns code of an cmd or 0(UNDEF_CMD) if command not recognized
short interpret_cmd(char *buffer, short buffer_len);



struct statement {
    char *cmd;
    char **args;
    short args_count;
};

// returns array of args or NULL when no args found in buffer
struct statement * interpret_args(char *buffer, short buffer_len);

// parses buffer string to strings array. Input length includes '\0'
// NULL if incorrect
struct statement * parse_statement(char *buffer, short input_len);
void free_statement(struct statement *s);


