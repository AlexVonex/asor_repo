include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sched.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <signal.h>

int main(/int argc, char * argv*/) {
    const int SLEEP_SECS = 40;
    sigset_t blk_set;

    sigemptyset(&blk_set);
    sigaddset(&blk_set, SIGINT);
    sigaddset(&blk_set, SIGTSTP);

    sigprocmask(SIG_BLOCK, &blk_set, NULL);

    sleep(SLEEP_SECS);
  

    sigset_t sig;
    sigpending(&sig);

    if(sigismember(&sig, SIGINT) == 1){
        printf("Hemos recibido una senal SIGINT \n");
        sigdelset(&blk_set, SIGINT);
    }
   
    if(sigismember(&sig, SIGTSTP) == 1){
        printf("Hemos recibido una senal SIGTSTP \n");
        sigdelset(&blk_set, SIGTSTP);
    }
    sigprocmask(SIG_UNBLOCK, &blk_set, NULL);
    
    return 0;
}
