#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_READERS 5
#define NUM_WRITERS 1

// Shared variable
int shared_data = 0;

// Semaphore and mutex initialization
sem_t mutex;        // Mutex for synchronizing readers and writers
sem_t write_sem;    // Semaphore for controlling writer access
int reader_count = 0; // Count of active readers

// Reader thread function
void *reader(void *arg) {
    int reader_id = *((int *)arg);

    while (1) {
        // Wait to enter the critical section
        sem_wait(&mutex);

        // Increment the count of active readers
        reader_count++;

        // If this is the first reader, lock the writer semaphore
        if (reader_count == 1) {
            sem_wait(&write_sem);
        }

        // Release the mutex as readers can now safely read
        sem_post(&mutex);

        // Reading the shared data
        printf("Reader %d: Read shared_data = %d\n", reader_id, shared_data);
        sleep(1);

        // Enter the critical section again to decrement reader count
        sem_wait(&mutex);

        // Decrement the reader count
        reader_count--;

        // If this is the last reader, release the writer semaphore
        if (reader_count == 0) {
            sem_post(&write_sem);
        }

        // Release the mutex
        sem_post(&mutex);

        // Sleep to simulate work
        sleep(1);
    }

    return NULL;
}

// Writer thread function
void *writer(void *arg) {
    while (1) {
        // Wait to enter the critical section (only one writer at a time)
        sem_wait(&write_sem);

        // Writing to the shared data
        shared_data++;
        printf("Writer: Wrote shared_data = %d\n", shared_data);

        // Simulate writing time
        sleep(2);

        // Release the writer semaphore for the next writer
        sem_post(&write_sem);

        // Sleep to simulate work
        sleep(1);
    }

    return NULL;
}

int main() {
    pthread_t readers[NUM_READERS];
    pthread_t writers[NUM_WRITERS];
    int reader_ids[NUM_READERS];

    // Initialize semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&write_sem, 0, 1);

    // Create reader threads
    for (int i = 0; i < NUM_READERS; i++) {
        reader_ids[i] = i + 1; // Assigning reader ID
        pthread_create(&readers[i], NULL, reader, (void *)&reader_ids[i]);
    }

    // Create writer threads
    for (int i = 0; i < NUM_WRITERS; i++) {
        pthread_create(&writers[i], NULL, writer, NULL) ;
    }

    // Wait for all threads to complete (in this case, they run indefinitely)
    for (int i = 0; i < NUM_READERS; i++) {
        pthread_join(readers[i], NULL);
    }
    for (int i = 0; i < NUM_WRITERS; i++) {
        pthread_join(writers[i], NULL);
    }

    // Destroy semaphores
    sem_destroy(&mutex);
    sem_destroy(&write_sem);

    return 0;
}

