#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

//#define driver_name	"/dev/ultraS_driver"
#define consecutive_interval	25	// milliseconds

#define TRIG1  15 // BCM-14 //7 // BCM- 4
#define ECHO1  16// BCM-15 //0 // BCM-17

#define TRIG2  4 //12 //BCM-10
#define ECHO2  5 //3 //BCM-22

int hcsr04_pins[2][2] = {  { TRIG1, ECHO1 },
                             { TRIG2, ECHO2 }
                        };

float readDist_cm( int tempC, int device_no )
{
    unsigned int duration = 0;
    float ultraSpeed;
    device_no--;
    //printf("START...\n");	
          pinMode( hcsr04_pins[device_no][0], OUTPUT);
		  digitalWrite(hcsr04_pins[device_no][0], LOW);
		  delayMicroseconds(2);
		  digitalWrite(hcsr04_pins[device_no][0], HIGH);
		  delayMicroseconds(10);
		  digitalWrite(hcsr04_pins[device_no][0], LOW);
          
		  pinMode(hcsr04_pins[device_no][1], INPUT);
		  //duration = pulseIn(echoPin, HIGH);
		  
		  while( digitalRead(hcsr04_pins[device_no][1]) == LOW )
			continue;
			
		  duration = micros();
		  
		  while( digitalRead(hcsr04_pins[device_no][1]) == HIGH )
			continue;
		  
		  duration =  micros() - duration; // time taken = final time - init time

		 //printf("DURATION DONE...\n");	 

    
    /*********************** Calculate distance ******************************/
    ultraSpeed = 331.3 + (0.606 * tempC);
    return( (duration / 20000.0) * ultraSpeed ); // in cm
    
}
