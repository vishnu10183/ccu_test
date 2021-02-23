
#include <stdio.h>
#include <pigpio.h>

#define ledPin 27

int main(int argc, char *argv[])
{
   double start;

   if (gpioInitialise() < 0)
   {
      fprintf(stderr, "pigpio initialisation failed\n");
      return 1;
   }

	/* Set GPIO modes */
   gpioSetMode(ledPin, PI_OUTPUT);

	start = time_time();
	gpioWrite(ledPin, 1); // HIGH 
	fprintf( stdout, "\nTime taken : %f",  time_time() - start);

	
   while ((time_time() - start) < 10.0) // 10 seconds
   {
      gpioWrite(ledPin, 1); // HIGH 
      time_sleep(0.5);

      gpioWrite(ledPin, 0); // LOW
      time_sleep(0.5);

      // Mirror GPIO24 from GPIO23 
      //gpioWrite(24, gpioRead(23));
   }
   

	 /* Start 75% dutycycle PWM on GPIO17 */	
	//gpioPWM(17, 192); /* 192/255 = 75% */

	fprintf( stdout, "\n Program Completed! \n" );
	gpioTerminate();

	return 0;
}
