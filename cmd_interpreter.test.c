#include <stdio.h>
#include <string.h> 

#include "test.h"
#include "cmd_interpreter.h"

int tests_run = 0;
 
// interpret_cmd

static char * empty_buffer__interpret_cmd__undef_cmd() {
    int buffer_len = 0;

    int cmd = interpret_cmd("", buffer_len);

    assert("err: expected UNDEF_CMD", cmd == UNDEF_CMD);
    
    return 0;
}


static char * buffer_overflow__interpret_cmd__buffer_overflow() {
    int buffer_len = 2;

    int cmd = interpret_cmd("list", buffer_len);

    assert("err: expected BUFFER_OVERFLOW_CMD", cmd == BUFFER_OVERFLOW_CMD);
    
    return 0;
}

static char * list_cmd_alias__interpret_cmd__list_cmd() {
    int buffer_len = 64;

    int list1 = interpret_cmd("list\n", buffer_len);
    int list2 = interpret_cmd("ls", buffer_len);
    int list3 = interpret_cmd("l", buffer_len);

    assert("err1: expected LIST_CMD", list1 == LIST_CMD);
    assert("err2: expected LIST_CMD", list2 == LIST_CMD);
    assert("err3: expected LIST_CMD", list3 == LIST_CMD);
    
    return 0;
}

static char * quit_cmd_alias__interpret_cmd__quit_cmd() {
    int buffer_len = 64;

    int result1 = interpret_cmd("quit", buffer_len);
    int result2 = interpret_cmd("q", buffer_len);
    int result3 = interpret_cmd("exit", buffer_len);
    int result4 = interpret_cmd("end", buffer_len);

    assert("err1: expected QUIT_CMD", result1 == QUIT_CMD);
    assert("err2: expected QUIT_CMD", result2 == QUIT_CMD);
    assert("err3: expected QUIT_CMD", result3 == QUIT_CMD);
    assert("err4: expected QUIT_CMD", result3 == QUIT_CMD);
    
    return 0;
}

static char * list_cmd_with_args__interpret_cmd__list_cmd() {
    int buffer_len = 64;

    int list1 = interpret_cmd("list asd dsa qwe \n", buffer_len);
    int list2 = interpret_cmd("ls\n", buffer_len);
    int list3 = interpret_cmd("l", buffer_len);

    assert("err1: expected LIST_CMD", list1 == LIST_CMD);
    assert("err2: expected LIST_CMD", list2 == LIST_CMD);
    assert("err3: expected LIST_CMD", list3 == LIST_CMD);
    
    return 0;
}


static char * random_string__interpret_cmd__undef_cmd() {
    int buffer_len = 64;

    int result1 = interpret_cmd("ptaki latajo kluczem", buffer_len);
    int result2 = interpret_cmd("asdasfadfasd", buffer_len);

    assert("err1: expected UNDEF_CMD", result1 == UNDEF_CMD);
    assert("err2: expected UNDEF_CMD", result2 == UNDEF_CMD);
    
    return 0;
}

// interpret_args

static char * empty_buffer__interpret_args__NULL() {
    struct statement *result = interpret_args("", 0);

    assert("err: empty_buffer__interpret_args__NULL", result == NULL);

    return 0;
}

static char * buffer_overflow__interpret_args__NULL() {
    struct statement *result = interpret_args("abc", 2);

    assert("err: buffer_overflow__interpret_args__NULL", result == NULL);

    return 0;
}

static char * cmd_with_two_args_string__interpret_args__2_args_array() {
    assert("err: cmd_with_two_args_string__interpret_args__2_args_array", 1 == 2);

    return 0;
}

static char * some_input__parse_statement__correct_args() {
    // GIVEN
    char *input = "cmd arg1 arg2";
    short input_len = 14;

    // WHEN
    struct statement *s = parse_statement(input, input_len);

    // THEN
    assert("parse_statement - some_input -> correct_args [1]", strcmp(s->cmd, "cmd") == 0);
    assert("parse_statement - some_input -> correct_args [2]", strcmp((s->args)[0], "arg1") == 0);
    assert("parse_statement - some_input -> correct_args [3]", strcmp((s->args)[1], "arg2") == 0);
    assert("parse_statement - some_input -> correct_args [4]", (s->args_count) == 2);

    // FINALLY
    free_statement(s);
}

static char * no_args__parse_statement__correct_args() {
    // GIVEN
    char *input = "cmd";
    short input_len = 4;

    // WHEN
    struct statement *s = parse_statement(input, input_len);

    // THEN
    assert("parse_statement - no_args -> correct_args [1]", strcmp(s->cmd, "cmd") == 0);
    assert("parse_statement - no_args -> correct_args [2]", (s->args_count) == 0);

    // FINALLY
    free_statement(s);
}

static char * whitespaces__parse_statement__rm_whitespaces() {
    // GIVEN
    char *input = "cmd\n";
    short input_len = 5;

    // WHEN
    struct statement *s = parse_statement(input, input_len);

    // THEN
    assert("parse_statement - whitespaces -> rm_whitespaces [1]", strcmp(s->cmd, "cmd") == 0);
    assert("parse_statement - whitespaces -> rm_whitespaces [2]", (s->args_count) == 0);

    // FINALLY
    free_statement(s);
}

// ----------------------------------------------------------



static char * all_tests() {
    run_test(empty_buffer__interpret_cmd__undef_cmd);
    run_test(buffer_overflow__interpret_cmd__buffer_overflow);
    run_test(list_cmd_alias__interpret_cmd__list_cmd);
    run_test(list_cmd_with_args__interpret_cmd__list_cmd);
    run_test(quit_cmd_alias__interpret_cmd__quit_cmd);
    run_test(random_string__interpret_cmd__undef_cmd);

    run_test(empty_buffer__interpret_args__NULL);
    run_test(buffer_overflow__interpret_args__NULL);
    run_test(cmd_with_two_args_string__interpret_args__2_args_array);

    run_test(some_input__parse_statement__correct_args);
    run_test(no_args__parse_statement__correct_args);
    run_test(whitespaces__parse_statement__rm_whitespaces);

    return 0;
}
 

int main() {
     char *result = all_tests();
     if (result != 0) {
         printf("%s\n", result);
     }
     else {
         printf("ALL TESTS PASSED\n");
     }
     printf("Tests run: %d\n", tests_run);
 
     return result != 0;
}

