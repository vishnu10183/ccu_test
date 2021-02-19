#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_TIMINGS	85
#define DHT_PIN		2
#define obs_no		10

int data[5] = { 0, 0, 0, 0, 0 };

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
		{
			c = data[2];	// for DHT11
		}
		if ( data[2] & 0x80 )
		{
			c = -c;
		}
		f = c * 1.8f + 32;
		//fprintf( stdout, "Temperature = %.1f *C (%.1f *F)\n",  c, f );
	}else  {
		fprintf( stdout,"Data not good, skip\n" );
		delay( 2000 );
		return( read_dht_temp( ch_t ) ); // re-read the temp
	}
	
	if( ch_t == 'C' || ch_t == 'c' )
		return( c );
	else if( ch_t == 'F' || ch_t == 'f' )
		return( f );
		
	return 0; // Just to remove warning
}


int main( void )
{
	int tests=0;
	fprintf( stdout,"Raspberry Pi DHT22 temperature test:\n" );
	
	if ( wiringPiSetup() == -1 )
		exit( 1 );

	while ( tests < obs_no )
	{
		fprintf( stdout, "\n %.2f 'C", read_dht_temp( 'c' ) );
		delay( 2000 ); /* wait 2 seconds before next read for DHT22 */
		tests++;
	}

	return(0);
}
