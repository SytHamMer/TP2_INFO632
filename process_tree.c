#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>



void process_tree(int n, int nmax){

    printf("Level %d (pid %d)\n", n, getpid());

    //recursivité

    if ( n<nmax){

        
        pid_t pid1 = fork();
        if (pid1 < 0) {
            printf("fork error\n");

        } else if (pid1 == 0) {
            printf("left Child  (pid %d) created, Son of %d\n",getpid(),getppid());
            process_tree(n+1,nmax);
            if(n==nmax-1)
                sleep(20);
            exit(0);
        } 

        pid_t pid2 = fork();
        if (pid2 < 0) {
            printf("fork error\n");

        } else if (pid2 == 0) {
            printf("right Child (pid %d) created son of %d\n", getpid(),getppid());
            process_tree(n+1,nmax);
            if(n==nmax-1)
                sleep(20);
            exit(0);
        }
        wait(NULL);wait(NULL); 
    }
}

int main() {
    int nmax = 3;
    process_tree(0,3);
    return 0;


}





//gcc  nomfichier.c -o nomficher
// ./nomfichier
