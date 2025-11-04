// Giao tiep noi bo 
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>

#define SERVER_PATH "./unix_dgram_server.sock"

int main() {
    int sockfd;
    struct sockaddr_un server_addr, client_addr;
    char buffer[1024];
    socklen_t client_len = sizeof(client_addr);

    // 1. Tao socket Unix
    sockfd = socket(AF_UNIX, SOCK_DGRAM, 0);
    unlink(SERVER_PATH);

    // 2. gan duong dan
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sun_family = AF_UNIX;
    strcpy(server_addr.sun_path, SERVER_PATH);

    bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));

    // 3. nhan du lieu tu client
    recvfrom(sockfd, buffer, sizeof(buffer), 0,
             (struct sockaddr*)&client_addr, &client_len);
    printf("Nhận được: %s\n", buffer);

    // 4. phan hoi lai client
    sendto(sockfd, "Chào từ UNIX Datagram", 22, 0,
           (struct sockaddr*)&client_addr, client_len);
    
    // close
    close(sockfd);
    unlink(SERVER_PATH);
    return 0;
}
