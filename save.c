#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    pid_t pid;

    for (int i = 0; i < n; i++) {
        if ((pid = fork()) < 0) {
            printf("Fork error.\n");
            exit(1);
        }
        else if (pid == 0) {
            printf("Child process %d with parent %d.\n", getpid(), getppid());
        }
        else {
            wait(NULL);
            printf("Parent process %d.\n", getpid());
            break;
        }
    }

    return 0;
}





//gcc -o nomfichier.c nomficher
// ./nomfichier
