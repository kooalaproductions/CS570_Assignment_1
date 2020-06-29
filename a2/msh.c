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
char *line = NULL;
size_t lineSize = 0;
char **args;
int cmdSize = 1;
char *userName;
char *c;


int parsePipe(char *line, char **tokens){
    int k;
    for(k = 0; k < 3; k++){
        tokens[k] = strsep(&line, "|");
        if(tokens[k] == NULL){
            break;
        }
    }

    if (tokens[1] == NULL){//if no pipe found return 0
        return 0;
    }
    else {
        return 1;
    }

}

/**
parseLine() has the parameters line and tokes since it is taking the user input and returning it as tokens. The delimiter of tokens is defined as white-space
and will continuously parse until it reaches the end of user input.
**/
char **parseLine(char *line, char **tokens){//parse line entered

    int index = 0;
    int size = 100;
    tokens = malloc(size * sizeof(char*));

    char *token = strtok(line, DELIM);//gets first token

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

    return tokens;

}
void executePipe(char** parsed, char** parsedpipe){

	int pipefd[3];
	pid_t p1, p2, p3;

	if (pipe(pipefd) < 0) {
		printf("\nPipe could not be initialized");
		return;
	}



	p1 = fork();
	if (p1 < 0) {
		printf("\nCould not fork");
		return;
	}

	if (p1 == 0) {

		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);

		if (execvp(parsed[0], parsed) < 0) {
			printf("\nCould not execute command 1..");
			exit(0);
		}
	}
	if(p2 == 0) {
		p2 = fork();

		if (p2 < 0) {
			printf("\nCould not fork");
			return;
		}

		if (p2 == 0) {
			close(pipefd[1]);
			dup2(pipefd[0], STDIN_FILENO);
			close(pipefd[0]);
			if (execvp(parsedpipe[0], parsedpipe) < 0) {
				printf("\nCould not execute command 2..");
				exit(0);
			}
		}
	}

	else{
            p3 = fork();

		if (p3 < 0) {
			printf("\nCould not fork");
			return;
		}

		if (p3 == 0) {
			close(pipefd[2]);
			dup2(pipefd[1], STDIN_FILENO);
			close(pipefd[1]);
			if (execvp(parsedpipe[1], parsedpipe) < 0) {
				printf("\nCould not execute command 3..");
				exit(0);
			}
		} else {
			wait(NULL);
			wait(NULL);
			wait(NULL);
		}

	}
}

/**
execute() is in charge of executing an executable filename. In this method we create multiple child process for each cmd entered by user.
If it is successful it will return 1 in order for the microshell to continue running its while loop.
**/
int execute(char **cmdArgs){

    pid_t child_pid;
    int status;
    child_pid = fork();

    if(child_pid == 0){
        if(execvp(cmdArgs[0], cmdArgs) <0){//checks if file name is executable
            printf("File name is not executable, please enter a new file name.\n");
            exit(0);
        }
    }
    else{
        waitpid(child_pid, &status, WUNTRACED);
    }

    return 1;


}


/**
micro_loop() is in charge of identifying the current user name and printing it such as cssc9999%. Getline will assign the entered argument or executable file name to
the variable line. Line will then be parsed to search for certain characters to emulate a shell. Once parsed line will return as a pointer args that the method will use
to string compare for the command "exit" in order to terminate the microshell. If exit is not found it will continue to the method execute() and finally it will free line and args.
**/
char micro_loop(){
    char* linePiped[3];
    int isPipe = 0;
    char* parsedArgsPiped[100];

    userName = (char *)malloc(10*sizeof(char));
    userName = getlogin();




    while(run){//loop runs forever

        printf("%s%% ", userName);//prints out the current username cssc9999%
        line = malloc(lineSize * sizeof(char));
        if(getline(&line,&lineSize,stdin) == -1){//grabs what the user enters and assigns it to variable line
            exit(0);
        }

        if((c=strchr(line,'\n'))!= NULL)*c='\0';//replaces the new line character with a null terminator

        isPipe = parsePipe(line, linePiped);

        if(isPipe){
            printf("there is a pipe\n");
            printf("%d\n", isPipe);

            parseLine(linePiped[0], args);
          parseLine(linePiped[1], args);
          parseLine(linePiped[2], args);

          printf("%s\n", linePiped[0]);
          printf("%s\n", linePiped[1]);
          printf("%s\n", linePiped[2]);

          executePipe(args, parsedArgsPiped);

        }

        else{
            args = parseLine(line, args);
        }

        if(strcmp(args[0], "exit") == 0){//If user enters 'exit', end microshell
            kill(0, SIGINT);
        }


       run = execute(args);

        free(line);
        free(args);

        }
        return 0;

    }



/**
main() runs micro_loop()
**/
int main(){
    micro_loop();//call continues loop


    }
