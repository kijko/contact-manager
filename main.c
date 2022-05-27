#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkedlist.h"

#define CMD_BUFFER 64
#define UNDEF_CMD 0
#define QUIT 1
#define LIST 2


char * execute(const int cmd);
int parsecmd(char *cmd);

int main(int argc, char *argv[]) {
    int exitcode = 0, cmdcode = 0;
    char cmd[CMD_BUFFER];
    char *result;
    
    //struct linkedlist *l = newll(intcmp);
    //addtoll(l, (void *) &a);
    //addtoll(l, (void *) &b);
    //addtoll(l, (void *) &c);
    //addtoll(l, (void *) &d);
    
    //utilizell(l);
    while (1) {
        printf("> ");
        scanf("%s", cmd);

        cmdcode = parsecmd(cmd);
        switch (cmdcode) {
            case UNDEF_CMD:
                printf("HELP PLACEHOLDER\n");
                break;

            case QUIT:
                printf("bye, bye\n");
                break;

            default:
                result = execute(cmdcode);
                printf("%s\n", result);
                free(result);
        }

        if (cmdcode == QUIT) {
            break;
        }
    }

    return exitcode;
}


char * execute(const int cmd) { // cmd > 1
    char *message, *msg;
    switch (cmd) {
        case LIST:
            message = "listing...";
            msg = (char *) malloc(10);

            for (int i = 0; i < 10; i++) {
                msg[i] = message[i];
            }            

            return msg;

        default:
            message = "x";
            msg = (char *) malloc(1);

            for (int i = 0; i < 1; i++) {
                msg[i] = message[i];
            }            

            return msg;
    }
}

int parsecmd(char *cmd) {
    char *quital[] = { "q", "quit", "exit", "ex", "end" };
    for (int i = 0; i < 4; i++) {
        if (strcmp(quital[i], cmd) == 0) {
            return QUIT;
        }
    }

    char *listal[] = { "list", "ls", "lst", "l" };
    for (int i = 0; i < 4; i++) {
        if (strcmp(listal[i], cmd) == 0) {
            return LIST;
        }
    }
    
    return UNDEF_CMD;
}


