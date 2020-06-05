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
FILE *fp;

void* thread_odd(void* arg){
sem_wait(&FLAG);
fp=fopen("QUOTE.txt","a");//append to file
fprintf(fp, "Threads ID: %d The Qoute\r \n", pthread_self());//write thread id

fclose(fp);//closing file


printf("Thread %d is running\n", pthread_self());

sleep(3);//critical section

printf("Exiting\n");
sem_post(&FLAG);
}

void* thread_even(void* arg){
sem_wait(&FLAG);
fp=fopen("QUOTE.txt","a");//append to file
fprintf(fp, "Threads ID: %d The Qoute\r \n", pthread_self());//write thread id

fclose(fp);//closing file


printf("Thread %d is running\n", pthread_self());

sleep(2);//critical section

printf("Exiting\n");
sem_post(&FLAG);
}

/*
int main(){
FILE *fp;
fp=fopen("QUOTE.txt","w");//opening file
fprintf(fp, "PID: %d\r \n", getpid());//write PID to file
fclose(fp);//closing file
return 0;
}
*/


int main(){

fp=fopen("QUOTE.txt","w");//opening file
fprintf(fp, "PID: %d\r \n", getpid());//write PID to file
fclose(fp);//closing file

sem_init(&FLAG, 0, 1);
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

sem_destroy(&FLAG);
printf("Please view file.");
return 0;
}


