// Giao tiep noi bo ( server )
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>

#define SOCKET_PATH "./unix_stream.sock"

int main() {
    int server_fd, client_fd;
    struct sockaddr_un addr;
    char buffer[1024];

    // 1. tao socket Unix
    server_fd = socket(AF_UNIX, SOCK_STREAM, 0);

    // 2. cau hinh duong dan
    memset(&addr, 0, sizeof(addr));
    addr.sun_family = AF_UNIX;
    strcpy(addr.sun_path, SOCKET_PATH);
    unlink(SOCKET_PATH); // del neu file da ton tai

    // 3. gan dia chi va lang nghe
    bind(server_fd, (struct sockaddr*)&addr, sizeof(addr));
    listen(server_fd, 5);
    printf("Server UNIX Stream đang chờ kết nối...\n");

    // 4. nhan ket noi
    client_fd = accept(server_fd, NULL, NULL);
    read(client_fd, buffer, sizeof(buffer));
    printf("Nhận được: %s\n", buffer);

    // 5. phan hoi lai
    write(client_fd, "Hello từ UNIX Stream", 21);

    // 6. close
    close(client_fd);
    close(server_fd);
    unlink(SOCKET_PATH);
    return 0;
}
