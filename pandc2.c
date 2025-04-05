#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define SIZE 5

int buffer[SIZE];
int in = 0, out = 0, count = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t full = PTHREAD_COND_INITIALIZER;
pthread_cond_t empty = PTHREAD_COND_INITIALIZER;

void *producer(void *arg) {
    int item = 1;
    while (1) {
        sleep(1);

        pthread_mutex_lock(&mutex);
        while (count == SIZE) {
            pthread_cond_wait(&empty, &mutex);
        }

        buffer[in] = item;
        in = (in + 1) % SIZE;
        count++;
        
        printf("Producer produced: %d, buffer size: %d\n", item, count);

        pthread_cond_signal(&full);
        pthread_mutex_unlock(&mutex);

        item++;
    }
    return NULL;
}

void *consumer(void *arg) {
    while (1) {
        sleep(2);

        pthread_mutex_lock(&mutex);
        while (count == 0) {
            pthread_cond_wait(&full, &mutex);
        }

        int item = buffer[out];
        out = (out + 1) % SIZE;
        count--;

        printf("Consumer consumed: %d, buffer size: %d\n", item, count);

        pthread_cond_signal(&empty);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t prod, cons;

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&full);
    pthread_cond_destroy(&empty);

    return 0;
}

