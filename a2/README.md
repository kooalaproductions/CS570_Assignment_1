# CS570_Assignment_1

Project will create a microshell that will parse commands to emulate a linux shell

Account cssc2123 is available for testing.

## Team Members

Jasmine Nelson RedID: 820233707 (cssc2157)

Ernesto Sanchez RedID: 819323499 (cssc2123)

### Class Information

CS570, Summer 2020

### Assignment Information

Assignment #2, Microshell

### Filename

README

### File Manifest

msh.c

msh.h

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


### List of tools not required in Assignment

We used all the tools at our disposal required by the Assignment

### List of deficiencies or bugs

There is none

## Lesson Learned

We learned the importance of parsing user input in order to execute specific arguments and also the capabilities a linux shell has to offer.

