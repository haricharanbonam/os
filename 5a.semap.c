#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

#define maxports 3
#define numprocess 5
sem_t port;
void *accessPort(void *arg)
{
	int pid = *((int *)arg);
	sem_wait(&port);
	printf("process %d opened a port \n",pid);
	sleep(2);
	printf("process %d closed a port \n",pid);
	sem_post(&port);
	return NULL;
}
int main()
{
	pthread_t process[numprocess];
	int processids[numprocess];
	sem_init(&port,0,maxports);
    for(int i = 0; i < numprocess; i++)
    {
  	processids[i]=i+1;  
        pthread_create(&process[i], NULL, accessPort, &processids[i]);
    }

    for(int i = 0; i < numprocess; i++)
    {
        pthread_join(process[i], NULL);
    }

    sem_destroy(&port);  

		return 0;
	
}
