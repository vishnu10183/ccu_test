
#define DHT_PIN		12 //2 // BCM-27

#define MAX_TIMINGS		85

int data[5] = { 0, 0, 0, 0, 0 };

/********************************* DHT22 Temperature function ****************************************/
int read_dht_temp( float *temp, char ch_t , float *humd )
{
	uint8_t laststate	= HIGH;
	uint8_t counter		= 0;
	uint8_t j			= 0, i;
	
	float h, c, f;

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
		h = (float)((data[0] << 8) + data[1]) / 10;
		if ( h > 100 )
		{
			h = data[0];	// for DHT11
		}
		c = (float)(((data[2] & 0x7F) << 8) + data[3]) / 10;
		if ( c > 125 )
			c = data[2];	// for DHT11
		if ( data[2] & 0x80 )
			c = -c;
		f = c * 1.8f + 32;
		//fprintf( stdout, "Temperature = %.1f *C (%.1f *F)\n",  c, f );
	}else  {
		//fprintf( stdout,"\nData not good, skip" );
		delay( 150 );
		return( read_dht_temp(   temp,  ch_t ,  humd  ) ); // re-read the temp
	}
	
	
	*humd = h;
	if( ch_t == 'C' || ch_t == 'c' )
		//return( c );
		*temp = c;
	else if( ch_t == 'F' || ch_t == 'f' )
		//return( f );
		*temp = f;
		
	return 1;
}
