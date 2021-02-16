#include<stdio.h>
#include<wiringPi.h>

#define ledPin 7

int main(void){
	wiringPiSetup();
	pinMode( ledPin, OUTPUT);
	printf("Starting....");
	while(1){
		digitalWrite( ledPin,HIGH );
		delay(1000);
		digitalWrite( ledPin, LOW );
		delay(1000);
	}
	return 0;
}
