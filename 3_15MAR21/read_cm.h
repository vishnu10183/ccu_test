#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

//#define driver_name	"/dev/ultraS_driver"
#define consecutive_interval	25	// milliseconds

#define TRIG1  4
#define ECHO1  17

#define TRIG2  10
#define ECHO2  22

int hcsr04_pins[2][2] = { { TRIG1, ECHO1 },
                            { TRIG2, ECHO2 }
                        };

float readDist_cm( int tempC, int device_no )
{
    
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

		  

    
    /*********************** Calculate distance ******************************/
    ultraSpeed = 331.3 + (0.606 * tempC);
    return( (duration / 20000.0) * ultraSpeed ); // in cm
    
}
