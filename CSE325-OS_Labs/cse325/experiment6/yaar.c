#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>

// Define the message structure
struct message {
    long msg_type;  // Message type (must be > 0)
    char msg_text[100];
};

// Sender process (Parent process)
void sender(int msgid) {
    struct message msg;
    msg.msg_type = 1;  // Message type (1 for simplicity)

    // Send a message
    strcpy(msg.msg_text, "Hello from sender process!");
    msgsnd(msgid, &msg, sizeof(msg.msg_text), 0);
    printf("Sender: Message sent\n");
}

// Receiver process (Child process)
void receiver(int msgid) {
    struct message msg;

    // Receive a message
    msgrcv(msgid, &msg, sizeof(msg.msg_text), 1, 0);
    printf("Receiver: Received message: %s\n", msg.msg_text);
}

int main() {
    pid_t pid;
    key_t key = 0x12345678;  // Generate unique key
    if (key == -1) {
        perror("ftok failed");
        exit(EXIT_FAILURE);
    }

    // Create message queue
    int msgid = msgget(key, 0666 | IPC_CREAT);

    pid = fork();  // Create a child process

    if (pid == 0) {  // Child process: Receiver
        receiver(msgid);
        // Cleanup message queue after use
        msgctl(msgid, IPC_RMID, NULL);
    } else {  // Parent process: Sender
        sleep(1);  // Ensure receiver is ready before sending
        sender(msgid);
    }

    return 0;
}

