#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>

#define CLIENT_PATH "./unix_dgram_client.sock"
#define SERVER_PATH "./unix_dgram_server.sock"

int main() {
    int sockfd;
    struct sockaddr_un client_addr, server_addr;
    char buffer[1024];

    // 1. tao socket 
    sockfd = socket(AF_UNIX, SOCK_DGRAM, 0);
    unlink(CLIENT_PATH);

    // 2. thiet lap dia chi client va sv
    memset(&client_addr, 0, sizeof(client_addr));
    client_addr.sun_family = AF_UNIX;
    strcpy(client_addr.sun_path, CLIENT_PATH);
    bind(sockfd, (struct sockaddr*)&client_addr, sizeof(client_addr));

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sun_family = AF_UNIX;
    strcpy(server_addr.sun_path, SERVER_PATH);

    // 3. gui va nhan du lieu
    sendto(sockfd, "Xin chao UNIX DGRAM", 20, 0,
           (struct sockaddr*)&server_addr, sizeof(server_addr));
    recvfrom(sockfd, buffer, sizeof(buffer), 0, NULL, NULL);
    printf("Phản hồi: %s\n", buffer);

    // close
    close(sockfd);
    unlink(CLIENT_PATH);
    return 0;
}
