#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void send_signal_to_receiver(pid_t receiver_pid, int signal) {
    kill(receiver_pid, signal);
    printf("Signal %d sent to process %d\n", signal, receiver_pid);
}

int main() {
    pid_t receiver_pid;

    // Assume receiver process has been started and we know its PID
    printf("Enter the PID of the receiver process: ");
    scanf("%d", &receiver_pid);

    // Send a SIGUSR1 signal to the receiver
    send_signal_to_receiver(receiver_pid, SIGUSR1);

    // Send a SIGUSR2 signal to the receiver
    send_signal_to_receiver(receiver_pid, SIGUSR2);

    return 0;
}

