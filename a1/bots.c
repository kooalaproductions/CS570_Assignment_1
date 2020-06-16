/*
Jasmine Nelson RedID: 820233707 (cssc2157)
Ernesto Sanchez RedID: 819323499 (cssc2123)

CS570, Summer 2020
Professor Leonard

Assignment #1, Write to File Using Threads
bots.c file
*/


#include "bots.h"


#define NUM_THREADS 7

sem_t FLAG;//semaphore for threads to use
FILE *fp;//file pointer
/**
ThreadDoesThis() function will utilize the semaphore to block/wait for all
the threads to complete their work. All threads created from the main() function
will be assigned a quote depending on their parity and print to QUOTE.txt periodically.
**/
void *ThreadDoesThis(void *ptr){

  int tid = 0;
  tid = (int)ptr;
  for(int j = 0; j < 8; j++){//iterate through threads
    if(tid % 2 == 0){//if thread id is even sleep(2)
      sleep(2);
    } else {//if thread is is odd sleep(3)
      sleep(3);
    }

    sem_wait(&FLAG);//wait semaphore

    printf("Thread %d is running\n", tid);//print out to console the running threads
    fp=fopen("QUOTE.txt","a");//append to file

    if(tid % 2 == 0){//if thread id is even
       fprintf(fp,"Thread %d: %cControlling complexity is the essence of computer programming.%c --Brian Kernigan\r \n", tid, '"', '"');
    } else{//if thread is is odd
        fprintf(fp,"Thread %d: %cComputer science is no more about computers than astronomy is about telescopes.%c --Edsger Dijkstra\r \n", tid, '"', '"');
    }

    fclose(fp);//close file

    sem_post(&FLAG);//release semaphore

  }
  pthread_exit(NULL);//terminates thread

}

/**
main() function will create threads and write to QUOTE.txt file.
By using the function ThreadDoesThis the function will distinguish
between the parity of thread ids.
**/
int main(void) {

  pid_t pid = getpid();
  fp=fopen("QUOTE.txt","w+");//opening file
  fprintf(fp, "PID: %d\r \n", pid);//writing pid to file
  fclose(fp);//closing file

  sem_init(&FLAG, 0 ,1);//initialize shared semaphore

  pthread_t threads[NUM_THREADS];
  for(int i = 1; i <= NUM_THREADS; i++){//creating necessary threads
    pthread_create(&threads[i], NULL, ThreadDoesThis, (void*)(size_t)i);
  }

  for(int i=1; i<= NUM_THREADS;i++){
    pthread_join(threads[i],NULL);//wait for threads to terminate and clean up resources
  }

  printf("Task completed! Please check QUOTE.txt.");
  sem_destroy(&FLAG);//destroy semaphore
  return 0;
}

