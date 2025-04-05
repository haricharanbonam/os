#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
	int pid =fork();
	if(pid==0)
	{
		printf("child process is running \n");
		printf("child process ecitong code with status 0 ");
		exit(0);
	}
	else if(pid >0)
	{
		int status;
		wait(&status);
		if(WIFEXITED(status))
		{
			printf("the child exited with status %d\n",WEXITSTATUS(status));
		}
		printf("parent process exiting with status code  0 which represents success \n");
		exit(0);
	}
	else
	{
		printf("the fork failed \n");
		exit(1);
	}
	return 0;
}
