#include <wiringPi.h>

#include <stdio.h> // for fprintf


// Pin-Out Macros
#define pingPin 7 // Trigger Pin of Ultrasonic Sensor
#define echoPin 0 // Echo Pin of Ultrasonic Sensor

int count = 0;

int main(void){
	fprintf( stdout, "Starting..\n\n");
	wiringPiSetup();
	while(1) {
		unsigned long int duration;
		float cm;

		if ( count < 100 ) {
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
