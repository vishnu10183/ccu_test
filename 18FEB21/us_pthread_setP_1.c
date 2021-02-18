// Program to try pThread and setPriority with ultrasonci sensor.

// Include Files
#include <pthread.h>

#include <wiringPi.h>

#include <sys/resource.h>
#include <stdio.h> // for fprintf
#include <unistd.h> // for getpid()


// Pin-Out Macros
#define pingPin 7 // Trigger Pin of Ultrasonic Sensor
#define echoPin 0 // Echo Pin of Ultrasonic Sensor

// Global Variables
int which = PRIO_PROCESS;
id_t pid;
int priority = -20;
int ret;
int count = 0;


// Thread Function
void *ultraS( void *param ){
	fprintf( stdout, "Starting..\n\n");
	pid = getpid();
	ret = setpriority(which, pid, priority);
	  if ( !ret )
		fprintf( stdout, "Successfully SetPriority : %d\n", getpriority(which, pid) );
	  else
		fprintf( stdout, "[Error] Set Priority Error.");
	  
	  wiringPiSetup();
	  while(1) {
		unsigned long int duration;
		float cm;
		
		if ( count <= 20 ) {
		  pinMode(pingPin, OUTPUT);
		  digitalWrite(pingPin, LOW);
		  delayMicroseconds(2);
		  digitalWrite(pingPin, HIGH);
		  delayMicroseconds(10);
		  digitalWrite(pingPin, LOW);
		  pinMode(echoPin, INPUT);
		  
		  //duration = pulseIn(echoPin, HIGH);
		  
		  
		  while( digitalRead(echoPin) == LOW )
			continue;
			
		  duration = micros();
		  
		  while( digitalRead(echoPin) == HIGH )
			continue;
		  
		  duration =  micros() - duration; // time taken = final time - init time

		  cm = duration/ 29.0 / 2.0; // convert microseconds to cm

		  //Serial.print(" | ");
		  //Serial.print(cm);
		  //Serial.println();
		  
		  fprintf ( stdout, " | ");
		  fprintf ( stdout, "%.3f \n", cm);
		  
		  count++;
		}
		else{
		  fprintf( stdout, "Program Completed !");
		  return 0;
		}
		delay(100);
	  }
	
}



int main()
{
	int dummy =0;
	/* this variable is our reference to the thread */
	pthread_t ultraS_thread;
	
	if(pthread_create(&ultraS_thread, NULL, ultraS, &dummy )) {

		fprintf(stderr, "Error creating thread\n");
		return 1;
	}
	
	/* wait for the thread to finish */
	if( pthread_join(ultraS_thread, NULL)) {

		fprintf(stderr, "Error joining thread\n");
		return 2;

	}
	
	fprintf( stdout, "Program Completed!" );
}
