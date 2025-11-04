#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];
    socklen_t client_len = sizeof(client_addr);

    // 1. Tao socket dang stream TCP
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    // 2. thiet lap dia chi sv
    server_addr.sin_family = AF_INET;          //  IPv4
    server_addr.sin_port = htons(8080);        // 8080 
    server_addr.sin_addr.s_addr = INADDR_ANY;  // lang nghe

    // 3. Gan dia chi cho socket
    bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));

    // 4. Ringing
    listen(server_fd, 5);
    printf("Server đang chờ kết nối...\n");

    // 5. Chap nhan ket noi
    client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_len);
    printf("Đã kết nối với client!\n");

    // 6. Nhan du lieu
    read(client_fd, buffer, sizeof(buffer));
    printf("Dữ liệu nhận được: %s\n", buffer);

    // 7. Phan hoi lai 
    write(client_fd, "Hello từ Server TCP!", 21);

    // 8. Close
    close(client_fd);
    close(server_fd);
    return 0;
}
