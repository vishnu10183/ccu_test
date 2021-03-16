/*
 * Program of ultrasonic sensor with temperature factor included using DHT22.
 * Set Priority Included
 * Set Affinity to one core Included
 * Mode function - Most Repeated Value
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
#include <math.h>

#include "readDriver_3.h"

#define DEBUG 0

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
#define obs_no_ultraS	5
#define consecutive_interval 25 //ms
#define decimal_digits	3


int data[5] = { 0, 0, 0, 0, 0 };
int tempC = 0 ;
float dist_cm[30] ;


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
		delay( 500 );
		return( read_dht_temp( ch_t ) ); // re-read the temp
	}
	
	if( ch_t == 'C' || ch_t == 'c' )
		return( c );
	else if( ch_t == 'F' || ch_t == 'f' )
		return( f );
		
	return 0; // Just to remove warning
}




// Mode Function to find maximum-repeated value from consecutive readings
float max_repeat( float arr[] ){
	float maxVal = 0.0;
	int maxCount = 0, indx, lp, temp_c=0, temp;
	
	for( lp=0; lp < obs_no_ultraS; lp++  ){
		
		// Convert reading to n-decimal precision
		temp = arr[lp] * pow(10, decimal_digits);
		arr[lp] = temp;
		arr[lp] /= pow(10, decimal_digits);
	}
	
	if( DEBUG ){
		fprintf( stdout, "\n\nConverted Readings:\n" );
		for( lp=0; lp < obs_no_ultraS; lp++  )
				fprintf( stdout, "%f\n", arr[lp] );
	}
	
	// Find most-repeated value
	for ( lp=0; lp < obs_no_ultraS; lp++ ){
		temp_c = 1;
		for( indx = 0; indx < lp; indx++ )
			if( arr[indx] == arr[lp] )
				++temp_c;
				
		if( temp_c > maxCount ){
			if(DEBUG)
				fprintf(stdout, "MaxCount: %d and MAxVal: %f\n", temp_c, arr[lp] );
			maxCount = temp_c;
			maxVal = arr[ lp ];
		}
	}
	if( DEBUG)
		fprintf( stdout, "Most-Repeated Count: " );
	fprintf( stdout, "%d\n", maxCount);
	return maxVal;
}


// Thread Function
void *ultraS( void *param ){
	int core_id = 2;
	
	int tests=0; //, temp;
	
	if ( wiringPiSetup() == -1 )
		exit( 1 );

	if (DEBUG)
		fprintf( stdout,"Reading Temperature:\n" );
	while ( tests < obs_no_temp )
	{
		delay( 2000 ); /* wait 2 seconds before next read for DHT22 */
		fprintf( stdout, "%.2f 'C\n", read_dht_temp( 'c' ) );
		//tempC += read_dht_temp( 'c' ) ;
		tempC = read_dht_temp( 'c' ) ;
		tests++;
	}
	//tempC /= 2.0;
	// Round-off to one decimal
	//temp = tempC * 10; 
	//tempC = (temp*1.0) / 10; 
	
	if (DEBUG)
		fprintf( stdout, "\nStarting..\n\n");
	pid = getpid();
	ret = setpriority(which, pid, priority);
	if (DEBUG){
		if ( !ret )
			fprintf( stdout, "\nSuccessfully SetPriority : %d\n", getpriority(which, pid) );
		else
			fprintf( stdout, "[Error] Set Priority Error.");
	}
	
	//assignToCore( pid, 	2 ); // affinity to core 2
	CPU_ZERO(&mask);
    CPU_SET(core_id, &mask);
    //pid = getpid();
    sched_setaffinity( pid, sizeof(mask), &mask);

	wiringPiSetup();
	while(1) {
		
		float cm;

		if ( count < obs_no_ultraS ) {
		  
		  /************* Calling C-application ******************************/
			
			cm = readDist( tempC );
			dist_cm[count] = cm;
		  
		  
		  fprintf ( stdout, "%.3f", cm); //%.3f
		  //fprintf ( stdout, " |  ");
		  fprintf ( stdout, "\n");
		  
		  count++;
		}
		else{
			if (DEBUG){
				fprintf( stdout, "Distance Completed !\n");
				fprintf( stdout, "\nMax value : ");
			}
			fprintf( stdout, "%.3f\n",  max_repeat(dist_cm) );
			return dist_cm;
		}
		delay(consecutive_interval);
	}

}



int main(  )
{
	int dummy =0;
	/* this variable is our reference to the thread */
	pthread_t ultraS_thread;
	
	if(pthread_create(&ultraS_thread, NULL, ultraS, &dummy )) {
		if (DEBUG)
			fprintf(stderr, "Error creating thread\n");
		return 1;
	}
	
	/* wait for the thread to finish */
	if( pthread_join(ultraS_thread, NULL)) {
		if (DEBUG)
			fprintf(stderr, "Error joining thread\n");
		return 2;

	}
	
	//fprintf( stdout, "Program Completed!" );
	if (DEBUG)
		printf( "\n\nProgram Completed!" );
	return 0;
}