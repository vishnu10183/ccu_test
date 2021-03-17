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

//#include "read_Driver.h"
#include "read_cm.h"
#include "dht_22.h"

#define DEBUG 0



// Global Variables
int which = PRIO_PROCESS;
id_t pid;
int priority = -20;
int ret;
int count = 0;
cpu_set_t  mask;


#define obs_no_temp		1
#define obs_no_ultraS	5
#define consecutive_interval 25 //ms
#define decimal_digits	3



int tempC = 0 ;
float dist_cm[30] , humid =0.0;



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


/********************************** Thread Function **********************************/
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
		
		//tempC += read_dht_temp( 'c' ) ;
		//tempC = read_dht_temp( 'c' ) ;
		read_dht_temp( &tempC, 'c' , &humid ) ;
		fprintf( stdout, "%d 'C\n", tempC );
		fprintf( stdout, "%.2f\n", humid );
		tests++;
	}
	
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
	//printf("Starting...1\n");
	
	/********************* Calling C-application for driver-1 ******************************/
	count=0;
	while(count < obs_no_ultraS) {
		
		float cm;
			
		//cm = readDist( tempC, "/dev/ultraS_driver1" );
		cm = readDist_cm( tempC, 1 );
		dist_cm[count] = cm;
		  
		count++;
		delay(consecutive_interval);
		}
		
	fprintf( stdout, "%.1f\n",  max_repeat(dist_cm) );
	//printf("Starting...2\n");
	
	/********************* Calling C-application for driver-2 ******************************/
	count=0;		
	while(count < obs_no_ultraS) {
		
		float cm;
			
		//cm = readDist( tempC, "/dev/us_driver2" );
		cm = readDist_cm( tempC, 2 );
		dist_cm[count] = cm;
		  
		count++;
		delay(consecutive_interval);
		}
		
	fprintf( stdout, "%.1f\n",  max_repeat(dist_cm) );		
				
	//printf("END...\n");	
	return dist_cm;

}



int main( void )
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
