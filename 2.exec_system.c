#include<stdio.h>
#include<unistd.h>
void main()
{
	printf("main process\n");
	execlp("./hello","./hello","hari","charan",NULL);
	printf("\ncurrent process \n");
}
