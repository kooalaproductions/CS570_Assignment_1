#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
FILE *fp;
fp=fopen("QUOTE.txt","w");//opening file

fprintf(fp, "PID: %d\n", getpid());//write PID to file
fclose(fp);//closing file
return 0;
}
