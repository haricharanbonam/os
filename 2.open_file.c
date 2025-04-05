#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
void main()
{
	int fd = open("hello.c",O_RDONLY);
	if(fd==-1)
	{
		printf("error opening that file\n");
	}
	char buff[100];
	int buffsize;
	buffsize=read(fd,buff,sizeof(buff)-1);
	buff[buffsize]='\0';
	printf("%s\n",buff);
	close(fd);
	printf("\n file is closed \n");
}
