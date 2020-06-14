/*
Jasmine Nelson (cssc2157)
Ernesto Sanchez (cssc2123)

CS570, Summer 2020
Professor Leonard

Assignment #1, Write to File Using Threads
bots.c file
*/


#include "bots.h"


#define NUM_THREADS 7

sem_t FLAG;
FILE *fp;

void *ThreadDoesThis(void *ptr){

  for(int j = 0; j < 8; j++){
    if(pthread_self() % 2 == 0){
      sleep(2);
    } else {
      sleep(3);
    }

    sem_wait(&FLAG);

    printf("Thread %d is running\n", pthread_self());
    fp=fopen("QUOTE.txt","a");

    if(pthread_self() % 2 == 0){
      fprintf(fp,"Thread %lu: %s\r \n", pthread_self(), "Controlling complexity is the essence of computer programming. --Brian Kernigan");
    } else{
      fprintf(fp,"Thread %lu: %s\r \n", pthread_self(), "Computer science is no more about computers than astronomy is about telescopes. --Edsger Dijkstra");
    }

    fclose(fp);

    sem_post(&FLAG);

  }
  pthread_exit(NULL);
}

int main(void) {

  pid_t pid = getpid();
  fp=fopen("QUOTE.txt","w+");
  fprintf(fp, "PID: %d\r \n", pid);
  fclose(fp);

  sem_init(&FLAG, 0 ,1);

  pthread_t threads[NUM_THREADS];
  for(int i = 1; i <= NUM_THREADS; i++){
    pthread_create(&threads[i], NULL, ThreadDoesThis, NULL);
  }

  for(int i=1; i<= NUM_THREADS;i++){
    pthread_join(threads[i],NULL);
  }

  pthread_exit(NULL);
  sem_destroy(&FLAG);
  return 0;
}

