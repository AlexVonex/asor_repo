#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sched.h>
#include <sys/resource.h>
#include <sys/time.h>

int main(int argc, char ** argv) {

    if(argc < 2){
            printf("error \n");
    }
    
    pid_t pid = fork();
    
    if(pid == 0){
        pid_t sesion = setsid();
        printf("Hijo: %i padre: %i\n", getpid(), getppid());

        int fdin = open("/tmp/daemon.out", O_CREAT, 00777);
        int fderror = open("/tmp/daemon.err", O_CREAT, 00777);
        int error = open("/dev/null",O_CREAT, 00777);
        int fd1 = dup2(fdin ,0);
        int fd2 = dup2(fderror, 1);
        int fd3 = dup2(error, 2); 

        int salida = execvp(argv[1], argv + 1);

        if(salida == -1){
            printf("error \n");
            return -1;
        }
    }
    else if(pid > 0){
        printf("Padre: %i hijo: %i\n", getpid(), pid);
    }
    else{
        exit(-1);
    }
    return 1;
}
