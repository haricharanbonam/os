#include<stdio.h>
#include<pthread.h>
#include<stdio.h>
#include<unistd.h>

void *print_message(void *arg)
{
	char *msg = (char *)arg;
	while(1)
	{
		printf("thread %ld :%s\n",pthread_self(),msg);
		sleep(1);
	}
	return NULL;
}

int main()
{
	pthread_t threads[3];
	
	pthread_create(&threads[0],NULL,print_message,"Hi");
	pthread_create(&threads[1],NULL,print_message,"Hello");
	pthread_create(&threads[2],NULL,print_message,"Good bye");
	for(int i=0;i<3;i++)
	{
		pthread_join(threads[i],NULL);
		
	}
	
	printf("all threads finished executing \n");
	
}
