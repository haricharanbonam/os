#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
void main()
{
	int pid = fork();
	if(pid==0)
	{
		char *argv[]={"cat","hello.c",NULL};
	execv("/bin/cd", argv);

	}
}
