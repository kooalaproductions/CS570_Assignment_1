# CS570_Assignment_1

Project will create a management of threads.

Account cssc2123 is available for testing.

## Team Members

Jasmine Nelson RedID: 820233707 (cssc2157)

Ernesto Sanchez RedID: 819323499 (cssc2123)

### Class Information

CS570, Summer 2020

### Assignment Information

Assignment #3, Management of Threads

### Filename

README

### File Manifest

mot.c

mot.h

README

Makefile

### Compile Instructions

```
make all
```

This will create a executable file named msh


### Operating Instructions

How to compile:

```
make all

./msh

```

To clean up and remove object files:

```
make clean

```

This will remove msh.o, and msh


## List of Decisions

Our first step was to determine how to print a continues loop with current username. Once we established our while loop we
then proceeded to parsing user input into tokens. We used the delimiter "\n" and white-space to correctly parse our tokens.
Parsing user input allowed us to create the argument "exit", when user enters the "exit" our program will terminate. The next step
was to determine if the user input is a qualifies path name using exec. Finally, we created the argument pipe to created any number of processes
to communicate with each other.

## Task assigned

Jasmine Nelson RedID: 820233707 (cssc2157):
- char **parseLinePipe(char *line, char **tokens)
- void execute(char *cmdArgs[])
- int executePipe(int n, struct command *cmd)

Ernesto Sanchez RedID: 819323499 (cssc2123):
- char micro_loop()
- void execute(char *cmdArgs[])
- char **parseLineSpace(char *line, char **tokens)


### List of tools not required in Assignment

We used all the tools at our disposal required by the Assignment

### List of deficiencies or bugs

We were able to successfully pipe commands of two and three arguments, however, we had troubles finding a way to do an unlimited amount of arguments.
Also, after the executePipe() function completes we were unable to loop so that more commands could be entered. We think it is because the execvp terminates
the entire program's process. The following pipe command works, "exectablefilename | executablefilename" but fails with "executablefilename argument | executablefilename argument".
We were unsure how to construct the required valid input formats because the assignment was unclear if we needed to implement input formats aside from the ones stated on the assignment.

## Lesson Learned

We learned the importance of parsing user input in order to execute specific arguments and also the capabilities a linux shell has to offer.

