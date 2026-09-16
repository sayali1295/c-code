#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
        int buffer_size, msg_size;

        int a[2];
        int b[2];
        int r = pipe(a);
        int k = pipe(b);

        // FIX 1: Use OR (||) instead of AND (&&) to catch single pipe failures
        if (r == -1 || k == -1)
        {
                printf("Pipe creation failed\n");
                return -1;
        }

        int i = fork();

        char *buffer = (char *) malloc (100); 
        char *bucket = (char *) malloc (100); 

        char *msg = (char *) malloc (50); 
        char *reply = (char *) malloc (50); 

        strcpy(buffer, "Hello Papa");
        buffer_size = strlen(buffer);

        strcpy(msg, "Hello my child");
        msg_size = strlen(msg);

        // Fork failed
        if(i < 0)
        {
                printf("Child process not created\n");
                return 1;
        }

        // Child execution started
        else if (i == 0)
        {
                printf("\nChild process created\n");

                // Optional but best practice: close unused ends for the child
                close(a[0]); // Child won't read from 'a'
                close(b[1]); // Child won't write to 'b'

                write(a[1], buffer, buffer_size);      // child writing parent
                
                // FIX 2: Capture bytes read and null-terminate string
                int bytes_read = read(b[0], reply, msg_size);           
                reply[bytes_read] = '\0'; 
                
                printf("Child received: %s\n", reply);

                close(a[1]);
                close(b[0]);
        }

        // Parent execution started
        else
        {
                printf("\nParent process\n");

                // Optional but best practice: close unused ends for the parent
                close(a[1]); // Parent won't write to 'a'
                close(b[0]); // Parent won't read from 'b'

                // FIX 2: Capture bytes read and null-terminate string
                int bytes_read = read(a[0], bucket, buffer_size);       
                bucket[bytes_read] = '\0';
                
                printf("Parent received: %s\n", bucket);

                write(b[1], msg, msg_size);            // parent writing child

                close(a[0]);
                close(b[1]);
        }

        free(buffer);
        free(bucket);
        free(msg);
        free(reply);
        return 0;
}
