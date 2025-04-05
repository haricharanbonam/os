
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5  
sem_t forks[N];

void *philosopher(void *num) {
    int id = *(int *)num;                                                                         
    while (1) {
        printf("Philosopher %d is thinking...\n", id);
        sleep(1);
        if (id % 2 == 0) {
            sem_wait(&forks[(id + 1) % N]); 
            printf("Philosopher %d picked up right fork %d\n", id, (id + 1) % N);
            sem_wait(&forks[id]); 
            printf("Philosopher %d picked up left fork %d\n", id, id);
        } else {
            sem_wait(&forks[id]); 
            printf("Philosopher %d picked up left fork %d\n", id, id);
            sem_wait(&forks[(id + 1) % N]); 
            printf("Philosopher %d picked up right fork %d\n", id, (id + 1) % N);
        }

        printf("Philosopher %d is eating...\n", id);
        sleep(2);

        sem_post(&forks[id]);
        printf("Philosopher %d put down left fork %d\n", id, id);
        sem_post(&forks[(id + 1) % N]);
        printf("Philosopher %d put down right fork %d\n", id, (id + 1) % N);
    }
}

int main() {
    pthread_t philosophers[N];
    int ids[N];

    for (int i = 0; i < N; i++)
        sem_init(&forks[i], 0, 1);

    for (int i = 0; i < N; i++) {
        ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }

    for (int i = 0; i < N; i++)
        pthread_join(philosophers[i], NULL);

    return 0;
}

