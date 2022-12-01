#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sched.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <signal.h>

int contadorint = 0;
int contadorstop = 0;

void handler(int signal){
    if(signal == SIGINT) { 
        contadorint++;
    }
    if(signal == SIGTSTP) { 
        contadorstop++;  
    } 
}

int main(/int argc, char * argv*/) {

    sigset_t blk_set;
    sigemptyset(&blk_set);
    struct sigaction act;

    sigaction(SIGINT, NULL, &act);
    act.sa_handler = handler;
    sigaction(SIGINT, &act, NULL);

    sigaction(SIGTSTP, NULL, &act);
    act.sa_handler = handler;
    sigaction(SIGTSTP, &act, NULL);

    while(contadorint + contadorstop < 10){ 
        sigsuspend(&blk_set);
    }
        printf("Senales de tipo SIGINT: %i \n", contadorint);
        printf("Senales de tipo SIGTSTP: %i \n", contadorstop);

    return 0;
}
