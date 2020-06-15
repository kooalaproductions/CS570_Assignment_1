# CS570_Assignment_1

Project will manage multiple threads written to a shared file.

## Team Members

Jasmine Nelson (cssc2157)

Ernesto Sanchez (cssc2123)

### Class Information

CS570, Summer 2020

### Assignment Information

Assignment #1, Write to File Using Threads

### Filename

README

### File Manifest

bots.c

bots.h

README

QOUTE.txt

Makefile

### Compile Instructions

How to compile:

```
make

./bots


```

To clean up and remove object files:

```
make clean

``


### Operating Instructions

If error: linker command not found for architecture x86_64

```
gcc -c bots.c

make
```

This will result in:

```
Simple compiler name bots has been compiled
```



## List of Decisions

We decided to approach this assingment step-by-step starting with getting the pid and printing to the QOUTE.txt. Since threads and semaphores were an unfamiliar topic
we researched POSIX documentation to figure out how to create threads and implement them. In order for our threads to run simultaneously we reasearched how to use semaphores to block/wait threads so that they
do not interrupt each other when printing to the file. We then categorized each thread as odd or even due to their thread id and as such a qoute was appendended in reference to their parity. According to how long
each thread sleeps for, we calculated when each thread wrote to the file, and determined the output.


### List of tools not required in Assignment

We used all the tools at our disposal required by the Assignment

### List of deficiencies or bugs

There is none

## Lesson Learned

By using threads we learned how to write to a file cuncurrently with the help of semaphores. Additionally, we learned the POSIX system calls for creating and managing the semaphores and threads.

