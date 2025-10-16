#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int status;

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }
    else if (pid == 0) {
        printf("Tien trinh con: PID = %d\n", getpid());
        exit(10);
    }
    else {
        printf("Tien trinh cha: PID = %d, PID con = %d\n", getpid(), pid);

        wait(&status);

        if (WIFEXITED(status)) {
            printf("Tien trinh con ket thuc binh thuong voi ma thoat = %d\n", WEXITSTATUS(status));
        } else {
            printf("Tien trinh con ket thuc bat thuong\n");
        }
    }

    return 0;
}
