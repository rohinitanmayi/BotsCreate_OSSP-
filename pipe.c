#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int pid;
    int fd[2];
    char msg[] = "hello child!";
    char buffer[20];

    if (pipe(fd) == -1) {
        perror("fail to create a pipe\n");
        exit(0);
    }

    pid = fork();

    if (pid < 0) {
        printf("failure in process creation\n");
        exit(0);
    }
    else if (pid == 0) {
        // Child process
        printf("I am in child process\n");
        close(fd[1]);
        read(fd[0], buffer, strlen(msg));
        printf("message from parent: %s\n", buffer);
        close(fd[0]);
    }
    else {
        // Parent process
        printf("I am in parent process\n");
        close(fd[0]);
        write(fd[1], msg, strlen(msg) + 1);
        close(fd[1]);
    }

    return 0;
}

