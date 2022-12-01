#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sched.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <signal.h>

int stop = 0;

void handler(int signal){
    if(signal == SIGUSR1) 
        stop = 1; 
}


int main(int argc, char ** argv) {

    if(argc < 2){
            printf("ERROR: Introduce el comando \n");
    }

    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGUSR1);

    int restante = atoi(argv[1]);
    int alarma = alarm(restante);

    struct sigaction act;
    sigaction(SIGUSR1, NULL, &act);
    act.sa_handler = handler;
    sigaction(SIGUSR1, &act, NULL);

    int i = 0;
    while(i < alarma && stop == 0){
        i++;
        sleep(1);
    }

    if(stop == 0){
        unlink(argv[0]);
        printf("Proceso terminado \n");
    }
    else{
        printf("Aqui estamos \n");
    }
    return 0;
}
