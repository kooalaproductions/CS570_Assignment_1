#include <stdio.h>
#include <stdlib.h>

int main(){
FILE *fp;
fp=fopen("QUOTE.txt","w");
fclose(fp);
return 0;
}
