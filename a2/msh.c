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

    int main(){

        while(1){
            printf("cssc9999%% ");
            fflush(NULL);

            if(!fgets(line, 1024, stdin)){
                return 0;
            }
        }

    }
