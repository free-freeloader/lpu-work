#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid1, pid2;

    printf("Process P1: PID = %d, PPID = %d\n", getpid(), getppid());

    pid1 = fork(); // First fork to create P2

    if (pid1 == 0) { // In P2 process
        printf("Process P2: PID = %d, PPID = %d\n", getpid(), getppid());

        pid2 = fork(); // Second fork to create P3

        if (pid2 == 0) { // In P3 process
            printf("Process P3: PID = %d, PPID = %d\n", getpid(), getppid());
        }
    }
    return 0;
}
