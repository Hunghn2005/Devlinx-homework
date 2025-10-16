#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int status;

    setenv("MY_COMMAND", "ls", 1);

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        char *cmd = getenv("MY_COMMAND");
        if (cmd == NULL) {
            printf("Khong tim thay bien moi truong!\n");
            exit(1);
        }
        printf("Tien trinh con: PID=%d, se thuc thi lenh '%s'\n", getpid(), cmd);
        execlp(cmd, cmd, NULL);
        perror("execlp failed");
        exit(1);
    } else {
        wait(&status);
        printf("Tien trinh cha: PID=%d, con ket thuc voi ma %d\n", getpid(), WEXITSTATUS(status));
    }

    return 0;
}
