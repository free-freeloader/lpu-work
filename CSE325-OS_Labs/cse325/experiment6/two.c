+++++++++++++++++++++++#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRINGS 5

// Thread function to compute string length
void *find_length(void *arg) {
    char *str = (char *)arg;
    int *length = malloc(sizeof(int));  // Allocate memory to store the length
    *length = strlen(str);
    pthread_exit(length);
}

int main() {
    pthread_t threads[MAX_STRINGS];
    char *strings[MAX_STRINGS] = {
        "Hello",
        "from",
        "pthread",
        "programming",
        "world"
    };

    int *lengths[MAX_STRINGS];

    // Create threads
    for (int i = 0; i < MAX_STRINGS; i++) {
        pthread_create(&threads[i], NULL, find_length, (void *)strings[i]);
        
    }

    // Join threads and collect lengths
    for (int i = 0; i < MAX_STRINGS; i++) {
        pthread_join(threads[i], (void **)&lengths[i]);
        printf("Length of string \"%s\": %d\n", strings[i], *lengths[i]);
        free(lengths[i]); 
    }

    return 0;
}

