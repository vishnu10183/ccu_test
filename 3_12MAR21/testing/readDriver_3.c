#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define driver_name	"/dev/ultraS_driver"
#define consecutive_interval	25	// milliseconds

int main(int argc, char *argv[])
{
    int timer_file, result;
    unsigned int distance = 0;

    timer_file = open( driver_name , O_RDWR );
    if (timer_file < 0)
    {
        fputs("open() failed, aborting...\n", stderr);
        return 1;
    }
    distance = 'a';
    write( timer_file, &distance, sizeof(distance) );
    usleep( consecutive_interval*1000 );
    result = read(timer_file, &distance, sizeof(distance) );
        
    if (result != 4)
    {
        fputs("reading error, aborting...\n", stderr);
        close(timer_file);
        return 1;
    }
    printf("Result : %d\n\n", result );
    printf("Duration is in us: %d\n", distance );
    printf("Distance is in cm: %f\n", distance / 58.0);
        
    close(timer_file);

    return 0;
}
