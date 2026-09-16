#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    // Duplicate the process
    pid = fork();

    if (pid < 0) {
        // Fork failed
        fprintf(stderr, "Fork Failed\n");
        return 1;
    } 
    else if (pid == 0) {
        // Child process execution path
        printf("Hello from Child! (PID: %d)\n", getpid());
    } 
    else {
        // Parent process execution path
        printf("Hello from Parent! (Child PID: %d, Parent PID: %d)\n", pid, getpid());
    }

    return 0;
}
