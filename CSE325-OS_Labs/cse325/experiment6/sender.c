#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define SEND_PIPE "/tmp/send_pipe"

int main() {
    // Create the named pipe
    mkfifo(SEND_PIPE, 0666);

    // Open the pipe for writing
    int fd = open(SEND_PIPE, O_WRONLY);
    
    // Write a message to the pipe
    char message[100];
    printf("Enter a message to send: ");
    fgets(message, sizeof(message), stdin);

    // Remove trailing newline
    message[strcspn(message, "\n")] = '\0';

    write(fd, message, strlen(message) + 1);

    printf("Message sent: %s\n", message);
    close(fd);

    // Optionally delete the pipe
    unlink(SEND_PIPE);
    return 0;
}

