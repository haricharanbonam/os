#include<stdio.h>
#include<unistd.h>
int main()
{
	fork();
	fork();
	fork();
	printf("the current process id is %d\n",getpid());
	
}
