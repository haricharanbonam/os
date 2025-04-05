#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
	int pid;
	pid=fork();
	if(pid>0)
	{
		wait(NULL);
		printf("this block wil be executed by the process and id is %d\n",getpid());
		printf("and its child process id is %d\n",pid);
		return 1;
	}
	else if(pid==0)
	{
		printf("this block will be executed by the child process \n");
	}
	else
	{
		printf("error : fork call is failed to create a child process \n");
	}
}
