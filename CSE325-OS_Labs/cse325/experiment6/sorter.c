#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Global array of integers
int numbers[SIZE] = {12, 34, 23, 56, 45, 67, 89, 21, 90, 54};
int sorted_numbers[SIZE];

// Function to sort a part of the array
void *sort_part(void *arg) {
    int *arr = (int *)arg;
    int n = SIZE / 2;  // Each thread handles half the array
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    pthread_exit(NULL);
}

// Function to merge two sorted arrays
void *merge_sorted(void *arg) {
    int *arr1 = (int *)arg;
    int *arr2 = arr1 + SIZE / 2;  // Second half starts after the first half

    int i = 0, j = 0, k = 0;
    while (i < SIZE / 2 && j < SIZE / 2) {
        if (arr1[i] < arr2[j]) {
            sorted_numbers[k++] = arr1[i++];
        } else {
            sorted_numbers[k++] = arr2[j++];
        }
    }
    while (i < SIZE / 2) {
        sorted_numbers[k++] = arr1[i++];
    }
    while (j < SIZE / 2) {
        sorted_numbers[k++] = arr2[j++];
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[3];
    
    // Split the array into two halves
    int first_half[SIZE / 2], second_half[SIZE / 2];
    for (int i = 0; i < SIZE / 2; i++) {
        first_half[i] = numbers[i];
        second_half[i] = numbers[SIZE / 2 + i];
    }

    // Create thread to sort the first half
    pthread_create(&threads[0], NULL, sort_part, (void *)first_half);

    // Create thread to sort the second half
    pthread_create(&threads[1], NULL, sort_part, (void *)second_half);

    // Join the sorting threads
    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }

    // Create thread to merge the sorted halves
    pthread_create(&threads[2], NULL, merge_sorted, (void *)first_half);

    // Wait for the merge thread to finish
    pthread_join(threads[2], NULL);

    // Print the final sorted array
    printf("Sorted Array: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", sorted_numbers[i]);
    }
    printf("\n");

    return 0;
}

