/*
Jasmine Nelson RedID: 820233707 (cssc2157)
Ernesto Sanchez RedID: 819323499 (cssc2123)

CS570, Summer 2020
Professor Leonard

Assignment #3, Management of Threads
mot.c file
*/

#include "mot.h"



unsigned int countdownTime = 0;
int timeSeconds = 0;
int localTimeSeconds = 0;
int alarmSeconds = 0;
int alarmTime = 0;
int isAlarm = 0;

pthread_t thread_id1;
pthread_t thread_id2;
pthread_t thread_id3;

/**
sig_handler will handle incoming signals and perform indicated tasks. When SIGUSR1 is received it will change the value of isAlarm to 1 in order to print out the alarm message.
Also once the CountdownTimer() has finished it will send a signal to our sig_handler and terminate the program.
**/
void sig_handler(int signum){
  if(signum == SIGUSR1){//will trigger of alarm when this signal is received
    isAlarm = 1;
  }
  if(signum == SIGTERM){//terminate the program when this signal is received
    exit(0);
  }

}

/**
CountdownTimer utilizes the first parameter entered as the count down and when it reaches zero it prints out a friendly message and sends a signal to the sig_handler
to let it know that it is time to terminate.
**/
void *CountdownTimer(){
  int alarmDeliveryTime = alarmSeconds - alarmTime;

  while(timeSeconds >= 0){//will be true until timeSeconds reaches 0
    sleep(1);
    timeSeconds--;
    if(alarmDeliveryTime == alarmSeconds){
      pthread_kill(thread_id1, SIGUSR1);
    }
    alarmSeconds--;
  }

  fprintf(stdout, "Countdown Finished\n");//when it exits the while loop it prints out this friendly message
  signal(SIGTERM, sig_handler);//signals the sig_handler to terminate the program
  pthread_kill(thread_id1, SIGTERM);//to perform a clean exit
   pthread_exit(NULL);

}

/**
PrintLocalTimer prints the current local time every second while the timeSeconds keeps decrementing.
**/
void *PrintLocalTime(){

    struct tm *timeinfo;

    while(timeSeconds > 0){
      sleep(1);
      int hours, minutes, seconds;
      time_t currentTime;

      time(&currentTime);

      struct tm *local = localtime(&currentTime);
      hours = local ->tm_hour;
      minutes = local ->tm_min;
      seconds = local ->tm_sec;
      printf("%02d:%02d:%d\n", hours,minutes,seconds);//prints out the current local time in military hour format
    }

    pthread_exit(NULL);
}

/**
AlarmMessage will print out a message before the program terminates alarming the user. This will only trigger off when a signal has been sent to the sig_handler
that will assign isAlarm to 1 and print out a message.
**/
void *AlarmMessage(){

    while(isAlarm == 0){
      //thread just waits
    }
    printf("Alarm time was reached\n");//when isAlarm = 1 it prints out this alarm message
    pthread_exit(NULL);
}

/**
main checks for parameters entered and creates all necessary threads for the program
**/
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

