
#include "test.h"

char **get_input(char *);

int main() {
    char **command;
    char *input;
    pid_t child_pid;
    int stat_loc;
    char *userName;

    while (1) {
        userName = (char *)malloc(10*sizeof(char));
        userName = getlogin();
         printf("%s%% ", userName);//prints out the current username cssc9999%
        input = readline("");
        command = get_input(input);


        if (!command[0]) {      /* Handle empty commands */
            free(input);
            free(command);
            continue;
        }

        child_pid = fork();
        if (child_pid == 0) {
            /* Never returns if the call is successful */
            execvp(command[0], command);
            printf("This won't be printed if execvp is successul\n");
        } else {
            waitpid(child_pid, &stat_loc, WUNTRACED);
        }

        free(input);
        free(command);
    }

    return 0;
}

char **get_input(char *input) {
    char **command = malloc(8 * sizeof(char *));
    char *separator = " ";
    char *parsed;
    int index = 0;

    parsed = strtok(input, separator);
    while (parsed != NULL) {
        command[index] = parsed;
        index++;

        parsed = strtok(NULL, separator);
    }

    command[index] = NULL;
    return command;
}