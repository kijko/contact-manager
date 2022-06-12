#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkedlist.h"

#define CMD_BUFFER_LEN 64
#define UNDEF_CMD 0
#define QUIT 1
#define LIST 2

void execute(const int cmd);
int parsecmd(char *cmd);

struct linkedlist *l;

int main(int argc, char *argv[]) {
    int exitcode = 0, cmdcode = 0, cmdlen = 0;
    char cmdbuffer[CMD_BUFFER_LEN];
    char *cmd;

    l = newll(stringcmp);
    
    while (1) {
        printf("> ");
        scanf("%s", cmdbuffer);
        
        for (int i = 0; i < CMD_BUFFER_LEN; i++) {
            if (cmdbuffer[i] != '\0') {
                cmdlen++;
            } else {
                cmdlen++;
                break;
            }
        }

        printf("cmdlen: %d", cmdlen);

        if (cmdlen > 0) {
            cmd = (char *) malloc(cmdlen);
            for (int i = 0; i < CMD_BUFFER_LEN; i++) {
                if (cmdbuffer[i] == '\0') {
                    cmd[i] = cmdbuffer[i];
                    break;
                } else {
                    cmd[i] = cmdbuffer[i];
                }
            }
            
            printf("%s", cmd);
            

            cmdcode = parsecmd(cmd);
            switch (cmdcode) {
                case UNDEF_CMD:
                    printf("HELP PLACEHOLDER\n");
                    break;

                case QUIT:
                    printf("bye, bye\n");
                    break;

                default:
                    execute(cmdcode);
                    printf("\n");
            }

            if (cmdcode == QUIT) {
                break;
            }
        }

    }

    utilizell(l);
    return exitcode;
}


void execute(const int cmd) { // cmd > 1
    char *message, *msg;
    switch (cmd) {
        case LIST:
            printf("listing...");
            break;

        default:
            printf("not implemented");
    }
}

int parsecmd(char *cmd) {
    char *quital[] = { "q", "quit", "exit", "ex", "end" };
    long unsigned int quitallen = sizeof(quital);
    printf("%ld", quitallen);
    for (int i = 0; i < quitallen; i++) {
        if (strcmp(quital[i], cmd) == 0) {
            return QUIT;
        }
    }

    char *listal[] = { "list", "ls", "lst", "l" };
    int listallen = sizeof(listal);
    printf("%d", listallen);
    for (int i = 0; i < listallen; i++) {
        if (strcmp(listal[i], cmd) == 0) {
            return LIST;
        }
    }
    
    return UNDEF_CMD;
}


