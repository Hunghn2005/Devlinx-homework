#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];
    socklen_t client_len = sizeof(client_addr);

    // 1. tao socket datagram
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    // 2. thiet lap dia chi sv
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // 3. gan dia chi cho socket
    bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));

    // 4. nhan du lieu 
    recvfrom(sockfd, buffer, sizeof(buffer), 0,
             (struct sockaddr*)&client_addr, &client_len);
    printf("Nhận được: %s\n", buffer);

    // 5. phan hoi lai
    sendto(sockfd, "Chào từ Server UDP", 19, 0,
           (struct sockaddr*)&client_addr, client_len);
           
        // close
    close(sockfd);
    return 0;
}
