#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// Signal handler for SIGUSR1
void handle_SIGUSR1(int sig) {
    printf("Receiver: Received SIGUSR1 signal!\n");
}

// Signal handler for SIGUSR2
void handle_SIGUSR2(int sig) {
    printf("Receiver: Received SIGUSR2 signal!\n");
}

int main() {
    // Register signal handlers for SIGUSR1 and SIGUSR2
    signal(SIGUSR1, handle_SIGUSR1) ;

    signal(SIGUSR2, handle_SIGUSR2);

    // Print the process ID so the sender knows where to send signals
    printf("Receiver Process PID: %d\n", getpid());

    // Infinite loop to keep the receiver running and wait for signals
    while (1) {
        pause(); // Wait for signals indefinitely
    }

    return 0;
}

