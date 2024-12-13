#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int n, i;
    printf("Enter the number of fork() calls: ");
    scanf("%d", &n);

    int total_processes = 1; // Start with 1 initial process

    for (i = 0; i < n; i++) {
        if (fork() == 0) {
            // Child process
            exit(0); // Child process exits here
        }
        total_processes *= 2; // Double the count after each fork
    }

    // Wait for all child processes to finish
    //for (i = 0; i < total_processes - 1; i++) {
      //  wait(NULL);
    //}

    printf("Total child processes created: %d\n", total_processes - 1);
    return 0;
}
