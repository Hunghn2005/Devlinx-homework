// Giao tiep noi bo ( client )
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>

#define SOCKET_PATH "./unix_stream.sock"

int main() {
    int sockfd;
    struct sockaddr_un addr;
    char buffer[1024];

    // 1. tao socket unix
    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);

    // 2. thiet lap dia chi
    memset(&addr, 0, sizeof(addr));
    addr.sun_family = AF_UNIX;
    strcpy(addr.sun_path, SOCKET_PATH);

    // 3. ket noi den sv
    connect(sockfd, (struct sockaddr*)&addr, sizeof(addr));

    // 4. gui va nhan du lieu
    write(sockfd, "Xin chao UNIX Stream", 21);
    read(sockfd, buffer, sizeof(buffer));
    printf("Phản hồi: %s\n", buffer);

    // 5. close
    close(sockfd);
    return 0;
}
