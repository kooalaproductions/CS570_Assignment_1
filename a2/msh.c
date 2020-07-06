/*
Jasmine Nelson RedID: 820233707 (cssc2157)
Ernesto Sanchez RedID: 819323499 (cssc2123)

CS570, Summer 2020
Professor Leonard

Assignment #2, Microshell
msh.c file
*/

#include "msh.h"


char *getlogin();
void exit(int status);
int run = 1;
int result;
char *line = NULL;
size_t lineSize = 0;
char **args;
int cmdSize;
char *userName;
char *c;
char *cmd[2];
pid_t pid;


struct arguments{
  const char **cmdArgs;
};

/**
executionPipe() takes in the arguments and creates processes in order to connect them and execute them.
**/
static int executePipe(int n, struct arguments *cmd){
static int loop = 1;
  int i;

  int in;
  int fd [2];

  in = 0;

  for (i = 0; i < n - 1; i++)
    {
      pipe (fd);
      pid_t pid;

      if ((pid = fork ()) == 0){

          if (in != 0){
              dup2 (in, 0);

              close (in);

          }

          if (fd[1] != 1) {

              dup2 (fd[1], 1);
              close (fd[1]);

          }

            if (execvp(cmd->cmdArgs [0], (char * const *)cmd->cmdArgs) < 0){
                return 0;
            }
            else{
                continue;
            }
          }

          close (fd [1]);
          in = fd [0];
      }

      if (in != 0) {
        dup2 (in, 0);
      }

        if(execvp(cmd [i].cmdArgs [0], (char * const *)cmd [i].cmdArgs) < 0){
             return 0;
        }
        else{
            return 1;
        }

 return loop;
}
/**
parseLinePipe() handles the parsing of pipe delimiters in order to execute input commands.
**/
char **parseLinePipe(char *line, char **tokens){
  int index = 0;
  int size = 100;
  cmdSize = 0;
  tokens = malloc(size * sizeof(char*));

  char *token = strtok(line, DELIM);

  while(token != NULL){
    if(size <= index){
      tokens = realloc(tokens, size * sizeof(char*));
    }
    tokens[index] = token;

    index++;
    token = strtok(NULL, DELIM);
    cmdSize++;
  }

  return tokens;
}

/**
parseLine() has the parameters line and tokes since it is taking the user input and returning it as tokens. The delimiter of tokens is defined as white-space and will continuously parse until it reaches the end of user input.
**/
char **parseLineSpace(char *line, char **tokens){//parse line entered

    int index = 0;
    int size = 100;
    cmdSize = 0;
    tokens = malloc(size * sizeof(char*));

    char *token = strtok(line, " ");//gets first token

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

/**
execute() is in charge of executing an executable filename. In this method we create multiple child process for each cmd entered by user.
If it is successful it will return 1 in order for the microshell to continue running its while loop.
**/
int execute(char **cmdArgs){

    pid_t child_pid;
    int status;
    child_pid = fork();

    if(child_pid == 0){
        if(execvp(cmdArgs[0], cmdArgs) < 0){//checks if file name is executable
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


    userName = (char *)malloc(10*sizeof(char));
    userName = getlogin();

    int isFirstCommand = 1;


    while(run){//loop runs forever

      printf("%s%% ", userName);//prints out the current username cssc9999%
      line = malloc(lineSize * sizeof(char));
      if(getline(&line,&lineSize,stdin) == -1){//grabs what the user enters and assigns it to variable line
          exit(0);
      }

      if((c=strchr(line,'\n'))!= NULL)*c='\0';


      if(strchr(line, '|') != NULL){

          args = parseLinePipe(line,args);

          const char *firstArg[] = {args[0], 0};
          const char *secondArg[] = {args[1], 0};
          const char *thirdArg[] = {args[2], 0};


          struct arguments cmd [] = { {firstArg}, {secondArg}, {thirdArg} };


            run = executePipe(cmdSize, cmd);
            printf("1-does it get here");


      } else {


        args = parseLineSpace(line, args);
        if(strcmp(args[0], "exit") == 0){//If user enters 'exit', end microshell
          exit(0);
        } else {
          run = execute(args);
        }
      }

      free(line);

    }
    return 0;
}

/**
main() runs micro_loop()
**/
int main(int argc, char **argv){

    micro_loop();//call continues loop
    return 0;
}
