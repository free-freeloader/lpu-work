#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    printf("Process: P1, PID: %d, PPID: %d\n", getpid(), getppid());

    pid_t pid = fork();
    if (pid == 0) {
        // Inside P2
        printf("Process: P2, PID: %d, PPID: %d\n", getpid(), getppid());

        pid_t pid2 = fork();
        if (pid2 == 0) {
            // Inside P4
            printf("Process: P4, PID: %d, PPID: %d\n", getpid(), getppid());

            pid_t pid3 = fork();
            if (pid3 == 0) {
                // Inside P5
                printf("Process: P5, PID: %d, PPID: %d\n", getpid(), getppid());
            }
        }
    } else {
	pid_t pid7 = fork();
        if (pid7 == 0) {
            // Inside P3
            printf("Process: P3, PID: %d, PPID: %d\n", getpid(), getppid());

            pid_t pid4 = fork();
            if (pid4 == 0) {
                // Inside P6
                printf("Process: P6, PID: %d, PPID: %d\n", getpid(), getppid());
            }
        }
    }

//    sleep(1);  // Allow all processes to print before main exits
    return 0;
}
