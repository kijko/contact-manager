#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

#include "test.h"

#include "contact_manager.h"
#include "cmd_interpreter.h"

int tests_run = 0;
 
static char * add_list_remove() {
    // GIVEN
    cm_init();

    // AND 
    char *contact = "Maciek - 000 000 000";
    char *args[1];
    args[0] = contact;

    // WHEN - THEN 1
    char *add_result = cm_run(ADD_CMD, 1, args);
    assert("add_list_remove[0]", strcmp(add_result, "'Maciek - 000 000 000' has been added\n") == 0);
    
    free(add_result);
    
    // WHEN - THEN 2
    char *get_result = cm_run(LIST_CMD, 0, NULL);
    printf("%s", get_result);
    assert("add_list_remove[1]", strcmp(get_result, "1. Maciek - 000 000 000\n") == 0);

    // WHEN - THEN 3
    char *remove_result = cm_run(REMOVE_CMD, 1, args);
    assert("add_list_remove[2]", strcmp(remove_result, "'Maciek - 000 000 000' has been deleted\n") == 0);

    // FINALLY
    cm_destroy();    

    return 0;
}

static char * all_tests() {
    run_test(add_list_remove);

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

