#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* worker(void* arg) {
    long idx = (long)arg;             
    printf("Thread #%ld với ID %lu đang chạy!\n", idx, (unsigned long)pthread_self());
    usleep(100 * 1000);
    pthread_exit((void*)idx);  
}

int main(void) {
    pthread_t t1, t2;

    if (pthread_create(&t1, NULL, worker, (void*)1L) != 0) {
        perror("pthread_create t1");
        return 1;
    }
    if (pthread_create(&t2, NULL, worker, (void*)2L) != 0) {
        perror("pthread_create t2");
        return 1;
    }

    void* ret1; 
    void* ret2;
    pthread_join(t1, &ret1);   
    pthread_join(t2, &ret2); 

    printf("Main: cả hai luồng đã xong (ret=%ld, %ld).\n", (long)ret1, (long)ret2);
    return 0;
}
