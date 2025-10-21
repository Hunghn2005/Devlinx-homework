#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

int data;
bool ready = false;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void* producer(void* arg) {
    for (int i = 1; i <= 10; i++) {
        pthread_mutex_lock(&mtx);
        while (ready) pthread_cond_wait(&cond, &mtx);
        data = rand() % 100;
        printf("[Producer] tạo data = %d\n", data);
        ready = true;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mtx);
        usleep(100000);
    }
    return NULL;
}

void* consumer(void* arg) {
    for (int i = 1; i <= 10; i++) {
        pthread_mutex_lock(&mtx);
        while (!ready) pthread_cond_wait(&cond, &mtx);
        printf("           [Consumer] đọc data = %d\n", data);
        ready = false;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mtx);
        usleep(80000);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    srand(time(NULL));
    pthread_create(&t1, NULL, producer, NULL);
    pthread_create(&t2, NULL, consumer, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Hoàn tất.\n");
}
