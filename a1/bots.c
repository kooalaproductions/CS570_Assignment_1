/*
Jasmine Nelson (cssc2157)
Ernesto Sanchez (cssc2123)

CS570, Summer 2020
Professor Leonard

Assignment #1, Write to File Using Threads
bots.c file
*/


#include "bots.h"


sem_t FLAG;//semaphore for threads to use
FILE *fp;//file pointer

#define NUM_THREADS 7
void* thread_odd(void* arg){
sem_wait(&FLAG);
fp=fopen("QUOTE.txt","a");//append to file
fprintf(fp, "Thread ID: %d %cComputer science is no more about computers than astronomy is about telescopes.%c --Edsger Dijkstra\r \n", pthread_self(), '"', '"');//write thread id

fclose(fp);//closing file


printf("Thread %d is running\n", pthread_self());//write to console which thread is running

sleep(3);//critical section

printf("Exiting\n");
sem_post(&FLAG);//release semaphore FLAG
 pthread_exit(NULL);
}

void* thread_even(void* arg){
sem_wait(&FLAG);
fp=fopen("QUOTE.txt","a");//append to file
fprintf(fp, "Thread ID: %lu %cControlling complexity is the essence of computer programming.%c --Brian Kernigan\r \n", (int unsigned long)pthread_self(), '"', '"');//write thread id

fclose(fp);//closing file


printf("Thread %lu is running\n", (int unsigned long)pthread_self());//write to console which thread is running

sleep(2);//critical section

printf("Exiting\n");
sem_post(&FLAG);//release semaphore FLAG
}

int main(){

fp=fopen("QUOTE.txt","w");//creating file
fprintf(fp, "PID: %d\r \n", getpid());//write PID to file
fclose(fp);//closing file

sem_init(&FLAG, 0, 1);

pthread_t threads[NUM_THREADS];
 int i;
   for( i = 0; i <= NUM_THREADS; i++ ) {
	pthread_create(&threads[i], NULL, thread_odd, (void *)i);
   }

 pthread_exit(NULL);



//pthread_t threads[7];
//    int report[7];
//
//
//    for(int i=0;i<8;i++){
//    report[i] = pthread_create(&threads[i],NULL,thread_odd,(void*)i);
//}
//
//for(int i=0;i<8;i++){
//    pthread_join(threads[i],NULL);
//}
/*
pthread_t t1,t2,t3,t4,t5,t6,t7;//initialize 7 threads

pthread_create(&t1, NULL, thread_odd, NULL);
sleep(2);
pthread_create(&t2, NULL, thread_even, NULL);
sleep(2);
pthread_create(&t3, NULL, thread_odd, NULL);
sleep(2);
pthread_create(&t4, NULL, thread_even, NULL);
sleep(2);
pthread_create(&t5, NULL, thread_odd, NULL);
sleep(2);
pthread_create(&t6, NULL, thread_even, NULL);
sleep(2);
pthread_create(&t7, NULL, thread_odd, NULL);
sleep(2);



pthread_join(t1, NULL);
pthread_join(t2, NULL);
pthread_join(t3, NULL);
pthread_join(t4, NULL);
pthread_join(t5, NULL);
pthread_join(t6, NULL);
pthread_join(t7, NULL);
*/
sem_destroy(&FLAG);
printf("Please view file.");
return 0;
}


