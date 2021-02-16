#include <stdio.h>
#include <wiringPi.h>
#include <wiringSerial.h>


int count = 0;


int main(void) {
  //Serial.begin(9600); // Starting Serial Terminal

  int fd ;
  int count ;
  unsigned int nextTime ;

  fprintf ( stdout, "Starting....");

  if ((fd = serialOpen ("/dev/ttyAMA0", 9600)) < 0)
  {
    fprintf ( stdout, "[ERROR]Unable to open serial device: \n") ;
    return 1 ;
  }
  
  for (count = 0 ; count < 256 ; )
  {
    if (millis () > nextTime)
    {
      printf ("\nOut: %3d: ", count) ;
      fflush (stdout) ;
      serialPutchar (fd, count) ;
      nextTime += 300 ;
      ++count ;
    }
  }
  return 0;
}
