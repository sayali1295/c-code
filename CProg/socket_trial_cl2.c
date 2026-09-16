/* This is CLIENT 2 of multiple client handling SERVER
 * In this program client is requesting service from SERVER listening on PORT 8080
 * PN: socket_trial_cl2.c
 * Final update Date: 13 AUG 2026
*/

#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h> 
#include<unistd.h>
#include<arpa/inet.h> // used for conversion inet_pton & inet_ntop
#define PORT 8080

int main()
{
	int c_fd;
	struct sockaddr_in  c_address;
	int c_address_len = sizeof(c_address);

	char * msg = (char *) malloc (50);

	c_fd = socket (AF_INET, SOCK_STREAM, 0);
	printf("%d\n", c_fd);

	c_address.sin_family = AF_INET;
	c_address.sin_port = htons(PORT);

	// Coverting human readable (text format) SERVER address to network byte order and store in sin_addr
	int i_res = inet_pton (AF_INET, "127.0.0.1", &c_address.sin_addr);
		if (i_res <= 0) printf("Recheck inet_pton");

	int c_res = connect (c_fd, (struct sockaddr *)&c_address, c_address_len);
		if (c_res == -1) printf("Recheck connect");
	
	strcpy (msg, "CLIENT 2: Hey Server! can you tell me my info?");

	int sen = send (c_fd, msg, strlen(msg), 0);
		if(sen == -1) printf("Recheck send");

	printf("----Msg sent by CLIENT----\n");
	printf("---------------------------------\n");

	struct sockaddr_in received_data; // empty struct to store client info

        int rec = recv (c_fd, &received_data, sizeof(received_data), 0);
                if (rec == -1) printf("Recheck receive");

		// checking if no. of bytes received equals sizeof struct received_data
        	else if (rec == sizeof(struct sockaddr_in))
        {
		// converting info back in human readable format
                char server_op[INET_ADDRSTRLEN];
                uint16_t port = ntohs(received_data.sin_port);

                inet_ntop(AF_INET, &(received_data.sin_addr), server_op, INET_ADDRSTRLEN);

		// Printing details of requesting client received from server 
                printf("Server tells me my public info is:\n");
                printf("Address Family:  %hu\n", received_data.sin_family);
                printf("IP:   %s\n", server_op);
                printf("Port: %hu\n", port);
        }

	printf("Please hit enter key to take exit from client2\n");
	getchar();

	close(c_fd);

return 0;
}
