#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>

#define SHM_SIZE 1024  // Size of shared memory
#define SHM_KEY 1234   // Key for shared memory

int main() {
    int shmid;
    char *shm;

    // Create shared memory segment
    shmid = shmget(SHM_KEY, SHM_SIZE, 0666 | IPC_CREAT);
    
    // Fork the process into producer and consumer
    if (fork() == 0) {
        // Consumer Process
        shm = (char *)shmat(shmid, NULL, 0);
       
        printf("Consumer: Waiting for data...\n");
        while (*shm == '\0');  // Wait for producer to write

        printf("Consumer: Data read from shared memory: %s\n", shm);

        // Detach and delete shared memory
        shmdt(shm);
        shmctl(shmid, IPC_RMID, NULL);
    } else {
        // Producer Process
        shm = (char *)shmat(shmid, NULL, 0);
        
        printf("Producer: Enter data: ");
        fgets(shm, SHM_SIZE, stdin);  // Write to shared memory

        printf("Producer: Data written to shared memory.\n");

        // Detach shared memory
        shmdt(shm);
    }

    return 0;
}

