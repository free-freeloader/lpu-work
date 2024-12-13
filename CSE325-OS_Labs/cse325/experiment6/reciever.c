#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define SEND_PIPE "/tmp/send_pipe"

int main() {
    // Create the named pipe (if not already existing)
    mkfifo(SEND_PIPE, 0666);

    // Open the pipe for reading
    int fd = open(SEND_PIPE, O_RDONLY);

    // Read a message from the pipe
    char message[100];
    read(fd, message, sizeof(message));

    printf("Message received: %s\n", message);
    close(fd);

    // Optionally delete the pipe
    unlink(SEND_PIPE);
    return 0;
}

