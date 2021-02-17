#include <wiringPi.h>

#include <sys/resource.h>
#include <stdio.h> // for fprintf
#include <unistd.h> // for getpid()

int which = PRIO_PROCESS;
id_t pid;
int priority = -20;
int ret;

#define pingPin 7 // Trigger Pin of Ultrasonic Sensor
#define echoPin 0 // Echo Pin of Ultrasonic Sensor

int count = 0;

float microsecondsToInches(long );
float microsecondsToCentimeters(long );

int main(void) {
  //Serial.begin(9600); // Starting Serial Terminal
  fprintf ( stdout, "Starting....\n\n");
  
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

      cm = microsecondsToCentimeters(duration);

      //Serial.print(" | ");
      //Serial.print(cm);
      //Serial.println();
      
      fprintf ( stdout, " | ");
      fprintf ( stdout, "%f \n", cm);
      
      count++;
    }
    else{
      fprintf( stdout, "Program Completed !");
      return 0;
    }
    delay(100);
  }
}
float microsecondsToInches(long microseconds) {
  return microseconds / 74.0 / 2.0;
}

float microsecondsToCentimeters(long microseconds) {
  return microseconds / 29.0 / 2.0;
}