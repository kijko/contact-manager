#include <stdio.h>
#include "test.h"

#include "cmd_interpreter.h"

int tests_run = 0;
 
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

    int list1 = interpret_cmd("list", buffer_len);
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


static char * random_string__interpret_cmd__undef_cmd() {
    int buffer_len = 64;

    int result1 = interpret_cmd("ptaki latajo kluczem", buffer_len);
    int result2 = interpret_cmd("asdasfadfasd", buffer_len);

    assert("err1: expected UNDEF_CMD", result1 == UNDEF_CMD);
    assert("err2: expected UNDEF_CMD", result2 == UNDEF_CMD);
    
    return 0;
}



// ----------------------------------------------------------



static char * all_tests() {
    run_test(empty_buffer__interpret_cmd__undef_cmd);
    run_test(buffer_overflow__interpret_cmd__buffer_overflow);
    run_test(list_cmd_alias__interpret_cmd__list_cmd);
    run_test(quit_cmd_alias__interpret_cmd__quit_cmd);
    run_test(random_string__interpret_cmd__undef_cmd);

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

