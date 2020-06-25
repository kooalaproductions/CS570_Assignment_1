#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int input(char *s,int length);

int main()
{
    char *buffer;
    char str[1000];
    size_t bufsize = 32;
    size_t characters;

    buffer = (char *)malloc(bufsize * sizeof(char));
    if( buffer == NULL)
    {
        perror("Unable to allocate buffer");
        exit(1);
    }

    printf("Type something: ");
    characters = getline(&buffer,&bufsize,stdin);
    printf("%zu characters were read.\n",characters);
    printf("You typed: '%s'\n",buffer);
    printf("%s",str);
    if(str == "exit"){
        printf("Family GUY!!");
    }

    return(0);
}
