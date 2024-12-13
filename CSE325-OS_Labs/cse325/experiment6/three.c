#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Global array of numbers
int numbers[SIZE] = {12, 34, 23, 56, 45, 67, 89, 21, 90, 54};

// Global variables to store the results
double average;
int max_value;
int min_value;

// Function to calculate average
void *calculate_average(void *arg) {
    double sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += numbers[i];
    }
    average = sum / SIZE;
    pthread_exit(NULL);
}

// Function to calculate maximum
void *calculate_maximum(void *arg) {
    max_value = numbers[0];
    for (int i = 1; i < SIZE; i++) {
        if (numbers[i] > max_value) {
            max_value = numbers[i];
        }
    }
    pthread_exit(NULL);
}

// Function to calculate minimum
void *calculate_minimum(void *arg) {
    min_value = numbers[0];
    for (int i = 1; i < SIZE; i++) {
        if (numbers[i] < min_value) {
            min_value = numbers[i];
        }
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[3];

    // Create threads for each statistical operation
    pthread_create(&threads[0], NULL, calculate_average, NULL);
    pthread_create(&threads[1], NULL, calculate_maximum, NULL);
    pthread_create(&threads[2], NULL, calculate_minimum, NULL);
    
    // Join the threads
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    // Output the results
    printf("Average: %.2f\n", average);
    printf("Maximum: %d\n", max_value);
    printf("Minimum: %d\n", min_value);

    return 0;
}

