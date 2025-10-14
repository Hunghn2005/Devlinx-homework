#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *path = argv[1];
    struct stat info;

    if (lstat(path, &info) < 0) {
        perror("Error accessing file");
        exit(EXIT_FAILURE);
    }
    printf("File Path: %s\n", path);

    printf("File Type: ");
    if (S_ISREG(info.st_mode))       printf("Regular File\n");
    else if (S_ISDIR(info.st_mode))  printf("Directory\n");
    else if (S_ISLNK(info.st_mode))  printf("Symbolic Link\n");
    else                             printf("Other\n");

    printf("Size: %ld bytes\n", info.st_size);


    char buf[80];
    struct tm *tmr = localtime(&info.st_mtime);
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", tmr);
    printf("Last Modified: %s\n", buf);

    return 0;
}
