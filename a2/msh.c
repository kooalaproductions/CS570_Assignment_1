/*
Jasmine Nelson RedID: 820233707 (cssc2157)
Ernesto Sanchez RedID: 819323499 (cssc2123)

CS570, Summer 2020
Professor Leonard

Assignment #2, Microshell
msh.c file
*/


#include "msh.h"

static char line[1024];
char *getlogin();
void exit(int status);
int run = 1;
int result;

    char micro_loop(){
    char *buf;
        buf = (char *)malloc(10*sizeof(char));
        buf = getlogin();


        while(run){//loop runs forever

           printf("%s%%", buf);
            fflush(NULL);

           if(!fgets(line, 1024, stdin)){//variable line has what the user entered
                return 0;
           }

           line[strlen(line)-1] = '\0';//remove null terminator
                result = strcmp(line, "exit");
                if(result == 0){// if line and exit match then exit program
                        exit(0);

                }
        }

    }

    int main(int argc, char **argv){
        micro_loop();

    }
