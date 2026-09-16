#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/select.h>

#define PORT 8080

int main() {
    int s_fd, new_socket, max_fd;
    int r_read, s_res;
    struct sockaddr_in s_address, c_address;
    int s_address_len = sizeof(s_address);
    int c_address_len = sizeof(c_address);
    fd_set readfds;

    // Initialize 3 separate client variables to 0
    int client1 = 0, client2 = 0, client3 = 0;

    char *buffer = (char *)malloc(1024);

    s_fd = socket(AF_INET, SOCK_STREAM, 0);
    printf("Server Master Socket FD: %d\n", s_fd);

    s_address.sin_family = AF_INET;
    s_address.sin_addr.s_addr = INADDR_ANY;
    s_address.sin_port = htons(PORT);

    if (bind(s_fd, (struct sockaddr *)&s_address, s_address_len) == -1) perror("Bind failed");
    if (listen(s_fd, 3) == -1) perror("Listen failed");

    printf("Server is waiting for up to 3 clients on port %d...\n", PORT);

    while (1) {
        FD_ZERO(&readfds);
        FD_SET(s_fd, &readfds);
        max_fd = s_fd;

        // Add active client variables individually and track max_fd
        if (client1 > 0) { FD_SET(client1, &readfds); if (client1 > max_fd) max_fd = client1; }
        if (client2 > 0) { FD_SET(client2, &readfds); if (client2 > max_fd) max_fd = client2; }
        if (client3 > 0) { FD_SET(client3, &readfds); if (client3 > max_fd) max_fd = client3; }

        int act = select(max_fd + 1, &readfds, NULL, NULL, NULL);
        if (act < 0) {
            perror("Select error");
            break;
        }

        // 1. Handle incoming connections
        if (FD_ISSET(s_fd, &readfds)) {
            c_address_len = sizeof(c_address);
            new_socket = accept(s_fd, (struct sockaddr *)&c_address, &c_address_len);
            
            if (client1 == 0) { client1 = new_socket; printf("Client 1 connected on FD %d\n", client1); }
            else if (client2 == 0) { client2 = new_socket; printf("Client 2 connected on FD %d\n", client2); }
            else if (client3 == 0) { client3 = new_socket; printf("Client 3 connected on FD %d\n", client3); }
            else {
                printf("Server full. Rejecting connection.\n");
                close(new_socket);
            }
        }

        // 2. Continuous routing logic: verify who sent the data and reply *only* to them
        if (client1 > 0 && FD_ISSET(client1, &readfds)) {
            r_read = read(client1, buffer, 1023);
            if (r_read <= 0) { printf("Client 1 disconnected\n"); close(client1); client1 = 0; }
            else {
                buffer[r_read] = '\0';
                printf("[Client 1 (FD %d) says]: %s\n", client1, buffer);
                send(client1, buffer, r_read, 0); // Targeted echo response back to client1
            }
        }

        if (client2 > 0 && FD_ISSET(client2, &readfds)) {
            r_read = read(client2, buffer, 1023);
            if (r_read <= 0) { printf("Client 2 disconnected\n"); close(client2); client2 = 0; }
            else {
                buffer[r_read] = '\0';
                printf("[Client 2 (FD %d) says]: %s\n", client2, buffer);
                send(client2, buffer, r_read, 0); // Targeted echo response back to client2
            }
        }

        if (client3 > 0 && FD_ISSET(client3, &readfds)) {
            r_read = read(client3, buffer, 1023);
            if (r_read <= 0) { printf("Client 3 disconnected\n"); close(client3); client3 = 0; }
            else {
                buffer[r_read] = '\0';
                printf("[Client 3 (FD %d) says]: %s\n", client3, buffer);
                send(client3, buffer, r_read, 0); // Targeted echo response back to client3
            }
        }
    }

    free(buffer);
    close(s_fd);
    return 0;
}

