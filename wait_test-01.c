#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char ** argv)   
{  
int i ;
for(i=1 ; i<6 ; ++i)
{
	pid_t pid = fork();  
	pid_t ppp;  

	if (pid==0)
	{
	    sleep(30);
	    printf("\n I am the first child and my id is %d \n", getpid());
	    printf("The first child process is now exiting now exiting\n\n");
	    exit(i);
	}

	else {
		    int status = 13;
		    printf("\nI am now waiting for the child process %d\n", pid);
		    waitpid (pid, &status, WNOHANG);
			//waitpid(-1,&st,WNOHANG);
		    printf("\n the status returned by the exiting child is %d\n", status>>8);
		}

	sleep(2);
}
sleep(120);
printf("\nI am now exiting");
exit(0);
}
