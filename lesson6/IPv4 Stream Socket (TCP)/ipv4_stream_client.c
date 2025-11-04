#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[1024];

    // 1. tao socket 
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // 2. Thiet lap dai chi sv
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    // 3. Ket noi den dv
    connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    // 4. Gui du lieu
    write(sockfd, "Xin chao Server TCP", 19);

    // 5. Nhan phan hoi tu sv
    read(sockfd, buffer, sizeof(buffer));
    printf("Phản hồi từ server: %s\n", buffer);

    // 6. Close
    close(sockfd);
    return 0;
}
