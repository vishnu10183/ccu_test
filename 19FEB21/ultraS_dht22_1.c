/*
 * Program of ultrasonic sensor with temperature factor included using DHT22.
 * Set Priority Included
 * Set Affinity to one core Included
 */


// Include Files

#define _GNU_SOURCE // Make sure this code is above all #includes
#include <sched.h> // for Core Affinity

#include <pthread.h>

#include <wiringPi.h>

#include <sys/resource.h>
#include <stdio.h> // for fprintf
#include <unistd.h> // for getpid()

#include <stdlib.h>
#include <stdint.h>


// Pin-Out Macros
#define pingPin 7 // Trigger Pin of Ultrasonic Sensor
#define echoPin 0 // Echo Pin of Ultrasonic Sensor

#define DHT_PIN		2

// Global Variables
int which = PRIO_PROCESS;
id_t pid;
int priority = -20;
int ret;
int count = 0;
cpu_set_t  mask;

#define MAX_TIMINGS		85
#define obs_no_temp		2
#define obs_no_ultraS	20


int data[5] = { 0, 0, 0, 0, 0 };
float tempC = 0.0 ;



// DHT22 function
float read_dht_temp( char ch_t )
{
	uint8_t laststate	= HIGH;
	uint8_t counter		= 0;
	uint8_t j			= 0, i;
	
	float c, f;

	data[0] = data[1] = data[2] = data[3] = data[4] = 0;

	/* pull pin down for 18 milliseconds */
	pinMode( DHT_PIN, OUTPUT );
	digitalWrite( DHT_PIN, LOW );
	delay( 18 );

	/* prepare to read the pin */
	pinMode( DHT_PIN, INPUT );

	/* detect change and read data */
	for ( i = 0; i < MAX_TIMINGS; i++ )
	{
		counter = 0;
		while ( digitalRead( DHT_PIN ) == laststate )
		{
			counter++;
			delayMicroseconds( 1 );
			if ( counter == 255 )
			{
				break;
			}
		}
		laststate = digitalRead( DHT_PIN );

		if ( counter == 255 )
			break;

		/* ignore first 3 transitions */
		if ( (i >= 4) && (i % 2 == 0) )
		{
			/* shove each bit into the storage bytes */
			data[j / 8] <<= 1;
			if ( counter > 16 )
				data[j / 8] |= 1;
			j++;
		}
	}

	/*
	 * check we read 40 bits (8bit x 5 ) + verify checksum in the last byte
	 * print it out if data is good
	 */
	if ( (j >= 40) &&
	     (data[4] == ( (data[0] + data[1] + data[2] + data[3]) & 0xFF) ) )
	{
		
		c = (float)(((data[2] & 0x7F) << 8) + data[3]) / 10;
		if ( c > 125 )
			c = data[2];	// for DHT11
		if ( data[2] & 0x80 )
			c = -c;
		f = c * 1.8f + 32;
		//fprintf( stdout, "Temperature = %.1f *C (%.1f *F)\n",  c, f );
	}else  {
		//fprintf( stdout,"\nData not good, skip" );
		delay( 2000 );
		return( read_dht_temp( ch_t ) ); // re-read the temp
	}
	
	if( ch_t == 'C' || ch_t == 'c' )
		return( c );
	else if( ch_t == 'F' || ch_t == 'f' )
		return( f );
		
	return 0; // Just to remove warning
}



// Thread Function
void *ultraS( void *param ){
	int core_id = 2;
	
	int tests=0;
	
	if ( wiringPiSetup() == -1 )
		exit( 1 );

	fprintf( stdout,"Reading Temperature:\n" );
	while ( tests < obs_no_temp )
	{
		delay( 2000 ); /* wait 2 seconds before next read for DHT22 */
		fprintf( stdout, "\n %.2f 'C", read_dht_temp( 'c' ) );
		tempC += read_dht_temp( 'c' ) ;
		tests++;
	}
	tempC /= 2.0;
	
	fprintf( stdout, "\nStarting..\n\n");
	pid = getpid();
	ret = setpriority(which, pid, priority);
	if ( !ret )
		fprintf( stdout, "\nSuccessfully SetPriority : %d\n", getpriority(which, pid) );
	else
		fprintf( stdout, "[Error] Set Priority Error.");
		
	//assignToCore( pid, 	2 ); // affinity to core 2
	CPU_ZERO(&mask);
    CPU_SET(core_id, &mask);
    //pid = getpid();
    sched_setaffinity( pid, sizeof(mask), &mask);

	wiringPiSetup();
	while(1) {
		unsigned long int duration;
		float cm, ultraSpeed;

		if ( count < obs_no_ultraS ) {
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

		  //cm = duration/ 29.0 / 2.0; // convert microseconds to cm
		  ultraSpeed = 331.3 + (0.606 * tempC);
		  cm = (duration / 20000.0) * ultraSpeed;

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
