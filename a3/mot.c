/*
Jasmine Nelson RedID: 820233707 (cssc2157)
Ernesto Sanchez RedID: 819323499 (cssc2123)

CS570, Summer 2020
Professor Leonard

Assignment #23, Management of Threads
mot.c file
*/

#include "mot.h"



unsigned int countdownTime = 0;
int timeSeconds = 0;
int localTimeSeconds = 0;
int alarmSeconds = 0;
clock_t startTime,timeDifference;
int alarmTime = 0;


//void signal_handler(int singalnum){
//
//    sigset_t set;
//
//    int sig;
//
//    sigfillset(&set);
//
//    while (1) {
// 	/* wait for a signal to arrive */
//
//	switch (sig=sigwait(&set, sig)) {
//
//	  /* here you would add whatever signal you needed to catch */
//	  case SIGINT : {
//			printf("Interrupted with signal %d, exiting...\n", sig);
//			exit(0);
//			}
//
//	  default : printf("GOT A SIGNAL = %d\n", sig);
//	  } /* end of switch */
//	} /* end of while */
//
//
//}
void *CountdownTimer(){

  while(timeSeconds >= 0){
    sleep(1);
    printf("Time left is %d\n", timeSeconds);
    timeSeconds--;
  }

  printf("Countdown Finished\n");
  pthread_exit(NULL);
}

void *PrintLocalTime(){

    startTime = clock();
    time_t currentTime;
    struct tm *timeinfo;


    /*while(localTimeSeconds >= 0){
      sleep(1);
      time(&currentTime);
      timeinfo = localtime(&currentTime);
      printf("Current local time and date: %s", asctime (timeinfo));
      localTimeSeconds--;
    }*/

    while(timeSeconds > 0){
      sleep(1);
      int hours, minutes, seconds;
      time_t now;

      time(&now);

      struct tm *local = localtime(&now);
      hours = local ->tm_hour;
      minutes = local ->tm_min;
      seconds = local ->tm_sec;

//      time(&currentTime);
//      timeinfo = localtime(&currentTime);
      printf("%02d:%02d:%d\n", hours,minutes,seconds);
    }

    pthread_exit(NULL);
}

void *AlarmMessage(){
    int alarmDeliveryTime = alarmSeconds - alarmTime;

    //sleep(alarmSeconds);
    //printf("Alarm at time %d has been reached.\n", alarmTime);

    while(alarmSeconds >= 0){
      sleep(1);
      if(alarmDeliveryTime == alarmSeconds){
        printf("Alarm at time %d has been reached.\n", alarmTime);
        //printf("Secondsalarm is %d\n", secondsAlarm);
        break;
      }
      alarmSeconds--;

    }
    pthread_exit(NULL);
}


int main(int argc, char *argv[]) {

       if(argc >= 5){
      printf("Too many arguments");
    } else if(argc == 4){
      countdownTime = atoi(argv[1]);
      alarmTime = atoi(argv[3]);
    } else {
      countdownTime = 25;
      alarmTime = 17;
    }

    timeSeconds = countdownTime;
    localTimeSeconds = countdownTime;
  alarmSeconds = countdownTime;

    pthread_t thread_id1;
    pthread_t thread_id2;
    pthread_t thread_id3;

    pthread_create(&thread_id1, NULL, CountdownTimer, NULL);
    pthread_create(&thread_id2, NULL, PrintLocalTime, NULL);
    pthread_create(&thread_id3, NULL, AlarmMessage, NULL);
    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);
    pthread_join(thread_id3, NULL);

    return 0;
}


//int main(){
//    long t1 = 1, t2 = 2, t3 = 3, t4 =4;
//    pthread_t threads[4];
//
//    pthread_create(&threads[0], NULL, signal_threads, (void*)t1);
//    pthread_create(&threads[1], NULL, count_down, (void*)t2);
//    pthread_create(&threads[2], NULL, count_down_monitor, (void*)t3);
//    pthread_create(&threads[3], NULL, wall_clock, (void*)t4);
//
//
//    int k;
//    for(k=1; k<= NUM_THREADS;k++){
//        pthread_join(threads[k],NULL);//wait for threads to terminate and clean up resources
//      }
//
//
//}
