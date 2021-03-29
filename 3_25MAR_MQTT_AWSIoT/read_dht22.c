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

#define DEBUG 1



// Global Variables
int which = PRIO_PROCESS;
id_t pid;
int priority = -20;
int ret;
int count = 0;
cpu_set_t  mask;


#define obs_no_temp		1

char tempDataFile[] = "tempData.txt";


float humid =0.0, tempC = 0 ;


short int ttt[3];
/********************************** Thread Function **********************************/
void *ultraS( void *param ){
	//int core_id = 1;
	
	int tests=0; //, temp;
	
	FILE *fp;
	fp = fopen( tempDataFile, "w" );
	
	if ( wiringPiSetup() == -1 )
		exit( 1 );

	if (DEBUG)
		fprintf( stdout,"Reading Temperature:\n" );
		
	while ( tests < obs_no_temp )
	{
		//delay( 1500 ); // wait 2 seconds before next read for DHT22 
		
		//tempC += read_dht_temp( 'c' ) ;
		//tempC = read_dht_temp( 'c' ) ;
		//fprintf( stdout, "ReadingTemp\n" )
		read_dht_temp( &tempC, 'f' , &humid ) ;
		fprintf( stdout, "%.2f 'F\n", tempC );
		fprintf( stdout, "%.2f\n", humid );
		fprintf( fp, "%0.2f ", tempC ); // Convert 'F to 'C
		fprintf( fp, "%0.2f ", humid );
		fclose(fp);
		tests++;
	}
	return ttt;
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
