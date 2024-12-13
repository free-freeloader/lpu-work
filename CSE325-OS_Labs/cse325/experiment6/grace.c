#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Flag to simulate resource cleanup
int cleanup_flag = 0;

// Function for graceful thread termination
void *graceful_thread(void *arg) {
    printf("Graceful thread started\n");

    // Simulating some work
    for (int i = 0; i < 5; i++) {
        if (cleanup_flag) {
            printf("Graceful thread: Cleaning up resources\n");
            pthread_exit(NULL);  // Gracefully exiting and cleaning up
        }
        printf("Graceful thread: Working %d\n", i);
        sleep(1);
    }

    // Graceful termination with resource cleanup
    printf("Graceful thread: Completing and cleaning up\n");
    pthread_exit(NULL);  // Exiting gracefully
}

// Function for abrupt thread termination
void *abrupt_thread(void *arg) {
    printf("Abrupt thread started\n");

    // Simulating some work
    for (int i = 0; i < 5; i++) {
        printf("Abrupt thread: Working %d\n", i);
        sleep(1);
    }

    // Abrupt termination via pthread_cancel
    printf("Abrupt thread: Terminated abruptly\n");
    pthread_exit(NULL);  // Exiting normally
}

int main() {
    pthread_t thread1, thread2;

    // Create the graceful thread
    pthread_create(&thread1, NULL, graceful_thread, NULL);

    // Create the abrupt thread
    pthread_create(&thread2, NULL, abrupt_thread, NULL);

    // Sleep for 2 seconds to let threads do some work
    sleep(2);

    // Simulate resource cleanup and request graceful thread exit
    cleanup_flag = 1;

    // Abruptly cancel the second thread
    printf("Main thread: Canceling abrupt thread\n");
    pthread_cancel(thread2);

    // Wait for the threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Main thread: All threads completed\n");
    return 0;
}

