#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sched.h>
#include <sys/resource.h>
#include <sys/time.h>
int main(/int argc, char * argv*/) {

    pid_t pid = getpid();
    printf("PID: %d \n", pid);
    
    pid_t ppid = getppid();
    printf("PPID: %d \n", ppid);

    pid_t gpid = getpgid(pid);
    printf("GPID: %d \n", gpid);

    pid_t sid = getsid(pid);
    printf("SID: %d \n", sid);

    struct rlimit limit;
    int x = getrlimit(RLIMIT_NOFILE, &limit);

    
    printf("LIMIT: %li \n", limit.rlim_max);

    size_t size = 4096;
    char buff =  malloc(sizeof(char)(size + 1));
    char *ruta = getcwd(buff, size + 1);
    printf("RUTA: %s \n", ruta);
    

    return 1;
}
