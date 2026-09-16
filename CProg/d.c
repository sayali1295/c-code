#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int a[2]; // child to parent pipe
    int b[2]; // parent to child pipe

    int r = pipe(a); 
    int k = pipe(b); 

    // 1. Correct pipe error checking
    if (r == -1 || k == -1)
    {
        printf("Pipe creation failed\n");
        return -1;
    }

    char *buffer = (char *) malloc(100); // buffer for filename input
    printf("Please enter file name\n");
    scanf("%99s", buffer); // Prevent buffer overflow

    int i = fork();

    if (i < 0)
    {
        printf("Child process not created\n");
        free(buffer);
        return 1;
    }

    // CHILD PROCESS
    if (i == 0)
    {
        printf("\n[Child] Started\n");
        close(a[0]); // Close unused read end
        close(b[1]); // Close unused write end

        // 2. Send the full string including '\0' to the parent
        int buffer_size = strlen(buffer) + 1; 
        write(a[1], buffer, buffer_size);                      
        close(a[1]); // Done writing filename

        char ch_reply;
        printf("[Child] Received contents:\n");
        
        // 3. Loop to read everything the parent sends until EOF
        while (read(b[0], &ch_reply, 1) > 0) 
        {                
            printf("%c", ch_reply);
        }
        printf("\n[Child] Exiting\n");
        close(b[0]);
    }
    // PARENT PROCESS
    else
    {
        printf("\n[Parent] Started\n");
        close(a[1]); // Close unused write end
        close(b[0]); // Close unused read end

        char *bucket = (char *) malloc(100); 
        
        // Read the filename from child
        read(a[0], bucket, 100);    
        close(a[0]); 

        FILE *fp = fopen(bucket, "r");

        if (fp == NULL)
        {
            // 4. Fixed Deadlock: Just write the error string to the child directly
            char *error = "Dear client, mentioned file is not found\n";
            write(b[1], error, strlen(error));
        }
        else
        {
            char ch;
            // Read file character by character and send to child
            while ((ch = getc(fp)) != EOF)
            {
                write(b[1], &ch, 1);
            }
            fclose(fp);
        }
        
        close(b[1]); // Closing the write end signals EOF to the child's read loop
        free(bucket);
    }

    free(buffer);
    return 0;
}
