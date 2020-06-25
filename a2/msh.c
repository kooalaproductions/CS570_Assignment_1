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
int run = 1;

    char micro_loop(){
    char *buf;
        buf = (char *)malloc(10*sizeof(char));
        buf = getlogin();


        while(run){

           printf("%s%%", buf);
            fflush(NULL);

           if(!fgets(line, 1024, stdin)){//variable line has what the user entered
                return 0;
           }

            printf("%s", line);

        }

    }

    int main(int argc, char **argv){
        micro_loop();

    }
