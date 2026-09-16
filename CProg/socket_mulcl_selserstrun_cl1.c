/* This program is a client of multiple client handeling server
* This program is implemented using select() to handle 2 fds
* i.e. stdin 0 (STDIN_FILENO) for typing msg & client socket fd for getting connection to server
* NEW UPDATE: This client will now be saved in struct implemented in its server as a record
* so no need to use getpeername() to know which client is commmunicating
* Also user_name is used to interact with client
* PN: socket_mulcl_selserstrun_cl1.c
* Final Update Date: 1 Sep 2026
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/select.h>

#define PORT 8080

int main() 
{
	int c_fd;
	struct sockaddr_in serv_address;
	int serv_address_len = sizeof(serv_address);
	fd_set readfds;

	char * buff = (char *) malloc (200);
	char * msg = (char *) malloc (200);

	if (buff == NULL || msg == NULL)
	{
		printf("Memory Alloction failed\n");
		return -1;
	}

	c_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (c_fd == -1)
	{
		printf("Socket creation failed\n");
		free(buff);
		free(msg);
		return -1;
	}
	printf("%d\n", c_fd);

	serv_address.sin_family = AF_INET;
	serv_address.sin_port = htons(PORT);

	// Convert ipv4 address from text to binary form
	int i_res = inet_pton(AF_INET, "127.0.0.1", &serv_address.sin_addr);
		if(i_res <= 0)
		{
			printf("Recheck inet_pton\n");
			free(buff);
			free(msg);
			return -1;
		}

	if (connect(c_fd, (struct sockaddr *)&serv_address, sizeof(serv_address)) == -1)
	{
        	perror("Connect failed\n");
		close (c_fd);
		free(buff);
		free(msg);
        	return -1;
    	}

	printf("=========================================================\n");	
	printf(" Connected to server!\n");
	printf("=========================================================\n\n");

	char user_name[50];
	memset(user_name, 0, 50);

	printf("Enter your username\n");
	if (fgets(user_name, 50, stdin) != NULL)
	{
		user_name[strcspn(user_name, "\n")] = '\0'; // Remove newline trailing byte		
		
		if (strlen(user_name) > 0)
		{
			write(c_fd, user_name, strlen(user_name)); // send user name to server	
		}
		else
		{
			write(c_fd, "AnonymousClient", 15); // send string AnonymousClient to server if client pressed enter mistakenly
		}
	}
	
	printf("=========================================================\n\n");
	printf("Profile processed DONE!\n");
	printf(" * Type your message and hit Enter to send.\n");
	printf(" * Type 'EXIT' (case-sensitive) to safely disconnect.\n");
	printf("=========================================================\n\n");


	//prompt to start typing
	printf("Press Enter to type\n>>\t");

	while (1)
	{
        	FD_ZERO(&readfds);

        	FD_SET(STDIN_FILENO, &readfds); // Watch terminal keyboard typing
        	FD_SET(c_fd, &readfds);         // Watch server connection

        	int max_fd = (c_fd > STDIN_FILENO) ? c_fd : STDIN_FILENO;
		
		// Wait for activity on either stdin or the socket
        	int act = select(max_fd + 1, &readfds, NULL, NULL, NULL);
		if (act < 0)
		{
			perror("select error\n");
			break;
		}

        	// Case A: You type a message

        	if (FD_ISSET(STDIN_FILENO, &readfds))
		{
			memset(buff, 0, 200);

            		if (fgets(buff, 200, stdin) != NULL)
			{
                		buff[strcspn(buff, "\n")] = '\0'; // Remove newline trailing byte
				if(strcmp(buff , "EXIT") == 0)
				{
					printf("Disconnecting...\n");
					break;
				}
                
                		if (strlen(buff) > 0)
				{
                    			write(c_fd, buff, strlen(buff));
					printf("\n---Msg sent by client---\n");
					printf("-------------------------\n\n");
                		}
            		}
        	}

        	// Case B: The server verifies you and sends you your specific response

		if (FD_ISSET(c_fd, &readfds)) 
		{
			memset(msg, 0, 200);

            		int rec = recv(c_fd, msg, 199, 0);

            		if (rec == 0)
			{
                		printf("Server closed connection.\n");
                		break;
            		}
			else if (rec > 0)
			{
                		msg[rec] = '\0';
                		printf("Server replied  >> %s\n", msg);
				printf("\nPress Enter to type\n>>\t");
            		}
       		 }
	}

	close(c_fd);
	free(buff);
	free(msg);
	return 0;
}

