#include<stdio.h>
#include<pthread.h>
#include<unistd.h>


#define maxports 3
#define numprocess 5

pthread_mutex_t lock;
pthread_cond_t portsAvailable;

int availablePorts = maxports;

void *accessPort(void *arg)
{
	int pid = *((int *)arg);
	pthread_mutex_lock(&lock);
	while(availablePorts==0)
	{
		pthread_cond_wait(&portsAvailable , &lock);
	}
	printf("process %d openened a port\n " ,pid);
	pthread_mutex_unlock(&lock);
	sleep(2);
	pthread_mutex_lock(&lock);
	availablePorts++;
	printf("process %d closed the port \n",pid);
	pthread_cond_signal(&portsAvailable);
	pthread_mutex_unlock(&lock);
}




int main()
{
	pthread_t process[numprocess];
	int processids[numprocess];
	pthread_mutex_init(&lock,NULL);
	pthread_cond_init(&portsAvailable,NULL);
	for(int i=0;i<numprocess;i++)
	{
		processids[i]=i+1;
		pthread_create(&process[i],NULL,accessPort,&processids[i]);
	}
	for(int i=0;i<numprocess;i++)
	{
		pthread_join(process[i],NULL);
	}
	pthread_mutex_destroy(&lock);
	pthread_cond_destroy(&portsAvailable);
	return 0;
	}

