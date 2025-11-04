#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[1024];

    // 1. tao socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    // 2. thiet lap dia chi sv
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    // 3. gui du lieu den sv
    sendto(sockfd, "Xin chao Server UDP", 20, 0,
           (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    // 4. nhan phan hoi
    recvfrom(sockfd, buffer, sizeof(buffer), 0, NULL, NULL);
    printf("Phản hồi: %s\n", buffer);

    // 5.close
    close(sockfd);
    return 0;
}
