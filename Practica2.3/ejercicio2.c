#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sched.h>

int main(/int argc, char * argv*/) {


    pid_t pid = getpid();
    int esquema =  sched_getscheduler(pid);

    struct sched_param p;
    //int prioridad = p.ched_priority;

    if(esquema == SCHED_OTHER){
        printf("OTHER \n");
    }
    else if(esquema == SCHED_FIFO){
        printf("FIFO \n");
    }
    else if(esquema == SCHED_RR){
        printf("RR \n");
    }
    else{
        char *s;
        perror(s);
    }

    int parametro = sched_getparam(pid, &p);
    int prio = p.sched_priority;
    printf("PRIORIDAD ACTUAL: %d \n", prio);
    int max = sched_get_priority_max(esquema);
    int min = sched_get_priority_min(esquema);

    printf("PRIORIDAD MAXIMA: %d \n", max);
    printf("PRIORIDAD MINIMA: %d \n", min);
  return 0;
}
