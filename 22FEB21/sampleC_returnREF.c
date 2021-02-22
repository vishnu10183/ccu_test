#include<stdio.h>

int main( int argc, char *argv[] )
{
	float *ptr;
	ptr = (float *)argv[1];
	
	*ptr = 24.12;
	
	return 777;
	
}
