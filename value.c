#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>



int main(){

    pid_t pid;
    int value;
    int status;

    pid = fork();


    if (pid<0) exit(1);

    else if(pid==0){
        printf("Entrer un entier:  \n");
        scanf("%d",&value);
        exit(value);

    }
    else{
        wait(&status);
        if (WIFEXITED(status)) {
            printf("Child returned: %d\n", WEXITSTATUS(status)); 
        }
    }
    return 0;


}





//gcc  nomfichier.c -o nomficher
// ./nomfichier
//ps -l pid zombie dit si celui du pid est zombie pendant que le code s'execute