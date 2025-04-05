#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

#define size 5
int buffer[size];

int in=0,out=0;

sem_t empty,full;

pthread_mutex_t mutex;
void *producer(void *arg)
{
	int item=1;
	while(1)
	{
		sleep(1);
		sem_wait(&empty);
		pthread_mutex_lock(&mutex);
		buffer[in]=item;
		printf("producer produced %d \n",item);
		in=(in+1)%size;
		pthread_mutex_unlock(&mutex);
		sem_post(&full);
		item++;
	}
	
}

void *consumer(void *arg)
{
	while(1)
	{
		sleep(2);
		sem_wait(&full);
		pthread_mutex_lock(&mutex);
		int item=buffer[out];
		printf("consumer  consumed %d \n",item);
		out=(out+1)%size;
		pthread_mutex_unlock(&mutex);
		sem_post(&empty);
		
	}
	
}

int main()
{
	pthread_t prod,cons;
	sem_init(&empty,0,size);
	sem_init(&full,0,0);
	
	pthread_mutex_init(&mutex,NULL);
	pthread_create(&prod,NULL,producer,NULL);
	pthread_create(&cons,NULL,consumer,NULL);
	pthread_join(prod,NULL);
	pthread_join(cons,NULL);
	
	sem_destroy(&empty);
	sem_destroy(&full);
	
	pthread_mutex_destroy(&mutex);
	return 0;
	
}
