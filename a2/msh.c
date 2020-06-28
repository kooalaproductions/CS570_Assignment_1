/*
Jasmine Nelson RedID: 820233707 (cssc2157)
Ernesto Sanchez RedID: 819323499 (cssc2123)

CS570, Summer 2020
Professor Leonard

Assignment #2, Microshell
msh.c file
*/


#include "msh.h"

#define DELIM " "


char *getlogin();
void exit(int status);
int run = 1;
int result;
char *line = NULL;
size_t lineSize = 0;
char **argsTwo;
char **args;
int cmdSize;
char *userName;
char *c;

char **parseLine(char *line, char **tokens){//parse line entered

    int index = 0;
    int size = 100;
    tokens = malloc(size * sizeof(char*));

    char *token = strtok(line, DELIM);//gets first token
    printf("In parse line\n");

    while(token != NULL){
        if(size <= index){//if index is greater than the size, allocate more space
             tokens = realloc(tokens, size * sizeof(char*));
        }
        tokens[index] = token;
        index++;
        token = strtok(NULL, " ");
        cmdSize++;
    }
    tokens[index] = NULL;
    printf("Success parse line\n");

    return tokens;


}

int execute(char **cmdArgs){

    pid_t child_pid;
    int stat_loc;
    child_pid = fork();
    printf("in Execute\n");

    if(child_pid == 0){
        if(execvp(cmdArgs[0], cmdArgs) <0){//checks if file name is executable
            printf("File name is not executable, please enter a new file name.\n");
            exit(0);
        }
    }
    else{
        waitpid(child_pid, &stat_loc, WUNTRACED);
    }

    return 1;


}

int  in_out(int in, int out, char *cmd[]){
  pid_t pid;

  return pid;
}
int pipes (int cmdSize, char *cmd[]){

}


char micro_loop(){
    userName = (char *)malloc(10*sizeof(char));
    userName = getlogin();


    while(run){//loop runs forever
//        line = readline("unix> ");
//        line = line = malloc(lineSize * sizeof(char));


        printf("%s%% ", userName);//prints out the current username cssc9999%
        line = malloc(lineSize * sizeof(char));
        if(getline(&line,&lineSize,stdin) == -1){//grabs what the user enters and assigns it to variable line
            exit(0);
        }
        printf("User entered: %s", line);

        if((c=strchr(line,'\n'))!= NULL)*c='\0';
        args = parseLine(line, args);

        if(strcmp(args[0], "exit") == 0){//If user enters 'exit', end microshell
//            kill(0, SIGINT);
            exit(0);
        }


       run = execute(args);

        free(line);
        free(args);

        }
        return 0;

    }




int main(int argc, char **argv){
    micro_loop();//call continues loop

    }
