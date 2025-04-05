#include<stdio.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/stat.h>

int main()
{
	struct stat buf;
	int e = stat("./hello.c",&buf);
	if(e==-1)
	printf(" error occured \n ");
	
	printf("%ld\n",buf.st_size);
	printf("%ld\n",buf.st_dev);
	printf("%d\n",buf.st_uid);
}
