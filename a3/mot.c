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
int isAlarm = 0;

pthread_t thread_id1;
pthread_t thread_id2;
pthread_t thread_id3;

void sig_handler(int signum){
  if(signum == SIGUSR1){
    isAlarm = 1;
  }
  if(signum == SIGTERM){
    exit(0);
  }

}
void *CountdownTimer(){
  int alarmDeliveryTime = alarmSeconds - alarmTime;

  while(timeSeconds >= 0){
    sleep(1);
    timeSeconds--;
    if(alarmDeliveryTime == alarmSeconds){
      pthread_kill(thread_id1, SIGUSR1);
    }
    alarmSeconds--;
  }

  printf("Countdown Finished\n");
  signal(SIGTERM, sig_handler);
  pthread_kill(thread_id1, SIGTERM);
   pthread_exit(NULL);

}


void *PrintLocalTime(){

    startTime = clock();
    time_t currentTime;
    struct tm *timeinfo;

    while(timeSeconds > 0){
      sleep(1);
      int hours, minutes, seconds;
      time_t now;

      time(&now);

      struct tm *local = localtime(&now);
      hours = local ->tm_hour;
      minutes = local ->tm_min;
      seconds = local ->tm_sec;
      printf("%02d:%02d:%d\n", hours,minutes,seconds);
    }

    pthread_exit(NULL);
}

void *AlarmMessage(){

    while(isAlarm == 0){
      //thread just waits
    }
    printf("Alarm time was reached\n");
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


    signal(SIGUSR1, sig_handler);

    timeSeconds = countdownTime;
    localTimeSeconds = countdownTime;
    alarmSeconds = countdownTime;

    pthread_create(&thread_id1, NULL, CountdownTimer, NULL);
    pthread_create(&thread_id2, NULL, PrintLocalTime, NULL);
    pthread_create(&thread_id3, NULL, AlarmMessage, NULL);

    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);
    pthread_join(thread_id3, NULL);


    return EXIT_SUCCESS;
}

