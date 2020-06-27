/*
Jasmine Nelson RedID: 820233707 (cssc2157)
Ernesto Sanchez RedID: 819323499 (cssc2123)

CS570, Summer 2020
Professor Leonard

Assignment #2, Microshell
msh.c file
*/


#include "msh.h"

#define DELIM " \n"


char *getlogin();
void exit(int status);
int run = 1;
int result;
char *line = NULL;
size_t lineSize = 0;
char *argsTwo[10];

void parseLine(char *line, char *tokens[]){//parse line entered
    int index = 0;
    int size = 100;

    char *token = strtok(line, DELIM);//gets first token

    while(token != NULL){
        if(size <= index){//if index is greater than the size, allocate more space
             tokens = realloc(tokens, size * sizeof(char*));
        }
        tokens[index] = token;
        index++;
        token = strtok(NULL, " ");
    }

}

void execute(char *cmdArgs[]){
    if(execvp(*cmdArgs, cmdArgs) <0){//checks if file name is executable
        printf("File name is not executable, please enter a new file name.\n");
    }

    size_t cmdSize = sizeof(cmdArgs)/sizeof(cmdArgs[0]);

    printf("%d\n",cmdSize);//im not sure why the size is 1
        int i;
        for (i=0;i < (sizeof (cmdArgs) /sizeof (cmdArgs[0]));i++) {
            printf("%lf\n",cmdArgs[i]);
        }



}


char micro_loop(){
    char *userName;



    userName = (char *)malloc(10*sizeof(char));
    userName = getlogin();


    while(run){//loop runs forever

        printf("%s%% ", userName);//prints out the current username cssc9999%
        line = (char *)malloc(lineSize * sizeof(char));
        if(getline(&line,&lineSize,stdin) == -1){//grabs what the user enters and assigns it to variable line
            exit(0);
        }

        parseLine(line, argsTwo);
        if(strcmp(argsTwo[0], "exit") == 0){//If user enters 'exit', end microshell
            exit(0);
        }

        execute(argsTwo);
//        if(argsTwo[0] == "exit"){
//            printf("exiting msh");
//            exit(0);
//    }
//        printf("%s\n", argsTwo[0]);
//        printf("%s\n", argsTwo[1]);
//        printf("%s\n", argsTwo[2]);

        }

    }




int main(int argc, char **argv){
    micro_loop();//call continues loop

    }
