#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "cmd_interpreter.h"
#include "linkedlist.h"

#define RESULT_BYTES_PER_LIST_ROW 100

static const char *ADD_MSG_PATTERN = "'%s' has been added\n";
static const char *LIST_ITEM_MSG_PATTERN = "%d. %s\n";
static struct linkedlist *store = NULL;

void cm_init() {
    store = newll(stringcmp);
}

void cm_destroy() {
    utilizell(store);
    store = NULL;
}

char * cm_run(short cmd, short argc, char **args) {
//    printf("DEBUG --- cmd: %d, argc: %d\n", cmd, argc);
 //   for (int i = 0; i < argc; i++) printf("DEBUG --- args[%d]: %s\n", i, args[i]);

    char *result;

    switch (cmd) {
        case ADD_CMD: {
            addtoll(store, (void *) args[0]);

            size_t result_size = (strlen(args[0]) + (strlen(ADD_MSG_PATTERN) - 2)) * sizeof(char) + 1;
            result = malloc(result_size);
            
            sprintf(result, ADD_MSG_PATTERN, args[0]);
            
            return result;
        }

        case LIST_CMD: {
            int count = 0;
            struct node *curr = store->first;
            while (curr != NULL) {
                count++;
                curr = (*curr).next;
            }
            
//            printf("DEBUG --- num of elements %d\n", count);

            if (count > 0) {
                int result_size = count * RESULT_BYTES_PER_LIST_ROW * sizeof(char);
                result = malloc(result_size);
                
                result[0] = '\0';
                
                char num_str[1000];
                int i = 0;
                curr = store->first;
                while (curr != NULL) {
                    i++;
                    sprintf(num_str, "%d. ", i);
                    strcat(result, num_str);                    

                    char *curr_value = (char *) curr->value;                    
                    strcat(result, curr_value);

                    strcat(result, "\n");
                    
                    curr = (*curr).next;
                }
                
            } else {
                result = malloc(1 * sizeof(char));
                result[0] = '\0';
            }

            return result;
        }

        default: {
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
}


