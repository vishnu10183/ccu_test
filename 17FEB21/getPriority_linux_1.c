#include <sys/resource.h>
#include <stdio.h> // for fprintf
#include <unistd.h> // for getpid()

int which = PRIO_PROCESS;
id_t pid;
int ret;

int main(void){

	pid = getpid();
	ret = getpriority(which, pid);
	fprintf( stdout, "Value is %d", ret );
}
