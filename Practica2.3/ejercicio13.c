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
            printf("ERROR: Introduce tiempo de alarma\n");
    }

    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGUSR1);
    sigprocmask(SIG_UNBLOCK, &mask, NULL);


    int restante = atoi(argv[1]);
    int alarma = alarm(restante);

    struct sigaction act;
    sigaction(SIGUSR1, NULL, &act);
    act.sa_handler = handler;
    sigaction(SIGUSR1, &act, NULL);

    int i = 0;
    while(alarma>0 && stop == 0){
        i++;
        sleep(1);
    }

    if(stop == 0){
        printf("Proceso terminado \n");
        unlink(argv[0]);
    }
    else{
        printf("Se paro la cuenta atras por la señal SIGUSR \n");
    }
    return 0;
}
