#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int pid = fork();
	if(pid>0)
	{
		printf("chlid process running\n");
		return 42; 
	}
	else if(pid==0)
	{
		int status;
		if(WIFEXITED(status))
		{
			printf("child proces s with status %d\n",WEXITSTATUS(status));
		}

	}
			else
		{
			printf("an error occured, fork failed \n");
		}
	return 0;
}
