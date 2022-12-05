#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sched.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <errno.h>

int main(int argc, char ** argv) {

    if(argc < 2){
            printf("ERROR: Introduce el comando \n");
    }

    int fd[2];
    int tuberia = pipe(fd);

    pid_t pid = fork();

    if(pid == 0){ //Hijo
        dup2(fd[0], 0);         //
        close(fd[1]);       //extremo de escritura
        close(fd[0]);       //extremo de lectura
        execlp(argv[3],argv[3],argv[4], NULL);
    }
    else if(pid > 0){ //Padre
        dup2(fd[1], 1); 
        close(fd[1]);       //extremo de escritura
        close(fd[0]);       //extremo de lectura
        execlp(argv[1],argv[1],argv[2], NULL);
    }
    else{
        perror("ERROR");
        return 0;
    }

    return 0;
}
