#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

char *str1, *str2, *result; // Global variables for strings

// Thread function to concatenate two strings
void *concatenate_strings(void *arg) {
    strcpy(result, str1);
    strcat(result, str2);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    
    // Initialize the strings
    str1 = "Hello, ";
    str2 = "World!";
    
    // Allocate memory for the result string (considering max length)
    result = (char *)malloc(strlen(str1) + strlen(str2) + 1);
    
    // Create a thread to concatenate strings
    pthread_create(&thread, NULL, concatenate_strings, NULL);
    
    // Wait for the thread to finish
    pthread_join(thread, NULL);
    
    // Print the concatenated result
    printf("Concatenated String: %s\n", result);
    
    // Free allocated memory
    free(result);
    
    return 0;
}

