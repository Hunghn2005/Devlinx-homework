#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


int data = 0;                     
pthread_rwlock_t rwlock;          

void* reader(void* arg) {
    int id = *(int*)arg;
    for (int i = 0; i < 3; i++) {
        pthread_rwlock_rdlock(&rwlock);
        printf("Reader %d đọc data = %d\n", id, data);
        pthread_rwlock_unlock(&rwlock);
        sleep(1);

    }
    return NULL;
}

void* writer(void* arg) {
    int id = *(int*)arg;
    for (int i = 0; i < 3; i++) {
        pthread_rwlock_wrlock(&rwlock);
        data++;
        printf("Writer %d ghi data = %d\n", id, data);
        pthread_rwlock_unlock(&rwlock);
        sleep(2);
    }
    return NULL;
}

int main() {
    pthread_t r[5], w[2];
    int id_r[5], id_w[2];

    pthread_rwlock_init(&rwlock, NULL);

    for (int i = 0; i < 5; i++) {
        id_r[i] = i + 1;
        pthread_create(&r[i], NULL, reader, &id_r[i]);
    }
    for (int i = 0; i < 2; i++) {
        id_w[i] = i + 1;
        pthread_create(&w[i], NULL, writer, &id_w[i]);
    }

    for (int i = 0; i < 5; i++) pthread_join(r[i], NULL);
    for (int i = 0; i < 2; i++) pthread_join(w[i], NULL);

    pthread_rwlock_destroy(&rwlock);
    return 0;
}
