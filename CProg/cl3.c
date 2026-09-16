#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/select.h>

#define PORT 8080

int main() {
    int c_fd;
    struct sockaddr_in c_address;
    char buffer[1024];
    fd_set readfds;

    c_fd = socket(AF_INET, SOCK_STREAM, 0);

    c_address.sin_family = AF_INET;
    c_address.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &c_address.sin_addr);

    if (connect(c_fd, (struct sockaddr *)&c_address, sizeof(c_address)) == -1) {
        perror("Connect failed");
        return -1;
    }

    printf("Connected to server! Type a message and hit Enter to communicate.\n\n");

    while (1) {
        FD_ZERO(&readfds);
        FD_SET(STDIN_FILENO, &readfds); // Watch terminal keyboard typing
        FD_SET(c_fd, &readfds);         // Watch server connection

        int max_fd = (c_fd > STDIN_FILENO) ? c_fd : STDIN_FILENO;
        select(max_fd + 1, &readfds, NULL, NULL, NULL);

        // Case A: You type a message
        if (FD_ISSET(STDIN_FILENO, &readfds)) {
            if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
                buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline trailing byte
                
                if (strlen(buffer) > 0) {
                    write(c_fd, buffer, strlen(buffer));
                }
            }
        }

        // Case B: The server verifies you and sends you your specific response
        if (FD_ISSET(c_fd, &readfds)) {
            int rec = recv(c_fd, buffer, 1023, 0);
            if (rec <= 0) {
                printf("Server closed connection.\n");
                break;
            } else {
                buffer[rec] = '\0';
                printf("Server replied directly to you: %s\n", buffer);
            }
        }
    }

    close(c_fd);
    return 0;
}

