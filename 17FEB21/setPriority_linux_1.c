#include <sys/resource.h>
#include <stdio.h> // for fprintf
#include <unistd.h> // for getpid()

int which = PRIO_PROCESS;
id_t pid;
int priority = -20;
int ret;

int main(void){
	fprintf( stdout, "Starting..\n\n");
	pid = getpid();
	ret = setpriority(which, pid, priority);
	fprintf( stdout, "Ret Value of SetPriority is %d\n", ret );
	
	ret = getpriority(which, pid);
	fprintf( stdout, "Priority Value is %d\n", ret );
	
}
