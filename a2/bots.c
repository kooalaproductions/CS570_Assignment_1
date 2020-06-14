

#include <stdio.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_THREADS 8

sem_t FLAG;

void *ThreadDoesThis(void *ptr) {

    int tid;
    tid = (int)ptr;

    for(int j = 0; j < 8; j++) {
        if(tid % 2 ==0){
            sleep(2);

        }else{
        sleep(3);
        }
         sem_wait(&FLAG);
    printf("Thread %d: %lu\n", tid, pthread_self());
    sem_post(&FLAG);

    }
   pthread_exit(NULL);

}

//    if(even){
//
//        for
//    }
//    else{
//        for
//    }



//
//for( int i = 0; i < 3; i++ ) {
//          sleep(2);
//     sem_wait(&mutex);
//    printf("\nEntered..\n");

    //critical section


    //signal
//    printf("\nJust Exiting...\n");

//   long tid;
//   tid = (long)threadid;
//   printf("Hello World! Thread ID, %d\n", tid);
//   printf("Thread %d is running\n", pthread_self());
//   sem_post(&mutex);
// }
//   pthread_exit(NULL);
//}
//int main () {
//   sem_init(&mutex, 0, 1);
//   pthread_t threads[NUM_THREADS];
//   int i;
//   for( i = 0; i < NUM_THREADS; i++ ) {
//         pthread_create(&threads[i], NULL, PrintHello, (void *)i);
//         sleep(2);
//   }
//     for( i = 0; i < NUM_THREADS; i++ ) {
//         pthread_join(&threads[i], NULL);
//   }
//
//
//   pthread_exit(NULL);
//   sem_destroy(&mutex);
//   return 0;
//}
