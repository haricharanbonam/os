#include<stdio.h>
#include<dirent.h>
int main()
{
	DIR *dir = opendir(".");
	if(dir==NULL)
	{
		printf("could not open a directory \n");
		return 1;
	}
	struct dirent *entry;
	while((entry=readdir(dir))!=NULL)
	{
		printf("%s\n",entry->d_name);
		printf("hey");
	}
	closedir(dir);
	return 0;
}

