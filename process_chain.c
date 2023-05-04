#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <n>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    pid_t pid;
    int i;

    for (i = 0; i < n; i++) {
        sleep(5);
        pid = fork();
        if (pid < 0) {
            printf("fork error\n");
            return 1;
        } else if (pid == 0) {
            printf("Child %d (pid %d) created\n", i + 1, getpid());
            printf("Parent (pid %d)\n",getppid());
        } else {
            printf("Parent (pid %d) created child %d (pid %d)\n", getpid(), i + 1, pid);
            wait(NULL);
            break;
        }
    }

    return 0;
}





//gcc  nomfichier.c -o nomficher
// ./nomfichier
