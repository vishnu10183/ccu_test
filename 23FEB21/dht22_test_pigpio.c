/*
 *  dht.c:
 *	read temperature and humidity from DHT11 or DHT22 sensor
 */

//#include <wiringPi.h>
#include <pigpio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_TIMINGS	85
#define DHT_PIN		27 
// 2

int data[5] = { 0, 0, 0, 0, 0 };

void read_dht_data()
{
	uint8_t laststate	= 1;
	uint8_t counter		= 0;
	uint8_t j			= 0, i;

	data[0] = data[1] = data[2] = data[3] = data[4] = 0;

	/* pull pin down for 18 milliseconds */
	gpioSetMode( DHT_PIN, PI_OUTPUT );
	gpioWrite( DHT_PIN, 0 );
	time_sleep( 0.018 );

	/* prepare to read the pin */
	gpioSetMode( DHT_PIN, PI_INPUT );

	/* detect change and read data */
	for ( i = 0; i < MAX_TIMINGS; i++ )
	{
		counter = 0;
		while ( gpioRead( DHT_PIN ) == laststate )
		{
			counter++;
			//delayMicroseconds( 1 );
			//time_sleep(0.000001);
			gpioDelay(1);
			if ( counter == 255 )
			{
				break;
			}
		}
		laststate = gpioRead( DHT_PIN );

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
		float h = (float)((data[0] << 8) + data[1]) / 10;
		if ( h > 100 )
		{
			h = data[0];	// for DHT11
		}
		float c = (float)(((data[2] & 0x7F) << 8) + data[3]) / 10;
		if ( c > 125 )
		{
			c = data[2];	// for DHT11
		}
		if ( data[2] & 0x80 )
		{
			c = -c;
		}
		float f = c * 1.8f + 32;
		fprintf( stdout, "Humidity = %.1f %% Temperature = %.1f *C (%.1f *F)\n", h, c, f );
	}else  {
		fprintf( stdout,"Data not good, skip\n" );
	}
}

int main( void )
{
	int tests = 0;
	
	fprintf( stdout,"Raspberry Pi DHT22 temperature/humidity test\n" );

	if ( gpioInitialise() < 0 )
		exit( 1 );

	while ( tests<30 )
	{
		read_dht_data();
		time_sleep( 2 ); /* wait 2 seconds before next read for DHT22 */
		tests++;
	}

	return(0);
}
