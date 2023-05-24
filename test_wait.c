#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char ** argv)   
{  
	pid_t pid = fork();  
	pid_t ppp;  

	if (pid==0)
	{
	    sleep(8);
	    printf("\n I am the first child and my id is %d \n", getpid());
	    printf("The first child process is now exiting now exiting\n\n");
	    exit(1);
	}

	else {
		    int status = 13;
		    printf("\nI am now waiting for the child process %d\n", pid);
		    waitpid (pid, &status, 0);
		    printf("\n the status returned by the exiting child is %d\n", status>>8);
		}

	printf("\nI am now exiting");
	exit(0);
}
