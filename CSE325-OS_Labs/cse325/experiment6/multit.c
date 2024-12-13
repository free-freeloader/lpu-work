#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 5

// Thread function to display thread ID and sequence
void *display_thread_info(void *thread_id) {
    long tid = (long)thread_id;
    printf("Thread ID: %ld, Execution Sequence: %ld\n", tid, tid + 1);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];

    // Create multiple threads
    for (long i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, display_thread_info, (void*)i);
    }

    // Join all threads
    for (long i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

