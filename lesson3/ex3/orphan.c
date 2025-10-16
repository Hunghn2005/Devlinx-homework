#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } else if (pid > 0) {
        printf("Parent process (PID=%d) exiting now.\n", getpid());
        exit(0);
    } else {
        for (int i = 0; i < 10; i++) {
            printf("Child (PID=%d): Parent PID (PPID) = %d\n", getpid(), getppid());
            sleep(2);
        }
    }

    return 0;
}
