#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int timer_file, result;
    unsigned int distance = 0;

    timer_file = open("/dev/us_service", O_RDWR);
    if (timer_file < 0)
    {
        fputs("open() failed, aborting...\n", stderr);
        return 1;
    }

    write(timer_file, &distance, sizeof(distance));
    usleep(100000);
    result = read(timer_file, &distance, sizeof(distance));
        
    if (result != 4)
    {
        fputs("reading error, aborting...\n", stderr);
        close(timer_file);
        return 1;
    }
    printf("Distance is in cm: %d\n", distance / 58000);
        
    close(timer_file);

    return 0;
}
