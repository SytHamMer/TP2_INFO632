#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>



int main(){

    pid_t pid;

    pid = fork();


    if(pid>0){
        printf("l'enfant il procède là \n");
        sleep(10);
    }
    else if(pid == 0){
        printf("L'enfant a fini\n");
        printf("Ceci est le pid du fils : (%d)\n",getpid());

    }
    return 0;




}





//gcc  nomfichier.c -o nomficher
// ./nomfichier
//ps -l pid zombie dit si celui du pid est zombie pendant que le code s'execute