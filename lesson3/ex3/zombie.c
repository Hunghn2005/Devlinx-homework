#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } 
    else if (pid == 0) {
        printf("Child process (PID=%d) exiting...\n", getpid());
        exit(0);
    } 
    else {
        printf("Parent process (PID=%d) sleeping for 20 seconds...\n", getpid());
        sleep(20);
        printf("Parent process wakes up and exits.\n");
    }

    return 0;
}

