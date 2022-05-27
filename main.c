#include <stdio.h>
#include <string.h>

#define UNDEF_CMD 0
#define LIST 1


void printhelp();
int execute(const int cmd);
int parsecmd(char *cmd);

int main(int argc, char *argv[]) {
    int exitcode = 0;
    if (argc > 1) {
        int cmd = parsecmd(argv[1]);
        if (cmd > 0) {
            exitcode = execute(cmd);
        } else {
            printhelp();
        }
    } else {
        printhelp();
    }

    return exitcode;
}


int execute(const int cmd) { // cmd > 0
    switch (cmd) {
        case LIST:
            printf("listing... \n");
            break;
    }
}

int parsecmd(char *cmd) {
    char *listal[] = { "list", "ls", "lst", "l" };
    for (int i = 0; i < 4; i++) {
        if (strcmp(listal[i], cmd) == 0) {
            return LIST;
        }
    }
    
    return UNDEF_CMD;
}

void printhelp() {
    printf("HELP PLACEHOLDER");
}

