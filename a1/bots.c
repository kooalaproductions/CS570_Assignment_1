/*
Jasmine Nelson (cssc2157)
Ernesto Sanchez (cssc2123)

CS570, Summer 2020
Professor Leonard

Assignment #1, Write to File Using Threads
bots.c file
*/


#include "bots.h"

int main(){
FILE *fp;
fp=fopen("QUOTE.txt","w");//opening file

fprintf(fp, "PID: %d\r \n", getpid());//write PID to file
fclose(fp);//closing file
return 0;
}
