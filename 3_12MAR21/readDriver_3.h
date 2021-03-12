#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define driver_name	"/dev/ultraS_driver"
#define consecutive_interval	25	// milliseconds

float readDist( int tempC )
{
    int timer_file; //, result;
    unsigned int duration = 0;
    float ultraSpeed;

    timer_file = open( driver_name , O_RDWR );
    if (timer_file < 0)
    {
        fputs("open() failed, aborting...\n", stderr);
        return 1;
    }
    duration = 'a';
    write( timer_file, &duration, sizeof(duration) );
    usleep( consecutive_interval*1000 );
    read(timer_file, &duration, sizeof(duration) );
    
    /*
    result = read(timer_file, &duration, sizeof(duration) );
        
    if (result != 4)
    {
        fputs("reading error, aborting...\n", stderr);
        //close(timer_file);
        //return 0;
    }
    
    printf("Result : %d\n\n", result );
    printf("Duration is in us: %d\n", distance );
    printf("Distance is in cm: %f\n", distance / 58.0);
    */   
    close(timer_file);

    //return 0;
    
    
    /*********************** Calculate distance ******************************/
    ultraSpeed = 331.3 + (0.606 * tempC);
    return( (duration / 20000.0) * ultraSpeed );
    
}
