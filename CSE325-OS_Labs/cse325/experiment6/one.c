#include <stdio.h>
#include <pthread.h>
#include <string.h>

void* msg(void* arg) {
    char* result = (char*)arg;
    for(int i = 0; i < 5; i++) {
        strcat(result, " ");          // Add a space between words
        strcat(result, ((char**)arg)[i]);  // Concatenate each word
    }
    return NULL;
}

int main(){
    char* strings[5] = {"My", "name", "is", "Pankaj", "Bashera"};
    pthread_t thread;
    
    // Allocate memory for the result string
    char result[1024] = "";  // Initialize the result to an empty string
    
    pthread_create(&thread, NULL, msg, (void*)strings);
    pthread_join(thread, NULL);

    printf("%s\n", result); // Print the concatenated string
    return 0;
}

