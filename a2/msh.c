/*
Jasmine Nelson RedID: 820233707 (cssc2157)
Ernesto Sanchez RedID: 819323499 (cssc2123)

CS570, Summer 2020
Professor Leonard

Assignment #2, Microshell
msh.c file
*/


#include "msh.h"

//static char line[1024];
char *getlogin();
void exit(int status);
int run = 1;
int result;
char *line = NULL;
size_t lineSize = 0;
char **args;

char **parseLine(char *line){
    int size = 64;
    int address = 0;
     char **tokens = malloc(size * sizeof(char*));
     char * token = strtok(line, " ");

     while( token != NULL ) {
      tokens[address] = token;
        address++;

    if (address >= size) {
      size += 64;
      tokens = realloc(tokens, size * sizeof(char*));
          if (!tokens) {
            exit(0);
          }
    }

    token = strtok(NULL, " ");//parse by white space

   }
   tokens[address] = NULL;

   return tokens;

}

char micro_loop(){
    char *userName;


    userName = (char *)malloc(10*sizeof(char));
    userName = getlogin();


    while(run){//loop runs forever

        printf("%s%% ", userName);
        line = (char *)malloc(lineSize * sizeof(char));
        if(getline(&line,&lineSize,stdin) == -1){
            exit(0);
        }

        args = parseLine(line);
        printf("%s\n", args[0]);
         printf("%s\n", args[1]);
           printf("%s\n", args[2]);

        }

    }




int main(int argc, char **argv){
    micro_loop();

    }
